#include "consoleui.h"
#include "utils.h"

using namespace std;

template<typename T> bool expect(T input, const vector<T> valid_input)
{
    auto result = find(valid_input.begin(), valid_input.end(), input);
    return result != valid_input.end();
}

consoleui::consoleui()
{

}

//This function keeps the program running until the user quits. It also displays the
//text commands and lists results.
void consoleui::run()
{
    bool running = true;

    do
    {
        ps.reset();

        cout << endl;
        cout << "list \t- This will list famous programmers or computers in the system" << endl;
        cout << "add \t- This will add a new famous programmer or computer to the system" << endl;
        cout << "change \t- This will change a famous programmer or computer in the system" << endl;
        cout << "remove \t- This will remove a famous programmer or computer from the system" << endl;
        cout << "sort \t- This will sort the list according to your preferences" << endl;
        cout << "search \t- This will search the system for a variable" << endl;
        cout << "quit \t- This will quit the program" << endl;
        cout << endl;

        string command = getInputString("Please enter a command:", SINGLE, "list|add|change|remove|sort|search|quit");

        if(command == "list")
        {
            listMenu();
        }
        else if(command == "add")
        {
            addMenu();
        }
        else if(command == "change")
        {
            changeMenu();
        }
        else if(command == "remove")
        {
            removeMenu();
        }
        else if(command == "sort")
        {
            sortMenu();
        }
        else if(command == "search")
        {
            searchMenu();
        }
        else if(command == "quit")
        {
            running = false;
        }

    } while(running);
}

