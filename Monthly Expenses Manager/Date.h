#pragma once
#include<iostream>
class Date{
    private:
        int day;
        int month;
        int year;
    public:
    Date();
    Date(int day, int month, int year);
    int getDay();
    int getMonth();
    int getYear();
    std::string toString();
    bool operator <(const Date& other);
    bool operator >(const Date& other);
    bool operator ==(const Date& other);
    bool operator <=(const Date& other);
    bool operator >=(const Date& other);
};
