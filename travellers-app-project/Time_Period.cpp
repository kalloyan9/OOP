#include <cstring>
#include <iostream>
#include "Time_Period.hpp"
//DD.MM.YYYY

TimePeriod::TimePeriod()
{
    strcpy(from, "00.00.0000");
    strcpy(to, "01.00.0000");
}


void TimePeriod::copy(const TimePeriod& other)
{
    strcpy(this->from, other.from);
    strcpy(this->to, other.to);
}


TimePeriod::TimePeriod(const TimePeriod& other)
{
    copy(other);
}


TimePeriod& TimePeriod::operator=(const TimePeriod& other)
{
    if (this != &other)
    {
        copy(other);
    }
    return *this;
}


inline bool isNumb(char z)
{
    return z >= '0' && z <= '9';
}


void TimePeriod::setFrom(const char* date)
{
    strcpy(this->from, date);
}


void TimePeriod::setTo(const char* date)
{
    strcpy(this->to, date);
}


inline int makeDigit(char t)
{
    return (t - '0');
}


bool TimePeriod::isValid()
{
    //checking the format of from DD.MM.YYYY
    if (!isNumb(from[0]) || !isNumb(from[1]) || from[2] != '.'
        || !isNumb(from[3]) || !isNumb(from[4]) || from[5] != '.'
        || !isNumb(from[6]) || !isNumb(from[7]) || !isNumb(from[8]) || !isNumb(from[9]))
        return false;

    //checking the format of to DD.MM.YYYY
    if (!isNumb(to[0]) || !isNumb(to[1]) || to[2] != '.'
        || !isNumb(to[3]) || !isNumb(to[4]) || to[5] != '.'
        || !isNumb(to[6]) || !isNumb(to[7]) || !isNumb(to[8]) || !isNumb(to[9]))
        return false;

    //converting the dates to a integer (days)
    //for from
    int day1 = makeDigit(from[0]) * 10 + makeDigit(from[1]);
    int month1 = (makeDigit(from[3]) * 10 + makeDigit(from[4]));
    int year1 = (makeDigit(from[6]) * 1000 + makeDigit(from[7]) * 100 + makeDigit(from[8]) * 10 + makeDigit(from[9]));
    if (day1 < 1 || month1 < 1 || (month1 == 2 && day1 > 29) || day1 > 31 || month1 > 12)
        return false;
    //for to
    int day2 = makeDigit(to[0]) * 10 + makeDigit(to[1]);
    int month2 = (makeDigit(to[3]) * 10 + makeDigit(to[4]));
    int year2 = (makeDigit(to[6]) * 1000 + makeDigit(to[7]) * 100 + makeDigit(to[8]) * 10 + makeDigit(to[9]));
    if (day2 < 1 || month2 < 1 || (month2 == 2 && day2 > 29) || day2 > 31 || month2 > 12)
        return false;
    //days*1, months*31, year*12*31
    int resInDays1 =
        day1 //days
        + month1 * 31 //months
        + year1 * 12 * 31;//year
    int resInDays2 =
        day2 //days
        + month2 * 31 //months
        + year2 * 12 * 31;//year

//std::cerr<< std::endl << resInDays1 << " " << resInDays2 << std::endl;
    return resInDays2 >= resInDays1;
}