template<typename T> void consoleui::printElement(T t, const int& width)
{
    const char separator    = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

//This function runs through the vector of person and prints out each instance of person. We are
//using an overloaded operator << to print out each field.
void consoleui::print_persons(vector<person> p)
{
    cout << endl;
    const int nameWidth = 25;
    const int restWidth = 15;
    printElement("Name", nameWidth);
    printElement("Sex", restWidth);
    printElement("Birth Year", restWidth);
    printElement("Death Year", restWidth);
    printElement("Nationality", restWidth);
    cout << endl;
    for(size_t i = 0; i < p.size(); i++)
    {
        cout << p.at(i);
    }

    cout << "----" << endl;
}
//This function runs through the vector of computers and prints out each instance of person. We are
//using an overloaded operator << to print out each field.
void consoleui::print_computers(vector<computer> c)
{
    cout << endl;
    const int nameWidth = 30;
    const int typeWidth = 20;
    const int restWidth = 15;
    printElement("Name", nameWidth);
    printElement("Build Year", restWidth);
    printElement("Computer Type", typeWidth);
    printElement("Built", restWidth);
    printElement("Nationality", restWidth);
    cout << endl;
    for(size_t i = 0; i < c.size(); i++)
    {
        cout << c.at(i);
    }
}

//Lists out information from the text file.
void consoleui::listMenu()
{
        cout << "Select one of the following:" << endl;
        cout << "persons - Prints out a list of persons" << endl;
        cout << "computers - Prints out a list of computers" << endl;

        string choice = getInputString(nomes, SINGLE, "persons|computers");

        if(choice == "persons")
        {
            vector<person> p = ps.getPersons();
            print_persons(p);
        }
        else if(choice == "computers")
        {
           vector<computer> c = ps.getComputers();
           print_computers(c);
        }
}

//

//this function allows you to add a scientist. The user can add value to each instance of the new scientist.
void consoleui::addMenu()
{
    cout << endl << "Select one of the following:" << endl;
    cout << "persons - Adds to the list of persons" << endl;
    cout << "computers - Adds to the list of computers" << endl << endl;

    string choice = getInputString(nomes, "persons|computers");

    if(choice == "persons")
    {
        string name;
        string sex;
        int year_of_birth;
        int year_of_death;
        string nationality;
        string info;

        name = getInputString("Name:", MULTI);

        while(name.empty())
        {
            cout << "The name field cannot be empty" << endl;
            name = getInputString("Name:", MULTI);
        }

        sex = getInputString("Sex: m|f", SINGLE, "m|f");
        year_of_birth = getInputInt("Year of birth:");
        year_of_death = getInputInt("Year of death:");
        nationality = getInputString("Nationality:", MULTI);
        info = getInputString("Info:", MULTI);

        cout << endl;

        ps.addPerson(name, sex, year_of_birth, year_of_death, nationality, info);
    }
    else if(choice == "computers")
    {

        string name;
        string type;
        int build_year;
        string b;       //horrible hack
        bool built;
        string nationality;
        string info;

        name = getInputString("Name:", MULTI);

        while(name.empty())
        {
            cout << "The name field cannot be empty" << endl;
            name = getInputString("Name:", MULTI);
        }

        type = getInputString("Type:", MULTI);

        build_year = getInputInt("Build year:");

        built = ("y" == getInputString("Built: y|n", SINGLE, "y|n"));

        nationality = getInputString("Nationality: ", MULTI);

        info = getInputString("Info: ", MULTI);

        cout << endl;

        ps.addComputer(name, build_year, type, built, nationality, info);

    }
}

//This function allows you to change some, or all properties of a person.
void consoleui::changeMenu()
{
    cout << endl;
    cout << "Please enter one of the following commands:" << endl;
    cout << "name \t\t"          << "- Remove by name" << endl;
    cout << "sex \t\t"          << "- Remove by sex" << endl;
    cout << "birth \t\t"        << "- Remove by year of birth" << endl;
    cout << "death \t\t"        << "- Remove by year of death" << endl;
    cout << "nationality \t"  << "- Remove by nationality" << endl << endl;
    string remove_command;
    cin >> remove_command;
    vector<person> match;

    vector<person> temp = ps.getPersons();

    if(remove_command == "name")
    {
        cout << "Enter the name" << endl;
        string name;
        cin.ignore(1000, '\n');
        getline(cin, name);
        //match = ps.matchByName(name);
    }
    else if(remove_command == "sex")
    {
        cout << "Enter the sex (m/f)" << endl;
        string sex;
        cin >> sex;
        //match = ps.matchBySex(sex);
    }
    else if(remove_command == "birth")
    {
        cout << "Enter the birth year" << endl;
        int birth;
        cin >> birth;
        //match = ps.matchByBirth(birth);
    }
    else if(remove_command == "death")
    {
        cout << "Enter the death year" << endl;
        int death;
        cin >> death;
        //match = ps.matchByDeath(death);
    }
    else if(remove_command == "nationality")
    {
        cout << "Enter the nationality" << endl;
        string nationality;
        cin >> nationality;
        //match = ps.matchByName(nationality);
    }

    if(match.size() == 1)
    {
        person the_person = match[0];

        ps.removePerson(the_person);

        string name;
        string sex;
        int birthyear;
        int deathyear;
        string nationality;
        string info;
        cout << "-1 Means no change" << endl;
        cout << "Name: " << endl;
        //cin.ignore(1000, '\n');
        getline(cin, name);
        cout << "Sex: " << endl;
        cin >> sex;
        cout << "Year of birth: " << endl;
        while(!(cin >> birthyear))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input it must be a number" << endl << "Try again:";
        }
        cout << "Year of death: " << endl;
        while(!(cin >> deathyear))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input it must be a number" << endl << "Try again:";
        }
        cout << "Nationality: " << endl;
        cin.ignore(1000, '\n');
        getline(cin, nationality);
        cout << "Info: " << endl;
        //cin.ignore(1000, '\n');
        getline(cin, info);

        name = (name != "-1")?(name):(the_person.getName());
        sex  = (sex != "-1")?(sex):(the_person.getSex());
        birthyear = (birthyear != -1)?(birthyear):(the_person.getBirthYear());
        deathyear = (deathyear != -1)?(deathyear):(the_person.getDeathYear());
        nationality = (nationality != "-1")?(nationality):(the_person.getNationality());
        info = (info != "-1")?(info):(the_person.getInfo());

        the_person = person(name, sex, birthyear, deathyear, nationality, info);
        ps.addPerson(the_person);

        cout << "Changes made" << endl;

    }
    else
    {
        if(match.size() == 0)
        {
            cout << "No people match this name" << endl;
        }
        else
        {
            cout << "Multiple people match this name: " << endl;
            print_persons(match);
        }
    }

}

