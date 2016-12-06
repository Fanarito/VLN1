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

}