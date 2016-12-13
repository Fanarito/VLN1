#include "person.h"



person::person(QString name, QString sex, int birthyear,
               int deathyear, QString nationality, QString info, int id)
{
    m_id = id;
    m_name = name;
    m_sex = sex;
    m_birthyear = birthyear;
    m_deathyear = deathyear;
    m_nationality = nationality;
    m_info = info;
}


QString person::getSex() const
{
    return m_sex;
}

void person::setSex(QString sex)
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
