#include "personservice.h"
#include <algorithm>


#include <iostream>

personservice::personservice()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID");
    curr_computers = data.getComputersByQuery("SELECT * FROM Computers c JOIN Nationality n ON c.NationalityID = n.ID");
}

vector<person> personservice::getPersons()
{
    return curr_persons;
}

vector<computer> personservice::getComputers()
{
    return curr_computers;
}

//Updates current working list of data with changes made in-program
void personservice::reset()
{
    curr_persons = data.getPersonsByQuery("SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID");
    curr_computers = data.getComputersByQuery("SELECT * FROM Computers c JOIN Nationality n ON c.NationalityID = n.ID");
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

void personservice::addComputer(std::string name, int build_year, std::string type, int built, std::string nationality, std::string info)
{
    data.addComputer(computer(name, build_year, type, built, nationality, info));
}

//TODO: REMOVE PERSON LOGIC!
void personservice::removePerson(person p)
{
    data.removePerson(p);
}


vector<person> personservice::sortPersons(string column, string order)
{
    curr_persons = data.getPersonsByQuery(QString::fromStdString("SELECT p.Name, p.Sex, p.Birth_Year, p.Death_Year, n.Nationality, p.Info FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY " + column + " " + order));
    return curr_persons;
}

vector<computer> personservice::sortComputers(string column, string order)
{
    curr_computers = data.getComputersByQuery(QString::fromStdString("SELECT c.Name, c.Build_Year, c.Computer_Type, c.Built, n.Nationality, c.Info FROM Computers c JOIN Nationality n ON c.NationalityID = n.ID ORDER BY " + column + " " + order));
    return curr_computers;
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
