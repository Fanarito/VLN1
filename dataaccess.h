#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <QtSql>

#include "person.h"
#include "computer.h"

static std::string DATABASE = "FamousProgrammers";
static char DELIMITER = '|';


class dataaccess
{
private:
    QSqlDatabase db;
public:
    dataaccess();

    std::vector<person> getPersonsByQuery(QString q);
    std::vector<computer> getComputersByQuery(QString q);
    void addPerson(person p);
    void removePerson(person p);
};

#endif // DATAACCESS_H
