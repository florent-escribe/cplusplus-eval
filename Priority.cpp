#include <iostream>
using namespace std;
#include "functions.hpp"

//mieux gérer le cas où c'est pas official, renvoyer un msg d'erreur ?

Priority::Priority (string priority_in) { //on va tester si la priorité est dans la liste autorisée
    int i = 0;
    while (i<5) {
        if (priority_in == tab_priorities [i]) {prio=priority_in; i=6;}
        else {i+=1;};
    };
    if (i==5) {
        cout << "\"" << priority_in << "\" is not a official priority" << endl;
    };
}

Priority::Priority () {}

void Priority::print_priority () {cout << "Priority : " << prio << endl;}