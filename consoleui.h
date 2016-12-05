#ifndef CONSOLEUI_H
#define CONSOLEUI_H


#include "personservice.h"
#include "computerservice.h"

class consoleui
{
public:
    consoleui();

    void run();
private:
    personservice ps;

    void print_persons(vector<person> p);
   // void print_computers(vector<computer> c);

    void list();
    void add();
    void change();
    void remove();
    void sort();
    void search();
    void save();
    void regex();
};

#endif // CONSOLEUI_H
