#ifndef PERSON_H
#define PERSON_H


#include <string>
#include <iostream>
#include <iomanip>

#include "object.h"

class person: public Object
{
protected:
    std::string m_sex;
    int m_birthyear;
    int m_deathyear;
public:
    person();
    person(std::string name, std::string sex, int birthyear,
           int deathyear, std::string nationality, std::string info);

    std::string getSex() const;
    void setSex(std::string sex);

    int getBirthYear() const;
    void setBirthYear(int year);

    int getDeathYear() const;
    void setDeathYear(int year);

    friend std::ostream& operator<<(std::ostream& lhs, const person rhs);

    friend bool operator==(const person lhs, const person rhs);
};

#endif // PERSON_H
