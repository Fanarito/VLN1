#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <vector>
#include <string>
#include <regex>
#include "person.h"
#include "dataaccess.h"

using namespace std;

class personservice
{
public:
    personservice();
    void addPerson(std::string name, std::string gender, int birthyear, int deathyear, std::string nationality, std::string info);

    void reset();
    void save();

    //Functions to sort the data according to the user's preferences.
    vector<person> getPersons();
    vector<person> alphabetical();
    vector<person> reverseAlphabetical();
    vector<person> ageDescending();
    vector<person> ageAscending();
    vector<person> deathDescending();
    vector<person> deathAscending();
    vector<person> genderMale();
    vector<person> genderFemale();
    vector<person> nationalityOrder();
    vector<person> nationalityReverse();

    vector<person> filterNameByRegex(std::string _regex);

private:
    dataaccess data;
    vector<person> persons;
    //vector<person> peopleSorted;
};

#endif // PERSONSERVICE_H
