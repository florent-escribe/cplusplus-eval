#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
        void set_date (Date d);
        string write_date ();
};

Date text_to_date (string date);


class Status { //attention, il faudra pouvoir changer sta depuis task, donc soit en public, soit donner l'autorisation
    string tab_stati [5] = {"open", "closed", "in progress", "boring", "interesting"};    //ou alors une fonction status valide, dans le genre
    string sta;
    public :
        Status ();
        Status (string status_in);  //potentiellement inutile
        void print_status ();
        string get_status ();
        void set_status (Status s);
        string write_status ();
};

class Priority {  //attention, il faudra pouvoir changer sta depuis task, donc soit en public, soit donner l'autorisation
    string tab_priorities [5] = {"no problem", "think about it", "kinda pressing but ok", "get to work now", "urgent"};
    string prio;
    public :
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
        Date date_creation; //elle est initialisée tt seule à auj grace à mon constructeur vide
        Date date_end;  //pb : elle est aussi initialisée à aujourd'hui
        Priority priority;
        Status status;
        float progress;

        //pour les suivants, grand array avant de savoir faire des strings
        string* com;
        Task* sub_tasks;

        int get_task_id ();
        string get_title ();
        string get_descr ();

        Task (int id_in, string title_in, string descr_in, Date date_debut = Date(), Date date_fin = Date(),
              Priority prio = Priority(), Status sta = Status(), float prog = 0.);



        void change_start_date (Date d);
        void set_end_date (Date d);

        void change_descr (string d);
        void change_status (Status s);
        void change_progress (float pc);
        void change_priority (Priority prio);

        void add_commentary ();
        void add_sub_task (Task subtask);

        void print_task ();
        void print_date_creation ();
        void print_end_date ();
};

/*
vector<string> split(const string& s, char delimiter)
//Fonction retournant un vector<string> a partir d'un string en spératant a chaque caractère delimiter
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
};
*/

//dans le fichier "fichier_texte.cpp"

void write_task (Task task);
int get_id ();  //donne l'id de la prochaine task, cad le nbr de lignes +1
Task text_to_task (string text);


//Dans User_interface :
string demanderAction ();
string demanderTitre ();
string demanderDescription ();
Priority demanderPriority ();
Status demanderStatus ();
int demanderId ();
string demanderModifiable ();
Date demanderDate ();