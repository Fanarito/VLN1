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
    persons = data.read();
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
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareName);
    return peopleSorted;
}

//Sorts by names in reverse alphabetical order
vector<person> personservice::reverseAlphabetical()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareNameReverse);
    return peopleSorted;
}

//Sorts by birth year in descending order
vector<person> personservice::birthDescending()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareYear);
    return peopleSorted;
}

//Sorts by birth year in ascending order
vector<person> personservice::birthAscending()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareYearReverse);
    return peopleSorted;
}

//Sorts by death year in descending order
vector<person> personservice::deathDescending()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareDeath);
    return peopleSorted;
}

//Sorts by death year in ascending order
vector<person> personservice::deathAscending()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareDeathReverse);
    return peopleSorted;
}

//Lists male scientists first
vector<person> personservice::genderMale()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareGender);
    return peopleSorted;
}

//Lists female scientists first
vector<person> personservice::genderFemale()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareGenderReverse);
    return peopleSorted;
}

//Sorts by nationalites in alphabetical order
vector<person> personservice::nationalityOrder()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareNationality);
    return peopleSorted;
}

//Sorts by nationalities in reverse alphabetical order
vector<person> personservice::nationalityReverse()
{
    vector<person> peopleSorted = persons;
    sort(peopleSorted.begin(), peopleSorted.end(), person::compareNationalityReverse);
    return peopleSorted;
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
  vector<person> peopleSorted;
  std::regex regex(_regex);

  for (size_t i = 0; i < persons.size(); i++) {
    if (std::regex_match(persons.at(i).getName(), regex))
      peopleSorted.push_back(persons[i]);
    else if (std::regex_match(persons.at(i).getSex(), regex))
      peopleSorted.push_back(persons[i]);
    else if (std::regex_match(std::to_string(persons.at(i).getBirthYear()), regex))
      peopleSorted.push_back(persons[i]);
    else if (std::regex_match(std::to_string(persons.at(i).getDeathYear()), regex))
      peopleSorted.push_back(persons[i]);
    else if (std::regex_match(persons.at(i).getNationality(), regex))
      peopleSorted.push_back(persons[i]);
  }
  return peopleSorted;
}
