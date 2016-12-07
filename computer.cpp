#include "computer.h"


computer::computer(std::string name, int buildyear, std::string type,
                   bool built, std::string nationality, std::string info, int id)
{
    m_id = id;
    m_name = name;
    m_buildyear = buildyear;
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

int computer::getBuildYear() const
{
    return m_buildyear;
}
void computer::setBuildYear(int year)
{
    m_buildyear = year;
}

/*
 * Overloaded operator for printing out to console
 *
 */
std::ostream& operator<<(std::ostream& lhs, const computer rhs)
{
    std::string built;
    std::string buildYear = std::to_string(rhs.getBuildYear());
    if(buildYear == "0")
    {
        buildYear = "Not built";
    }
    if(rhs.getBuilt())
    {
        built = "True";
    }
    else
    {
        built = "False";
    }

    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << rhs.getId();
    lhs << std::left << std::setw(nameCompWidth) << std::setfill(separator) << rhs.getName();
    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << buildYear;
    lhs << std::left << std::setw(typeWidth) << std::setfill(separator) << rhs.getType();
    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << built;
    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << rhs.getNationality() << std::endl;

    return lhs;
}

