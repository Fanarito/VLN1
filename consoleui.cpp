#include "consoleui.h"
#include "utils.h"
#include <time.h>

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
        cout << endl << Color::GREEN << "list \t" << Color::AQUA << "- This will list famous programmers, computers, connections, nationalities and computer types in the system" << endl;
        cout << Color::GREEN << "add \t" << Color::AQUA <<"- This will add a new famous programmer, computer or connection to the system" << endl;
        cout << Color::GREEN <<"change \t" << Color::AQUA <<"- This will change a famous programmer or computer in the system" << endl;
        cout << Color::GREEN <<"remove \t" << Color::AQUA <<"- This will remove a famous programmer or computer from the system" << endl;
        cout << Color::GREEN <<"sort \t" << Color::AQUA <<"- This will sort the list according to your preferences" << endl;
        cout << Color::GREEN <<"search \t" << Color::AQUA <<"- This will search the system for a variable" << endl;
        cout << Color::GREEN <<"info \t" << Color::AQUA <<"- This will display information about a famous programmer or computer (including connections)" << endl;
        cout << Color::GREEN <<"clear \t" << Color::AQUA <<"- This will clear the window"<<endl;
        cout << Color::GREEN <<"quit \t" << Color::AQUA <<"- This will quit the program"<< endl;
        cout << endl;

        cout << Color::PURPLE;
        command = getInputString("Please enter a command:", SINGLE, VALID_COMMANDS);

        string choice;

        if(command == "change" || command == "search" || command == "sort" || command == "info")
        {
            cout << endl;
            choice = getInputString("Select one of the following: persons|computers", SINGLE, "persons|computers");
        }
        else if(command == "add" || command == "list" || command == "remove")
        {
            cout << endl;
            choice = getInputString("Select one of the following: " + VALID_ADD_COMMANDS, SINGLE);
        }

        /*else if(command != "quit" && command != "clear")
        {
            cout << endl;
            choice = getInputString("Select one of the following: " + VALID_TABLE_NAMES, SINGLE, VALID_TABLE_NAMES);
        }*/

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
        else if(command == "clear")
        {
            cout << string(100, '\n');
        }
        else if(command == "quit")
        {
            running = false;
        }


    } while(running);
}

//Lists out information from the database
void consoleui::listMenu(string choice)
{
        if(choice == "persons")
        {
            vector<person> p = ps.getPersons();
            printPersons(p);
        }
        else if(choice == "computers")
        {
           vector<computer> c = ps.getComputers();
           printComputers(c);
        }
        else if(choice == "connections")
        {
            cout << endl << "Connections to persons or computers?" << endl;

            string conn_choice = getInputString("persons|computers", SINGLE, "persons|computers");
            cout << endl;

            if(conn_choice == "persons")
            {
                printPersonConnections(ps.getPersons());
            }
            else if(conn_choice == "computers")
            {
                printComputerConnections(ps.getComputers());
            }
        }
        else if(choice == "nationalities")
        {
           vector<string> n = ps.getNationalities();

           cout << endl;
           for(size_t i = 0; i < n.size(); i++)
           {
               cout << n.at(i) << endl;
           }
        }
        else if(choice == "computer_types")
        {
           vector<string> ct = ps.getComputerTypes();

           cout << endl;
           for(size_t i = 0; i < ct.size(); i++)
           {
               cout << ct.at(i) << endl;
           }
        }
        else
        {
            cout << endl << Color::RED << "Invalid command!" << Color::PURPLE << endl << endl;
            run();
        }
}

