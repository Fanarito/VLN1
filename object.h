#ifndef OBJECT_H
#define OBJECT_H

#include <QString>

#include <string>
#include <iostream>

class Object
{
protected:
    int m_id;
    QString m_name;
    QString m_nationality;
    QString m_info;
public:
    Object(int id = 0, QString name="Undefined", QString nationality="Undefined", QString info="");

    unsigned int getId() const;

    QString getName() const;
    void setName(QString name);

    QString getNationality() const;
    void setNationality(QString nationality);

    QString getInfo() const;
    void setInfo(QString info);
};

#endif // OBJECT_H
