#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "person.h"

static std::string FILENAME = "../VNL1/personsNew.txt";
static char DELIMITER = '|';

class dataaccess
{
private:
    std::vector<person> people;
public:
    dataaccess();
    void read();
    std::vector<person> *getPeople();
};

#endif // DATAACCESS_H