//This function allows you to remove one or more persons from the list.
void consoleui::removeMenu()
{
    cout << endl;
    cout << "Please enter one of the following commands:" << endl;
    cout << "name \t\t"          << "- Remove by name" << endl;
    cout << "sex \t\t"          << "- Remove by sex" << endl;
    cout << "birth \t\t"        << "- Remove by year of birth" << endl;
    cout << "death \t\t"        << "- Remove by year of death" << endl;
    cout << "nationality \t"  << "- Remove by nationality" << endl << endl;
    string remove_command;
    cin >> remove_command;
    vector<person> match;
    if(remove_command == "name")
    {
        cout << "Enter the name" << endl;
        string name;
        cin.ignore(1000, '\n');
        getline(cin, name);
        //match = ps.matchByName(name);
    }
    else if(remove_command == "sex")
    {
        cout << "Enter the sex (m/f)" << endl;
        string sex;
        cin >> sex;
        //match = ps.matchBySex(sex);
    }
    else if(remove_command == "birth")
    {
        cout << "Enter the birth year" << endl;
        int birth;
        cin >> birth;
        //match = ps.matchByBirth(birth);
    }
    else if(remove_command == "death")
    {
        cout << "Enter the death year" << endl;
        int death;
        cin >> death;
        //match = ps.matchByDeath(death);
    }
    else if(remove_command == "nationality")
    {
        cout << "Enter the nationality" << endl;
        string nationality;
        cin >> nationality;
        //match = ps.matchByName(nationality);
    }
    if(match.size() >= 1)
    {
        person the_person = match[0];
        ps.removePerson(the_person);
        for(size_t i = 0; i < match.size(); i++)
        {
            ps.removePerson(match[i]);
        }
        cout << "Use the save command if you want to keep the changes" << endl;
    }
    else
    {
        if(match.size() == 0)
        {
            cout << "Something went wrong" << endl;
        }
    }
}

