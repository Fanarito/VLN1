#include "person.h"

person::person(std::string name, std::string sex, int birthyear, int deathyear)
{
    m_name = name;
    m_sex = sex;
    m_birthyear = birthyear;
    m_deathyear = deathyear;
}

std::string person::getName() {
    return m_name;
}
void person::setName(std::string name) {
    m_name = name;
}


std::string person::getSex() {
    return m_sex;
}
void person::setSex(std::string sex) {
    m_sex = sex;
}

int person::getBirthYear() {
    return m_birthyear;
}
void person::setBirthYear(int birthyear) {
    m_birthyear = birthyear;
}

int person::getDeathYear() {
    return m_deathyear;
}
void person::setDeathYear(int deathyear) {
    m_deathyear = deathyear;
}
