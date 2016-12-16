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
int service::addPerson(QString name, QString gender, int birthyear, int deathyear, bool alive, QString nationality, QString info)
{
    return data.addPerson(person(name,gender,birthyear,deathyear,alive,nationality,info));
}

void service::addPerson(person p)
{
    data.addPerson(p);
}

void service::changePerson(person p)
{
    data.changePerson(p);
}

void service::changeComputer(computer c)
{
    data.changeComputer(c);
}

int service::addComputer(QString name, int build_year, QString type, int built, QString nationality, QString info)
{
    return data.addComputer(computer(name, build_year, type, built, nationality, info));
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
    data.getComputerById(cid, success);

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

// Returns false if the connection was not added, for instance if the connections is already present
bool service::addConnection(int comp_id, int person_id)
{
    bool noerr;
    vector<person> persons = getPersonsConnectedWithComputer(getComputerById(comp_id,noerr));

    if(!noerr) return false;

    for(person p : persons)
    {
        if(p.getId() == person_id)
        {
            return false;
        }
    }

    data.addConnection(comp_id, person_id);
    return true;
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
