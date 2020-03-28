#include <iostream>
using namespace std;
#include "functions.hpp"
#include <fstream>
#include <string>
#include <vector>


int main () {
    //string action = demanderAction();
    string action = demanderGeneral ("Quelle action désirez vous accomplir ? ");
    if ( action =="create") {
        string titre = demanderGeneral("Titre : ");
        string description = demanderGeneral("Description : ");
        Priority prio = demanderGeneral("Priorité : ");
        Status sta = demanderGeneral("Status : ");
        Task task = Task (get_id(),titre,description,Date(),Date(),prio,sta);   //METTRE LES DATES A LA FIN DANS LES ARGS pour pouvoir ne pas les écrire ici
        write_task(task);
    };
    if ( action == "change" ){
        int id = demanderId();
        if (exist_task(id)) {
            //string modifiable [4] = {"date de fin", "priorité", "statut", "progrès"};
            string element = demanderGeneral("Element à modifier : ");

            if (element=="date de fin") {
                change_end_date (id);
                /*Date d = demanderDate();

                ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");
                ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");  //Ouverture d'un fichier en lecture
                string ligne;
                while (getline(repository_in, ligne)) {         //je lis tout le fichier
                    if (ligne[0]-'0' != id) {
                        flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
                    }
                    else {
                        Task task_to_change = text_to_task(ligne);
                        //task_to_change.print_task();
                        task_to_change.date_end=d;
                        flux_new_repository<<task_to_change.write()<<endl;
                    }
                }
                remove ("task_repository.txt");
                char oldname[]="new_repository.txt";
                char newname[]="task_repository.txt";
                rename(oldname,newname);*/
                /*
                while (ligne[0]-'0' != id) {        // ligne[0]-'0' permet de convertir le premier terme en int
                    flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
                    getline(repository_in, ligne);
                };

                // Je suis mtn a la bonne ligne
                // Mtn, je veux pouvoir modifier l'élément d'indice 4 dans une découpe selon ";"
                Task task_to_change = text_to_task(ligne);
                task_to_change.date_end=d;
                //write_task(task_to_change);
                */
            };
            if (element=="priorité") change_priority(id);
            if (element=="status") change_status(id);     
            if (element=="progrès") change_progress(id);
        }
        else cout << "La tâche " << id << " n'existe pas." << endl;
    };
    if (action=="delete") {
        int id = demanderId();
        if (exist_task(id)) delete_task (id);
        else cout << "La tâche " << id << " n'existe pas." << endl;            
    };
}







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
