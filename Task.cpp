#include <iostream>
using namespace std;
#include "functions.hpp"
#include <ctime>


//faire des arguments possiblement vides pour priorité/status...

Task::Task (int id_in, string title_in, string descr_in) {
    id=id_in;
    title=title_in;
    descr=descr_in;
    progress=0;
}

void Task::print_task () {
    cout << "Tâche n° " << id << endl << "Titre : " << title << endl << "Description : " << descr << endl
    << "Date de création : ";
    date_creation.print_date();
    cout << "Date de fin : ";
    date_end.print_date();
    cout << endl;
}

void Task::set_end_date (Date date) {date_end = date;}    // faudra vrmt faire qqchose pour uniformiser les dates

void Task::change_start_date (Date d) {date_creation.set_date(d);}

void Task::change_progress (float pc) {progress = pc;}

//void Task::set_end_date (Date d) {date_end.set_date(d);}

void Task::change_status (Status s) {status.set_status(s);}