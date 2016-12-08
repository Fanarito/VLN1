#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace constants {
    const std::string VALID_TABLE_NAMES = "persons|computers|connections";
    const std::string VALID_ADD_COMMANDS = "persons|computers|connections|nationalities|computer_types";

    const std::string VALID_PERSON_COLUMNS = "id|name|sex|birth_year|death_year|nationality";
    const std::string VALID_COMPUTER_COLUMNS = "id|name|build_year|computer_type|built|nationality";
    const std::string VALID_CONNECTIONS_COLUMNS = "computersid|personsid";

    const std::string VALID_COMMANDS = "list|add|change|remove|sort|search|info|clear|quit";
    const std::string VALID_SORT_COMMANDS = "asc|desc";

    const std::string INPUT_ENDER = "end;";

    const std::string NO_MESS = "\0";
    const std::string NO_EXP = "\0";

    const int AL_KHWARIZMI = 780; //WAS PYTHAGORAS

    const bool MULTI = true;
    const bool SINGLE = false;

    const int nameWidth = 30;
    const int typeWidth = 20;
    const int restWidth = 15;
    const int pageWidth = 60;

    const int combinedWidth = nameWidth + restWidth * 4 + typeWidth;

    const char separator = ' ';

    static std::string DATABASE = "CompSci.sqlite";
}

#endif // CONSTANTS_H
