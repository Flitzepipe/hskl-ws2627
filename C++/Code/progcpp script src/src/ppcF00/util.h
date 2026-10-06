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

#include <iosfwd>
#include <string>
#include <locale>
#include <algorithm>

#include "../lib/hdate.h"

namespace FProg {
    
    template<typename T>
    void toLower(T& s) {
        const auto& facet = std::use_facet<std::ctype<char>>(std::locale());
        facet.tolower(&s[0], &s[0] + s.size());
    }
    
    template<typename T>
    T toLower(const T& s) {
        T copy{s};
        toLower(copy);
        return copy;
    }
    
    template<typename T>
    void sort(T& c) {
        std::sort(std::begin(c), std::end(c));
    }
    
    template<typename C, typename It>
    void copy(const C& c, It inserter) {
        std::copy(std::begin(c), std::end(c), inserter);
    }
    
    template<typename C>
    std::ostream& put(const C& c, std::ostream& out) {
        copy(c, std::ostream_iterator<typename C::value_type>(out, "\n"));
        return out;
    }
}

namespace date {
    template<typename T>
    class DateFormat
    {
        friend DateFormat<const year_month_day&> dateFormat(const year_month_day& ymd, char sep);
        friend DateFormat<year_month_day&> dateFormat(year_month_day& ymd, char sep);
        friend std::ostream& operator<<(std::ostream& out, const DateFormat<const year_month_day&>& f);
        friend std::ostream& operator<<(std::ostream& out, const DateFormat<year_month_day&>& f);
        friend std::istream& operator>>(std::istream& in, const DateFormat<year_month_day&>& f);
        
        inline DateFormat(T ymd, char sep) : mYmd(ymd), mSep(sep) {}
        T mYmd;
        const char mSep = '-';
    };
    
    inline DateFormat<const year_month_day&> dateFormat(const year_month_day& ymd, char sep = '-')
    {
        return DateFormat<const year_month_day&>(ymd, sep);
    }
    
    inline DateFormat<year_month_day&> dateFormat(year_month_day& ymd, char sep = '-')
    {
        return DateFormat<year_month_day&>(ymd, sep);
    }
    
    inline std::ostream& operator<<(std::ostream& out, const DateFormat<const year_month_day&>& f) {
        return out << f.mYmd.year() << f.mSep << static_cast<unsigned>(f.mYmd.month()) << f.mSep << f.mYmd.day();
    }
    
    inline std::ostream& operator<<(std::ostream& out, const DateFormat<year_month_day&>& f) {
        return out << f.mYmd.year() << f.mSep << static_cast<unsigned>(f.mYmd.month()) << f.mSep << f.mYmd.day();
    }
    
    inline std::istream& operator>>(std::istream& in, const DateFormat<year_month_day&>& f) {
        int year = 0;
        int month = 0;
        int day = 0;
        char seperator = f.mSep;
        in >> year >> seperator >> month >> seperator >> day;
        f.mYmd = date::year{year}/month/day;
        return in;
    }
    
}
