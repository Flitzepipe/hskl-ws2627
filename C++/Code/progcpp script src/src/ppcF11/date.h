#pragma once

#include "common.h"

#include <cstdint>
#include <cstdlib>
#include <cassert>
#include <ctime>

namespace FProg {
    struct Day final {
        explicit Day(uint8_t day);
        const uint8_t value{};
    };
    struct Month final {
        explicit Month(uint8_t month);
        const uint8_t value{};
    };
    struct Year final {
        const int16_t value{};
    };
    class Date final {
        friend std::string to_string(const Date& d);
    public:
        Date() = delete;
        Date(Day d, Month m, Year y);
        
        static Date today();
        
        size_t julianDay() const;
        Date& add(int days);
        
        Date& operator++();
        Date operator++(int);
        Date& operator--();
        Date operator--(int);
        
        static Date julianDayNumberToDate(const size_t julianDayNumber);
        static bool isLeapYear(const int year);
        static bool isValid(const Date& date);
        static uint8_t numberOfDaysInMonth(const uint8_t month, const int year);
        
        void swap(Date& other);
    private:
        uint8_t mDay{1};
        uint8_t mMonth{1};
        int16_t mYear{1};
    };
    bool operator==(const Date& lhs, const Date& rhs);    
    bool operator<(const Date& lhs, const Date& rhs);    
    std::string to_string(const Date& d);
    void swap(Date& a, Date& b);
    std::ostream& operator<<(std::ostream& stream, const Date& date);
}

