#ifndef CONSOLEUI_H
#define CONSOLEUI_H


#include "personservice.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <array>

const string VALID_TABLE_NAMES = "persons|computers|connections";

const string VALID_PERSON_COLUMNS = "id|name|sex|birth_year|death_year|nationality";
const string VALID_COMPUTER_COLUMNS = "id|name|build_year|computer_type|built|nationality";
const string VALID_CONNECTIONS_COLUMNS = "computersid|personsid";

const string VALID_COMMANDS = "list|add|change|remove|sort|search|info|quit";
const string VALID_SORT_COMMANDS = "asc|desc";

const string INPUT_ENDER = "end;";

const string NO_MESS = "\0";
const string NO_EXP = "\0";

const int PYTHAGORAS = -570;

const bool MULTI = true;
const bool SINGLE = false;

class consoleui
{
public:
    consoleui();
    void run();
private:

    const int nameWidth = 30;
    const int typeWidth = 20;
    const int restWidth = 15;
    const int pageWidth = 60;
    const int combinedWidth = nameWidth + restWidth * 4 + typeWidth;
    const char separator = ' ';

    personservice ps;

    void listMenu(string choice);
    void addMenu(string choice);
    void changeMenu(string choice);
    void removeMenu(string choice);
    void sortMenu(string choice);
    int searchMenu(string choice);
    void infoMenu(string choice);

    void tablePrint(string s, int width);

    void printDetailsPerson(person p);
    void printDetailsComputer(computer c);

    void printInfoPerson(person p);
    void printInfoComputer(computer c);

    void printPersons(vector<person> p);
    void printPersons(person p);

    void printComputers(vector<computer> c);
    void printComputers(computer c);

    void printPersonConnections(vector<person> persons);
    void printComputerConnections(vector<computer> computers);

    std::string getInputString(std::string message, bool multiToken, string expected, bool allow_number);
    std::string getInputString(std::string message, bool multiToken, string expected);
    std::string getInputString(std::string message, bool multiToken);

    int getInputInt(std::string message, int low_bound, int high_bound);
    int getInputInt(std::string message);


};

#endif // CONSOLEUI_H
