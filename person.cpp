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

std::string person::getSex() const
{
    return m_sex;
}

void person::setSex(std::string sex)
{
    m_sex = sex;
}

/*
 * Overloaded operator for printing out to console
 *
 */
std::ostream& operator<<(std::ostream& lhs, const person rhs)
{
	lhs.setf(std::ios::left);

    int stdwidth = 15;

    lhs.width(stdwidth);
    lhs << "Name: " << rhs.getName() << std::endl;

    lhs.width(stdwidth);
    lhs << "-" << std::endl;

    lhs.width(stdwidth);
    lhs << "Sex: " << rhs.getSex() << std::endl;

    lhs.width(stdwidth);
    lhs << "Year of birth: " << rhs.getBirthYear() << std::endl;

    lhs.width(stdwidth);
    lhs << "Year of death: " << rhs.getDeathYear() << std::endl;

    lhs.width(stdwidth);
    lhs << "Nationality: " << rhs.getNationality() << std::endl;

    lhs.width(stdwidth);
    lhs << "Info: " << rhs.getInfo() << std::endl;

    return lhs;
}

//Overloaded operator to compare person with another person. Returns true if they are the same.
bool operator==(const person lhs, const person rhs)
{
	if(lhs.m_name != rhs.m_name) return false;
	if(lhs.m_sex != rhs.m_sex) return false;
	if(lhs.m_birthyear != rhs.m_birthyear) return false;
	if(lhs.m_nationality != rhs.m_nationality) return false;
	if(lhs.m_info != rhs.m_info) return false;

	return true;
}

int person::compareGender(person a, person b)
{
    return a.m_sex > b.m_sex;
}

int person::compareGenderReverse(person a, person b)
{
    return a.m_sex < b.m_sex;
}
