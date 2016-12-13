#include "object.h"

Object::Object(int id, QString name, QString nationality, QString info)
{
    m_id = id;
    m_name = name;
    m_nationality = nationality;
    m_info = info;
}

unsigned int Object::getId() const
{
    return m_id;
}

QString Object::getName() const
{
    return m_name;
}

void Object::setName(QString name)
{
    m_name = name;
}

QString Object::getNationality() const
{
    return m_nationality;
}

void Object::setNationality(QString nationality)
{
    m_nationality = nationality;
}

QString Object::getInfo() const
{
    return m_info;
}

void Object::setInfo(QString info)
{
    m_info = info;
}
