#ifndef SERVICE_H
#define SERVICE_H

#include <vector>
#include <string>
#include <regex>
#include <algorithm>
#include <iostream>

#include "person.h"
#include "computer.h"
#include "dataaccess.h"

using namespace std;

class service
{
public:
    service();
    int addPerson(QString name, QString gender, int birthyear, int deathyear, bool alive, QString nationality, QString info);
    void addPerson(person p);
    int addComputer(QString name, int build_year, QString type, int built, QString nationality, QString info);
    bool addConnection(int comp_id, int person_id);
    void addNationality(QString nationality);
    void addComputerType(QString comp_type);

    void removePerson(int id);
    void removeComputer(int id);
    void removeConnection(int pid, int cid, bool &success);

    void updatePerson(person p);
    void updateComputer(computer c);

    vector<person> getPersons();
    vector<computer> getComputers();
    vector<QString> getNationalities();
    vector<QString> getComputerTypes();

    vector<person> getPersonsConnectedWithComputer(computer c);
    vector<computer> getComputersConnectedWithPerson(person p);

    person getPersonById(unsigned int id, bool &success);
    computer getComputerById(unsigned int id, bool &success);
    int getNationalityById(QString nat);
    int getComputerTypeById(QString comp_type);

    //Functions to sort the data according to the user's preferences.
    vector<person> sortPersons(QString column, QString order);
    vector<computer> sortComputers(QString column, QString order);

    vector<person> searchPersons(vector<QString> args);
    vector<computer> searchComputers(vector<QString> args);

    std::vector<person> filterPersons(QString search_string);
    std::vector<computer> filterComputers(QString search_string);

    vector<person> filterWithRegex(QString _regex);

    int getIdOfPerson(person p);
    int getIdOfComputer(computer c);

private:
    static dataaccess data;
};

#endif // SERVICE_H
