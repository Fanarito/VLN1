#include <iostream>
#include <string>
#include <algorithm>
#include "consoleui.h"

using namespace std;

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
        cout << endl;
        cout << "Please enter one of the following commands:" << endl;
        cout << "list \t- This will list all famous programmers in the system" << endl;
        cout << "add \t- This will add a new famous programmer to the system" << endl;
        cout << "change \t- This will change a famous programmer in the system" << endl;
        cout << "remove \t- This will remove a famous programmer from the system" << endl;
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
        else if(command == "change")
        {
            change();
        }
        else if(command == "remove")
        {
            remove();
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

//This function runs through the vector of person and prints out each instance of person. We are
//using an overloaded operator << to print out each field.
void consoleui::print_persons(vector<person> p)
{
    for(size_t i = 0; i < p.size(); i++)
    {
        cout << "----" << endl;
        cout << p.at(i);
    }

    cout << "----" << endl;
}
//Lists out information from the text file.
void consoleui::list()
{
    vector<person> p = ps.getPersons();
    print_persons(p);
}

//this function allows you to add a scientist. The user can add value to each instance of the new scientist.
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

void consoleui::change()
{
	bool success = false;

	do {

		string name;

		cout << "Name of person you want to change: " << endl;

		cin.ignore(1000, '\n');
		getline(cin, name);

		vector<person> temp = ps.getPersons();
		vector<person> match;

        for(size_t i = 0; i < temp.size(); i++)
        {
            if(temp[i].getName().find(name) != string::npos)
            {
                match.push_back(temp[i]);
            }
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
			cin >> birthyear;
			cout << "Year of death: " << endl;
			cin >> deathyear;
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

			success = true;

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

	}while(!success);
}

void consoleui::remove()
{
}

//This is the function where you can choose how you want to sort the list. After you have made your
//choice the new list will be printed.
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
        }
        else if(alph_command == "za")
        {
             sortedList = personservice().reverseAlphabetical();
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
        }
        else if(sex_command == "female")
        {
            sortedList = personservice().genderFemale();
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
            } 
			else 
			{
                sortedList = personservice().deathAscending();
            }
        }
        else if(order_command == "desc")
        {
            if(sort_command == "birth")
            {
                sortedList = personservice().birthDescending();
            } 
			else 
			{
                sortedList = personservice().deathDescending();
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
        }
        else if(nat_command == "za")
        {
            sortedList = personservice().nationalityReverse();
        }
    }

	print_persons(sortedList);
}
//This function allows you to search for a specific scientist in the list. You can search the system by
//his name, sex, birth year, death year or nationality.
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
    cout << endl << "Search string: " << endl << endl;
    cin.ignore(1000, '\n');

    if(searchCommand == "name")
    {
		getline(cin, search_string);
 		match = ps.matchByName(search_string);		
    }
    else if(searchCommand == "sex")
    {
		getline(cin, search_string);
		match = ps.matchBySex(search_string);
    }
    else if(searchCommand == "birth")
    {
        int search_int;
        cin >> search_int;

        while(!(cin >> search_int))
        {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input it must be a number" << endl << "Try again:";
        }

		match = ps.matchByBirth(search_int);
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

		match = ps.matchByDeath(search_int);
    }
    else if(searchCommand == "nationality")
    {
        getline(cin, search_string);

		match = ps.matchByNationality(search_string);
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
    cin.ignore(1000, '\n');
    getline(cin, rx);
    print_persons(ps.filterNameByRegex(rx));
}
