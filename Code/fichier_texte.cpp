#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.hpp"
#include <sstream>
using namespace std;


void write_task (Task task) {   //on écrit directement la tâche à la suite

    ofstream flux_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt", ios::app); //fichier d'écriture
    flux_repository << task.get_task_id() <<";"<< task.get_title() <<";"<< task.get_descr() <<";"<< task.date_creation.write_date()
                    <<";"<< task.date_end.write_date() <<";"<< task.priority.write_priority() <<";"<< task.status.write_status()
                    <<";"<< task.progress << ";" << task.sub_task << ";" << task.comments << endl;
}

int get_id () {

    ofstream flux_identifiant_out ("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_identifiant.txt"); // fichier d'écriture
    ifstream flux_identifiant_in ("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/identifiant.txt");      // fichier de lecture
    int id;
    flux_identifiant_in >> id;
    flux_identifiant_out << id+1;

    remove ("identifiant.txt");
    char oldname[]="new_identifiant.txt";
    char newname[]="identifiant.txt";
    rename(oldname,newname);

    return id;
}


Task text_to_task (string text) {   // text est une ligne du repository

    // Les attributs sont délimités par des ';'. Je vais stocker la position de chaque ';' dans le tableau pos_pt_vrg.
    text+=";";                              // facilite le remplissage à la fin
    // Je sais qu'il y aura exactement 10 ';' d'après la structure décrite dans la partie Fonctionnement détaillé 

    int len = text.length();                // longueur de la string
    int pos_pt_vrg [10];
    int compt_pt_vrg = 0;                   // compteur du nbr de ";" parcourus
    int pos_text = 0;                       // position dans text
    while (compt_pt_vrg < 10) {
        if (text[pos_text]==';') {
            pos_pt_vrg[compt_pt_vrg]=pos_text;
            compt_pt_vrg+=1;
        }
        pos_text+=1;
    }

    string attributs [10];                   // on stocke les att ss forme de string.
    attributs[0]=text.substr(0,pos_pt_vrg[0]);

    //remplissage de attributs
    for (int i=1; i<10; i+=1) {
        attributs[i]= text.substr(pos_pt_vrg[i-1]+1,pos_pt_vrg[i]-pos_pt_vrg[i-1]-1);
    }

    //création de la tâche
    Task task = Task(stoi(attributs[0]), attributs[1], attributs[2], text_to_date(attributs[3]), text_to_date(attributs[4]),
                     Priority(attributs[5]), Status(attributs[6]), stoi(attributs[7]), attributs[8], attributs[9]);
    return task;
}



void change_end_date (int id) {
    Date d = demanderDate();

    ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    while (getline(repository_in, ligne)) {         //je lis tout le fichier
        Task task = text_to_task(ligne);            //je crée la Task correspondante
        if (task.get_task_id() != id) {             //cette ligne n'est pas concernée
            flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
        }
        else {
            //cette ligne est la ligne concernée : je crée la Task correspondante, je la modifie puis je l'écris.
            Task task_to_change = text_to_task(ligne);
            task_to_change.date_end=d;
            flux_new_repository<<task_to_change.write()<<endl;
        }
    }
    remove ("task_repository.txt");
    char oldname[]="new_repository.txt";
    char newname[]="task_repository.txt";
    rename(oldname,newname);
    cout << "La date de fin a bien été modifiée."<<endl;
}

void change_priority (int id) {
    
    ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    while (getline(repository_in, ligne)) {         //je lis tout le fichier
        Task task = text_to_task(ligne);            //je crée la Task correspondante            
        if (task.get_task_id() != id) {
            flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
        }
        else {
            //cette ligne est la ligne concernée : je crée la Task correspondante, je demande la nouvelle valeur, je modifie puis je l'écris.
            Task task_to_change = text_to_task(ligne);
            cout<< "La priorité actuelle est : " << task_to_change.priority.write_priority() <<endl;
            Priority p = demanderGeneral("Nouvelle priorité (no problem, think about it, kinda pressing but ok, get to work now, urgent): ");
            task_to_change.priority=p;
            flux_new_repository<<task_to_change.write()<<endl;
        }
    }
    remove ("task_repository.txt");
    char oldname[]="new_repository.txt";
    char newname[]="task_repository.txt";
    rename(oldname,newname);
    cout<<"La priorité a bien été modifiée."<<endl;
}

