#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <iostream>
#include <iomanip>

#include "object.h"
#include "constants.h"

using namespace constants;

class computer: public Object
{
private:
    std::string m_type;
    bool m_built;
    int m_buildyear;

public:
    computer(std::string name="Undefined", int buildyear=0, std::string type="Undefined",
             bool built=false, std::string info="", std::string nationality="Undefined", int id=0);

    std::string getType() const;
    void setType(std::string type);

    bool getBuilt() const;
    void setBuilt(bool built);

    int getBuildYear() const;
    void setBuildYear(int year);

    friend std::ostream& operator<<(std::ostream& lhs, const computer rhs);
};

#endif // COMPUTER_H

