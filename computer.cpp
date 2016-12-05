#include "computer.h"


computer::computer(std::string name, int buildyear, std::string type, bool built, std::string info, std::string nationality)
{
    m_name = name;
    m_birthyear = buildyear;
    m_type = type;
    m_info = info;
    m_nationality = nationality;
    m_built = built;
}

std::string computer::getType() const
{
    return m_type;
}
void computer::setType(std::string type)
{
    m_type = type;
}

bool computer::getBuilt() const
{
    return m_built;
}
void computer::setBuilt(bool built)
{
    m_built = built;
}

/*
 * Overloaded operator for printing out to console
 *
 */
std::ostream& operator<<(std::ostream& lhs, const computer rhs)
{
	lhs.setf(std::ios::left);

    int stdwidth = 15;

    lhs.width(stdwidth);
    lhs << "Name: " << rhs.getName() << std::endl;

    lhs.width(stdwidth);
    lhs << "-" << std::endl;

    lhs.width(stdwidth);
    lhs << "Built: " << rhs.getBuilt() << std::endl;

    lhs.width(stdwidth);
    lhs << "Type: " << rhs.getType() << std::endl;

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

//Overloaded operator to compare computer with another computer. Returns true if they are the same.
bool operator==(const computer lhs, const computer rhs)
{
	if(lhs.m_name != rhs.m_name) return false;
	if(lhs.m_birthyear != rhs.m_birthyear) return false;
	if(lhs.m_nationality != rhs.m_nationality) return false;
	if(lhs.m_info != rhs.m_info) return false;
  if(lhs.m_type != rhs.m_type) return false;
  if(lhs.m_built != rhs.m_built) return false;

	return true;
}

