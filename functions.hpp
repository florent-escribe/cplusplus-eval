#include <iostream>
using namespace std;


/* pour l'instant je vais juste récup la date à l'instant de création. ça serait cool de faire JJ/MM/YYYY a la fin
class Date {
    int day;
    int month;
    int year;
};
dans le constructeur : si on met rien, on met la date de l'ordi
*/

class Status { //attention, il faudra pouvoir changer sta depuis task, donc soit en public, soit donner l'autorisation
    string tab_stati [5] = {"open", "closed", "in progress", "boring", "interesting"};    //ou alors une fonction status valide, dans le genre
    string sta;
    public :
        Status (string status_in);
        void print_status ();
};

class Priority {  //attention, il faudra pouvoir changer sta depuis task, donc soit en public, soit donner l'autorisation
    string tab_priorities [5] = {"no problem", "think about it", "kinda pressing but ok", "get to work now", "urgent"};
    string prio;
    public :
        Priority (string priority_in);
        void print_priority ();
};

class Task {
    int id;
    string title;
    string descr;
//    Date date_creation;
    string date_creation;
    public :
//        Date date_end;
/*        string date_end;
        Status status;
        float progress;
        Priority priority;
        //pour les suivants, grand array avant de savoir faire des strings
        string* com;
        Task* sub_tasks;
        void change_start_date ();
        void set_end_date ();
        void change_status ();
        void change_progress ();
        void change_priority ();
        void add_commentary ();
        void add_sub_task ();
        void print_date ();
        */
        Task (int id_in, string title_in, string descr_in);
        void print_task ();

};

