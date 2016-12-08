#ifndef UTILS_H
#define UTILS_H

// Splits a string into a vector of strings with a specified delimiter.
// Example: split this string becomes [split, this, string]

#include <vector>
#include <sstream>
#include <time.h>

namespace utils
{
    std::vector<std::string> split(const std::string &s, char delim);
    std::string removeWhiteSpace(std::string str);
    std::string wordWrap(std::string str, int width);
    int getCurrentYear();
    bool isStrInt(std::string str);
}

#endif //UTILS_H