void change_status (int id) {
    
    ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    while (getline(repository_in, ligne)) {         //je lis tout le fichier
        Task task = text_to_task(ligne);            //je crée la Task correspondante
        if (task.get_task_id() != id) {
            flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
        }
        else {
            //cette ligne est la ligne concernée : je crée la Task correspondante, je demande la nouvelle valeur, je modifie puis je l'écris.
            Task task_to_change = text_to_task(ligne);
            cout << "Le status actuel est : " << task_to_change.status.write_status() << endl;
            Status s = demanderGeneral("Nouveau status (open, closed, in progress, forgotten long ago, friendly): ");
            
            task_to_change.status=s;
            flux_new_repository<<task_to_change.write()<<endl;
        }
    }
    remove ("task_repository.txt");
    char oldname[]="new_repository.txt";
    char newname[]="task_repository.txt";
    rename(oldname,newname);
    cout<<"Le status a bien été modifié."<<endl;
}

void change_progress (int id) {
    
    ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    while (getline(repository_in, ligne)) {         //je lis tout le fichier
        Task task = text_to_task(ligne);            //je crée la Task correspondante
        if (task.get_task_id() != id) {
            flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
        }
        else {
            //cette ligne est la ligne concernée : je crée la Task correspondante, je demande la nouvelle valeur, je modifie puis je l'écris.
            Task task_to_change = text_to_task(ligne);
            cout << "Le progrès actuel est : " << task_to_change.progress << "%." << endl;
            int pr = stoi(demanderGeneral("Nouveau progrès : "));
            task_to_change.progress=pr;
            flux_new_repository<<task_to_change.write()<<endl;
        }
    }
    remove ("task_repository.txt");
    char oldname[]="new_repository.txt";
    char newname[]="task_repository.txt";
    rename(oldname,newname);
    cout<<"Le progrès a bien été modifié."<<endl;
}

void change_sub_task (int id) {
    string action = demanderGeneral("Désirez-vous ajouter ou supprimer une sous-tâche ? ");
    if (action=="ajouter") {
        string add_id = demanderGeneral("Quelles tâches souhaitez-vous ajouter (identifiants séparés par des espaces)? ");
        ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture
        ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
        string ligne;
        while (getline(repository_in, ligne)) {         //je lis tout le fichier
            Task task = text_to_task(ligne);            //je crée la Task correspondante
            if (task.get_task_id() != id) {
                flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
            }
            else {
                //cette ligne est la ligne concernée : je crée la Task correspondante, je modifie puis je l'écris.
                Task task_to_change = text_to_task(ligne);
                task_to_change.sub_task+=" ";
                task_to_change.sub_task+=add_id;
                flux_new_repository<<task_to_change.write()<<endl;
            }
        }
        remove ("task_repository.txt");
        char oldname[]="new_repository.txt";
        char newname[]="task_repository.txt";
        rename(oldname,newname);
        cout<<"Nouvelle sous-tâche ajoutée."<<endl;
    };
    if (action=="supprimer") {
        
        ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture
        ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
        string ligne;
        while (getline(repository_in, ligne)) {         //je lis tout le fichier
            Task task = text_to_task(ligne);            
            if (task.get_task_id() != id) {
                flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
            }
            else {
                //cette ligne est la ligne concernée : je crée la Task correspondante, j'affiche ce qui existe, je demande ce qu'il faut supprimer puis je recopie.
                Task task_to_change = text_to_task(ligne);
                string new_sub_task;
                cout << "Les sous-tâches sont : " << task_to_change.sub_task << endl;
                int del_id = stoi(demanderGeneral("Quelle sous-tâche désirez-vous supprimer ? "));
                auto sub_ta_segm = istringstream{task_to_change.sub_task};  //on va parcourir chaque sous-tâche préexistante
                int id_aux;        //pour lire les identifiants préexistants
                while (sub_ta_segm>>id_aux){
                    if (id_aux != del_id) {       //on recopie id_aux si il est pas à supprimer
                        string str_id = to_string(id_aux);
                        new_sub_task+=str_id;
                        new_sub_task+=" ";
                    }
                }              
                task_to_change.sub_task=new_sub_task;
                flux_new_repository<<task_to_change.write()<<endl;
            }
        }
        remove ("task_repository.txt");
        char oldname[]="new_repository.txt";
        char newname[]="task_repository.txt";
        rename(oldname,newname);
        cout<<"Sous-tâche supprimée."<<endl;
    };
}

