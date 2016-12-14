#include "service.h"

dataaccess service::data;

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

vector<QString> service::getNationalities()
{
    return data.getNationalities();
}

vector<QString> service::getComputerTypes()
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

int service::getNationalityById(QString nat)
{
    return data.getNationalityID(nat);
}

int service::getComputerTypeById(QString comp_type)
{
    return data.getComputer_TypeID(comp_type);
}

//Adds a person to a vector for later use
void service::addPerson(QString name, QString gender, int birthyear, int deathyear, QString nationality, QString info)
{
    data.addPerson(person(name,gender,birthyear,deathyear,nationality,info));
}

void service::addPerson(person p)
{
    data.addPerson(p);
}

void service::addComputer(QString name, int build_year, QString type, int built, QString nationality, QString info)
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

/*void service::removeNationality(QString nationality)
{
    data.removeNationality(nationality);
}

void service::removeComputerType(QString comp_type)
{
    data.removeComputerType(comp_type);
}*/

vector<person> service::searchPersons(vector<QString> args)
{
    return data.searchPersons(args);
}

vector<computer> service::searchComputers(vector<QString> args)
{
    return data.searchComputers(args);
}

std::vector<person> service::filterPersons(QString search_string)
{
    return data.filterPersons(search_string);
}

std::vector<computer> service::filterComputers(QString search_string)
{
    return data.filterComputers(search_string);
}


vector<person> service::sortPersons(QString column, QString order)
{
    if(column == "id")
    {
        column = "p.id";
    }

    return data.sortPersons(column, order);
}

vector<computer> service::sortComputers(QString column, QString order)
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

void service::addNationality(QString nationality)
{
    data.addNationality(nationality);
}

void service::addComputerType(QString comp_type)
{
    data.addComputerType(comp_type);
}

int service::getIdOfPerson(person p)
{
    int id = p.getId();

    return id;
}

int service::getIdOfComputer(computer c)
{
    int id = c.getId();

    return id;
}
