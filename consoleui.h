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
	  void change();
	  void remove();
    void sort();
    void search();
    void save();
    void regex();
};

#endif // CONSOLEUI_H
