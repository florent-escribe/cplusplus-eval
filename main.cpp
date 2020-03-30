#include <iostream>
using namespace std;
#include "functions.hpp"
#include <fstream>
#include <string>
#include <vector>



int main () {
    string action = demanderGeneral ("Quelle action désirez vous accomplir : create, change, delete, show ? ");
    if ( action =="create") {
        string titre = demanderGeneral("Titre (sans point virgule) : ");
        string description = demanderGeneral("Description (sans point virgule) : ");
        Priority prio = demanderGeneral("Priorité (no problem, think about it, kinda pressing but ok, get to work now, urgent): ");
        Status sta = demanderGeneral("Status (open, closed, in progress, forgotten long ago, friendly): ");
        string sub_ta = demanderGeneral("Sous-tâches (identifiants séparés par des espaces): ");
        int nbr_com = stoi(demanderGeneral("Combien de commentaires ? "));
        string com;
        string com_in;
        for (int i=0;i<nbr_com;i+=1){
            cout << "Commentaire " << i+1 << " : ";
            getline(cin,com_in);
            com+='|';
            com+=com_in;
        }
        Task task = Task (get_id(),titre,description,Date(),Date(),prio,sta,0,sub_ta,com);   //METTRE LES DATES A LA FIN DANS LES ARGS pour pouvoir ne pas les écrire ici
        // je dois réarranger les arguments du constructeur pour mettre tous les vides à la fin
        write_task(task);
    };
    if ( action == "change" ){
        int id = demanderId();
        if (exist_task(id)) {
            string element = demanderGeneral("Element à modifier (date de fin, priorité, status, progrès, sous-tâches, commentaires): ");

            if (element=="date de fin") change_end_date (id);
            if (element=="priorité") change_priority(id);
            if (element=="status") change_status(id);     
            if (element=="progrès") change_progress(id);
            if (element=="sous-tâches") change_sub_task(id);
            if (element=="commentaires") change_com(id);
        }
        else cout << "La tâche n°" << id << " n'existe pas." << endl;
    };
    if (action=="delete") {
        int id = demanderId();
        if (exist_task(id)) delete_task (id);
        else cout << "La tâche n°" << id << " n'existe pas." << endl;            
    };
    if (action=="show") {
        string critere = demanderGeneral("Quel est votre critère de choix ? (identifiant, priorité, status) ");
        if (critere=="identifiant") {
            int id = stoi(demanderGeneral("Identifiant : n°"));
            show_id(id);
        }
        if (critere=="priorité") {
            Priority prio = Priority(demanderGeneral("Priorité : (no problem, think about it, kinda pressing but ok, get to work now, urgent) "));
            show_priority(prio);
        }
        if (critere=="status") {
            Status sta = Status(demanderGeneral("Status (open, closed, in progress, forgotten long ago, friendly): "));
            show_status(sta);
        }
    };
}