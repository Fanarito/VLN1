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

    void list();
    void add();
    void sort();
    void search();
    void save();
};

#endif // CONSOLEUI_H
