#include <iostream>
using namespace std;
#include "functions.hpp"

int main () {
    Priority pr = Priority ("no problem");
    pr.print_priority();        // pourquoi il m'engeule pas alors que pr existe pas vrmt ??

    Status st = Status ("in progress");
    st.print_status();

    Task ta = Task (01, "premiere tache", "test n°1");
    ta.print_task();

}