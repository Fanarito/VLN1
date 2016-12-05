#ifndef CONSOLEUI_H
#define CONSOLEUI_H


#include "personservice.h"

class consoleui
{
public:
    consoleui();

    void run();
private:
    personservice ps;

    void print_persons(vector<person> p);
    void print_computers(vector<computer> c);

    void list();
    void add();
    void change();
    void remove();
    void sort();
    void search();
};

#endif // CONSOLEUI_H
