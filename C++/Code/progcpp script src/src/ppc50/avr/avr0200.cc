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

#include <array>
#include <utility>

volatile uint8_t x = 0;

using std::array;

template <class T, uint16_t size>
unsigned int pivot (array<T, size> & v, unsigned int start,  unsigned int stop, unsigned int position)
{
    using std::swap;
	swap (v[start], v[position]);

    unsigned int low = start + 1;
	unsigned int high = stop;
	while (low < high)
		if (v[low] < v[start])
			low++;
		else if (v[--high] < v[start])
			swap (v[low], v[high]);

	swap (v[start], v[--low]);
	return low;
}

template <class T, uint16_t size>
void quickSort(array<T, size> & v, uint16_t low, uint16_t high)
{
	if (low >= high)
		return;

	// select the pivot value
	unsigned int pivotIndex = (low + high) / 2;

	// partition the array
	pivotIndex = pivot (v, low, high, pivotIndex);

	// sort the two sub arrays
	if (low < pivotIndex)
		quickSort(v, low, pivotIndex);
	if (pivotIndex < high)
		quickSort(v, pivotIndex + 1, high);
}

template <class T, uint16_t size> 
void quickSort(array<T, size> & v) 
{
    if (v.size > 1) {
        quickSort(v, 0, v.size - 1);
    }
}

array<uint8_t, 100> v1;
//array<uint16_t, 100> v2;

int main() {
	for (size_t i = 0; i < v1.size; i++)
		v1[i] = i;
	quickSort(v1);

//	for (size_t i = 0; i < v2.size; i++)
//		v2[i] = v2.size - i;
//	quickSort(v2);
}

