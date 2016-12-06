#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <QtSql>

#include "person.h"
#include "computer.h"

static std::string DATABASE = "CompSci.sqlite";

class dataaccess
{
private:
    QSqlDatabase db;
public:
    dataaccess();

    std::vector<person> getPersonsByQuery(QString q);
    std::vector<computer> getComputersByQuery(QString q);

    person getPersonById(unsigned int id);
    computer getComputerById(unsigned int id);

    std::vector<person> searchPersons(std::vector<std::string> args);
    std::vector<computer> searchComputers(std::vector<std::string> args);

    std::vector<person> execQueryPerson(QSqlQuery query);
    std::vector<computer> execQueryComputer(QSqlQuery query);

    int getNationalityID(std::string nationality);

    void addPerson(person p);
    void removePerson(int id);

    void addComputer(computer p);

};

#endif // DATAACCESS_H
