#include "service.h"

service::service()
{

}

vector<person> service::getPersons()
{
    return data.getPersons();
}

vector<computer> service::getComputers()
{
    return data.getComputers();
}

vector<std::string> service::getNationalities()
{
    return data.getNationalities();
}

vector<std::string> service::getComputerTypes()
{
    return data.getComputerTypes();
}


vector<person> service::getPersonsConnectedWithComputer(computer c)
{
    bool temp;
    return data.getPersonsByComputerId(c.getId(), temp);
}

vector<computer> service::getComputersConnectedWithPerson(person p)
{
    bool temp;
    return data.getComputersByPersonId(p.getId(), temp);
}


person service::getPersonById(unsigned int id, bool &success)
{
    return data.getPersonById(id, success);
}

computer service::getComputerById(unsigned int id, bool &success)
{
    return data.getComputerById(id, success);
}

int service::getNationalityById(std::string nat)
{
    return data.getNationalityID(nat);
}

int service::getComputerTypeById(std::string comp_type)
{
    return data.getComputer_TypeID(comp_type);
}

//Adds a person to a vector for later use
void service::addPerson(std::string name, std::string gender, int birthyear, int deathyear, std::string nationality, std::string info)
{
    data.addPerson(person(name,gender,birthyear,deathyear,nationality,info));
}

void service::addPerson(person p)
{
    data.addPerson(p);
}

void service::addComputer(std::string name, int build_year, std::string type, int built, std::string nationality, std::string info)
{
    data.addComputer(computer(name, build_year, type, built, nationality, info));
}

void service::removePerson(int id)
{
    data.removePerson(id);
}

void service::removeComputer(int id)
{
    data.removeComputer(id);
}

void service::removeConnection(int pid, int cid, bool &success)
{
    data.getPersonById(pid, success);
    data.getComputerById(pid, success);

    if(!success) return;

    data.removeConnection(pid, cid);
}

void service::removeNationality(std::string nationality)
{
    data.removeNationality(nationality);
}

void service::removeComputerType(std::string comp_type)
{
    data.removeComputerType(comp_type);
}

vector<person> service::searchPersons(vector<string> args)
{
    return data.searchPersons(args);
}

vector<computer> service::searchComputers(vector<string> args)
{
    return data.searchComputers(args);
}

vector<person> service::sortPersons(string column, string order)
{
    if(column == "id")
    {
        column = "p.id";
    }

    return data.sortPersons(column, order);
}

vector<computer> service::sortComputers(string column, string order)
{
    if(column == "id")
    {
        column = "c.id";
    }

    return data.sortComputers(column, order);
}

void service::updatePerson(person p)
{
    data.updatePerson(p);
}

void service::updateComputer(computer c)
{
    data.updateComputer(c);
}

void service::addConnection(int comp_id, int person_id)
{
    data.addConnection(comp_id, person_id);
}

void service::addNationality(std::string nationality)
{
    data.addNationality(nationality);
}

void service::addComputerType(std::string comp_type)
{
    data.addComputerType(comp_type);
}
