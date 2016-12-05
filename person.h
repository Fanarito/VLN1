#ifndef PERSON_H
#define PERSON_H


#include <string>
#include <iostream>

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

    friend std::ostream& operator<<(std::ostream& lhs, const person rhs);

    friend bool operator==(const person lhs, const person rhs);

    static int compareGender(person a, person b);
    static int compareGenderReverse(person a, person b);
    static int compareYear(person a, person b);
    static int compareYearReverse(person a, person b);
    static int compareDeath(person a, person b);
    static int compareDeathReverse(person a, person b);
};

#endif // PERSON_H
