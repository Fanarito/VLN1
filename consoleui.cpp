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
        cout << "info \t- This will display information about a famous programmer or computer" << endl;
        cout << "quit \t- This will quit the program" << endl;
        cout << endl;

        string command = getInputString("Please enter a command:", SINGLE, "list|add|change|remove|sort|search|info|quit");
        string choice;

        if(command != "quit")
        {
            choice = getInputString("Select one of the following: persons|computers", SINGLE, "persons|computers");
        }

        if(command == "list")
        {
            listMenu(choice);
        }
        else if(command == "add")
        {
            addMenu(choice);
        }
        else if(command == "change")
        {
            changeMenu(choice);
        }
        else if(command == "remove")
        {
            removeMenu(choice);
        }
        else if(command == "sort")
        {
            sortMenu(choice);
        }
        else if(command == "search")
        {
            searchMenu(choice);
        }
        else if(command == "info")
        {
            infoMenu(choice);
        }
        else if(command == "quit")
        {
            running = false;
        }

    } while(running);
}


//This function runs through the vector of person and prints out each instance of person. We are
//using an overloaded operator << to print out each field.
void consoleui::print_persons(vector<person> p)
{
    cout << endl;
    cout << left << setw(restWidth) << setfill(separator) << "ID";
    cout << left << setw(namePersonWidth) << setfill(separator) << "Name";
    cout << left << setw(restWidth) << setfill(separator) << "Sex";
    cout << left << setw(restWidth) << setfill(separator) << "Birth Year";
    cout << left << setw(restWidth) << setfill(separator) << "Death Year";
    cout << left << setw(restWidth) << setfill(separator) << "Nationality" << std::endl;
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
    cout << left << setw(restWidth) << setfill(separator) << "ID";
    cout << left << setw(nameCompWidth) << setfill(separator) << "Name";
    cout << left << setw(restWidth) << setfill(separator) << "Build Year";
    cout << left << setw(typeWidth) << setfill(separator) << "Computer Type";
    cout << left << setw(restWidth) << setfill(separator) << "Built";
    cout << left << setw(restWidth) << setfill(separator) << "Nationality" << std::endl;
    cout << endl;
    for(size_t i = 0; i < c.size(); i++)
    {
        cout << c.at(i);
    }
}

void consoleui::print_options(string options)
{
}

