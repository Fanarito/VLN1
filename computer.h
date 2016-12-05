#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>


class computer
{
private:
    std::string c_name;
    std::string c_buildyear;
    std::string c_type;
    bool c_built;
    std::string c_info;
    std::string c_nationality;

public:
    computer();
    computer(std::string name, std::string buildyear, std::string type, bool built, std::string info, std::string nationality);

    std::string getName() const;
    void setName(std::string name);

    std::string getBuildYear() const;
    void setBuildYear(int buildyear);

    int getType() const;
    void setType(std::string type);

    int getInfo() const;
    void setInfo(std::string info);

    std::string getNationality() const;
    void setNationality(std::string nationality);

};

#endif // COMPUTER_H

