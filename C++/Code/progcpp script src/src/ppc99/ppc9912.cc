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
#include <memory>
#include <vector>

const size_t SIMULATION_STEPS = 1000;
const size_t NUM = (1000UL*1000);

struct Dings
{
    float x = 0.0f;
    float y = 0.0f;
    std::string name = "default name";
   
    void move(float dx, float dy)
    {
        x += dx;
        y += dy;
    }

    void set_name(const std::string& n)
    {
        name = n;
    }
    void set_name(std::string&& n)
    {
        name = std::move(n);
    }
};

int main()
{
    std::vector<Dings> data(NUM);
    
    for (size_t st = 0; st < SIMULATION_STEPS; ++st)
    {
        for (size_t i = 0; i < NUM; ++i)
            data[i].move(0.01f, -0.02f);
    }
    return 0;
}