//Lists out information from the text file.
void consoleui::listMenu(string choice)
{
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

//this function allows you to add a scientist. The user can add value to each instance of the new scientist.
void consoleui::addMenu(string choice)
{
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
void consoleui::changeMenu(string choice)
{
    searchMenu(choice);

    if(choice == "persons")
    {
        int changeId = getInputInt("Please Enter ID of person you want to remove. -1 to cancel");

        if(changeId == -1) return;

        person p = ps.getPersonById(changeId);

        string name = getInputString("Enter name: (empty for no change)", MULTI);
        // string nationality = getInputString("Enter nationality: (empty for no change)", MULTI);
        string info = getInputString("Enter info: (empty for no change)", MULTI);
        string sex = getInputString("Enter sex(empty for no change): ", SINGLE);
        int birthyear = getInputInt("Enter year of birth(-1 for unchanged): ");
        int deathyear = getInputInt("Enter year of death(0 for not dead, -1 for unchanged): ");

        if (!name.empty()) p.setName(name);
        // if (!nationality.empty()) p.setNationality(nationality);
        if (!info.empty()) p.setInfo(info);
        if (!sex.empty()) p.setSex(sex);
        if (birthyear != -1) p.setBirthYear(birthyear);
        if (deathyear != -1) p.setDeathYear(deathyear);

        ps.updatePerson(p);
    }
    else if(choice == "computers")
    {
        int changeId = getInputInt("Please enter ID of computer you want to remove. -1 to cancel");

        if(changeId == -1) return;

        computer comp = ps.getComputerById(changeId);

        string name = getInputString("Enter name: ", MULTI);
        // string nationality = getInputString("Enter nationality; ", MULTI);
        string info = getInputString("Enter info: ", MULTI);
        bool built = getInputInt("Was it built, 0 for no, 1 for yes: ");
        int buildyear;
        if (built)
            buildyear = getInputInt("When was it built: ");
        string type = getInputString("Enter machine type: ", MULTI);

        if (!name.empty()) comp.setName(name);
        // if (!nationality.empty()) comp.setNationality(nationality);
        if (!info.empty()) comp.setInfo(info);
        comp.setBuilt(built);
        if (buildyear != -1) comp.setBuildYear(buildyear);
        if (!type.empty()) comp.setType(type);

        ps.updateComputer(comp);
    }
}

//This function allows you to remove one or more persons from the list.
void consoleui::removeMenu(string choice)
{
    searchMenu(choice);

    if(choice == "persons")
    {
        int removeID = getInputInt("Please Enter ID of person you want to remove. -1 to cancel");

        if(removeID == -1) return;

        ps.removePerson(removeID);
    }
    else if(choice == "computers")
    {
        int removeID = getInputInt("Please enter ID of computer you want to remove. -1 to cancel");

        if(removeID == -1) return;

        ps.removePerson(removeID);
    }
}

//This is the function where you can choose how you want to sort the list. After you have made your
//choice the new list will be printed.
void consoleui::sortMenu(string choice)
{
    string options;

    if(choice == "persons") options = VALID_PERSON_COLUMNS;
    else if(choice == "computers") options = VALID_COMPUTER_COLUMNS;

    cout << "Please enter one of the following:" << endl;
    cout << options << endl;

    string column = getInputString(NO_MESS,SINGLE,options);
    string order = getInputString(NO_MESS,SINGLE, "asc|desc");

    if(choice == "persons")
    {
        print_persons(ps.sortPersons(column, order));
    }
    else if(choice == "computers")
    {
        print_computers(ps.sortComputers(column, order));
    }

}
//This function allows you to search for a specific scientist in the entire list. You can search the system by
//This name, sex, birth year, death year or nationality.
void consoleui::searchMenu(string choice)
{
    vector<string> arguments;

    arguments.push_back(choice);

    string options;
    if (choice == "persons") options = VALID_PERSON_COLUMNS;
    else if (choice == "computers") options = VALID_COMPUTER_COLUMNS;

    cout << "Enter column to search in" << endl;
    cout << "Valid column names are: " << options << endl;
    cout << endl << INPUT_ENDER << " - to stop inputting arguments" << endl;

    string column = getInputString(
                    "Enter column name: ",
                    SINGLE, options + "|end;"
                );
    if (column == "end;") return;

    string search_string;
    if (column == "birth_year" || column == "death_year" || column == "build_year")
        search_string = to_string(getInputInt("Input year: "));
    else
        search_string = getInputString("Input searchstring: ", MULTI);

    arguments.push_back(column);
    arguments.push_back(search_string );

    if (choice == "persons") {
        print_persons(ps.searchPersons(arguments));
    }
    else if (choice == "computers") {
        print_computers(ps.searchComputers(arguments));
    }
}

string consoleui::getInputString(string message, bool multiToken, string expected)
{
    if(message != NO_MESS)
    {
        cout << message << endl;
    }

    string input;
    getline(cin, input);

    input = utils::removeWhiteSpace(input);

    if(!multiToken && utils::split(input, ' ').size() > 1)
    {
        cout << "Multiple tokens detected in buffer, please try again." << endl;

        return getInputString(message, multiToken, expected);
    }

    if(expected == NO_EXP)
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
    return getInputString(message, multiToken, NO_EXP);
}

int consoleui::getInputInt(string message)
{
    if(message != NO_MESS)
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

//This allows you to request information about a person or computer
void consoleui::infoMenu(string choice)
{
    searchMenu(choice);

    if(choice == "persons")
    {
        int infoID = getInputInt("Please enter ID of person you want information about. -1 to cancel");

        if(infoID == -1) return;
    }
    else if(choice == "computers")
    {
        int infoID = getInputInt("Please enter ID of computer you want information about -1 to cancel");

        if(infoID == -1) return;
    }
}
