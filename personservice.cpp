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

void personservice::addPerson(std::string name, std::string gender, int birthyear, int deathyear, std::string nationality, std::string info)
{
    person p(name, gender, birthyear, deathyear, nationality, info);
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

vector<person> personservice::nationalityOrder()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareNationality);
    return peopleSorted;
}

vector<person> personservice::nationalityReverse()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareNationalityReverse);
    return peopleSorted;
}

vector<person> personservice::filterNameByRegex(std::string _regex) {
  vector<person> peopleSorted;
  std::regex regex(_regex);

  for (size_t i = 0; i < persons.size(); i++) {
    if (std::regex_match(persons.at(i).getName(), regex))
      peopleSorted.push_back(persons[i]);
  }
  return peopleSorted;
}
