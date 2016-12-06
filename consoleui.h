#ifndef CONSOLEUI_H
#define CONSOLEUI_H


#include "personservice.h"
#include <iostream>
#include <string>
#include <algorithm>

const string valid_person_columns[] = {
    "name", "sex", "birthyear", "deathyear", "nationality", "info"
};

const string valid_computer_columns[] = {
    "name", "buildyear", "nationality", "built"
};

const bool MULTI_TOKEN = true;
const bool SINGLE_TOKEN = true;

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

    std::string getInputString(std::string message);
    int getInputInt(std::string message);
};

#endif // CONSOLEUI_H
