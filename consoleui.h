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
const string VALID_PERSON_COLUMNS = "name|sex|birth_year|death_year|nationality|info";
const string VALID_COMPUTER_COLUMNS = "name|build_year|nationality|built";

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

    const int nameCompWidth = 30;
    const int namePersonWidth = 25;
    const int typeWidth = 20;
    const int restWidth = 15;
    const char separator = ' ';

    template<typename T> void printElement(T t, const int& width);

    std::string getInputString(std::string message, bool multiToken, string expected);
    std::string getInputString(std::string message, bool multiToken);
    int getInputInt(std::string message);
};

#endif // CONSOLEUI_H
