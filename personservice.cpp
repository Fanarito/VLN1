#include "personservice.h"
#include <algorithm>


#include <iostream>

personservice::personservice()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID");
}

vector<person> personservice::getPersons()
{
    return curr_persons;
}

//Updates current working list of data with changes made in-program
void personservice::reset() {
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID");
}

//Adds a person to a vector for later use
void personservice::addPerson(std::string name, std::string gender, int birthyear, int deathyear, std::string nationality, std::string info)
{
    data.addPerson(person(name,gender,birthyear,deathyear,nationality,info));
}

void personservice::addPerson(person p)
{
    data.addPerson(p);
}

//TODO: REMOVE PERSON LOGIC!
void personservice::removePerson(person p)
{
    //persons.erase(std::remove(persons.begin(), persons.end(), p), persons.end());
    reset();
}

//Sorts by names in alphabetical order
vector<person> personservice::alphabetical()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY name");
    return curr_persons;
}

//Sorts by names in reverse alphabetical order
vector<person> personservice::reverseAlphabetical()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY name DESC");
    return curr_persons;
}

//Sorts by birth year in ascending order
vector<person> personservice::birthAscending()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY birthyear");
    return curr_persons;
}

//Sorts by birth year in descending order
vector<person> personservice::birthDescending()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY birthyear DESC");
    return curr_persons;
}

//Sorts by death year in ascending order
vector<person> personservice::deathAscending()
{
   curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY deathyear");
   return curr_persons;
}

//Sorts by death year in descending order
vector<person> personservice::deathDescending()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY deathyear DESC");
    return curr_persons;
}

//Lists male scientists first
vector<person> personservice::genderMale()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY sex DESC");
    return curr_persons;
}

//Lists female scientists first
vector<person> personservice::genderFemale()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY sex");
    return curr_persons;
}

//Sorts by nationalites in alphabetical order
vector<person> personservice::nationalityOrder()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY nationality");
    return curr_persons;
}

//Sorts by nationalities in reverse alphabetical order
vector<person> personservice::nationalityReverse()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY nationality DESC");
    return curr_persons;
}

//Changes string input, name, to lowercase and runs through vector of person and changes its name variables to lowercase.
//This function returns a vector of all names that match, without distinguising uppercase and lowercase characters.
//The change and remove functions in the personservice class use this to make matching case insensitive.
vector<person> personservice::matchByName(string name)
{
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	vector<person> match;

    for(size_t i = 0; i < curr_persons.size(); i++)
	{
        string thename = curr_persons[i].getName();
		transform(thename.begin(), thename.end(), thename.begin(), ::tolower);

		if(thename.find(name) != string::npos)
		{
            match.push_back(curr_persons[i]);
		}
	}

    curr_persons = match;
    return curr_persons;
}

//Changes string input, sex, to lowercase and runs through vector of person and changes its sex variables to lowercase.
//This function returns a vector of all sexes that match, without distinguising uppercase and lowercase characters.
//The change and remove functions in the personservice class use this to make matching case insensitive.
vector<person> personservice::matchBySex(string sex)
{
	transform(sex.begin(), sex.end(), sex.begin(), ::tolower);
	vector<person> match;

    for(size_t i = 0; i < curr_persons.size(); i++)
	{
        string thesex = curr_persons[i].getSex();
        transform(thesex.begin(), thesex.end(), thesex.begin(), ::tolower);

		if(thesex == sex)
		{
            match.push_back(curr_persons[i]);
		}
	}

    curr_persons = match;
    return curr_persons;
}

//Runs through a vector of person and looks for birth years that match the int input, year.
//The matches are returned in the vector of person, match.
vector<person> personservice::matchByBirth(int year)
{
	vector<person> match;

    for(size_t i = 0; i < curr_persons.size(); i++)
	{
        if(curr_persons[i].getBirthYear() == year)
		{
            match.push_back(curr_persons[i]);
		}
	}

    curr_persons = match;
    return curr_persons;
}

//Runs through a vector of person and looks for death years that match the int input, year.
//The matches are returned in the vector of person, match.
vector<person> personservice::matchByDeath(int year)
{
	vector<person> match;

    for(size_t i = 0; i < curr_persons.size(); i++)
	{
        if(curr_persons[i].getDeathYear()  == year)
		{
            match.push_back(curr_persons[i]);
		}
	}

    curr_persons = match;
    return curr_persons;
}

//Changes string input, nationality, to lowercase and runs through vector of person and changes its nationality variables to lowercase.
//This function returns a vector of all nationalities that match, without distinguising uppercase and lowercase characters.
//The change and remove functions in the personservice class use this to make matching case insensitive.
vector<person> personservice::matchByNationality(string nationality)
{
    transform(nationality.begin(), nationality.end(), nationality.begin(), ::tolower);
	vector<person> match;

    for(size_t i = 0; i < curr_persons.size(); i++)
	{
        string thenationality = curr_persons[i].getNationality();
		transform(thenationality.begin(), thenationality.end(), thenationality.begin(), ::tolower);

		if(thenationality.find(nationality) != string::npos)
		{
            match.push_back(curr_persons[i]);
		}
	}

    curr_persons = match;
    return curr_persons;
}


// Goes through the current list and removes all individuals that do not match the regex statement.
// It tries to match the name, sex, birthyear, deathyear and nationality of the individual to the regex statement.
vector<person> personservice::filterWithRegex(std::string _regex) {
  try {
    std::regex regex(_regex);
    bool matches = false;

    for (size_t i = 0; i < curr_persons.size(); i++) {
      if (std::regex_match(curr_persons.at(i).getName(), regex))
        matches = true;
      else if (std::regex_match(curr_persons.at(i).getSex(), regex))
        matches = true;
      else if (std::regex_match(std::to_string(curr_persons.at(i).getBirthYear()), regex))
        matches = true;
      else if (std::regex_match(std::to_string(curr_persons.at(i).getDeathYear()), regex))
        matches = true;
      else if (std::regex_match(curr_persons.at(i).getNationality(), regex))
        matches = true;

      if (!matches) {
        curr_persons.erase(curr_persons.begin() + i);
        i--;
      }
      matches = false;
    }
  } catch (std::regex_error) {
    curr_persons.empty();
  }
  return curr_persons;
}
