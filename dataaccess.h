#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "person.h"

static std::string FILENAME = "personsNew.txt";
static char DELIMITER = '|';

class dataaccess
{
public:
    dataaccess();

    static std::vector<person> read();
    static void save(std::vector<person> people);
};

#endif // DATAACCESS_H
