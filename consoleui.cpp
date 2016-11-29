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
        cout << "Please enter one of the following commands:" << endl;
        cout << "list - This will list all famous programmers in the system" << endl;
        cout << "add - This will add a new famous programmer to the system" << endl;
        cout << "sort - This will sort the list according to your preferences" << endl;
        cout << "search - This will search the system for a variable" << endl;
        cout << "save - Saves all famous programmers currently in the system to a file" << endl;
        cout << "quit - This will quit the program" << endl;
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
        cout << "Name: " << p[i].getName() << endl;
        cout << "-" << endl;
        cout << "Sex: " << p[i].getSex() << endl;
        cout << "Year of birth: " << p[i].getBirthYear() << endl;
        cout << "Year of death: " << p[i].getDeathYear() << endl;
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

    cout << "Name: " << endl;
    cin.ignore(1000, '\n');
    getline(cin, name);

    cout << "Sex: " << endl;
    cin >> sex;

    cout << "Year of birth: " << endl;
    cin >> year_of_birth;

    cout << "Year of death: " << endl;
    cin >> year_of_death;

    cout << endl;

    ps.addPerson(name, sex, year_of_birth, year_of_death);

}

void consoleui::sort()
{
    cout << "Please enter one of the following commands:" << endl;
    cout << "alphabetical - Sorts by alphabetical order" << endl;
    cout << "sex - Sort by sex" << endl;
    cout << "birth - Sorts by year of birth" << endl;
    cout << "death - Sorts by year of death" << endl;

    string sort_command;
    cin >> sort_command;

    if(sort_command == "alphabetical")
    {
        cout << "Please enter one of the following commands:" << endl;
        cout << "az - Sorts by alphabetical order" << endl;
        cout << "za - Sorts by reverse alphabetical order" << endl;

        string alph_command;
        cin >> alph_command;

        if(alph_command == "az")
        {
            //TODO: Put in function for sorting in normal alphabetical order
        }
        else if(alph_command == "za")
        {
             //TODO: Put in function for sorting in reverse alphabetical order
        }
    }
    else if(sort_command == "sex")
    {
        cout << "Please enter one of the following commands:" << endl;
        cout << "male - Lists men first" << endl;
        cout << "female - Lists women first" << endl;

        string sex_command;
        cin >> sex_command;

        if(sex_command == "male")
        {
            //TODO: Put in function for sorting by male first
        }
        else if(sex_command == "female")
        {
            //TODO: Put in function for sorting by female first
        }
    }
    else if(sort_command == "birth" || sort_command == "death")
    {
        cout << "Please enter one of the following commands:" << endl;
        cout << "asc - Sort by " + sort_command + " year (ascending order)" << endl;
        cout << "desc - Sort by " + sort_command + " year (descending order)" << endl;

        string order_command;
        cin >> order_command;

        if(order_command == "asc")
        {
            //TODO: Put in function for sorting by birth or death year (ascending)
            if(sort_command == "birth")
            {

            } else {

            }
        }
        else if(order_command == "desc")
        {
            //TODO: Put in function for sorting by birth or death year (descending)
            if(sort_command == "birth")
            {

            } else {

            }
        }
    }
}

void consoleui::search()
{
    cout << "name - Will search the system for a name" << endl;
    cout << "sex - Will search the system for a sex" << endl;
    cout << "birth - Will search the system for a birth year" << endl;
    cout << "death - Will search the system for a death year" << endl;

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
        cin >> search_int;

        for(size_t i = 0; i < temp.size(); i++)
        {
            if(temp[i].getDeathYear() == search_int)
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
