#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <iostream>

class Object
{
private:
    std::string m_name;
    int m_birthyear;
    int m_deathyear;
    std::string m_nationality;
    std::string m_info;
public:
    Object(std::string name="Undefined", int birthyear=0, int deathyear=0,
           std::string nationality="Undefined", std::string info="");

    std::string getName() const;
    void setName(std::string name);

    int getBirthYear() const;
    void setBirthYear(int birthyear);

    int getDeathYear() const;
    void setDeathYear(int deathyear);

    std::string getNationality() const;
    void setNationality(std::string nationality);

    std::string getInfo() const;
    void setInfo(std::string info);

    friend std::ostream& operator<<(std::ostream& lhs, const Object rhs);
    friend bool operator==(const Object lsh, const Object rhs);

    static int compareName(Object a, Object b);
    static int compareNameReverse(Object a, Object b);
    static int compareYear(Object a, Object b);
    static int compareYearReverse(Object a, Object b);
    static int compareDeath(Object a, Object b);
    static int compareDeathReverse(Object a, Object b);
    static int compareNationality(Object a, Object b);
    static int compareNationalityReverse(Object a, Object b);
};

#endif // OBJECT_H
