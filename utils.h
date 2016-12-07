// Splits a string into a vector of strings with a specified delimiter.
// Example: split this string becomes [split, this, string]

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

}