void change_com (int id) {
    
    ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string action = demanderGeneral("Désirez-vous ajouter ou supprimer un commentaire ? ");
    
    if (action=="ajouter") {
        int nbr_com = stoi(demanderGeneral("Combien de commentaires ? "));
        string com; // contiendra tous les nouveaux commentaires séparés par des '|'
        string com_in;  // contient les nouveaux commentaires un à la fois, quand l'utilisateur les tape.
        for (int i=0;i<nbr_com;i+=1){
            cout << "Commentaire " << i+1 << " : ";
            getline(cin,com_in);
            com+='|';
            com+=com_in;
        }
        string ligne;
        while (getline(repository_in, ligne)) {         //je lis tout le fichier
            Task task = text_to_task(ligne);
            if (task.get_task_id() != id) {
                flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
            }
            else {
                //cette ligne est la ligne concernée : je crée la Task correspondante, j'ajoute le nouveau commmentaire puis je l'écris.
                Task task_to_change = text_to_task(ligne);
                task_to_change.comments+=com;
                flux_new_repository<<task_to_change.write()<<endl;
            }
        }
        remove ("task_repository.txt");
        char oldname[]="new_repository.txt";
        char newname[]="task_repository.txt";
        rename(oldname,newname);
        cout<<"Commentaire ajouté."<<endl;
    };
    if (action=="supprimer") {
        string ligne;
        while (getline(repository_in, ligne)) {         //je lis tout le fichier
            Task task = text_to_task(ligne);
            if (task.get_task_id() != id) {
                flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo
            }
            else {
                //cette ligne est la ligne concernée : je crée la Task correspondante, j'affiche les valeurs supprimables, je demande celle à supprimer, puis je recopie.
                Task task_to_change = text_to_task(ligne);
                string com = task_to_change.comments;
                string new_com;
                cout << "Les commentaires sont : " <<endl;
                print_com(task_to_change.comments);
                int del_com = stoi(demanderGeneral("Quel commentaire désirez-vous supprimer (son numéro)? "));
                // affichage des commentaires existants : il faut décomposer une string selon les '|'
                int compt_delim = 1;    // nombre de '|'
                int pos_com=0;          // position dans les commentaires
                int len = com.length();
                while (pos_com<len) {
                    if (com[pos_com] == '|') {
                        if (compt_delim==del_com) {
                            pos_com+=1;
                            while (pos_com<len and com[pos_com]!='|') pos_com+=1;
                            compt_delim+=1;
                        }
                        if (pos_com<len) {// On vérifie que l'on n'est pas à la fin :
                            new_com+='|'; // si le del_com était le dernier, alors on sort du while précédent en dehors de com et il ne faut rien faire.
                            pos_com+=1;
                            compt_delim+=1;
                        }
                    }
                    else {
                        new_com+=com[pos_com];
                        pos_com+=1;
                    }
                }         
                task_to_change.comments=new_com;
                flux_new_repository<<task_to_change.write()<<endl;
                cout << "Le commentaire "<< del_com << " a bien été supprimé."<<endl;
            }
        }
        remove ("task_repository.txt");
        char oldname[]="new_repository.txt";
        char newname[]="task_repository.txt";
        rename(oldname,newname);
    };
}


void delete_task (int id) {
    ofstream flux_new_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/new_repository.txt");  //fichier d'écriture, créé vide sur le moment
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    while (getline(repository_in, ligne)) {         //je lis tout le fichier
        Task task = text_to_task(ligne);
        if (task.get_task_id() != id) {
            flux_new_repository << ligne << endl;   //je copie la ligne dans le nouveau repo uniquement si son identifiant n'est pas celui à supprimer.
        }
    }
    remove ("task_repository.txt");
    char oldname[]="new_repository.txt";
    char newname[]="task_repository.txt";
    rename(oldname,newname);
    cout << "La tâche " << id << " a bien été supprimée." << endl;
}

bool exist_task (int id) {
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    while (getline(repository_in, ligne)) {         //je lis tout le fichier
        Task task = text_to_task(ligne);
        if (task.get_task_id() == id) {                   //ça convertit un char en int
            return true;
        }
    }
    return false;
}

bool est_dedans (int x, int* t, int len) {
    for (int i=0;i<len;i+=1) {
        if (t[i]==x) return true;
    }
    return false;
}