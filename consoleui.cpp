#include <iostream>
#include <string>
#include "consoleui.h"

using namespace std;
consoleui::consoleui()
{

}

void consoleui::run()
{
    string quit;
    do
    {
        cout << "Please enter one of the following commands:" << endl;
        cout << "list - This will list all famous programmers in the system" << endl;
        cout << "add - This will add a new famous programmer to the system" << endl;
        cout << "sort - This will sort the list according to your preferences" << endl;
        cout << "search - This will search the system for a variable" << endl;
        cout << "save - Saves all famous programmers currently in the system to a file" << endl;
        cout << "quit - This will quit the program" << endl;

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
        else if(command == "search")
        {
            cout << "name - Will search the system for a name" << endl;
            cout << "sex - Will search the system for a sex" << endl;
            cout << "birth - Will search the system for a birth year" << endl;
            cout << "death - Will search the system for a death year" << endl;
            string searchCommand;
            cin >> searchCommand;
            if(searchCommand == "name")
            {
                //TODO: Put in function to search for name
            }
            else if(searchCommand == "sex")
            {
                //TODO: Put in function to search for sex
            }
            else if(searchCommand == "birth")
            {
                //TODO: Put in function to search for birth
            }
            else if(searchCommand == "death")
            {
                //TODO: Put in function to search for death
            }
        }
        else if(command == "save")
        {
            //TODO: Put in function to save;
        }
        else if(command == "quit")
        {
            break;
        }
        else
        {
            cout << "That is not a valid command" << endl;
        }
    } while(true);
}
