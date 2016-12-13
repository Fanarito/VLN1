#include "computer.h"

computer::computer(QString name, int buildyear, QString type,
                   bool built, QString nationality, QString info, int id)
{
    m_id = id;
    m_name = name;
    m_buildyear = buildyear;
    m_type = type;
    m_info = info;
    m_nationality = nationality;
    m_built = built;
}

QString computer::getType() const
{
    return m_type;
}
void computer::setType(QString type)
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

