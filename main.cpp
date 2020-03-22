#include <iostream>
using namespace std;
#include "functions.hpp"
#include <fstream>
#include <string>
#include <vector>


int main () {
    string action = demanderAction();
    if ( action =="create") {
        string titre = demanderTitre();
        string description = demanderDescription();
        Priority prio = demanderPriority();
        Status sta = demanderStatus();
        Task task = Task (get_id(),titre,description,sta,prio);
        write_task(task);
    };
    if ( action == "change" ){
        int id = demanderId();
        //string modifiable [4] = {"date de fin", "priorité", "statut", "progrès"};
        string element = demanderModifiable();

        if (element=="date de fin") {
            Date d = demanderDate();
        }
        

    }
}
/*  TESTS DE CREATION DE MES CLASSES
    Priority pr = Priority ("no problem");
    pr.print_priority();

    Status st = Status ("in progress");
    st.print_status();



    Task ta = Task (01, "premiere tache", "test n°1");
    ta.set_end_date(Date (25,1,2020));
    ta.change_status(st);
    ta.change_descr("test change descr");
    ta.print_task();
*/


/*      PREMIERE VERSION OU ON METTAIT TOUTES LES REQUETES DUN COUP
int main (int argc, char* argv []) {

    //faire une fonction par niveau : la première regarde que argv[1], la 2eme [2]...

    if ( ((string)argv[1]) =="create") {
        //il faut récup l'identifiant, càd le nbr de ligne du .txt +1
        Task task = Task (get_id(),argv[3],argv[5]);
        write_task(task);
    };

    if ( ((string)argv[1]) =="change") {
        if ( ((string)argv[3]) =="date de début") {
            
        };        
    };
*/
