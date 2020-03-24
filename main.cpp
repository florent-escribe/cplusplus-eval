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
        Task task = Task (get_id(),titre,description,Date(),Date(),prio,sta);   //METTRE LES DATES A LA FIN DANS LES ARGS pour pouvoir ne pas les écrire ici
        write_task(task);
    };
    if ( action == "change" ){
        int id = demanderId();
        //string modifiable [4] = {"date de fin", "priorité", "statut", "progrès"};
        string element = demanderModifiable();

        if (element=="date de fin") {
            Date d = demanderDate();

            //ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");
            ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");  //Ouverture d'un fichier en lecture
            string ligne;
            getline(repository_in, ligne);
            while (ligne[0]-'0' != id) {        // ligne[0]-'0' permet de convertir le premier terme en int
                //flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
                getline(repository_in, ligne);
            };
            // Je suis mtn a la bonne ligne
            // Mtn, je veux pouvoir modifier l'élément d'indice 4 dans une découpe selon ";"
            Task task_to_change = text_to_task(ligne);
            task_to_change.date_end=d;
            write_task(task_to_change);
      
        }
    }
    if (action=="test"){
        string const nom_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");
        ifstream repository_in("task_repository.txt");  //Ouverture d'un fichier en lecture
        string ligne;
        getline(repository_in, ligne);
        cout<<ligne<<endl;
        cout<<endl;
        Task ta = text_to_task(ligne);
        cout<<endl;
        ta.print_task();
        
        cout<<endl;
        cout<<"on arrive au bout"<<endl;      
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
