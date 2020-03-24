#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.hpp"
using namespace std;

void write_task (Task task) {
    
    string const nom_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");   //cette fct servira juste à écrire dans le nouveau repo
    ofstream flux_repository(nom_repository.c_str(), ios::app);
    if(flux_repository){
        flux_repository << task.get_task_id() <<";"<< task.get_title() <<";"<< task.get_descr() <<";"<< task.date_creation.write_date()
        <<";"<< task.date_end.write_date() <<";"<< task.priority.write_priority() <<";"<< task.status.write_status()
        <<";"<< task.progress << endl;//RESTE LES COMS ET SSTACHES
    }
    else{
      cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    };
}

int get_id () {
    int i=1;
    string const nom_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");
    ifstream repository_in("task_repository.txt");  //Ouverture d'un fichier en lecture
    string ligne;
    while (getline(repository_in, ligne)) {i+=1;};
    return i;
}


//faute d'avoir trouvé une bonne méthode de découpeur de string, je le fais à la main, cf explications.txt

Task text_to_task (string text) {   //text est une ligne du repository
    
    int pos_pt_vrg [7];                     // tableau de 7 entiers : les positions des ";" ATTENTION yen aura 9 a la fin
    int compt_pt_vrg = 0;                   // compteur du nbr de ";" parcourus
    int pos_text = 0;                       // position dans text
    while (compt_pt_vrg < 7) {
        if (text[pos_text]==';') {
            pos_pt_vrg[compt_pt_vrg]=pos_text;
            compt_pt_vrg+=1;
        }                                   //JE VAIS AVOIR UN PB AVEC LA LONGEUR DU PROG A LA FIN.
                                            //on suppose POUR LINSTANT que c'est un entier
        pos_text+=1;
    }

    string attributs [8];                   // on stocke les att ss forme de string. ATTENTION : pour l'instant que 8 élé
    attributs[0]=text.substr(0,pos_pt_vrg[0]);
    for (int i=1; i<7; i+=1) {              //remplissage de attributs
        attributs[i]= text.substr(pos_pt_vrg[i-1]+1,pos_pt_vrg[i]-pos_pt_vrg[i-1]-1);
    }
    attributs[7] = text[pos_pt_vrg[6]+1];   //CARREMENT FAUX, ON SUPPOSE UN ENTIER POUR PROGRESS, FAUDRA GERER SA TAILLE
    
    float x = 0.;                           //meme probleme, cest une mesure temporaire
    Task task = Task(stoi(attributs[0]), attributs[1], attributs[2], text_to_date(attributs[3]), text_to_date(attributs[4]),
                     Priority(attributs[5]), Status(attributs[6]), /*float(stoi(attributs[7]))*/ x);
    return task;

}