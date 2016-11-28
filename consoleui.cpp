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
}
