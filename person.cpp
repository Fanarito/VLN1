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
    std::stringstream info;

    int infowidth = 30;

    info << std::setw(infowidth) << "Name: "        << m_name << std::endl;
    info << std::setw(infowidth) << "Sex: "         << ((m_sex == "f")?("Female"):("Male")) << std::endl;
    info << std::setw(infowidth) << "Nationality: " << m_nationality << std::endl;
    info << std::setw(infowidth) << "Born: "        << m_birthyear << std::endl;
    if(m_deathyear != 0)
        info << std::setw(infowidth) << "Died: "    << m_deathyear << std::endl;
    info << std::setw(infowidth) << "Information:"  << utils::wordWrap(m_info, infowidth*2) << std::endl;

    return info.str();
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
    std::string death = std::to_string(rhs.getDeathYear());
    std::string sex = rhs.getSex();
    if(death == "0")
    {
        death = "Alive";
    }
    if(sex == "f")
    {
        sex = "Female";
    }
    else if(sex == "m")
    {
        sex = "Male";
    }

    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << rhs.getId();
    lhs << std::left << std::setw(nameWidth) << std::setfill(separator) << rhs.getName();
    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << sex;
    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << rhs.getBirthYear();
    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << death;
    lhs << std::left << std::setw(restWidth) << std::setfill(separator) << rhs.getNationality() << std::endl;

    return lhs;
}
