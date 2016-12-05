#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <iostream>

class Object
{
protected:
    uint m_id;
    std::string m_name;
    std::string m_nationality;
    std::string m_info;
public:
    Object(std::string name="Undefined", std::string nationality="Undefined", std::string info="");

    uint getId() const;

    std::string getName() const;
    void setName(std::string name);

    std::string getNationality() const;
    void setNationality(std::string nationality);

    std::string getInfo() const;
    void setInfo(std::string info);

    friend std::ostream& operator<<(std::ostream& lhs, const Object rhs);
    friend bool operator==(const Object lsh, const Object rhs);
};

#endif // OBJECT_H
