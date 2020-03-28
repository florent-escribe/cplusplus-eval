#include <iostream>
using namespace std;
#include "functions.hpp"
#include <ctime>

int Task::get_task_id () {return id;}
string Task::get_title () {return title;}
string Task::get_descr () {return descr;}



//faire des arguments possiblement vides pour priorité/status...
/*Task::Task (int id_in, string title_in, string descr_in) {//les dates de création/fin sont initialisées à auj par défaut à la création
    id=id_in;
    title=title_in;
    descr=descr_in;
    progress=0;
}*/


//Je rajoute des arg potentiellement vides
Task::Task (int id_in, string title_in, string descr_in, Date date_debut, Date date_fin, Priority prio, Status sta, int prog) {
    //les dates de création/fin sont initialisées à auj par défaut à la création
    id=id_in;
    title=title_in;
    descr=descr_in;
    status=sta;
    priority=prio;
    progress=0;
    date_creation=date_debut;
    date_end=date_fin;
    progress=prog;
}

string Task::write () {
    string ligne = to_string(id);
    ligne+=";";
    ligne+=title;
    ligne+=";";
    ligne+=descr;
    ligne+=";";
    ligne+=date_creation.write_date();
    ligne+=";";
    ligne+=date_end.write_date();
    ligne+=";";
    ligne+=priority.write_priority();
    ligne+=";";
    ligne+=status.write_status();
    ligne+=";";
    ligne+=to_string(progress);
    return ligne;
}

void Task::print_task () {
    cout << "Tâche n° " << id << endl << "Titre : " << title << endl << "Description : " << descr << endl
    << "Date de création : ";
    date_creation.print_date();
    cout << "Date de fin : ";
    date_end.print_date();
    priority.print_priority();
    status.print_status();
    cout << "Progress : " << progress;
    cout << endl;
}

void Task::change_start_date (Date d) {date_creation=d;}
void Task::set_end_date (Date date) {date_end = date;}    // faudra vrmt faire qqchose pour uniformiser les dates

void Task::change_descr (string d) {descr=d;}
void Task::change_status (Status s) {status=s;}
void Task::change_progress (float pc) {progress = pc;}
void Task::change_priority (Priority prio) {priority=prio;}

void Task::print_date_creation () {date_creation.print_date();}
void Task::print_end_date () {date_end.print_date();}