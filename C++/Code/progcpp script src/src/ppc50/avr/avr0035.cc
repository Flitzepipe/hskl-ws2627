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

#include <avr/register.h>
#include <avr/pins.h>
#include <scoped.h>
#include <specials.h>

using namespace BMCPP::AVR;

using PortB = Port<ATMega328::Port, B>;

using led0 = Pin<PortB, 0>;
using led1 = Pin<PortB, 1>;
using led2 = Pin<PortB, 2>;
using led3 = Pin<PortB, 3>;
using leds = PinSet<led0, led1, led2, led3>;

template<typename IndexType, typename ValueType = std::byte, size_t Size = (1 << (sizeof(ValueType) * 8))>
class CheckedMap {
    static inline void triggerError(){} // non-constexpr to trigger error
public:
    struct Inserter {
        constexpr explicit Inserter(IndexType i, CheckedMap& map) : index(i), map(map) {}  
        constexpr void operator=(ValueType v) {
            map.insert(index, v);                        
        }
        IndexType index;
        CheckedMap& map;
    };
    constexpr Inserter operator[](IndexType i) {
        return Inserter(i, *this);
    }
    constexpr void insert(IndexType i, ValueType v) {
        if (mValues[static_cast<uint8_t>(i)]) {
            triggerError(); // trigger compile-time error
        }
        mValues[static_cast<uint8_t>(i)] = v;
        if (!BMCPP::Util::unique(mValues)) {
            triggerError(); // trigger compile-time error
        }
    }    
    constexpr const ValueType& operator[](IndexType i) const {
        return *mValues[static_cast<uint8_t>(i)];
    }
private:
    std::array<std::optional<ValueType>, Size> mValues;
};

template<typename N, typename T>
auto make_map();

struct Inst {
    enum class Name {a, b, c};
    typedef Name name_type;
    typedef std::byte value_type;
    static constexpr auto Code = []{
        CheckedMap<Name, value_type> codes;
        codes[Name::a] = std::byte{1 << 0};
        codes[Name::b] = std::byte{1 << 1};
        codes[Name::c] = std::byte{1 << 2};
        return codes;
    }();
};

template<typename T>
concept isInstruction = requires (T t) {
        typename T::Name;
        T::Code;
        typename T::name_type;
        typename T::value_type;
    };     
    
template<uint8_t LeftBit, uint8_t RightBit>
struct BitRange {
    static_assert(LeftBit >= RightBit);
    static_assert(LeftBit < (sizeof(uint64_t) * 8));
    static inline constexpr auto leftBit = LeftBit;
    static inline constexpr auto rightBit = RightBit;
};

typedef BitRange<7,4> UpperNibble;
typedef BitRange<3,0> LowerNibble;

template<isInstruction I>
struct Command {
    typedef typename I::Name name_type;
    typedef typename I::value_type value_type;

    template<typename Range>
    static constexpr BMCPP::Util::bitsN_t<Range::leftBit - Range::rightBit + 1> get(name_type name) {
        value_type v = I::Code[name];
        value_type mask = value_type{(1 << (Range::leftBit - Range::rightBit + 1)) - 1};
        return BMCPP::Util::bitsN_t<Range::leftBit - Range::rightBit + 1>((v >> Range::rightBit) & mask);
    }
    static constexpr std::byte get(name_type name) {
        static_assert(std::is_same<typename I::value_type, std::byte>::value);
        return I::Code[name];
    }
    template<typename... N>
    static constexpr std::byte combine(N... name) {
        static_assert(std::is_same<typename I::value_type, std::byte>::value);
        return (I::Code[name] | ...);
    }
};

using C1 = Command<Inst>;

int main() {
    leds::dir<Output>();

    auto ha = C1::get<UpperNibble>(Inst::Name::a);
    auto la = C1::get<LowerNibble>(Inst::Name::a);
    
    while(true){
        leds::set(ha);
        leds::set(la);
        
        auto b = C1::combine(Inst::Name::b, Inst::Name::a);
    }
}

inline void __assert_fail (bool, const char*, unsigned int) noexcept {while(true){}}
