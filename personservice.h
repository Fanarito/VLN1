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

    void addComputer(std::string name, int build_year, std::string type, int built, std::string nationality, std::string info);

    void removePerson(person p);
    void removeComputer(computer c);

    void reset();

    vector<person> getPersons();
    vector<computer> getComputers();

    //Functions to sort the data according to the user's preferences.
    vector<person> sortPersons(string column, string order);
    vector<computer> sortComputers(string column, string order);

	vector<person> matchByName(string);
	vector<person> matchBySex(string);
	vector<person> matchByBirth(int);
	vector<person> matchByDeath(int);
	vector<person> matchByNationality(string);

    vector<person> searchPersons(vector<string> args);
    vector<computer> searchComputers(vector<string> args);

    vector<computer> matchByCompName(string);
    vector<computer> matchByBuild(int);
    vector<computer> matchByType(string);
    vector<computer> matchByBuilt(string);
    vector<computer> matchByCompNationality(string);

    vector<person> filterWithRegex(std::string _regex);

private:
    dataaccess data;
    vector<person> curr_persons;
    vector<computer> curr_computers;
};

#endif // PERSONSERVICE_H
