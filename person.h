#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "object.h"
#include "utils.h"
#include "constants.h"

using namespace constants;

class person: public Object
{
protected:
    std::string m_sex;
    int m_birthyear;
    int m_deathyear;
    //std::vector<uint> computer_ids;
public:
    person(std::string name="Undefined", std::string sex="Undefined", int birthyear=0,
           int deathyear=0, std::string nationality="Undefined", std::string info="", int id = 0);

    std::string getSex() const;
    void setSex(std::string sex);

    int getBirthYear() const;
    void setBirthYear(int year);

    int getDeathYear() const;
    void setDeathYear(int year);

    std::string getDetailedInformation();

    //std::vector<uint> getConnectedComputerIds();

    friend std::ostream& operator<<(std::ostream& lhs, const person rhs);
};

#endif // PERSON_H
