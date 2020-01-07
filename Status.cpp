#include <iostream>
using namespace std;
#include "functions.hpp"

//mieux gérer le cas où c'est pas official, renvoyer un msg d'erreur ?

Status::Status (string status_in) { //on va tester si le status est dans la liste autorisée
    int i = 0;
    while (i<5) {
        if (status_in == tab_stati [i]) {sta=status_in; i=6;}
        else {i+=1;};
    };
    if (i==5) {
        cout << "\"" << status_in << "\" is not a official status" << endl;
    };
}

void Status::print_status () {cout << "Status : " << sta << endl;}