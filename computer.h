#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <iostream>
#include <iomanip>

#include <QString>

#include "object.h"
#include "constants.h"

using namespace constants;

class computer: public Object
{
private:
    QString m_type;
    bool m_built;
    int m_buildyear;

public:
    computer(QString name="Undefined", int buildyear=0, QString type="Undefined",
             bool built=false, QString info="", QString nationality="Undefined", int id=0);

    QString getType() const;
    void setType(QString type);

    bool getBuilt() const;
    void setBuilt(bool built);

    int getBuildYear() const;
    void setBuildYear(int year);
};

#endif // COMPUTER_H