//This is the function where you can choose how you want to sort the list. After you have made your
//choice the new list will be printed.
void consoleui::sortMenu()
{
    vector<person> sortedPersonsList;
    vector<computer> sortedComputersList;

    cout << endl;
    cout << "Please enter one of the following commands:" << endl;
    cout << "computers - Sorts computers table " << endl;
    cout << "persons - Sorts persons table " << endl << endl;

    string table = getInputString(nomes, SINGLE, "computers|persons");

    if(table == "computers")
    {
        cout << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << "name \t\t" << "- Sorts names alphabetically" << endl;
        cout << "build_year \t" << "- Sorts by build year" << endl;
        cout << "computer_type \t" << "- Sorts computer type alphabetically" << endl;
        cout << "built \t\t" << "- Sorts by whether it has been built" << endl;
        cout << "nationality \t" << "- Sorts nationalities alphabetically" << endl << endl;

        string column = getInputString(nomes, SINGLE, "name|build_year|computer_type|built|nationality");

        cout << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << "asc \t- Sorts by ascending order" << endl;
        cout << "desc \t- Sorts by descending order" << endl << endl;

        string order = getInputString(nomes, SINGLE, "asc|desc");

        sortedComputersList = ps.sortComputers(column, order);
        print_computers(sortedComputersList);
    }
    else if(table == "persons")
    {
        cout << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << "name \t\t" << "- Sorts names alphabetically" << endl;
        cout << "sex \t\t"          << "- Sort by sex" << endl;
        cout << "birth_year \t"        << "- Sorts by year of birth" << endl;
        cout << "death_year \t"        << "- Sorts by year of death" << endl;
        cout << "nationality \t"  << "- Sorts nationalities alphabetically" << endl << endl;

        string column = getInputString(nomes, SINGLE, "name|sex|birth_year|death_year|nationality");

        cout << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << "asc \t- Sorts by ascending order" << endl;
        cout << "desc \t- Sorts by descending order" << endl << endl;

        string order = getInputString(nomes, SINGLE, "asc|desc");

        sortedPersonsList = ps.sortPersons(column, order);
        print_persons(sortedPersonsList);
    }
}
//This function allows you to search for a specific scientist in the entire list. You can search the system by
//This name, sex, birth year, death year or nationality.
void consoleui::searchMenu()
{
    vector<string> arguments;

    string table;
    do {
        cout << "persons - Will search in the persons table" << endl;
        cout << "computers - Will search in the computers table" << endl;

        cin >> table;
    } while (!expect(table, valid_table_names));

    arguments.push_back(table);
    string input;

    do {
        cout << "Enter column to search in" << endl;
        cout << "Valid column names below" << endl;
        if (table == "persons") {
            for (string column : valid_person_columns) {
                cout << column << endl;
            }
            cout << "end; - to stop inputting arguments" << endl;

            cin >> input;
        } else if (table == "computers") {
            for (string column : valid_computer_columns) {
                cout << column << endl;
            }
            cout << "end; - to stop inputting arguments" << endl;

            cin >> input;
        }
    } while(input != INPUT_ENDER);

    //TODO: Implement searching functionality

    /*

    cout << endl;
    cout << "name - Will search the system for a name" << endl;
    cout << "sex - Will search the system for a sex(m/f)" << endl;
    cout << "birth - Will search the system for a birth year" << endl;
    cout << "death - Will search the system for a death year" << endl;
    cout << "nationality - Will search the system for a nationality" << endl << endl;


    vector<person> match;
    vector<person> temp = ps.getPersons();

    string searchCommand;
    string search_string;

    cin >> searchCommand;
    cout << endl << "Search string: " << endl << endl;
    cin.ignore(1000, '\n');

    if(searchCommand == "name")
    {
		getline(cin, search_string);
        //match = ps.matchByName(search_string);
    }
    else if(searchCommand == "sex")
    {
		getline(cin, search_string);
        //match = ps.matchBySex(search_string);
    }
    else if(searchCommand == "birth")
    {
        int search_int;


        //match = ps.matchByBirth(search_int);
    }
    else if(searchCommand == "death")
    {
        int search_int;
        while(!(cin >> search_int))
        {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input it must be a number" << endl << "Try again:";
        }

        //match = ps.matchByDeath(search_int);
    }
    else if(searchCommand == "nationality")
    {
        getline(cin, search_string);

        //match = ps.matchByNationality(search_string);
	}
    else
    {
        cout << "error: invalid search command" << endl;
    }

    print_persons(match);
    */
}

string consoleui::getInputString(string message, bool multiToken, string expected)
{
    if(message != nomes)
    {
        cout << message << endl;
    }

    string input;
    getline(cin, input);

    auto first = input.find_first_not_of(" \t");
    if(first == string::npos) return "";
    auto last = input.find_last_not_of(" \t");
    auto range = last - first + 1;

    input = input.substr(first,range);

    if(!multiToken && utils::split(input, ' ').size() > 1)
    {
        cout << "Multiple tokens detected in buffer, please try again." << endl;

        return getInputString(message, multiToken, expected);
    }

    if(expected == noexp)
    {
        return input;
    }
    else
    {
        vector<string> exp = utils::split(expected, '|');

        if(find(exp.begin(), exp.end(), input) != exp.end())
        {
            return input;
        }

        cout << "Invalid input, please try again." << endl;

        return getInputString(message, multiToken, expected);
    }
}

string consoleui::getInputString(string message, bool multiToken)
{
    return getInputString(message, multiToken, noexp);
}

int consoleui::getInputInt(string message)
{
    if(message != nomes)
    {
        cout << message << endl;
    }

    int input;

    while(!(cin >> input))
    {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input it must be a number" << endl << "Try again:";
    }

    cin.ignore();

    return input;
}
