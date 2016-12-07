#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <vector>
#include <string>
#include <regex>
#include <algorithm>
#include <iostream>

#include "person.h"
#include "computer.h"
#include "dataaccess.h"

using namespace std;

class personservice
{
public:
    personservice();
    void addPerson(std::string name, std::string gender, int birthyear, int deathyear, std::string nationality, std::string info);
    void addPerson(person p);

    void addComputer(std::string name, int build_year, std::string type, int built, std::string nationality, std::string info);

    void addConnection(int comp_id, int person_id);

    void removePerson(int id);
    void removeComputer(int id);
    void removeConnection(int pid, int cid);

    void updatePerson(person p);
    void updateComputer(computer c);

    vector<person> getPersons();
    vector<computer> getComputers();

    vector<person> getPersonsConnectedWithComputer(computer c);
    vector<computer> getComputersConnectedWithPerson(person p);

    person getPersonById(unsigned int id, bool &success);
    computer getComputerById(unsigned int id, bool &success);

    //Functions to sort the data according to the user's preferences.
    vector<person> sortPersons(string column, string order);
    vector<computer> sortComputers(string column, string order);

    vector<person> searchPersons(vector<string> args);
    vector<computer> searchComputers(vector<string> args);

    vector<person> filterWithRegex(std::string _regex);

private:
    dataaccess data;
};

#endif // PERSONSERVICE_H
