#include "object.h"

Object::Object(std::string name, int birthyear, int deathyear, std::string nationality, std::string info)
{
    m_name = name;
    m_birthyear = birthyear;
    m_deathyear = deathyear;
    m_nationality = nationality;
    m_info = info;
}

uint Object::getId() const
{
    return m_id;
}

std::string Object::getName() const
{
    return m_name;
}

void Object::setName(std::string name)
{
    m_name = name;
}

int Object::getBirthYear() const
{
    return m_birthyear;
}
void Object::setBirthYear(int birthyear)
{
    m_birthyear = birthyear;
}

int Object::getDeathYear() const
{
    return m_deathyear;
}

void Object::setDeathYear(int deathyear)
{
    m_deathyear = deathyear;
}

std::string Object::getNationality() const
{
    return m_nationality;
}

void Object::setNationality(std::string nationality)
{
    m_nationality = nationality;
}

std::string Object::getInfo() const
{
    return m_info;
}

void Object::setInfo(std::string info)
{
    m_info = info;
}

/*
 * Overloaded operator for printing out to console
 *
 */
std::ostream& operator<<(std::ostream& lhs, const Object rhs)
{
    lhs.setf(std::ios::left);

    int stdwidth = 15;

    lhs.width(stdwidth);
    lhs << "Name: " << rhs.getName() << std::endl;

    lhs.width(stdwidth);
    lhs << "-" << std::endl;

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

//Overloaded operator to compare Object with another Object. Returns true if they are the same.
bool operator==(const Object lhs, const Object rhs)
{
	if(lhs.m_name != rhs.m_name) return false;
	if(lhs.m_birthyear != rhs.m_birthyear) return false;
  if(lhs.m_deathyear != rhs.m_birthyear) return false;
	if(lhs.m_nationality != rhs.m_nationality) return false;
	if(lhs.m_info != rhs.m_info) return false;

	return true;
}

int Object::compareName(Object a, Object b)
{
    return a.m_name < b.m_name;
}
int Object::compareNameReverse(Object a, Object b)
{
    return a.m_name > b.m_name;
}

int Object::compareYear(Object a, Object b)
{
    return a.m_birthyear > b.m_birthyear;
}

int Object::compareYearReverse(Object a, Object b)
{
    return a.m_birthyear < b.m_birthyear;
}

int Object::compareDeath(Object a, Object b)
{
    return a.m_deathyear > b.m_deathyear;
}

int Object::compareDeathReverse(Object a, Object b)
{
    return a.m_deathyear < b.m_deathyear;
}

int Object::compareNationality(Object a, Object b)
{
    return a.m_nationality < b.m_nationality;
}

int Object::compareNationalityReverse(Object a, Object b)
{
    return a.m_nationality > b.m_nationality;
}

