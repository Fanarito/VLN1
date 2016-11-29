#include "personservice.h"
#include <algorithm>


#include <iostream>

personservice::personservice()
{
    persons = dataaccess::read();
    current_list = persons;
}

vector<person> personservice::getPersons()
{
    return current_list;
}

void personservice::reset() {
  current_list = persons;
}

//Saves data to text file
void personservice::save() {
    dataaccess::save(persons);
}

//Adds a person to a vector for later use
void personservice::addPerson(std::string name, std::string gender, int birthyear, int deathyear, std::string nationality, std::string info)
{
    person p(name, gender, birthyear, deathyear, nationality, info);
    persons.push_back(p);
}

void personservice::addPerson(person p)
{
	persons.push_back(p);
}

void personservice::removePerson(person p)
{
	persons.erase(std::remove(persons.begin(), persons.end(), p), persons.end());
}

//this is where we sort the names in alphabetical order
//Sorts by names in alphabetical order
vector<person> personservice::alphabetical()
{
    sort(current_list.begin(), current_list.end(), person::compareName);
    return current_list;
}

//Sorts by names in reverse alphabetical order
vector<person> personservice::reverseAlphabetical()
{
    sort(current_list.begin(), current_list.end(), person::compareNameReverse);
    return current_list;
}

//Sorts by birth year in descending order
vector<person> personservice::birthDescending()
{
    sort(current_list.begin(), current_list.end(), person::compareYear);
    return current_list;
}

//Sorts by birth year in ascending order
vector<person> personservice::birthAscending()
{
    sort(current_list.begin(), current_list.end(), person::compareYearReverse);
    return current_list;
}

//Sorts by death year in descending order
vector<person> personservice::deathDescending()
{
    sort(current_list.begin(), current_list.end(), person::compareDeath);
    return current_list;
}

//Sorts by death year in ascending order
vector<person> personservice::deathAscending()
{
    sort(current_list.begin(), current_list.end(), person::compareDeathReverse);
    return current_list;
}

//Lists male scientists first
vector<person> personservice::genderMale()
{
    sort(current_list.begin(), current_list.end(), person::compareGender);
    return current_list;
}

//Lists female scientists first
vector<person> personservice::genderFemale()
{
    sort(current_list.begin(), current_list.end(), person::compareGenderReverse);
    return current_list;
}

//Sorts by nationalites in alphabetical order
vector<person> personservice::nationalityOrder()
{
    sort(current_list.begin(), current_list.end(), person::compareNationality);
    return current_list;
}

//Sorts by nationalities in reverse alphabetical order
vector<person> personservice::nationalityReverse()
{
    sort(current_list.begin(), current_list.end(), person::compareNationalityReverse);
    return current_list;
}

vector<person> personservice::matchByName(string name)
{
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	vector<person> match;

	for(size_t i = 0; i < persons.size(); i++)
	{
		string thename = persons[i].getName();
		transform(thename.begin(), thename.end(), thename.begin(), ::tolower);

		if(thename.find(name) != string::npos)
		{
			match.push_back(persons[i]);
		}
	}

	return match;
}

vector<person> personservice::matchBySex(string sex)
{
	transform(sex.begin(), sex.end(), sex.begin(), ::tolower);
	vector<person> match;	

	for(size_t i = 0; i < persons.size(); i++)
	{
		string thesex = persons[i].getSex();
        transform(thesex.begin(), thesex.end(), thesex.begin(), ::tolower);

		if(thesex == sex)
		{
			match.push_back(persons[i]);
		}
	}

	return match;
}

vector<person> personservice::matchByBirth(int year)
{
	vector<person> match;

	for(size_t i = 0; i < persons.size(); i++)
	{
		if(persons[i].getBirthYear() == year)
		{
			match.push_back(persons[i]);
		}
	}

	return match;
}

vector<person> personservice::matchByDeath(int year)
{	
	vector<person> match;

	for(size_t i = 0; i < persons.size(); i++)
	{
		if(persons[i].getDeathYear()  == year)
		{
			match.push_back(persons[i]);
		}
	}

	return match;
}

vector<person> personservice::matchByNationality(string nationality)
{
    transform(nationality.begin(), nationality.end(), nationality.begin(), ::tolower);
	vector<person> match;

	for(size_t i = 0; i < persons.size(); i++)
	{
		string thenationality = persons[i].getNationality();
		transform(thenationality.begin(), thenationality.end(), thenationality.begin(), ::tolower);

		if(thenationality.find(nationality) != string::npos)
		{
			match.push_back(persons[i]);
		}
	}

	return match;
}


// COMMENT HERE
vector<person> personservice::filterNameByRegex(std::string _regex) {
  try {
    std::regex regex(_regex);
    bool matches = false;

    for (size_t i = 0; i < current_list.size(); i++) {
      if (std::regex_match(current_list.at(i).getName(), regex))
        matches = true;
      else if (std::regex_match(current_list.at(i).getSex(), regex))
        matches = true;
      else if (std::regex_match(std::to_string(current_list.at(i).getBirthYear()), regex))
        matches = true;
      else if (std::regex_match(std::to_string(current_list.at(i).getDeathYear()), regex))
        matches = true;
      else if (std::regex_match(current_list.at(i).getNationality(), regex))
        matches = true;

      if (!matches) {
        current_list.erase(current_list.begin() + i);
        i--;
      }
    }
  } catch (std::regex_error) {
    current_list.empty();
  }
  return current_list;
}
