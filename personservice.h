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
private:
    vector<person> _persons;
};

#endif // PERSONSERVICE_H
