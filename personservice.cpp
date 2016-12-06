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

vector<person> personservice::matchByName(string name)
{
    curr_persons = data.getPersonsByQuery(QString::fromStdString("SELECT p.Name, p.Sex, p.Birth_Year, p.Death_Year, n.Nationality, p.Info FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID WHERE p.Name LIKE '%" + name + "%'"));
    return curr_persons;
}

vector<person> personservice::matchBySex(string sex)
{
    curr_persons = data.getPersonsByQuery(QString::fromStdString("SELECT p.Name, p.Sex, p.Birth_Year, p.Death_Year, n.Nationality, p.Info FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID WHERE p.Sex LIKE '%" + sex + "%'"));
    return curr_persons;
}

vector<person> personservice::matchByBirth(int year)
{
    curr_persons = data.getPersonsByQuery(QString::fromStdString("SELECT p.Name, p.Sex, p.Birth_Year, p.Death_Year, n.Nationality, p.Info FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID WHERE p.Birth_Year LIKE '%" + to_string(year) + "%'"));
    return curr_persons;
}

vector<person> personservice::matchByDeath(int year)
{
    curr_persons = data.getPersonsByQuery(QString::fromStdString("SELECT p.Name, p.Sex, p.Birth_Year, p.Death_Year, n.Nationality, p.Info FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID WHERE p.Death_Year LIKE '%" + to_string(year) + "%'"));
    return curr_persons;
}

vector<person> personservice::matchByNationality(string nationality)
{
    curr_persons = data.getPersonsByQuery(QString::fromStdString("SELECT p.Name, p.Sex, p.Birth_Year, p.Death_Year, n.Nationality, p.Info FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID WHERE n.Nationality LIKE '%" + nationality + "%'"));
    return curr_persons;
}

vector<computer> personservice::matchByCompName(string name)
{
    curr_computers = data.getComputersByQuery(QString::fromStdString("SELECT c.Name, c.Build_Year, c.Computer_Type, c.Built, n.Nationality, c.Info FROM Computers c JOIN Nationality n ON c.NationalityID = n.ID WHERE c.Name LIKE '%" + name + "%'"));
    return curr_computers;
}

vector<computer> personservice::matchByBuild(int build)
{
    curr_computers = data.getComputersByQuery(QString::fromStdString("SELECT c.Name, c.Build_Year, c.Computer_Type, c.Built, n.Nationality, c.Info FROM Computers c JOIN Nationality n ON c.NationalityID = n.ID WHERE c.Build_Year LIKE '%" + to_string(build) + "%'"));
    return curr_computers;
}

vector<computer> personservice::matchByType(string type)
{
    curr_computers = data.getComputersByQuery(QString::fromStdString("SELECT c.Name, c.Build_Year, c.Computer_Type, c.Built, n.Nationality, c.Info FROM Computers c JOIN Nationality n ON c.NationalityID = n.ID WHERE c.Computer_Type LIKE '%" + type + "%'"));
    return curr_computers;
}

vector<computer> personservice::matchByBuilt(string built)
{
    curr_computers = data.getComputersByQuery(QString::fromStdString("SELECT c.Name, c.Build_Year, c.Computer_Type, c.Built, n.Nationality, c.Info FROM Computers c JOIN Nationality n ON c.NationalityID = n.ID WHERE c.Built = '" + built + "'"));
    return curr_computers;
}

vector<computer> personservice::matchByCompNationality(string nationality)
{
    curr_computers = data.getComputersByQuery(QString::fromStdString("SELECT c.Name, c.Build_Year, c.Computer_Type, c.Built, n.Nationality, c.Info FROM Computers c JOIN Nationality n ON c.NationalityID = n.ID WHERE n.Nationality LIKE '%" + nationality + "%'"));
    return curr_computers;
}
