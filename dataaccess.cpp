#include "dataaccess.h"
#include <iostream>

dataaccess::dataaccess()
{

}

std::vector<std::string> split(const std::string &s, char delim)
{

    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> tokens;

    while (std::getline(ss, item, delim))
    {
        tokens.push_back(item);
    }

    return tokens;
}

/*
 * Reads the file and saves it to a vector
 */
std::vector<person> dataaccess::read()
{
    std::fstream file(FILENAME);

    std::vector<person> people;

    std::vector<std::string> p;
    std::string line;
    while(std::getline(file, line))
    {
        p = split(line, DELIMITER);
        people.push_back(person(p[0], p[1], std::stoi(p[2]), std::stoi(p[3]), p[4], p[5]));
    }

    return people;
}

/*
 * Saves the vector to a file
 */
void dataaccess::save(std::vector<person> people)
{
    std::ofstream file(FILENAME);

    std::string line;

    for (size_t i = 0; i < people.size(); i++)
    {
        line = people[i].getName() + DELIMITER + people[i].getSex() + DELIMITER + std::to_string(people[i].getBirthYear()) + DELIMITER + std::to_string(people[i].getDeathYear()) + DELIMITER + people[i].getNationality() + DELIMITER + people[i].getInfo();
        file << line << std::endl;
    }
}
