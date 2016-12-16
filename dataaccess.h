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
    std::vector<QString> getNationalities();
    std::vector<QString> getComputerTypes();

    std::vector<person> getPersonsByQuery(QString q);
    std::vector<computer> getComputersByQuery(QString q);

    person getPersonById(unsigned int id, bool &success);
    computer getComputerById(unsigned int id, bool &success);

    std::vector<person> getPersonsByComputerId(unsigned int id, bool &success);
    std::vector<computer> getComputersByPersonId(unsigned int id, bool &success);

    std::vector<person> searchPersons(std::vector<QString> args);
    std::vector<computer> searchComputers(std::vector<QString> args);

    std::vector<person> filterPersons(QString search_string);
    std::vector<computer> filterComputers(QString search_string);

    std::vector<person> sortPersons(QString column, QString order);
    std::vector<computer> sortComputers(QString column, QString order);

    std::vector<person> execQueryPerson(QSqlQuery query);
    std::vector<computer> execQueryComputer(QSqlQuery query);
    std::vector<QString> execQueryNat(QSqlQuery query);
    std::vector<QString> execQueryComp(QSqlQuery query);

    int getNationalityID(QString nationality);
    int getComputer_TypeID(QString computer_type);

    int addPerson(person p);
    void removePerson(int id);

    void changePerson(person p);
    void changeComputer(computer c);

    int addComputer(computer p);
    void removeComputer(int id);

    void addConnection(int comp_id, int person_id);
    void removeConnection(int pid, int cid);

    void addNationality(QString nationality);

    void addComputerType(QString comp_type);

    void updatePerson(person p);
    void updateComputer(computer c);

};

#endif // DATAACCESS_H
