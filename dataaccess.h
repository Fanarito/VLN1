#ifndef DATAACCESS_H
#define DATAACCESS_H

#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "person.h"

//static std::string FILENAME = "../VNL1/personsNew.txt";
static std::string FILENAME = "personsNew.txt";
static char DELIMITER = '|';

class dataaccess
{
private:
    //std::vector<person> people;
public:
    dataaccess();

    std::vector<person> read();
    void save(std::vector<person> people);
    //std::vector<person> *getPeople();
};

#endif // DATAACCESS_H
