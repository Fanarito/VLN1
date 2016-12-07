#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <QtSql>

#include <string>
#include <vector>

#include <sstream>
#include <iostream>

#include "person.h"
#include "computer.h"

static std::string DATABASE = "CompSci.sqlite";

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

    void addPerson(person p);
    void removePerson(int id);

    void addComputer(computer p);
    void removeComputer(int id);

    void addConnection(int comp_id, int person_id);

    void updatePerson(person p);
    void updateComputer(computer c);

};

#endif // DATAACCESS_H
