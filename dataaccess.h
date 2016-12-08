#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <QtSql>

#include <string>
#include <vector>

#include <sstream>
#include <iostream>

#include "person.h"
#include "computer.h"

#include "constants.h"

using namespace constants;


class dataaccess
{
private:
    QSqlDatabase db;
public:
    dataaccess();
    ~dataaccess();

    std::vector<person> getPersons();
    std::vector<computer> getComputers();

    std::vector<person> getPersonsByQuery(QString q);
    std::vector<computer> getComputersByQuery(QString q);

    person getPersonById(unsigned int id, bool &success);
    computer getComputerById(unsigned int id, bool &success);

    std::vector<person> getPersonsByComputerId(unsigned int id, bool &success);
    std::vector<computer> getComputersByPersonId(unsigned int id, bool &success);

    std::vector<person> searchPersons(std::vector<std::string> args);
    std::vector<computer> searchComputers(std::vector<std::string> args);

    std::vector<person> sortPersons(std::string column, std::string order);
    std::vector<computer> sortComputers(std::string column, std::string order);

    std::vector<person> execQueryPerson(QSqlQuery query);
    std::vector<computer> execQueryComputer(QSqlQuery query);

    int getNationalityID(std::string nationality);
    int getComputer_TypeID(std::string computer_type);

    void addPerson(person p);
    void removePerson(int id);

    void addComputer(computer p);
    void removeComputer(int id);

    void addConnection(int comp_id, int person_id);
    void removeConnection(int pid, int cid);

    void addNationality(std::string nationality);

    void addComputerType(std::string comp_type);

    void updatePerson(person p);
    void updateComputer(computer c);

};

#endif // DATAACCESS_H
