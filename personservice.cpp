#include "personservice.h"
#include <algorithm>

personservice::personservice()
{

}

vector<person> personservice::getPersons()
{
    return *_persons;
}

void personservice::addPerson(std::string name, std::string gender, int birthyear, int deathyear)
{
    person p(name, gender, birthyear, deathyear);
    //Add the person to a vector for later use
    _persons->push_back(p);
}
//this is where we sort the names in alphabetical order
vector<person> personservice::alphabetical()
{
    peopleSorted = sort(_persons->begin(), _persons->end(), person::compareName);
    return peopleSorted;
}
vector<person> personservice::reverseAlphabetical()
{
    peopleSorted = sort(_persons->begin(), _persons->end(), person::compareNameReverse());
    return peopleSorted;
}
vector<person> personservice::ageDescending()
{
    peopleSorted = sort(_persons->begin(), _persons->end(), person::compareYear());
    return peopleSorted;
}
vector<person> personservice::ageAscending()
{
    peopleSorted = sort(_persons->begin(), _persons->end(), person::compareYearReverse());
    return peopleSorted;
}

vector<person> personservice::deathDescending()
{
    peopleSorted = sort(_persons->begin(), _persons->end(), person::compareDeath());
    return peopleSorted;
}
vector<person> personservice::deathAscending()
{
    peopleSorted = sort(_persons->begin(), _persons->end(), person::compareDeathReverse());
    return peopleSorted;
}

vector<person> personservice::genderMale()
{
    peopleSorted = sort(_persons->begin(), _persons->end(), person::compareGender());
    return peopleSorted;
}
vector<person> personservice::genderFemale()
{
    peopleSorted = sort(_persons->begin(), _persons->end(), person::compareGenderReverse());
    return peopleSorted;
}



