#include <iostream>
using namespace std;
#include "functions.hpp"
#include <ctime>


//faire des arguments possiblement vides pour priorité/status...

Task::Task (int id_in, string title_in, string descr_in) {
    id=id_in;
    title=title_in;
    descr=descr_in;
    
    time_t now = time(0);   //now : pointeur contenant le nbr de secondes depuis le 01/01/1970
    tm *ltm = localtime(&now);


    progress=0;


}

void Task::print_task () {
    cout << "Tâche n° " << id << endl << "Titre : " << title << endl << "Description : " << descr << endl
    << "Date de création : ";
    date_creation.print_date();
    cout << endl;
}

void Task::set_end_date (Date date) {date_end = date;}    // faudra vrmt faire qqchose pour uniformiser les dates

void Task::change_progress (float pc) {progress = pc;}

