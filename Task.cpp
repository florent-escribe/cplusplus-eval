#include <iostream>
using namespace std;
#include "functions.hpp"
#include <ctime>

int Task::get_task_id () {return id;}
string Task::get_title () {return title;}
string Task::get_descr () {return descr;}


Task::Task (int id_in, string title_in, string descr_in, Date date_debut, Date date_fin, Priority prio, Status sta, int prog, string sub_ta, string com) {
    id=id_in;
    title=title_in;
    descr=descr_in;
    status=sta;
    priority=prio;
    progress=0;
    date_creation=date_debut;
    date_end=date_fin;
    progress=prog;
    sub_task=sub_ta;
    comments=com;
}

string Task::write () {
    string ligne = to_string(id);
    ligne = ligne + ";"+ title +";"+ descr +";"+ date_creation.write_date() +";"+ date_end.write_date() +";"+
            priority.write_priority() +";"+ status.write_status() +";"+ to_string(progress) +";"+ sub_task +";"+ comments;
    return ligne;
}

void Task::print_task () {
    cout << "Tâche n° " << id << endl << "Titre : " << title << endl << "Description : " << descr << endl << "Date de création : ";
    date_creation.print_date();
    cout << "Date de fin : ";
    date_end.print_date();
    priority.print_priority();
    status.print_status();
    cout << "Progress : " << progress << "%" <<endl;
    cout << "Sous-tâches : " << sub_task << endl;
    cout << "Commentaires :"<<endl;
    print_com(comments);
}


void Task::print_date_creation () {date_creation.print_date();}
void Task::print_end_date () {date_end.print_date();}