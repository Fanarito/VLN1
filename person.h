#ifndef PERSON_H
#define PERSON_H


#include <string>
#include <iostream>
#include <iomanip>

#include <QString>

#include "object.h"
#include "utils.h"
#include "constants.h"

using namespace constants;

class person: public Object
{
protected:
    QString m_sex;
    int m_birthyear;
    int m_deathyear;
public:
    person(QString name="Undefined", QString sex="Undefined", int birthyear=0,
           int deathyear=0, QString nationality="Undefined", QString info="", int id = 0);

    QString getSex() const;
    void setSex(QString sex);

    int getBirthYear() const;
    void setBirthYear(int year);

    int getDeathYear() const;
    void setDeathYear(int year);
};

#endif // PERSON_H
