#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.hpp"
using namespace std;

void write_task (Task task) {
    
    string const nom_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");   //cette fct servira juste à écrire dans le nouveau repo
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
    /*ça marche pas du tout dès qu'on va commencer à supprimer des tâches.
    int i=1;
    string const nom_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");
    ifstream repository_in("task_repository.txt");  //Ouverture d'un fichier en lecture
    string ligne;
    while (getline(repository_in, ligne)) {i+=1;};
    return i;
    */

   //nouvelle version avec .txt ; je considère juste que identifiant existe déjà, pas très méchant comme supposition

    ofstream flux_identifiant_out ("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_identifiant.txt");
    ifstream flux_identifiant_in ("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/identifiant.txt");
    int id;
    flux_identifiant_in >> id;
    flux_identifiant_out << id+1;

    remove ("identifiant.txt");
    char oldname[]="new_identifiant.txt";
    char newname[]="identifiant.txt";
    rename(oldname,newname);

    return id;
}


//faute d'avoir trouvé une bonne méthode de découpeur de string, je le fais à la main, cf explications.txt

/*
Task text_to_task (string text) {   //text est une ligne du repository
    
    int len = text.len();                   //longueur de la string
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
                     Priority(attributs[5]), Status(attributs[6]), /*float(stoi(attributs[7]))*/ /*x);
    return task;

}*/

Task text_to_task (string text) {   //text est une ligne du repository
    
    int len = text.length();                   //longueur de la string
    int pos_pt_vrg [7];                     // tableau de 7 entiers : les positions des ";" ATTENTION yen aura 9 a la fin
    int compt_pt_vrg = 0;                   // compteur du nbr de ";" parcourus
    int pos_text = 0;                       // position dans text
    while (compt_pt_vrg < 7) {
        if (text[pos_text]==';') {
            pos_pt_vrg[compt_pt_vrg]=pos_text;
            compt_pt_vrg+=1;
        }
        pos_text+=1;
    }

    string attributs [8];                   // on stocke les att ss forme de string. ATTENTION : pour l'instant que 8 élé
    attributs[0]=text.substr(0,pos_pt_vrg[0]);
    for (int i=1; i<7; i+=1) {              //remplissage de attributs
        attributs[i]= text.substr(pos_pt_vrg[i-1]+1,pos_pt_vrg[i]-pos_pt_vrg[i-1]-1);
    }
    attributs[7] = text.substr(pos_pt_vrg[6]+1,len-1-pos_pt_vrg[6]);

    Task task = Task(stoi(attributs[0]), attributs[1], attributs[2], text_to_date(attributs[3]), text_to_date(attributs[4]),
                     Priority(attributs[5]), Status(attributs[6]), (stoi(attributs[7])));
    return task;
}



void change_end_date (int id) {
    Date d = demanderDate();

    ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    while (getline(repository_in, ligne)) {         //je lis tout le fichier
        if (ligne[0]-'0' != id) {
            flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
        }
        else {
            Task task_to_change = text_to_task(ligne);
            task_to_change.date_end=d;
            flux_new_repository<<task_to_change.write()<<endl;
        }
    }
    remove ("task_repository.txt");
    char oldname[]="new_repository.txt";
    char newname[]="task_repository.txt";
    rename(oldname,newname);
}

void change_priority (int id) {
    Priority p = demanderGeneral("Nouvelle priorité : ");

    ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    while (getline(repository_in, ligne)) {         //je lis tout le fichier
        if (ligne[0]-'0' != id) {
            flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
        }
        else {
            Task task_to_change = text_to_task(ligne);
            task_to_change.priority=p;
            flux_new_repository<<task_to_change.write()<<endl;
        }
    }
    remove ("task_repository.txt");
    char oldname[]="new_repository.txt";
    char newname[]="task_repository.txt";
    rename(oldname,newname);
}

void change_status (int id) {
    Status s = demanderGeneral("Nouveau status : ");

    ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    while (getline(repository_in, ligne)) {         //je lis tout le fichier
        if (ligne[0]-'0' != id) {
            flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
        }
        else {
            Task task_to_change = text_to_task(ligne);
            task_to_change.status=s;
            flux_new_repository<<task_to_change.write()<<endl;
        }
    }
    remove ("task_repository.txt");
    char oldname[]="new_repository.txt";
    char newname[]="task_repository.txt";
    rename(oldname,newname);
}

void change_progress (int id) {
    int pr = stoi(demanderGeneral("Nouveau progrès : "));

    ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    while (getline(repository_in, ligne)) {         //je lis tout le fichier
        if (ligne[0]-'0' != id) {
            flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
        }
        else {
            Task task_to_change = text_to_task(ligne);
            task_to_change.progress=pr;
            flux_new_repository<<task_to_change.write()<<endl;
        }
    }
    remove ("task_repository.txt");
    char oldname[]="new_repository.txt";
    char newname[]="task_repository.txt";
    rename(oldname,newname);
}

void delete_task (int id) {
    ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture, créé vide sur le moment
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    while (getline(repository_in, ligne)) {         //je lis tout le fichier
        if (ligne[0]-'0' != id) {                   //ça convertit un char en int
            flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
        }
    }
    remove ("task_repository.txt");
    char oldname[]="new_repository.txt";
    char newname[]="task_repository.txt";
    rename(oldname,newname);
    cout << "La tâche " << id << " a bien été supprimée." << endl;
}

bool exist_task (int id) {                          //true si existe, false sinon
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    while (getline(repository_in, ligne)) {         //je lis tout le fichier
        if (ligne[0]-'0' == id) {                   //ça convertit un char en int
            return true;
        }
    }
    return false;
}