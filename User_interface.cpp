#include <iostream>
using namespace std;
#include "functions.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


string demanderGeneral (string question) {
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
    cout << "Date de fin, format DD MM YYYY : ";
    string date;
    getline(cin,date);
    cout<<endl;
    auto date_segment = istringstream{date};    //ça découpe une string selon les espaces
    int d;
    int m;
    int y;
    date_segment>>d;
    date_segment>>m;
    date_segment>>y;
    return Date(d,m,y);
}

void print_com (string com) {
    com+='|';                              // facilite la décomposition à la fin
    int len = com.length();                // longueur de la string
    int compt_delim = 0;                   // compteur du nbr de "|" parcourus
    int pos_com = 0;                       // position dans com
    while (pos_com<len) {                  // je récupère le nombre de "|", cad le nbr de com +1
        if (com[pos_com]=='|') {
            compt_delim+=1;
        }
        pos_com+=1;
    }
    pos_com=0;
    int tab_delim [compt_delim];            // tableau des positions des délimiteurs de com
    int compt_delim_bis = 0;
    while (compt_delim_bis<compt_delim) {
        if (com[pos_com]=='|') {
            tab_delim[compt_delim_bis]=pos_com;
            compt_delim_bis+=1;
        }
        pos_com+=1;
    }
    int com_num = 1;
    for (int i=0;i<compt_delim-1;i+=1) {
        cout << com_num << " : " << com.substr(tab_delim[i]+1, tab_delim[i+1]-tab_delim[i]-1)<<endl;
        com_num+=1;
    }
}
