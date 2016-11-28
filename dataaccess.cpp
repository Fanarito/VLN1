#include "dataaccess.h"

dataaccess::dataaccess()
{

}

std::vector<std::string> split(const std::string &s, char delim) {
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> tokens;
    while (std::getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

/*
 * Reads the file and saves it to a vector
 */
void dataaccess::read() {
    std::fstream file(FILENAME);

    std::vector<std::string> p;
    std::string line;
    while(std::getline(file, line)) {
        p = split(line, DELIMITER);
        people.push_back(person(p[0], p[1], std::stoi(p[2]), std::stoi(p[3])));
    }
}

/*
 * Returns a pointer to the people vector
 */
std::vector<person> dataaccess::getPeople() {
    return *people;
}
