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

#pragma once

namespace BMCPP {
    namespace AVR {
        struct Output;
        
        template<typename T>
        concept isMCU = requires(T t) {
                typename T::Port;
                typename T::Status;
        };
        
        template<typename P>
        concept isPort = requires (P p) { 
                typename P::mcuport_type;
                typename P::name_type;
                p.get();
        };
    
        template<typename P>
        concept isPin = requires (P p) { 
                typename P::port;
                P::template dir<BMCPP::AVR::Output>();
        };

        template<typename PS>
        concept isPinSet = requires (PS p) { 
                typename PS::pinlist;
        };
    }
}
