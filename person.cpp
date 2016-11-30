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
	lhs.setf(std::ios::left);

	lhs.width(15);
    lhs << "Name: " << rhs.getName() << std::endl;

	lhs.width(15);
    lhs << "-" << std::endl;

	lhs.width(15);
    lhs << "Sex: " << rhs.getSex() << std::endl;

	lhs.width(15);
    lhs << "Year of birth: " << rhs.getBirthYear() << std::endl;

	lhs.width(15);
    lhs << "Year of death: " << rhs.getDeathYear() << std::endl;

	lhs.width(15);
    lhs << "Nationality: " << rhs.getNationality() << std::endl;

	lhs.width(15);
    lhs << "Info: " << rhs.getInfo() << std::endl;

    return lhs;
}

bool operator==(const person lhs, const person rhs)
{
	if(lhs.m_name != rhs.m_name) return false;
	if(lhs.m_sex != rhs.m_sex) return false;
	if(lhs.m_birthyear != rhs.m_birthyear) return false;
	if(lhs.m_nationality != rhs.m_nationality) return false;
	if(lhs.m_info != rhs.m_info) return false;

	return true;
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
    return a.m_birthyear > b.m_birthyear;
}

int person::compareYearReverse(person a, person b)
{
    return a.m_birthyear < b.m_birthyear;
}

int person::compareDeath(person a, person b)
{
    return a.m_deathyear > b.m_deathyear;
}

int person::compareDeathReverse(person a, person b)
{
    return a.m_deathyear < b.m_deathyear;
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
