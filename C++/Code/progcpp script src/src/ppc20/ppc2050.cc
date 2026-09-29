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

#include <string>

//[kvp1
template<typename KeyType, typename ValueType> // <> Das allg. Template
class KVPair {
public:
    explicit KVPair(const KeyType& key, const ValueType& value) : 
        mKey{key}, mValue{value} {}
private:
    const KeyType mKey;
    ValueType mValue;
};
//]
//[kvp2
template<typename KeyType> // <> Eine partielle Spezialisierung: der Template-Typ-Parameter `ValueType` ...
class KVPair<KeyType, const char*> { // <> ... durch den konkreten Typ `const char*` ersetzt worden.
public:
    explicit KVPair(const KeyType& key, const char* value) : 
        mKey{key}, mValue{value} {}
private:
    const KeyType mKey;
    std::string mValue; //<> Auch ein C-String als _Wert_ wird als {stdstring} gespeichert.
};
//]
//[kvp3
template<typename KeyType, size_t N>
class KVPair<KeyType, char[N]> {
public:
    explicit KVPair(const KeyType& key, const char* value) : 
        mKey{key}, mValue{value} {}
private:
    const KeyType mKey;
    std::string mValue; 
};
//]
//[kvp4
template<typename KeyType, typename ValueType>
class KVPair<KeyType*, ValueType>;
//]
int main() {
    //[main1
    KVPair<int, std::string> kv1{1, "abc"}; // <> Hier findet eine implizite Wandlung von `const char*` nach `std::string` statt.
    KVPair<int, const char*> kv2{2, "def"};
    //]
    //[main2
    KVPair                   kv3{3, "ghi"}; // <> Automatische Template-Parameter-Ableitung
    //]
    //[main3
#if 0 //-
    KVPair<const char*, std::string> kv4{"a", "xyz"}; // <> Durch die (unvollständige) Spezialisierung für Zeigertypen ist dies nicht mehr möglich.
#endif //-
    //]
}
