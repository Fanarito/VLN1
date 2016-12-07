#include "object.h"

Object::Object(int id, std::string name, std::string nationality, std::string info)
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

std::string Object::getName() const
{
    return m_name;
}

void Object::setName(std::string name)
{
    m_name = name;
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
