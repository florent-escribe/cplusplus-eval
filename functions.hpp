#include <iostream>
using namespace std;

//ALLER VOIR LE DISCOURSE, YA PT DES TRUCS

//pour l'instant je vais juste récup la date à l'instant de création. ça serait cool de faire JJ/MM/YYYY a la fin
class Date {
    int day;
    int month;
    int year;
    public :
        void print_date ();
        Date ();
        Date (int d, int m, int y);
        int give_day ();
        int give_month ();
        int give_year ();
        void set_date (Date d);
};



class Status { //attention, il faudra pouvoir changer sta depuis task, donc soit en public, soit donner l'autorisation
    string tab_stati [5] = {"open", "closed", "in progress", "boring", "interesting"};    //ou alors une fonction status valide, dans le genre
    string sta;
    public :
        Status ();
        Status (string status_in);  //potentiellement inutile
        void print_status ();
        string get_status ();
        void set_status (Status s);
};

class Priority {  //attention, il faudra pouvoir changer sta depuis task, donc soit en public, soit donner l'autorisation
    string tab_priorities [5] = {"no problem", "think about it", "kinda pressing but ok", "get to work now", "urgent"};
    string prio;
    public :
        Priority (string priority_in);  //potentiellement inutile
        Priority ();
        void print_priority ();
};


class Task {
    int id;
    string title;
    string descr;    
    public :
        Date date_creation; //elle est initialisée tt seule à auj grace à mon constructeur vide
        Date date_end;  //pb : elle est aussi initialisée à aujourd'hui
        Priority priority;
        Status status;
        float progress;

        //pour les suivants, grand array avant de savoir faire des strings
        string* com;
        Task* sub_tasks;
        void change_start_date (Date d);
        void set_end_date (Date d);
        void change_status (Status s);
        void change_progress (float pc);
        void change_priority (Priority prio);
        void add_commentary ();
        void add_sub_task (Task subtask);
        void print_date ();
        
        Task (int id_in, string title_in, string descr_in);
        void print_task ();

};

