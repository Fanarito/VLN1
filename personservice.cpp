#include "personservice.h"
#include <algorithm>

personservice::personservice()
{
  dataaccess().read();
  _persons = dataaccess().getPeople();
}

vector<person> personservice::getPersons()
{
    return *_persons;
}

void personservice::reset() {
  peopleSorted = *_persons;
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
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareName);
    return peopleSorted;
}
vector<person> personservice::reverseAlphabetical()
{
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareNameReverse);
    return peopleSorted;
}
vector<person> personservice::ageDescending()
{
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareYear);
    return peopleSorted;
}
vector<person> personservice::ageAscending()
{
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareYearReverse);
    return peopleSorted;
}

vector<person> personservice::deathDescending()
{
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareDeath);
    return peopleSorted;
}
vector<person> personservice::deathAscending()
{
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareDeathReverse);
    return peopleSorted;
}

vector<person> personservice::genderMale()
{
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareGender);
    return peopleSorted;
}
vector<person> personservice::genderFemale()
{
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareGenderReverse);
    return peopleSorted;
}



