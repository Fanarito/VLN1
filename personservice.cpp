#include "personservice.h"
#include <algorithm>

personservice::personservice()
{
    persons = dataaccess::read();
}

vector<person> personservice::getPersons()
{
    return persons;
}

void personservice::reset() {
    //peopleSorted = persons;
    persons = data.read();
}

void personservice::save() {
    dataaccess::save(persons);
}

void personservice::addPerson(std::string name, std::string gender, int birthyear, int deathyear)
{
    person p(name, gender, birthyear, deathyear);
    //Add the person to a vector for later use
    persons.push_back(p);
}
//this is where we sort the names in alphabetical order
vector<person> personservice::alphabetical()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareName);
    return peopleSorted;
}
vector<person> personservice::reverseAlphabetical()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareNameReverse);
    return peopleSorted;
}
vector<person> personservice::ageDescending()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareYear);
    return peopleSorted;
}
vector<person> personservice::ageAscending()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareYearReverse);
    return peopleSorted;
}

vector<person> personservice::deathDescending()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareDeath);
    return peopleSorted;
}
vector<person> personservice::deathAscending()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareDeathReverse);
    return peopleSorted;
}

vector<person> personservice::genderMale()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareGender);
    return peopleSorted;
}
vector<person> personservice::genderFemale()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareGenderReverse);
    return peopleSorted;
}



