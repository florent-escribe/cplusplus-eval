#include <iostream>
using namespace std;
#include "functions.hpp"

Date::Date () {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
}

Date::Date (int d, int m, int y) {
    year = y;
    month=m;
    day=d;
}

void Date::print_date () {
    cout << day << "/" << month << "/" << year << endl;
}

int Date::give_day () {return day;}
int Date::give_month () {return month;}
int Date::give_year () {return year;}

void Date::set_date (Date d) {
    day=d.give_day();
    month=d.give_month();
    year=d.give_year();
}

string Date::write_date () {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}