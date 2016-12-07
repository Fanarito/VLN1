#ifndef CONSOLEUI_H
#define CONSOLEUI_H


#include "personservice.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <array>

const string VALID_TABLE_NAMES = "persons|computers";
const string VALID_PERSON_COLUMNS = "id|name|sex|birth_year|death_year|nationality|info";
const string VALID_COMPUTER_COLUMNS = "id|name|build_year|computer_type|built|nationality";
const string VALID_COMMANDS = "list|add|change|remove|sort|search|info|quit";

const string INPUT_ENDER = "end;";

const string NO_MESS = "\0";
const string NO_EXP = "\0";

const bool MULTI = true;
const bool SINGLE = false;

class consoleui
{
public:
    consoleui();
    void run();
private:
    personservice ps;

    void print_persons(vector<person> p);
    void print_person(person p);
    void print_computers(vector<computer> c);
    void print_computer(computer c);
    void print_options(string options);

    void listMenu(string choice);
    void addMenu(string choice);
    void changeMenu(string choice);
    void removeMenu(string choice);
    void sortMenu(string choice);
    int searchMenu(string choice);
    void infoMenu(string choice);

    const int nameCompWidth = 30;
    const int namePersonWidth = 25;
    const int typeWidth = 20;
    const int restWidth = 15;
    const char separator = ' ';

    template<typename T> void printElement(T t, const int& width);

    std::string getInputString(std::string message, bool multiToken, string expected, bool allow_number);
    std::string getInputString(std::string message, bool multiToken, string expected);
    std::string getInputString(std::string message, bool multiToken);
    int getInputInt(std::string message);
};

#endif // CONSOLEUI_H