//This function allows you to add a person/computer/connection/nationality/computer_type.
void consoleui::addMenu(string choice)
{
    if(choice == "persons")
    {
        string name;
        string sex;
        int birthyear;
        int deathyear;
        string nationality;
        string info;

        cout << endl;
        name = getInputString("Name:", MULTI);

        while(name.empty())
        {
            cout << "The name field cannot be empty" << endl;
            name = getInputString("Name:", MULTI);
        }

        cout << endl;
        sex = getInputString("Sex: m|f", SINGLE, "m|f");

        cout << endl;
        deathyear = getInputInt("Year of death (if alive enter 0):", PYTHAGORAS, utils::getCurrentYear());
        do
        {
            cout << endl;
            birthyear = getInputInt("Enter year of birth(cannot be after death year): ", PYTHAGORAS, utils::getCurrentYear());
        }
        while(birthyear > deathyear && deathyear != 0);

        cout << endl;

        nationality = getInputString("Nationality:", MULTI);

        while(nationality.empty())
        {
            cout << "The field cannot be empty" << endl;
            nationality = getInputString("Nationality:", MULTI);
        }

        string answer;
        int check = ps.getNationalityById(nationality);

        bool running = true;


        if(check == 0)
        {
            cout << endl << "Nationality type does not exist in database. Would you like to add this nationality to the database (y/n)?" << endl << endl;
            answer = getInputString(NO_MESS, SINGLE, "y|n");

            if(answer == "n")
            {
                return;
            }
            else if(answer == "y")
            {
                while(nationality.empty())
                {
                    cout << "The field cannot be empty" << endl;
                    nationality = getInputString("Nationality:", MULTI);
                }
                cout << endl;

                running = false;

                ps.addNationality(nationality);
            }
        }

        cout << endl;
        info = getInputString("Info:", MULTI);

        cout << endl;

        ps.addPerson(name, sex, birthyear, deathyear, nationality, info);
    }
    else if(choice == "computers")
    {

        string name;
        string type;
        int build_year = 0; //Asked for if machine was built
        bool built;
        string nationality;
        string info;

        cout << endl;
        name = getInputString("Name:", MULTI);

        while(name.empty())
        {
            cout << "The name field cannot be empty" << endl;
            name = getInputString("Name:", MULTI);
        }

        cout << endl;
        type = getInputString("Type:", MULTI);

        while(type.empty())
        {
            cout << "The field cannot be empty" << endl;
            type = getInputString("Type:", MULTI);
        }

        string answer;
        int check = ps.getComputerTypeById(type);

        if(check == 0)
        {
            cout << endl << "Computer type does not exist in database. Would you like to add this computer type to the database (y/n)?" << endl << endl;
            answer = getInputString(NO_MESS, SINGLE, "y|n");

            if(answer == "n")
            {
                return;
            }
            else if(answer == "y")
            {
                while(type.empty())
                {
                    cout << "The field cannot be empty" << endl;
                    type = getInputString("Type:", MULTI);
                }
                cout << endl;

                ps.addComputerType(type);
            }
        }

        cout << endl;
        built = ("y" == getInputString("Built: y|n", SINGLE, "y|n"));

        cout << endl;
        if(built) build_year = getInputInt("Build year:", PYTHAGORAS, utils::getCurrentYear());

        cout << endl;
        nationality = getInputString("Nationality: ", MULTI);

        while(nationality.empty())
        {
            cout << "The field cannot be empty" << endl;
            nationality = getInputString("Nationality:", MULTI);
        }

        string answer_nat;
        int check_nat = ps.getNationalityById(nationality);

        if(check_nat == 0)
        {
            cout << endl << "Nationality type does not exist in database. Would you like to add this nationality to the database (y/n)?" << endl << endl;
            answer = getInputString(NO_MESS, SINGLE, "y|n");

            if(answer == "n")
            {
                return;
            }
            else if(answer == "y")
            {
                while(nationality.empty())
                {
                    cout << "The field cannot be empty" << endl;
                    nationality = getInputString("Nationality:", MULTI);
                }
                cout << endl;

                ps.addNationality(nationality);
            }
        }

        cout << endl;
        info = getInputString("Info: ", MULTI);

        cout << endl;

        ps.addComputer(name, build_year, type, built, nationality, info);

    }
    else if(choice == "connections")
    {
        int comp_id;
        int person_id;


        searchMenu("persons");
        cout << endl;
        person_id = getInputInt("Please enter the ID of the person you want to connect:");
        searchMenu("computers");
        cout << endl;
        comp_id = getInputInt("Please enter the ID of the computer you want to connect to previusly selected person:");
        cout << endl;

        ps.removeConnection(comp_id, person_id);
        ps.addConnection(comp_id, person_id);

    }
    else if(choice == "computer_types")
    {
        string comp_type;

        cout << endl;
        comp_type = getInputString("Computer type:", MULTI);

        while(comp_type.empty())
        {
            cout << "The field cannot be empty" << endl;
            comp_type = getInputString("Computer type:", MULTI);
        }

        cout << endl;

        ps.addComputerType(comp_type);

    }
    else
    {
        cout << Color::RED << "Invalid command!" << Color::PURPLE << endl << endl;

        run();
    }

    cout << choice << " added!" << endl;
}


