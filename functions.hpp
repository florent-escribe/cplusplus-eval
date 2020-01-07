#include <iostream>
using namespace std;

//utiliser la bibliothèque ctime pour récup le tmps local ; l'adapter pour le transformer en Date
class Date {
    int day;
    int month;
    int year;
};
//dans le constructeur : si on met rien, on met la date de l'ordi

class Status {
    char tab_stati [5] = {"open", "closed", "in progress", "boring", "interesting"};    //ou alors une fonction status valide, dans le genre
    char sta;
    public :
        Status (char status_in);
};

class Priority {
    char tab_priorities [5] = {"no problem", "think about it", "kinda pressing but ok", "get to work now", "urgent"};
    char prio;
    public :
        Priority (char priority_in);
};

class Task {
    int id;
    char title;
    char descr;
        public :
        Date date_creation;
        Date date_end;
        Status status;
        float progress;
        Priority priority;
        //pour les suivants, grand array avant de savoir faire des strings
        char* com;
        Task* sub-tasks;
        void change_start_date ();
        void set_end_date ();
        void change_status ();
        void change_progress ();
        void change_priority ();
        void add_commentary ();
        void add sub_task ();
};

