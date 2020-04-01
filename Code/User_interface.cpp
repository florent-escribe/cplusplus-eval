#include <iostream>
using namespace std;
#include "functions.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


string demanderGeneral (string question) {  // question est typiquement "Quel identifiant ?" ou "Quel commentaire ?"
    cout << question ;
    string reponse;
    getline(cin,reponse);
    cout<<endl;
    return reponse;
}

int demanderId () {
    cout << "Identifiant de la tâche à modifier : ";
    int id;
    cin >> id;
    cin.ignore();
    cout << endl;
    return id;
}


Date demanderDate () {
    cout << "Date de fin, format DD MM YYYY : "; // ce format est utile pour la fonction de découpage ci-dessous
    string date;
    getline(cin,date);
    cout<<endl;
    auto date_segment = istringstream{date};    // cela permet de découper une string selon les espaces.
    int d;
    int m;
    int y;
    date_segment>>d;
    date_segment>>m;
    date_segment>>y;
    return Date(d,m,y);
}

void print_com (string com) {              // com est la section commentaire d'une tâche dans le fichier texte. Les commentaires sont séparés par '|' (cd Fonctionnement détaillé)
    com+='|';                              // facilite la décomposition à la fin
    
    // Les commentaires sont délimités par des '|'. Je vais stocker la position de chaque '|' dans le tableau tab_delim.
    // Pour créer ce tableau, j'ai besoin du nombre de '|' que je calcule avec compt_delim
    int len = com.length();                // longueur de la string
    int compt_delim = 0;                   // compteur du nbr de "|" parcourus
    int pos_com = 0;                       // position dans com
    while (pos_com<len) {                  // je récupère le nombre de "|", cad le nbr de com +1
        if (com[pos_com]=='|') {
            compt_delim+=1;
        }
        pos_com+=1;
    }
    pos_com=0;                              // je vais reparcourir com
    int tab_delim [compt_delim];            // tableau des positions des délimiteurs de com : tab_delim[i] contient la position du ième '|'
    int compt_delim_bis = 0;                // je recompte les délimiteurs pour savoir quand m'arrêter
    while (compt_delim_bis<compt_delim) {
        if (com[pos_com]=='|') {
            tab_delim[compt_delim_bis]=pos_com;
            compt_delim_bis+=1;
        }
        pos_com+=1;
    }
    int com_num = 1;
    for (int i=0;i<compt_delim-1;i+=1) {    // J'affiche le numéro du commentaire puis le commentaire lui-même
        cout << com_num << " : " << com.substr(tab_delim[i]+1, tab_delim[i+1]-tab_delim[i]-1)<<endl;
        com_num+=1;
    }
}

//3 fois la meme chose, c'est juste l'attribut testé qui change.
void show_id (int id) {
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    bool t = true;     // t = on n'a croisé personne. On aurait pu utilier exist_task mais comme ça on économise une lecture du fichier.
    while (getline(repository_in,ligne) and t){
        Task task = text_to_task(ligne);
        if (task.get_task_id()==id) {
            task.print_task();
            cout<<endl;
            t = false;
        }
    }
    if (t) cout << "La tâche n°" << id << " n'existe pas."<<endl;
}

void show_priority (Priority prio) {
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    bool t = true;  //t = on n'a croisé personne
    while (getline(repository_in,ligne)){
        Task task = text_to_task(ligne);
        if (task.priority.prio==prio.prio) {
            task.print_task();
            cout<<endl;
            t = false;
        }
    }
    if (t) cout << "Aucune tâche de priorité " << prio.write_priority() <<endl;
}

void show_status (Status sta) {
    ifstream repository_in("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");       //fichier de lecture
    string ligne;
    bool t = true;  //t = on n'a croisé personne
    while (getline(repository_in,ligne)){
        Task task = text_to_task(ligne);
        if (task.status.sta==sta.sta) {
            task.print_task();
            cout<<endl;
            t = false;
        }
    }
    if (t) cout << "Aucune tâche de status " << sta.write_status() <<endl;
}