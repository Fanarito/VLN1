#include <iostream>
#include <string>
#include "consoleui.h"

using namespace std;

consoleui::consoleui()
{

}

void consoleui::run()
{
    bool running = true;

    do
    {
        cout << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << "list \t- This will list all famous programmers in the system" << endl;
        cout << "add \t- This will add a new famous programmer to the system" << endl;
        cout << "sort \t- This will sort the list according to your preferences" << endl;
        cout << "search \t- This will search the system for a variable" << endl;
        cout << "regex \t- Use regex to match either name, sex, birthyear or deathyear" << endl;
        cout << "save \t- Saves all famous programmers currently in the system to a file" << endl;
        cout << "quit \t- This will quit the program" << endl;
        cout << endl;

        string command;
        cin >> command;

        if(command == "list")
        {
            list();
        }
        else if(command == "add")
        {
            add();
        }
        else if(command == "sort")
        {
            sort();
        }
        else if(command == "search")
        {
            search();
        }
        else if(command == "regex")
        {
            regex();
        }
        else if(command == "save")
        {
            ps.save();
        }
        else if(command == "quit")
        {
            running = false;
        }
        else
        {
            cout << "That is not a valid command" << endl;
        }

    } while(running);
}

void consoleui::print_persons(vector<person> p)
{
    for(size_t i = 0; i < p.size(); i++)
    {
        cout << "----" << endl;
        cout << p.at(i);
    }

    cout << "----" << endl;
}

void consoleui::list()
{
    vector<person> p = ps.getPersons();
    print_persons(p);
}

void consoleui::add()
{
    string name;
    string sex;
    int year_of_birth;
    int year_of_death;
    string nationality;
    string info;

    cout << "Name: " << endl;
    cin.ignore(1000, '\n');
    getline(cin, name);

    cout << "Sex: " << endl;
    cin >> sex;

    cout << "Year of birth: " << endl;
    cin >> year_of_birth;

    cout << "Year of death: " << endl;
    cin >> year_of_death;

    cout << "Nationality: " << endl;
    cin >> nationality;

    cout << "Information: " << endl;
    cin.ignore(1000, '\n');
    getline(cin, info);

    cout << endl;

    ps.addPerson(name, sex, year_of_birth, year_of_death, nationality, info);

}

void consoleui::sort()
{
    vector<person> sortedList;

    cout << endl;
    cout << "Please enter one of the following commands:" << endl;
    cout << "alphabetical \t" << "- Sorts by alphabetical order" << endl;
    cout << "sex \t\t"          << "- Sort by sex" << endl;
    cout << "birth \t\t"        << "-Sorts by year of birth" << endl;
    cout << "death \t\t"        << "- Sorts by year of death" << endl;
    cout << "nationality \t"  << "- Sorts nationalities alphabetically" << endl << endl;

    string sort_command;
    cin >> sort_command;

    if(sort_command == "alphabetical")
    {
        cout << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << "az - Sorts by alphabetical order" << endl;
        cout << "za - Sorts by reverse alphabetical order" << endl << endl;

        string alph_command;
        cin >> alph_command;

        if(alph_command == "az")
        {
            sortedList = personservice().alphabetical();
            print_persons(sortedList);
        }
        else if(alph_command == "za")
        {
             sortedList = personservice().reverseAlphabetical();
             print_persons(sortedList);
        }

    }
    else if(sort_command == "sex")
    {
        cout << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << "male - Lists men first" << endl;
        cout << "female - Lists women first" << endl << endl;

        string sex_command;
        cin >> sex_command;

        if(sex_command == "male")
        {
            sortedList = personservice().genderMale();
            print_persons(sortedList);
        }
        else if(sex_command == "female")
        {
            sortedList = personservice().genderFemale();
            print_persons(sortedList);
        }
    }
    else if(sort_command == "birth" || sort_command == "death")
    {
        cout << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << "asc - Sort by " + sort_command + " year (ascending order)" << endl;
        cout << "desc - Sort by " + sort_command + " year (descending order)" << endl << endl;

        string order_command;
        cin >> order_command;

        if(order_command == "asc")
        {
            if(sort_command == "birth")
            {
                sortedList = personservice().birthAscending();
                print_persons(sortedList);
            } else {
                sortedList = personservice().deathAscending();
                print_persons(sortedList);
            }
        }
        else if(order_command == "desc")
        {
            if(sort_command == "birth")
            {
                sortedList = personservice().birthDescending();
                print_persons(sortedList);
            } else {
                sortedList = personservice().deathDescending();
                print_persons(sortedList);
            }
        }
    }
    else if(sort_command == "nationality")
    {
        cout << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << "az - Sorts nationalities by alphabetical order" << endl;
        cout << "za - Sorts nationalities by reverse alphabetical order" << endl << endl;

        string nat_command;
        cin >> nat_command;

        if(nat_command == "az")
        {
            sortedList = personservice().nationalityOrder();
            print_persons(sortedList);
        }
        else if(nat_command == "za")
        {
             sortedList = personservice().nationalityReverse();
             print_persons(sortedList);
        }
    }
}

void consoleui::search()
{
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
    cout << "Search string: " << endl;
    cin.ignore(1000, '\n');

    if(searchCommand == "name")
    {
        getline(cin, search_string);

        for(size_t i = 0; i < temp.size(); i++)
        {
            if(temp[i].getName().find(search_string) != string::npos)
            {
                match.push_back(temp[i]);
            }
        }
    }
    else if(searchCommand == "sex")
    {
        getline(cin, search_string);

        for(size_t i = 0; i < temp.size(); i++)
        {
            if(temp[i].getSex().find(search_string) != string::npos)
            {
                match.push_back(temp[i]);
            }
        }
    }
    else if(searchCommand == "birth")
    {
        int search_int;
        cin >> search_int;

        for(size_t i = 0; i < temp.size(); i++)
        {
            if(temp[i].getBirthYear() == search_int)
            {
                match.push_back(temp[i]);
            }
        }
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

        for(size_t i = 0; i < temp.size(); i++)
        {
            if(temp[i].getDeathYear() == search_int)
            {
                match.push_back(temp[i]);
            }
        }
    }
    else if(searchCommand == "nationality")
    {
        getline(cin, search_string);

        for(size_t i = 0; i < temp.size(); i++)
        {
            if(temp[i].getNationality().find(search_string) != string::npos)
            {
                match.push_back(temp[i]);
            }
        }
    }
    else
    {
        cout << "error: invalid search command" << endl;
    }

    print_persons(match);
}

void consoleui::regex()
{
    std::string rx;
    cin >> rx;
    print_persons(ps.filterNameByRegex(rx));
}
