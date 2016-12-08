#ifndef CONSOLEUI_H
#define CONSOLEUI_H


#include "personservice.h"
#include "utils.h"
#include "constants.h"
#include "color.h"

using namespace constants;

class consoleui
{
public:
    consoleui();
    void run();
private:
    personservice ps;
    string command;

    void listMenu(string choice);
    void addMenu(string choice);
    void changeMenu(string choice);
    void removeMenu(string choice);
    void sortMenu(string choice);
    int searchMenu(string choice, bool printRes=true);
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
