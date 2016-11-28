#ifndef PERSONSERVICE_H
#define PERSONSERVICE_H

#include <vector>
#include <string>
#include "person.h"

using namespace std;

class personservice
{
public:
    personservice();
    void addPerson(std::string name, std::string gender, int birthyear, int deathyear);
    vector<person> getPersons();
    vector<person> alphabetical();
    vector<person> reverseAlphabetical();
    vector<person> ageDescending();
    vector<person> ageAscending();;
    vector<person> deathDescending();
    vector<person> deathAscending();
    vector<person> genderMale();
    vector<person> genderFemale();
private:
    vector<person> *_persons;
    vector<person> peopleSorted;
};

#endif // PERSONSERVICE_H
