#ifndef PERSON_H
#define PERSON_H


#include <string>
#include <iostream>

#include "object.h"

class person: public Object
{
protected:
    std::string m_sex;

public:
    person();
    person(std::string name, std::string sex, int birthyear, int deathyear, std::string nationality, std::string info);

    std::string getSex() const;
    void setSex(std::string sex);

    friend std::ostream& operator<<(std::ostream& lhs, const person rhs);
    friend bool operator==(const person lsh, const person rhs);

    static int compareGender(person a, person b);
    static int compareGenderReverse(person a, person b);
};

#endif // PERSON_H
