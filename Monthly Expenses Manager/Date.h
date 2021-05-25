#pragma once

class Date{
    private:
        int day;
        int month;
        int year;
        cha date;
    public:
    Date();
    Date(int day, int month, int year);
    int getDay();
    int getMonth();
    int getYear();
    string toString();
    bool operator <(Date const &other);
    bool operator >(Date const &other);
    bool operator ==(Date const &other);
    bool operator <=(Date const &other);
    bool operator >=(Date const &other);
};
