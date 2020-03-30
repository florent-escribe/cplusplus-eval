#include <iostream>
using namespace std;


// Dans Date.cpp
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
        string write_date ();
};

Date text_to_date (string date);

//Dans Status.cpp
class Status {
    string tab_stati [5] = {"open", "closed", "in progress", "forgotten long ago", "friendly"};    //ou alors une fonction status valide, dans le genre
    public :
        string sta;
        Status ();
        Status (string status_in);
        void print_status ();
        string get_status ();
        void set_status (Status s);
        string write_status ();
};

class Priority {  //attention, il faudra pouvoir changer sta depuis task, donc soit en public, soit donner l'autorisation
    string tab_priorities [5] = {"no problem", "think about it", "kinda pressing but ok", "get to work now", "urgent"};
    public :
        string prio;    //c'est plus pratique en public pour y accéder facilement, pas besoin de le protéger
        Priority (string priority_in);  //potentiellement inutile
        Priority ();
        void print_priority ();
        string write_priority ();
};


class Task {
    int id;
    string title;
    string descr;    
    public :
        Date date_creation;
        Date date_end;
        Priority priority;
        Status status;
        int progress;
        string sub_task;
        string comments;

        int get_task_id ();
        string get_title ();
        string get_descr ();

        Task (int id_in, string title_in, string descr_in, Date date_debut = Date(), Date date_fin = Date(),
              Priority prio = Priority(), Status sta = Status(), int prog = 0, string sub_ta = "", string com = "");
        string write ();

        void print_task ();
        void print_date_creation ();
        void print_end_date ();
};


//dans le fichier "fichier_texte.cpp"

void write_task (Task task);
int get_id ();  //donne l'id de la prochaine task
Task text_to_task (string text);
void change_end_date (int id);
void change_priority (int id);
void change_status (int id);
void change_progress (int id);
void change_sub_task (int id);
void change_com (int id);
void delete_task (int id);
bool exist_task (int id);
bool est_dedans (int x, int* t, int len);

//Dans User_interface :
/*string demanderAction ();
string demanderTitre ();
string demanderDescription ();
Priority demanderPriority ();
Status demanderStatus ();
string demanderModifiable ();*/
string demanderGeneral (string question);
int demanderId ();
Date demanderDate ();

void print_com (string com);

//3 fois la meme chose, c'est juste l'attribut testé qui change.
void show_id (int id);
void show_priority (Priority prio);
void show_status (Status sta);
