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
    person();
    person(std::string name, std::string sex, int birthyear, int deathyear);

    std::string getName() const;
    void setName(std::string name);

    std::string getSex() const;
    void setSex(std::string sex);

    int getBirthYear() const;
    void setBirthYear(int birthyear);

    int getDeathYear() const;
    void setDeathYear(int deathyear);

    static int compareName(person a, person b);
    static int compareNameReverse(person a, person b);
    static int compareYear(person a, person b);
    static int compareYearReverse(person a, person b);
    static int compareDeath(person a, person b);
    static int compareDeathReverse(person a, person b);
    static int compareGender(person a, person b);
    static int compareGenderReverse(person a, person b);

};

#endif // PERSON_H
