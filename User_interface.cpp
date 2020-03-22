#include <iostream>
using namespace std;
#include "functions.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

string demanderAction () {
    cout << "Quelle action désirez vous accomplir ? ";
    string action;
    getline(cin,action);
    cout<<endl;
    return action;
}

string demanderTitre () {
    cout << "Titre : ";
    string titre;
    getline(cin,titre);
    cout<<endl;
    return titre;
}

string demanderDescription () {
    cout << "Description : ";
    string description;
    getline(cin,description);
    cout<<endl;
    return description;
}

Priority demanderPriority () {
    cout << "Priorité : ";
    string prio;
    getline(cin,prio);
    cout<<endl;
    return Priority(prio);
}

Status demanderStatus () {
    cout << "Status : ";
    string status;
    getline(cin,status);
    cout<<endl;
    return Status(status);
}

int demanderId () {
    cout << "Identifiant de la tâche à modifier : ";
    int id;
    cin >> id;
    cin.ignore();
    cout << endl;
    return id;
}

string demanderModifiable () {
    cout << "Element à modifier : ";
    string modif;
    getline(cin,modif);
    cout<<endl;
    return modif;
}

Date demanderDate () {
    cout << "Date de fin, format DD MM YYYY : ";
    string date;
    getline(cin,date);
    cout<<endl;
    auto date_segment = istringstream{date};
    int d;
    int m;
    int y;
    date_segment>>d;
    date_segment>>m;
    date_segment>>y;
    return Date(d,m,y);
}