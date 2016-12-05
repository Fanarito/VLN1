#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <QtSql>

#include "person.h"

static std::string FILENAME = "personsNew.txt";
static char DELIMITER = '|';


class dataaccess
{
private:
    QSqlDatabase db;
public:
    dataaccess();

    std::vector<person> getPersonsByQuery(std::string q);
};

#endif // DATAACCESS_H
