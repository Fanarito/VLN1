#ifndef CONSOLEUI_H
#define CONSOLEUI_H


#include "personservice.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <array>

const vector<string> valid_table_names = {
    "persons", "computers"
};

const vector<string> valid_person_columns = {
    "name", "sex", "birthyear", "deathyear", "nationality", "info"
};

const vector<string> valid_computer_columns = {
    "name", "buildyear", "nationality", "built"
};

const string INPUT_ENDER = "end;";

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
