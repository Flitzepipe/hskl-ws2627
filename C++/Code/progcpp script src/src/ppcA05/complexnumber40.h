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

#include "../ppc.h"

#include <string>

//[CN -a
class ComplexNumber
{
public:
    //[a
    ComplexNumber(double real = 0.0, double imag = 0.0);
    ~ComplexNumber();

    double real() const;
    double imag() const;
    std::string name() const;
    std::string toString() const;
    //]
    //[svg
    std::string toSVG() const; // <> Die Beobachter-Elementfunktion, um die `svg`-Darstellung zu generieren.

    std::string color() const;
    void color(std::string color);
    //]
    //[a
    void real(double value);
    void imag(double value);
    void name(std::string name);

    bool isReal() const;
    bool isImag() const;

    void add(ComplexNumber c);
    static ComplexNumber add(ComplexNumber c1, ComplexNumber c2);
    //]
private:
    //[a
    double mReal{0.0};
    double mImag{0.0};
    std::string mName;
    //]
    //[svg
    inline static const int mSVGRadius{3}; // <> Ein _statisches_ Datenelement zur Festlegung des Radius des `circle`-Elements in der `svg`-Darstellung
    std::string mColor{"black"};
    //]
};
//]
