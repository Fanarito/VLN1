#include "personservice.h"
#include <algorithm>


#include <iostream>

personservice::personservice()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM persons");
}

vector<person> personservice::getPersons()
{
    return curr_persons;
}

//Updates current working list of data with changes made in-program
void personservice::reset() {
    curr_persons = data.getPersonsByQuery("SELECT * FROM persons");
}

//Adds a person to a vector for later use
void personservice::addPerson(std::string name, std::string gender, int birthyear, int deathyear, std::string nationality, std::string info)
{
    person p(name, gender, birthyear, deathyear, nationality, info);
    persons.push_back(p);
    reset();
}

void personservice::addPerson(person p)
{
    persons.push_back(p);
    reset();
}

void personservice::removePerson(person p)
{
    persons.erase(std::remove(persons.begin(), persons.end(), p), persons.end());
    reset();
}

//Sorts by names in alphabetical order
vector<person> personservice::alphabetical()
{
    current_list = data.getPersonsByQuery("SELECT * FROM persons ORDER BY name");
}

//Sorts by names in reverse alphabetical order
vector<person> personservice::reverseAlphabetical()
{
    current_list = data.getPersonsByQuery("SELECT * FROM persons ORDER BY name DESC");
}

//Sorts by birth year in ascending order
vector<person> personservice::birthAscending()
{
    current_list = data.getPersonsByQuery("SELECT * FROM persons ORDER BY birthyear");
}

//Sorts by birth year in descending order
vector<person> personservice::birthDescending()
{
    current_list = data.getPersonsByQuery("SELECT * FROM persons ORDER BY birthyear DESC");
}

//Sorts by death year in ascending order
vector<person> personservice::deathAscending()
{
   current_list = data.getPersonsByQuery("SELECT * FROM persons ORDER BY deathyear");
}

//Sorts by death year in descending order
vector<person> personservice::deathDescending()
{
    current_list = data.getPersonsByQuery("SELECT * FROM persons ORDER BY deathyear DESC");
}

//Lists male scientists first
vector<person> personservice::genderMale()
{
    current_list = data.getPersonsByQuery("SELECT * FROM persons ORDER BY sex DESC");
}

//Lists female scientists first
vector<person> personservice::genderFemale()
{
    current_list = data.getPersonsByQuery("SELECT * FROM persons ORDER BY sex");
}

//Sorts by nationalites in alphabetical order
vector<person> personservice::nationalityOrder()
{
    current_list = data.getPersonsByQuery("SELECT * FROM persons ORDER BY nationality");
}

//Sorts by nationalities in reverse alphabetical order
void personservice::nationalityReverse()
{
    current_list = data.getPersonsByQuery("SELECT * FROM persons ORDER BY nationality DESC");
}

//Changes string input, name, to lowercase and runs through vector of person and changes its name variables to lowercase.
//This function returns a vector of all names that match, without distinguising uppercase and lowercase characters.
//The change and remove functions in the personservice class use this to make matching case insensitive.
vector<person> personservice::matchByName(string name)
{
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	vector<person> match;

	for(size_t i = 0; i < current_list.size(); i++)
	{
		string thename = current_list[i].getName();
		transform(thename.begin(), thename.end(), thename.begin(), ::tolower);

		if(thename.find(name) != string::npos)
		{
			match.push_back(current_list[i]);
		}
	}

    current_list = match;
	return current_list;
}

//Changes string input, sex, to lowercase and runs through vector of person and changes its sex variables to lowercase.
//This function returns a vector of all sexes that match, without distinguising uppercase and lowercase characters.
//The change and remove functions in the personservice class use this to make matching case insensitive.
vector<person> personservice::matchBySex(string sex)
{
	transform(sex.begin(), sex.end(), sex.begin(), ::tolower);
	vector<person> match;

	for(size_t i = 0; i < current_list.size(); i++)
	{
		string thesex = current_list[i].getSex();
        transform(thesex.begin(), thesex.end(), thesex.begin(), ::tolower);

		if(thesex == sex)
		{
			match.push_back(current_list[i]);
		}
	}

    current_list = match;
	return current_list;
}

//Runs through a vector of person and looks for birth years that match the int input, year.
//The matches are returned in the vector of person, match.
vector<person> personservice::matchByBirth(int year)
{
	vector<person> match;

	for(size_t i = 0; i < current_list.size(); i++)
	{
		if(current_list[i].getBirthYear() == year)
		{
			match.push_back(current_list[i]);
		}
	}

    current_list = match;
	return current_list;
}

//Runs through a vector of person and looks for death years that match the int input, year.
//The matches are returned in the vector of person, match.
vector<person> personservice::matchByDeath(int year)
{
	vector<person> match;

	for(size_t i = 0; i < current_list.size(); i++)
	{
		if(current_list[i].getDeathYear()  == year)
		{
			match.push_back(current_list[i]);
		}
	}

    current_list = match;
	return current_list;
}

//Changes string input, nationality, to lowercase and runs through vector of person and changes its nationality variables to lowercase.
//This function returns a vector of all nationalities that match, without distinguising uppercase and lowercase characters.
//The change and remove functions in the personservice class use this to make matching case insensitive.
vector<person> personservice::matchByNationality(string nationality)
{
    transform(nationality.begin(), nationality.end(), nationality.begin(), ::tolower);
	vector<person> match;

	for(size_t i = 0; i < current_list.size(); i++)
	{
		string thenationality = current_list[i].getNationality();
		transform(thenationality.begin(), thenationality.end(), thenationality.begin(), ::tolower);

		if(thenationality.find(nationality) != string::npos)
		{
			match.push_back(current_list[i]);
		}
	}

    current_list = match;
	return current_list;
}


// Goes through the current list and removes all individuals that do not match the regex statement.
// It tries to match the name, sex, birthyear, deathyear and nationality of the individual to the regex statement.
vector<person> personservice::filterWithRegex(std::string _regex) {
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
      matches = false;
    }
  } catch (std::regex_error) {
    current_list.empty();
  }
  return current_list;
}
