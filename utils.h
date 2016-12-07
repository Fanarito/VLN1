#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <sstream>

namespace utils {

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

    std::string removeWhiteSpace(std::string str)
    {
        auto first = str.find_first_not_of(" \t");

        if(first == std::string::npos) return "";

        auto last = str.find_last_not_of(" \t");
        auto range = last - first + 1;

        return str.substr(first,range);
    }

    std::string wordWrap(std::string str, int width)
    {
        int count_since_last_newline = 0;
        int last_space_index = 0;

        for (size_t i = 0; i < str.length(); i++)
        {
            count_since_last_newline++;
            if (str.at(i) == ' ')
                last_space_index = i;
            if (count_since_last_newline >= width)
            {
                str.insert(last_space_index + 1, "\n");
                count_since_last_newline = 0;
            }
        }

        return str;
    }
}

#endif
