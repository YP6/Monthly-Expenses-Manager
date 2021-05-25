#include "Date.h"

Date::Date(){


}

Date:: Date(int day, int month, int year){
    this->day = day;
    this->month = month;
    this->year = year;
}


int Date::getDay(){
    return this->day;
}


int Date::getMonth(){
    return this->month;
}


int Date::getYear(){
    return this->year;
}

bool Date::operator<(Date other)
{
    if (year < other.getYear())
        return true;

    if (year == other.getYear())
        if (month < other.getMonth())
            return true;
    if (year == other.getYear())
        if (month == other.getMonth())
            if(day < other.getDay())
                return true;
    return false;
}

bool Date::operator>(Date other)
{
    return other < Date(day,month,year);
}

bool Date::operator==(Date other)
{
    if (year == other.getYear())
        if (month == other.getMonth())
            if (day == other.getDay())
                return true;
    return false;
}

bool Date::operator>=(Date other)
{
    return (other == Date(day,month,year)) || (Date(day,month,year) > other);
}

bool Date::operator<=(Date other)
{
    return (other == Date(day, month, year)) || (Date(day, month, year) < other);
}







