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
        flux_repository << task.get_id() <<";"<< task.get_title() <<;<< task.get_descr() << task.date_creation <<";"<<
                           task.date_end <<";"<< task.priority <<";"<< task.status <<";"<< task.progress << endl;//RESTE LES COMS ET SSTACHES
    }
    else{
      cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

}