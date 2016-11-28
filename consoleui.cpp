#include <iostream>
#include <string>
#include "consoleui.h"

using namespace std;
consoleui::consoleui()
{

}

void consoleui::run()
{
    cout << "Please enter one of the following commands:" << endl;
    cout << "list - This will list all famous programmers in the system" << endl;
    cout << "add - This will add a new famous programmer to the system" << endl;
    cout << "sort - This will sort the list according to your preferences" << endl;

    string command;
    cin >> command;

    if(command == "list")
    {
        personservice ps;
        vector<person> p = ps.getPersons();
        for(unsigned int i = 0; i < p.size(); i++)
        {
            cout << "Name: " << p[i].getName() << endl;
            cout << "Sex: " << p[i].getSex() << endl;
            cout << "Birthyear: " << p[i].getBirthYear() << endl;
            cout << "Year of death: " << p[i].getDeathYear() << endl;
        }
    }
    else if(command == "add")
    {

    }
    else if(command == "sort")
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
        else if(sort_command == "birth")
        {
            cout << "Please enter one of the following commands:" << endl;
            cout << "asc - Sort by birth year (ascending order)" << endl;
            cout << "desc - Sort by birth year (descending order)" << endl;

            string birth_command;
            cin >> birth_command;

            if(birth_command == "asc")
            {
                //TODO: Put in function for sorting by birth year (ascending)
            }
            else if(birth_command == "desc")
            {
                //TODO: Put in function for sorting by birth year (descending)
            }
        }
        else if(sort_command == "death")
        {
            cout << "Please enter one of the following commands:" << endl;
            cout << "asc - Sort by year of death (ascending order)" << endl;
            cout << "desc - Sort by year of death (descending order)" << endl;

            string death_command;
            cin >> death_command;

            if(death_command == "asc")
            {
                //TODO: Put in function for sorting by death year (ascending)
            }
            else if(death_command == "desc")
            {
                //TODO: Put in function for sorting by death year (descending)
            }
        }

    }
}
