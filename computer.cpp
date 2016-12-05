#include "computer.h"


computer::computer(std::string name, std::string buildyear, std::string type, bool built, std::string info, std::string nationality)
{
    c_name = name;
    c_buildyear = buildyear;
    c_type = type;
    c_info = info;
    c_nationality = nationality;

}

std::string computer::getName() const
{
    return c_name;
}

void computer::setName(std::string name)
{
    c_name = name;
}

int computer::getBuildYear() const
{
    return c_buildyear;
}

void computer::setBuildYear(int buildyear)
{
    c_buildyear = buildyear;
}

std::string computer::getType() const
{
    return c_type;
}
void computer::setType(std::string type)
{
    c_type = type;
}

std::string computer::getInfo() const
{
    return c_info;
}

void computer::setInfo(std::string info)
{
    c_info = info;
}

std::string person::getNationality() const
{
    return c_nationality;
}

void person::setNationality(std::string nationality)
{
    c_nationality = nationality;
}
