#include "personservice.h"
#include <algorithm>


#include <iostream>

personservice::personservice()
{

}

vector<person> personservice::getPersons()
{
    return data.getPersons();
}

vector<computer> personservice::getComputers()
{
    return data.getComputers();
}

person personservice::getPersonById(unsigned int id)
{
    return data.getPersonById(id);
}

computer personservice::getComputerById(unsigned int id)
{
    return data.getComputerById(id);
}

void personservice::reset()
{

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

void personservice::removePerson(int id)
{
    data.removePerson(id);
}

void personservice::removeComputer(int id)
{
    data.removeComputer(id);
}

vector<person> personservice::searchPersons(vector<string> args)
{
    return data.searchPersons(args);
}

vector<computer> personservice::searchComputers(vector<string> args)
{
    return data.searchComputers(args);
}

vector<person> personservice::sortPersons(string column, string order)
{
    if(column == "id")
    {
        column = "p.id";
    }

    return data.getPersonsByQuery(QString::fromStdString("SELECT p.ID, p.Name, p.Sex, p.Birth_Year, p.Death_Year, n.Nationality, p.Info FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY " + column + " " + order));
}

vector<computer> personservice::sortComputers(string column, string order)
{
    if(column == "id")
    {
        column = "c.id";
    }

    return data.getComputersByQuery(QString::fromStdString("SELECT c.ID, c.Name, c.Build_Year, c.Computer_Type, c.Built, n.Nationality, c.Info FROM Computers c JOIN Nationality n ON c.NationalityID = n.ID ORDER BY " + column + " " + order));
}

void personservice::updatePerson(person p)
{
    data.updatePerson(p);
}

void personservice::updateComputer(computer c)
{
    data.updateComputer(c);
}
