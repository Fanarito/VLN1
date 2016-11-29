#include "person.h"
#include <iostream>

person::person(std::string name, std::string sex, int birthyear, int deathyear, std::string nationality, std::string info)
{
    m_name = name;
    m_sex = sex;
    m_birthyear = birthyear;
    m_deathyear = deathyear;
    m_nationality = nationality;
    m_info = info;
}

std::string person::getName() const
{
    return m_name;
}

void person::setName(std::string name)
{
    m_name = name;
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
void person::setBirthYear(int birthyear)
{
    m_birthyear = birthyear;
}

int person::getDeathYear() const
{
    return m_deathyear;
}

void person::setDeathYear(int deathyear)
{
    m_deathyear = deathyear;
}

std::string person::getNationality() const
{
    return m_nationality;
}

void person::setNationality(std::string nationality)
{
    m_nationality = nationality;
}

std::string person::getInfo() const
{
    return m_info;
}

void person::setInfo(std::string info)
{
    m_info = info;
}

/*
 * Overloaded operator for printing out to console
 *
 */
std::ostream& operator<<(std::ostream& lhs, const person rhs)
{
    lhs << "Name: " << rhs.getName() << std::endl;
    lhs << "-" << std::endl;
    lhs << "Sex: " << rhs.getSex() << std::endl;
    lhs << "Year of birth: " << rhs.getBirthYear() << std::endl;
    lhs << "Year of death: " << rhs.getDeathYear() << std::endl;
    lhs << "Nationality: " << rhs.getNationality() << std::endl;
    lhs << "Info: " << rhs.getInfo() << std::endl;

    return lhs;
}

int person::compareName(person a, person b)
{
    return a.m_name < b.m_name;
}
int person::compareNameReverse(person a, person b)
{
    return a.m_name > b.m_name;
}

int person::compareYear(person a, person b)
{
    return a.m_birthyear < b.m_birthyear;
}

int person::compareYearReverse(person a, person b)
{
    return a.m_birthyear > b.m_birthyear;
}

int person::compareDeath(person a, person b)
{
    return a.m_deathyear < b.m_deathyear;
}

int person::compareDeathReverse(person a, person b)
{
    return a.m_deathyear > b.m_deathyear;
}

int person::compareGender(person a, person b)
{
    return a.m_sex > b.m_sex;
}

int person::compareGenderReverse(person a, person b)
{
    return a.m_sex < b.m_sex;
}

int person::compareNationality(person a, person b)
{
    return a.m_nationality < b.m_nationality;
}

int person::compareNationalityReverse(person a, person b)
{
    return a.m_nationality > b.m_nationality;
}
