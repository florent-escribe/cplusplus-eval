#include <iostream>
using namespace std;
#include "functions.hpp"


Status::Status (string status_in) {
    int i = 0;
    while (i<5) {
        if (status_in == tab_stati [i]) {sta=status_in; i=6;}
        else {i+=1;};
    };
}

Status::Status () {}

void Status::print_status () {cout << "Status : " << sta << endl;}

string Status::write_status () {return sta;}