//This function allows you to change some, or all properties of a person/computer.
void consoleui::changeMenu(string choice)
{
    int res = searchMenu(choice);
    int changeId;

    if(choice == "persons")
    {
        if (res == -1)
            changeId = getInputInt("Please Enter ID of person you want to change. -1 to cancel");
        else
            changeId = res;

        if(changeId == -1) return;

        bool success;
        person p = ps.getPersonById(changeId, success);

        if (!success)
        {
            cout << endl << "Person not found" << endl;
            return;
        }

        cout << endl;
        string name = getInputString("Enter name: (empty for no change)", MULTI);
        string nationality = getInputString("Enter nationality: (empty for no change)", MULTI);
        string sex = getInputString("Enter sex(empty for no change): ", SINGLE);
        int deathyear = getInputInt("Enter year of death(0 for not dead, -1 for unchanged): ",PYTHAGORAS, utils::getCurrentYear());
        int birthyear;
        do
        {
            birthyear = getInputInt("Enter year of birth(-1 for unchanged, cannot be after death year): ", PYTHAGORAS, utils::getCurrentYear());
        } while(birthyear > deathyear && deathyear != 0 && deathyear != -1);

        string info = getInputString("Enter info: (empty for no change)", MULTI);

        if (!name.empty()) p.setName(name);
        if (!nationality.empty()) p.setNationality(nationality);
        if (!info.empty()) p.setInfo(info);
        if (!sex.empty()) p.setSex(sex);
        if (birthyear != -1) p.setBirthYear(birthyear);
        if (deathyear != -1) p.setDeathYear(deathyear);

        ps.updatePerson(p);
    }
    else if(choice == "computers")
    {
        if (res == -1)
            changeId = getInputInt("Please enter ID of computer you want to change. -1 to cancel");
        else
            changeId = res;

        if(changeId == -1) return;

        bool success;
        computer comp = ps.getComputerById(changeId, success);

        if (!success)
        {
            cout << endl << "Computer not found" << endl;
            return;
        }

        string name = getInputString("Enter name: ", MULTI);
        // string nationality = getInputString("Enter nationality; ", MULTI);
        string info = getInputString("Enter info: ", MULTI);
        bool built = getInputInt("Was it built, 0 for no, 1 for yes: ");
        int buildyear = -1;
        if (built)
        {
            buildyear = getInputInt("When was it built: ", PYTHAGORAS, utils::getCurrentYear());
        }
        else
        {
            buildyear = 0;
        }
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

//This function allows you to remove one or more persons/computers from the list.
void consoleui::removeMenu(string choice)
{
    int res;
    if (choice != "connections")
        res = searchMenu(choice);

    int removeId;

    if(choice == "persons")
    {
        if (res == -1)
            removeId = getInputInt("Please Enter ID of person you want to remove. -1 to cancel");
        else
            removeId = res;

        if(removeId == -1) return;

        ps.removePerson(removeId);
    }
    else if(choice == "computers")
    {
        if (res == -1)
            removeId = getInputInt("Please enter ID of computer you want to remove. -1 to cancel");
        else
            removeId = res;

        if(removeId == -1) return;

        ps.removeComputer(removeId);
    }
    else if(choice == "connections")
    {
        int pid = searchMenu("persons");
        int cid = searchMenu("computers");

        ps.removeConnection(pid, cid);
    }
}

//This is the function where you can choose how you want to sort the list. After you have made your
//choice the new list will be printed.
void consoleui::sortMenu(string choice)
{
    string options, column, order;

    if(choice == "persons") options = VALID_PERSON_COLUMNS;
    else if(choice == "computers") options = VALID_COMPUTER_COLUMNS;

    cout << endl;
    cout << "Column you would like to sort by:" << endl;
    cout << options << endl;
    cout << endl;

    column = getInputString(NO_MESS,SINGLE,options);

    cout << endl;
    cout << VALID_SORT_COMMANDS << endl;
    cout << endl;

    order = getInputString(NO_MESS,SINGLE, VALID_SORT_COMMANDS);

    if(choice == "persons")
    {
        printPersons(ps.sortPersons(column, order));
    }
    else if(choice == "computers")
    {
        printComputers(ps.sortComputers(column, order));
    }

}

//This function allows you to search for a specific scientist/computer in the entire list. You can search the system
//by their properties. Example: for a person you can search by name, sex, birth year, death year or nationality.
int consoleui::searchMenu(string choice, bool printRes)
{
    vector<string> arguments;
    arguments.push_back(choice);

    string options, column, search_string;

    if(choice == "persons") options = VALID_PERSON_COLUMNS;
    else if(choice == "computers") options = VALID_COMPUTER_COLUMNS;

    cout << endl;
    cout << endl << "Enter column to search in or enter id" << endl;
    cout << options << endl;
    cout << endl;

    column = getInputString(
                    "Enter column name: ",
                    SINGLE, options,
                    true
                );

    // Disgusting but it works
    if (utils::isStrInt(column) && choice == "persons")
    {
        bool success;

        person p = ps.getPersonById(stoi(column), success);

        if (!success)
        {
            cout << endl << "Person not found try again" << endl;
            return searchMenu(choice);
        }

        if (printRes)
            printPersons(p);

        return stoi(column);
    }
    else if (utils::isStrInt(column) && choice == "computers")
    {
        bool success;
        computer c = ps.getComputerById(stoi(column), success);

        if (!success)
        {
            cout << endl << "Computer not found try again" << endl;
            return searchMenu(choice);
        }

        if (printRes)
            printComputers(c);

        return stoi(column);
    }


    if(column == "sex")
    {
        search_string = getInputString("m|f", SINGLE, "m|f");
    }
    else if (column == "birth_year" || column == "death_year" || column == "build_year")
    {
        search_string = to_string(getInputInt("Input year: ", PYTHAGORAS, utils::getCurrentYear()));
    }
    else if (column == "id")
    {
        search_string = to_string(getInputInt("Enter id: "));
        column = choice + ".id";
    }
    else
        search_string = getInputString("Input searchstring: ", MULTI);
    arguments.push_back(column);
    arguments.push_back(search_string );

    if (choice == "persons") {
        vector<person> p = ps.searchPersons(arguments);
        if (p.size() > 1)
        {
            printPersons(p);
            return -1;
        }
        else if (p.size() == 0)
        {
            cout << endl << "No persons found try again" << endl;
            return searchMenu(choice);
        }

        if (printRes)
            printPersons(p);
        return p.at(0).getId();
    }
    else if (choice == "computers") {
        vector<computer> c = ps.searchComputers(arguments);
        if (c.size() > 1)
        {
            printComputers(c);
            return -1;
        }
        else if (c.size() == 0)
        {
            cout << endl << "No computers found try again" << endl;
            return searchMenu(choice);
        }
        if (printRes)
            printComputers(c);
        return c.at(0).getId();
    }

    return -1;
}

//This allows you to request information about a person or a computer.
//This information includes associations between people and computers.
void consoleui::infoMenu(string choice)
{
    int res = searchMenu(choice, false);
    int infoId;

    if(choice == "persons")
    {
        person infoPerson;
        string infoPrint;

        if (res == -1)
            infoId = getInputInt("Please enter ID of person you want information about. -1 to cancel");
        else
            infoId = res;

        if(infoId == -1) return;

        bool success;
        infoPerson = ps.getPersonById(infoId, success);

        if (success)
        {
            printInfoPerson(infoPerson);
        }
        else
        {
            cout << endl << "Person not found" << endl;
        }
    }
    else if(choice == "computers")
    {
        computer infoComputer;
        string infoPrint;

        if (res == -1)
            infoId = getInputInt("Please enter ID of computer you want information about -1 to cancel");
        else
            infoId = res;

        if(infoId == -1) return;

        bool success;
        infoComputer = ps.getComputerById(infoId, success);

        if (success)
        {
            printInfoComputer(infoComputer);
        }
        else
        {
            cout << endl << "Computer not found" << endl;
        }
    }
}

//Prints table
void consoleui::tablePrint(string s, int width)
{
    cout << left << setw(width) << setfill(separator) << s;
}

//Prints details about a scientist
void consoleui::printDetailsPerson(person p)
{
    string death = to_string(p.getDeathYear());
    string sex = p.getSex();

    death = (death == "0")?("Alive"):(death);
    sex = (sex == "f")?("Female"):("Male");
    cout << Color::LBLUE;
    tablePrint(to_string(p.getId()), restWidth);
    cout << Color::BLUE;
    tablePrint(p.getName(), nameWidth);
    cout << Color::LBLUE;
    tablePrint(sex, restWidth);
    cout << Color::BLUE;
    tablePrint(to_string(p.getBirthYear()), restWidth);
    cout << Color::LBLUE;
    tablePrint(death, restWidth);
    cout << Color::BLUE;
    tablePrint(p.getNationality(), restWidth);

    cout << Color::PURPLE << endl;
}

//Prints details about a computer
void consoleui::printDetailsComputer(computer c)
{

    string built;
    string buildYear = to_string(c.getBuildYear());

    buildYear = (buildYear == "0")?("Not built"):(buildYear);
    built = (c.getBuilt())?("True"):("False");
    cout << Color::YELLOW;
    tablePrint(to_string(c.getId()), restWidth);
    cout << Color::LYELLOW;
    tablePrint(c.getName(), nameWidth);
    cout << Color::YELLOW;
    tablePrint(buildYear, restWidth);
    cout << Color::LYELLOW;
    tablePrint(c.getType(), typeWidth);
    cout << Color::YELLOW;
    tablePrint(built, restWidth);
    cout << Color::LYELLOW;
    tablePrint(c.getNationality(), restWidth);

    cout << Color::PURPLE << endl;
}

//Prints information about a requested person
void consoleui::printInfoPerson(person p)
{
    string name = p.getName();
    string nationality = p.getNationality();
    string death = to_string(p.getDeathYear());
    string birth = to_string(p.getBirthYear());
    string sex = p.getSex();
    string info = p.getInfo();

    sex = (sex == "f")?("Female"):("Male");

    cout << endl;
    cout << Color::LBLUE;
    tablePrint(name, restWidth);
    cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

    cout << Color::BLUE;
    tablePrint("Nationality: ", restWidth);
    tablePrint(nationality, restWidth);
    cout << endl;

    cout << Color::LBLUE;
    tablePrint("Born: ", restWidth);
    tablePrint(birth, restWidth);
    cout << endl;

    cout << Color::BLUE;
    if(death != "0")
    {
        tablePrint("Died: ", restWidth);
        tablePrint(death, restWidth);
        cout << endl;
    }

    cout << endl;
    cout << Color::LBLUE;
    tablePrint("Information ", restWidth);
    cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

    cout << utils::wordWrap(info, pageWidth);

    cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

    cout << endl;

    vector<computer> computers_connected = ps.getComputersConnectedWithPerson(p);
    cout << Color::BLUE;

    if(computers_connected.size() > 0)
    {
        tablePrint("Associated Computers", restWidth);
        cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

        for(computer c : computers_connected)
        {
            cout << c.getName() << endl;
        }

        cout << left << setw(pageWidth) << setfill('-') << "" << Color::PURPLE << endl;
    }
}

//Prints information about a requested computer
void consoleui::printInfoComputer(computer c)
{
    string name = c.getName();
    string type = c.getType();
    string nationality = c.getNationality();
    string buildYear = to_string(c.getBuildYear());
    string info = c.getInfo();

    buildYear = (buildYear == "0")?("Not built"):(buildYear);

    cout << Color::YELLOW;
    cout << endl;
    tablePrint(name, restWidth);
    cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

    cout << Color::LYELLOW;
    tablePrint("Type: ", restWidth);
    tablePrint(type, restWidth);
    cout << endl;

    cout << Color::YELLOW;
    tablePrint("Nationality: ", restWidth);
    tablePrint(nationality, restWidth);
    cout << endl;

    cout << Color::LYELLOW;
    tablePrint("Built: ", restWidth);
    tablePrint(buildYear, restWidth);
    cout << endl;

    cout << Color::YELLOW;
    cout << endl;
    tablePrint("Information ", restWidth);
    cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

    cout << utils::wordWrap(info, pageWidth);

    cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

    cout << Color::LYELLOW;
    cout << endl;

    vector<person> persons_connected = ps.getPersonsConnectedWithComputer(c);

    if(persons_connected.size() > 0)
    {
        tablePrint("Associated People", restWidth);
        cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

        for(person p : persons_connected)
        {
            cout << p.getName() << endl;
        }

        cout << left << setw(pageWidth) << setfill('-') << "" << endl;
    }
    cout << Color::PURPLE;
}

//This function runs through the vector of person and prints out each instance of person in a table.
//The table does not include information.
void consoleui::printPersons(vector<person> p)
{
    if(p.size() == 0) return;

    cout << Color::GRAY << endl;

    tablePrint("ID", restWidth);
    tablePrint("Name", nameWidth);
    tablePrint("Sex", restWidth);
    tablePrint("Birth Year", restWidth);
    tablePrint("Death Year", restWidth);
    tablePrint("Nationality", restWidth);

    cout << endl << endl;

    for(size_t i = 0; i < p.size(); i++)
    {
        printDetailsPerson(p.at(i));
    }
}

// Prints single person
void consoleui::printPersons(person p)
{
    cout << Color::LBLUE;
    vector<person> temp;
    temp.push_back(p);
    printPersons(temp);
    cout << Color::PURPLE;
}

//This function runs through the vector of computer and prints out each instance of computer in a table.
void consoleui::printComputers(vector<computer> c)
{
    if(c.size() == 0) return;

    cout << Color::GRAY << endl;

    tablePrint("ID", restWidth);
    tablePrint("Name", nameWidth);
    tablePrint("Build Year", restWidth);
    tablePrint("Computer Type", typeWidth);
    tablePrint("Built", restWidth);
    tablePrint("Nationality", restWidth);

    cout << endl;

    for(size_t i = 0; i < c.size(); i++)
    {
        printDetailsComputer(c.at(i));
    }
}

void consoleui::printComputers(computer c)
{
    cout << Color::YELLOW;
    vector<computer> temp;
    temp.push_back(c);
    printComputers(temp);
    cout << Color::PURPLE;
}

//Prints a table of connections for all persons
void consoleui::printPersonConnections(vector<person> persons)
{
    cout << Color::GRAY << endl;

    tablePrint("Person", nameWidth);
    tablePrint("ID", restWidth);
    tablePrint("Name", nameWidth);
    tablePrint("Build Year", restWidth);
    tablePrint("Computer Type", typeWidth);
    tablePrint("Built", restWidth);
    tablePrint("Nationality", restWidth);

    cout << Color::PURPLE << endl << endl;

    for (person p : persons)
    {
        vector<computer> connections = ps.getComputersConnectedWithPerson(p);
        if (connections.size() == 0)
            continue;

        cout << endl;

        tablePrint(p.getName(), nameWidth);

        cout << endl;

        for (computer c : connections)
        {
            cout << setw(nameWidth - 1) << setfill('-') << " ";
            cout << " ";
            printDetailsComputer(c);
        }

        cout << left << setw(combinedWidth + nameWidth) << setfill('-') << " " << endl;
    }
    cout << Color::PURPLE;
}

//Prints a table of connections for all computers
void consoleui::printComputerConnections(vector<computer> computers)
{
    cout << Color::GRAY << endl;
    cout << left << setw(nameWidth) << setfill(' ') << "Computer";
    cout << left << setw(restWidth) << setfill(separator) << "ID";
    cout << left << setw(nameWidth) << setfill(separator) << "Name";
    cout << left << setw(restWidth) << setfill(separator) << "Sex";
    cout << left << setw(restWidth) << setfill(separator) << "Birth Year";
    cout << left << setw(restWidth) << setfill(separator) << "Death Year";
    cout << left << setw(restWidth) << setfill(separator) << "Nationality" << endl;
    cout << Color::PURPLE << endl;

    for (computer c : computers)
    {
        vector<person> connections = ps.getPersonsConnectedWithComputer(c);
        if (connections.size() == 0)
            continue;

        cout << endl;
        cout << left << setw(nameWidth) << setfill(' ') << c.getName();
        cout << endl;

        for (person p : connections)
        {
            cout << setw(nameWidth - 1) << setfill('-') << " ";
            cout << " ";
            printDetailsPerson(p);
        }

        cout << left << setw(combinedWidth + nameWidth) << setfill('-') << " " << endl;
    }
    cout << Color::PURPLE;
}

//Receives input from user and validates the input
string consoleui::getInputString(string message, bool multiToken, string expected, bool allow_number)
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
        cout << Color::RED << "Multiple tokens detected in buffer, please try again." << Color::PURPLE << endl;

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
        } else if (allow_number && input.find_first_not_of("0123456789") == string::npos && !input.empty())
            return input;

        cout << endl << Color::RED << "Invalid input, please try again." << Color::PURPLE << endl << endl;

        return getInputString(message, multiToken, expected, allow_number);
    }
}

//Receives input from user and validates the input
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
        cout << Color::RED << "Multiple tokens detected in buffer, please try again." << Color::PURPLE << endl;

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

        cout << endl << "Invalid input, please try again." << endl << endl;

        return getInputString(message, multiToken, expected);
    }

    cout << Color::PURPLE;
}

//Receives input from user and validates the input
string consoleui::getInputString(string message, bool multiToken)
{
    return getInputString(message, multiToken, NO_EXP);
}

int consoleui::getInputInt(string message)
{
    return getInputInt(message, INT_MIN, INT_MAX);
}

//Receives input from user and validates the input
int consoleui::getInputInt(string message, int low_bound, int high_bound)
{
    if(message != NO_MESS)
    {
        cout << message << endl;
    }

    int input;

    while(!(cin >> input))
    {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << endl << Color::RED << "Invalid input it must be a number" << Color::PURPLE << endl << "Try again:";
    }

    if(input > high_bound || input < low_bound)
    {
        cout << Color::RED << "Input out of bounds, please try again." << Color::PURPLE << endl;
        return getInputInt(message, high_bound, low_bound);
    }

    cin.ignore();

    return input;
}
