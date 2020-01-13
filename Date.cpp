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