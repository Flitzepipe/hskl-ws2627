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

#include "common.h"
#include <iterator>
#include "concepts.h"

namespace FProg
{
    
    template<typename C>
    requires Container<C>
    class Inserter final : public std::iterator<std::output_iterator_tag, typename C::value_type> {
    public:
        Inserter(C& container) : mContainer(container) {}
        
        Inserter& operator*() {return *this;}
        
        Inserter& operator=(const typename C::value_type& v) {mContainer.push_back(v); return *this;}
        
        Inserter& operator++() {return *this;}
    private:
        C& mContainer;
    };
    
    template<typename C>
    Inserter<C> make_inserter(C& container) {
        return Inserter<C>(container);
    }
    
}
