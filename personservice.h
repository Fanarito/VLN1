#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <vector>
#include <string>
#include <regex>
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

	void removePerson(person p);

    void reset();

    //Functions to sort the data according to the user's preferences.
    vector<person> getPersons();

    vector<person> sortPersons(string column, string order);
    vector<computer> sortComputers(string column, string order);

    vector<person> filterWithRegex(std::string _regex);

private:
    dataaccess data;
    vector<person> curr_persons;
};

#endif // PERSONSERVICE_H
