#include "person.h"



person::person(std::string name, std::string sex, int birthyear,
               int deathyear, std::string nationality, std::string info, int id)
{
    m_id = id;
    m_name = name;
    m_sex = sex;
    m_birthyear = birthyear;
    m_deathyear = deathyear;
    m_nationality = nationality;
    m_info = info;
}


std::string person::getSex() const
{
    return m_sex;
}

void person::setSex(std::string sex)
{
    m_sex = sex;
}

int person::getBirthYear() const
{
    return m_birthyear;
}
void person::setBirthYear(int year)
{
    m_birthyear = year;
}

int person::getDeathYear() const
{
    return m_deathyear;
}

void person::setDeathYear(int year)
{
    m_deathyear = year;
}

std::string person::getDetailedInformation()
{
    return "";
}

/*
 * Overloaded operator for printing out to console
 *
 */
