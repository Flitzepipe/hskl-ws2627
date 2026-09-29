/*
 * ++C - C++ introduction
 * Copyright (C) 2013, 2014, 2015, 2016, 2017, 2018 - 2022 Wilhelm Meier <wilhelm.meier@hs-kl.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <cstdint>
#include <cstddef>
#include <optional>
#include <array>

#include <avr/register.h>
#include <avr/pins.h>

#include <scoped.h>
#include <specials.h>
#include <meta.h>

using namespace BMCPP::AVR;

using PortB = Port<ATMega328::Port, B>;

using led0 = Pin<PortB, 0>;
using led1 = Pin<PortB, 1>;
using led2 = Pin<PortB, 2>;
using led3 = Pin<PortB, 3>;
using leds = PinSet<led0, led1, led2, led3>;

using namespace std::literals;    

namespace BMCPP {
    namespace Command {
        namespace detail {
            inline constexpr bool unique(const auto& values) {
                for(const auto& a : values) {
                    for(const auto& b: values) {
                        if (&a != &b) {
                            if (a == b) {
                                return false;
                            }
                        }
                    }
                }
                return true;
            }
        }
        template<auto v>
        struct Value {
            typedef decltype(v) value_type;
            inline static constexpr auto value = v;
        };

        template<typename Command, auto v>
        struct Option {
            typedef Command command_type;
            typedef decltype(v) value_type;
            inline static constexpr auto value = v;  
        };
        template<typename CList, typename OList>
        struct CommandSet;
        template<template<typename...> typename CList, typename... CC, template<typename...> typename OList, typename... OO>
        struct CommandSet<CList<CC...>, OList<OO...>> {
            typedef typename BMCPP::Meta::front<CList<CC...>>::value_type value_type;
            static_assert(BMCPP::Meta::all_same<value_type, BMCPP::Meta::List<typename CC::value_type...>>::value);
            static_assert(BMCPP::Meta::all_same<value_type, BMCPP::Meta::List<typename OO::value_type...>>::value);
            
            typedef CList<CC...> commands;
            typedef OList<CC...> options;
            inline static constexpr std::array<std::byte, sizeof...(CC)> commandValues = {CC::value ...};
//            inline static constexpr std::array<std::byte, sizeof...(OO)> optionsValues = {OO::value ...};
            inline static constexpr std::array<std::byte, sizeof...(OO)> optionsValues = {(OO::command_type::value | OO::value) ...};
            static_assert(detail::unique(commandValues));
            static_assert(detail::unique(optionsValues));
            
            template<typename C, typename... O>
            requires (BMCPP::Meta::contains<commands, C>::value) &&
            (std::is_same<C, typename O::command_type>::value && ... && true)
            static value_type value(C, O...) {
                return C::value | (O::value | ... | 0_byte);    
            }
            template<typename C, typename... O>
            requires (BMCPP::Meta::contains<commands, C>::value) &&
            (std::is_same<C, typename O::command_type>::value && ... && true)
            static value_type value() {
                return C::value | (O::value | ... | 0_byte);    
            }
        };
    }
}


namespace BMCPP {
    namespace Externals {
        using namespace BMCPP::Command;
        template<typename... T> using list = BMCPP::Meta::List<T...>;
 
        struct Lcd {
            struct On : Value<0x31_byte> {};
            struct Mode : Value<0x02_byte>{};
            struct State : Value<0x04_byte>{};
            struct Test : Value<0x08_byte>{};
            
            struct CursorIncrement : Option<Mode, 0x01_byte> {};
            struct ShiftDisplay : Option<Mode, 0x02_byte> {};
            struct X : Option<State, 0x03_byte> {}; 
            
            using commands = BMCPP::Externals::CommandSet<list<On, Mode, State, Test>, list<CursorIncrement, ShiftDisplay, X>>;
        };        
    }
}

template<typename T, uint8_t LeftBit, uint8_t RightBit>
struct BitRange {
    typedef T source_type;
    static_assert(LeftBit >= RightBit);
    static_assert(LeftBit < (sizeof(T) * 8));
    static inline constexpr auto leftBit = LeftBit;
    static inline constexpr auto rightBit = RightBit;
    
    static constexpr BMCPP::Util::bitsN_t<LeftBit - RightBit + 1> convert(source_type v) {
        return BMCPP::Util::bitsN_t<LeftBit - RightBit + 1>{v >> RightBit};
    }
};

using UpperNibble = BitRange<std::byte, 7, 4> ;
using LowerNibble = BitRange<std::byte, 3, 0> ;

template<BMCPP::AVR::isPinSet PinSet, typename Commands>
requires requires {typename Commands::commands; typename Commands::options;}
struct CommandPort {
    template<typename C, typename... OO>
    requires 
    requires(C c) {c.value;} &&
    (requires(OO o) {typename OO::command_type; typename OO::value_type;} && ... && true) &&
    (std::is_same<C, typename OO::command_type>::value && ... && true) &&
    BMCPP::Meta::contains<typename Commands::commands, C>::value 
    inline static void put(OO... options) {
        auto ov = (options.value | ... | C::value);
        PinSet::set(ov);
    }

    template<typename Part, typename C, typename... OO>
    requires 
    requires(C c) {c.value;} &&
    requires(Part p) {typename Part::source_type;} &&
    (requires(OO o) {typename OO::command_type; typename OO::value_type;} && ... && true) &&
    (std::is_same<C, typename OO::command_type>::value && ... && true) &&
    BMCPP::Meta::contains<typename Commands::commands, C>::value 
    inline static void put(OO... options) {
        typename Part::source_type ov = (options.value | ... | C::value);
        PinSet::set(Part::convert(ov));
    }
    
    template<typename C, typename... OO>
    requires 
    requires(C c) {c.value;} &&
    (std::is_same<C, typename OO::command_type>::value && ... && true) &&
    (requires(OO o) {typename OO::command_type;} && ... && true)
    static void get(OO... options) {
        PinSet::read();
    }
};

using lcd = BMCPP::Externals::Lcd; 
using lcdPort = CommandPort<leds, lcd::commands>;

template<typename C, typename... OO>
void writeCommand(C, OO... oo) {

}
template<typename C, typename... OO>
void writeCommand() {

}

int main() {
//    lcdPort::put<lcd::Test>();
//    lcdPort::put<lcd::On>();
//    lcdPort::put<lcd::Mode>(lcd::CursorIncrement{}, lcd::ShiftDisplay{});
//    lcdPort::get<lcd::State>(lcd::X{});

//    lcdPort::put<LowerNibble, lcd::On>();
//    lcdPort::put<UpperNibble, lcd::On>();
    
//    lcdPort::put<BitRange<std::byte, 7, 4>, lcd::On>();
//    lcdPort::put<BitRange<std::byte, 3, 0>, lcd::On>();
    
    
//    lcdPort::put<LowerNibble, lcd::Mode>(lcd::CursorIncrement{}, lcd::ShiftDisplay{});
//    lcdPort::put<UpperNibble, lcd::Mode>(lcd::CursorIncrement{}, lcd::ShiftDisplay{});
    
    writeCommand(lcd::Mode{}, lcd::CursorIncrement{});
    writeCommand<lcd::Mode, lcd::CursorIncrement>();
//    write(lcd::commands::template value<lcd::Mode, lcd::CursorIncrement>());
    
}
