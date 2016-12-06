#ifndef CONSOLEUI_H
#define CONSOLEUI_H


#include "personservice.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>
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
const bool MULTI = true;
const bool SINGLE = false;

const string nomes = "\0";
const string noexp = "\0";

class consoleui
{
public:
    consoleui();

    void run();
private:
    personservice ps;

    void print_persons(vector<person> p);
    void print_computers(vector<computer> c);

    void listMenu();
    void addMenu();
    void changeMenu();
    void removeMenu();
    void sortMenu();
    void searchMenu();
    template<typename T> void printElement(T t, const int& width);

    std::string getInputString(std::string message, bool multiToken, string expected);
    std::string getInputString(std::string message, bool multiToken);
    int getInputInt(std::string message);
};

#endif // CONSOLEUI_H
