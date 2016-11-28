#include "personservice.h"
#include <algorithm>

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
//this is where we sort the names in alphabetical order
vector<person> personservice::alphabetical(string name)
{
    peopleSorted = sort(_persons->begin(), _persons->end(), person::compareName);
    return peopleSorted;



}
