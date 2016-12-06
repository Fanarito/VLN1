#include "person.h"
#include <iostream>

person::person(std::string name, std::string sex, int birthyear,
               int deathyear, std::string nationality, std::string info)
{
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

/*
 * Overloaded operator for printing out to console
 *
 */
std::ostream& operator<<(std::ostream& lhs, const person rhs)
{
    const int nameWidth = 25;
    const int restWidth = 15;
    const char separator = ' ';

    lhs << std::left << std::setw(nameWidth) << std::setfill(separator) << rhs.getName();
    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << rhs.getSex();
    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << rhs.getBirthYear();
    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << rhs.getDeathYear();
    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << rhs.getNationality() << std::endl;

    return lhs;
}

//Overloaded operator to compare person with another person. Returns true if they are the same.
bool operator==(const person lhs, const person rhs)
{
    if(lhs.m_id != rhs.m_id) return false;
    if(lhs.m_name != rhs.m_name) return false;
    if(lhs.m_sex != rhs.m_sex) return false;
    if(lhs.m_birthyear != rhs.m_birthyear) return false;
    if(lhs.m_nationality != rhs.m_nationality) return false;
    if(lhs.m_info != rhs.m_info) return false;

    return true;
}
