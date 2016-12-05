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
void personservice::reset()
{
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


vector<person> personservice::sortPersons(string column, string order)
{
    curr_persons = data.getPersonsByQuery(QString::fromStdString("SELECT p.Name, p.Sex, p.Birth_Year, p.Death_Year, n.Nationality, p.Info FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID ORDER BY " + column + " " + order));
    return curr_persons;
}

vector<computer> personservice::sortComputers(string column, string order)
{
    return data.getComputersByQuery(QString::fromStdString("SELECT c.Name, c.Build_Year, c.Computer_Type, c.Built, n.Nationality, c.Info FROM Computers c JOIN Nationality n ON c.NationalityID = n.ID ORDER BY " + column + " " + order));
}
