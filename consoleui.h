#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <array>
#include <time.h>

#include "personservice.h"
#include "utils.h"
#include "constants.h"

using namespace constants;

class consoleui
{
public:
    consoleui();
    void run();
private:
    personservice ps;

    void printPersons(vector<person> p);
    void printComputers(vector<computer> c);

    void printPerson(person p);
    void printComputer(computer c);

    void printPersonConnections(vector<person> persons);
    void printComputerConnections(vector<computer> computers);

    void listMenu(string choice);
    void addMenu(string choice);
    void changeMenu(string choice);
    void removeMenu(string choice);
    void sortMenu(string choice);
    int searchMenu(string choice);
    void infoMenu(string choice);

    std::string getInputString(std::string message, bool multiToken, string expected, bool allow_number);
    std::string getInputString(std::string message, bool multiToken, string expected);
    std::string getInputString(std::string message, bool multiToken);

    int getInputInt(std::string message, int low_bound, int high_bound);
    int getInputInt(std::string message);

    int getCurrentYear();
};

#endif // CONSOLEUI_H
