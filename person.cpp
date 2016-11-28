#include "person.h"

person::person()
{

}

std::string getName() {
    return m_name;
}
void setName(std::string name) {
    m_name = name;
}


std::string getSex() {
    return m_sex;
}
void setSex(std::string sex) {
    m_sex = sex;
}

int getBirthYear() {
    return m_birthyear;
}
void setBirthYear(int birthyear) {
    m_birthyear = birthyear;
}

int getDeathYear() {
    return m_deathyear;
}
void setDeathYear(int deathyear) {
    m_deathyear = deathyear;
}
