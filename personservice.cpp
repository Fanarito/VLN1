#include "personservice.h"

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

vector<std::string> personservice::getNationalities()
{
    return data.getNationalities();
}

vector<std::string> personservice::getComputerTypes()
{
    return data.getComputerTypes();
}


vector<person> personservice::getPersonsConnectedWithComputer(computer c)
{
    bool temp;
    return data.getPersonsByComputerId(c.getId(), temp);
}

vector<computer> personservice::getComputersConnectedWithPerson(person p)
{
    bool temp;
    return data.getComputersByPersonId(p.getId(), temp);
}


person personservice::getPersonById(unsigned int id, bool &success)
{
    return data.getPersonById(id, success);
}

computer personservice::getComputerById(unsigned int id, bool &success)
{
    return data.getComputerById(id, success);
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

void personservice::removeConnection(int pid, int cid)
{
    data.removeConnection(pid, cid);
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

    return data.sortPersons(column, order);
}

vector<computer> personservice::sortComputers(string column, string order)
{
    if(column == "id")
    {
        column = "c.id";
    }

    return data.sortComputers(column, order);
}

void personservice::updatePerson(person p)
{
    data.updatePerson(p);
}

void personservice::updateComputer(computer c)
{
    data.updateComputer(c);
}

void personservice::addConnection(int comp_id, int person_id)
{
    data.addConnection(comp_id, person_id);
}

void personservice::addNationality(std::string nationality)
{
    data.addNationality(nationality);
}

void personservice::addComputerType(std::string comp_type)
{
    data.addComputerType(comp_type);
}
