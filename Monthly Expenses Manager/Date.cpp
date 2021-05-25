#include <ctime>
#include "Date.h"

Date::Date(){
    time_t date = time(0);
    tm* currentDate = localtime(&date);
    this->day = currentDate->tm_mday; 
    this->month = (currentDate->tm_mon + 1);
    this->year = (currentDate->tm_year + 1900);

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
