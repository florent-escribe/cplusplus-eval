#include <iostream>
using namespace std;
#include "functions.hpp"


Priority::Priority (string priority_in) {
    int i = 0;
    while (i<5) {
        if (priority_in == tab_priorities [i]) {prio=priority_in; i=6;}
        else {i+=1;};
    };
}

Priority::Priority () {}

void Priority::print_priority () {cout << "Priority : " << prio << endl;}

string Priority::write_priority () {return prio;}