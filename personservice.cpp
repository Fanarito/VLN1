#include "personservice.h"

personservice::personservice()
{

}

vector<person> personservice::getPersons()
{
    return _persons;
}

void personservice::addPerson(std::string name, std::string gender, int birthyear, int deathyear)
{
    person p(name, gender, birthyear, deathyear);
    //Add the person to a vector for later use
    _persons.push_back(p);
}
