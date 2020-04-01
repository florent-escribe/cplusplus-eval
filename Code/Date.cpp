#include <iostream>
using namespace std;
#include "functions.hpp"

Date::Date () {
    time_t now = time(0);       // on récupère l'heure locale
    tm *ltm = localtime(&now);  // on met au bon format
    year = 1900 + ltm->tm_year; // on décompose en jour mois année
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

string Date::write_date () {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

Date text_to_date (string date) {   // date est sous la forme "day/month/year"

    // Je recupère la position des '/' dans un tableau, je découpe date selon ces valeurs.

    int pos_slash [2];              // tableau de deux entiers : les positions des deux slashs
    int compt_slash = 0;            // compteur du nbr de slash parcourus
    int pos_date = 1;               // position dans date, le premier élément étant forcément un entier
    while (compt_slash < 2) {
        if (date[pos_date]=='/') {
            pos_slash[compt_slash]=pos_date;
            compt_slash+=1;
        }
        pos_date+=1;
    }

    int day = stoi (date.substr(0, pos_slash[1]));
    int month = stoi (date.substr(pos_slash[0]+1, pos_slash[1]-pos_slash[0]-1));
    int year = stoi (date.substr(pos_slash[1]+1, 4));

    return Date(day, month, year);    
}