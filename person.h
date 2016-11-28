#ifndef PERSON_H
#define PERSON_H

#include <string>

class person
{
private:
    std::string m_name;
    std::string m_sex;
    int m_birthyear;
    int m_deathyear;
public:
    person(std::string name, std::string sex, int birthyear, int deathyear);

    std::string getName();
    void setName(std::string name);

    std::string getSex();
    void setSex(std::string sex);

    int getBirthYear();
    void setBirthYear(int birthyear);

    int getDeathYear();
    void setDeathYear(int deathyear);
};

#endif // PERSON_H
