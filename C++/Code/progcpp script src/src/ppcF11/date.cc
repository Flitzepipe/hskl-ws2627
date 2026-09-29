#include "date.h"

#include <iostream> 

namespace FProg {
    Date& Date::add(int days) {
        size_t julianDayNumber = julianDay();
        julianDayNumber += days;
        Date newDate = julianDayNumberToDate(julianDayNumber);
        assert(isValid(newDate));
        mDay = newDate.mDay;
        mMonth = newDate.mMonth;
        mYear = newDate.mYear;
        return *this;
    }
    Date& Date::operator++() {
        add(1);
        return *this;
    }
    Date Date::operator++(int) {
        Date tmp(*this);
        ++(*this);
        return tmp;
    }
    
    Date& Date::operator--()
    {
        add(-1);
        return *this;
    }
    
    Date Date::operator--(int)
    {
        Date tmp(*this);
        --(*this);
        return tmp;
    }
    
    Date::Date(Day d, Month m, Year y) :
        mDay{d.value}, mMonth{m.value}, mYear{y.value}{
    }
    
    Date Date::today() {
        const std::time_t time{std::time(nullptr)};
        std::tm* ltime{localtime(&time)};
        assert(ltime->tm_mday <= 31);
        assert(ltime->tm_mon <= 12);
        return Date{
            Day{static_cast<uint8_t>(ltime->tm_mday)}, 
            Month{static_cast<uint8_t>(ltime->tm_mon + 1)}, 
            Year{static_cast<int16_t>(ltime->tm_year + 1900)}
        }; 
    }
    
    size_t Date::julianDay() const {
        // from http://www.tondering.dk/main/index.php/calendar-information
        const size_t a = (14 - mMonth)/12;
        const size_t y = mYear+4800-a;
        const size_t m = mMonth + 12*a - 3;
        return mDay + (153*m+2)/5 + y*365 + y/4 - y/100 + y/400 - 32045;
    }
    
    Date Date::julianDayNumberToDate(const size_t julianDayNumber) {
        // from http://www.tondering.dk/main/index.php/calendar-information
        const size_t a = julianDayNumber + 32044u;
        const size_t b = (4u * a + 3u) / 146097u;
        const size_t c = a - (b * 146097u) / 4u;
        const size_t d = (4u * c + 3u) / 1461u;
        const size_t e = c - (1461u * d) / 4u;
        const size_t m = (5u * e + 2u) / 153u;
        const uint8_t day = static_cast<uint8_t>(e - (153u * m + 2u) / 5u + 1);
        const uint8_t month = static_cast<uint8_t>(m + 3u - 12u * (m / 10u));
        const int16_t year = static_cast<int16_t>(b * 100u + d - 4800u + m / 10u);
        return Date{Day{day}, Month{month}, Year{year}};
    }
    
    bool Date::isLeapYear(const int year) {
        return (((year % 4) == 0) && ((year % 100) != 0)) || ((year % 400) == 0);
    }
    
    bool Date::isValid(const Date& date) {
        return ((date.mMonth > 0) && ((date.mMonth <= 12))) &&
                ((date.mDay > 0) && (date.mDay <= numberOfDaysInMonth(date.mMonth, date.mYear)));
    }
    
    uint8_t Date::numberOfDaysInMonth(const uint8_t month, const int year)
    {
        assert((month > 0) && (month <= 12));
        static uint8_t numberOfDaysInMonth[] =
        {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        numberOfDaysInMonth[1] = isLeapYear(year) ? 29 : 28;
        return numberOfDaysInMonth[month - 1];
    }
    
    void Date::swap(Date& other) {
        using std::swap;
        swap(mDay, other.mDay);
        swap(mMonth, other.mMonth);
        swap(mYear, other.mYear);
    }
    
    Day::Day(uint8_t day) : value{day} {
        assert((day >= 1) && (day <= 31));
    }
    
    Month::Month(uint8_t month) : value{month} {
        assert((month >= 1) && (month <= 12));
    }
    
    bool operator==(const Date& lhs, const Date& rhs) {
        return lhs.julianDay() == rhs.julianDay();
    }
    
    bool operator<(const Date& lhs, const Date& rhs) {
        return lhs.julianDay() < rhs.julianDay();
    }
    
    std::string to_string(const Date& d) {
        using std::to_string;
        return to_string(d.mYear) + '-' + to_string(d.mMonth) + '-' + to_string(d.mDay);
    }
    
    void swap(Date& a, Date& b) {
        a.swap(b);
    }
    
    std::ostream& operator<<(std::ostream& stream, const Date& date) {
        using std::to_string;
        return stream << to_string(date);
    }
    
    
    
    
    
    
    
    
}
