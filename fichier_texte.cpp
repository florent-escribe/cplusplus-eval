#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.hpp"
using namespace std;

void write_task (Task task) {
    
    string const nom_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");
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
    int i=1;
    string const nom_repository("/mnt/c/Users/flore/Documents/GitHub/cplusplus-eval/task_repository.txt");
    ifstream repository_in("task_repository.txt");  //Ouverture d'un fichier en lecture
    string ligne;
    while (getline(repository_in, ligne)) {i+=1;};
    return i;
}