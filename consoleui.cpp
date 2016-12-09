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
        EXIT = false;

        cout << endl << Color::GREEN << "list \t" << Color::AQUA << "- This will list famous programmers, computers, connections, nationalities or computer types in the system" << endl;
        cout << Color::GREEN << "add \t" << Color::AQUA <<"- This will add a new famous programmer, computer, connection, nationality or computer type to the system" << endl;
        cout << Color::GREEN <<"change \t" << Color::AQUA <<"- This will change a famous programmer or computer in the system" << endl;
        cout << Color::GREEN <<"remove \t" << Color::AQUA <<"- This will remove a famous programmer, computer, connection, nationality or computer type from the system" << endl;
        cout << Color::GREEN <<"sort \t" << Color::AQUA <<"- This will sort the list according to your preferences" << endl;
        cout << Color::GREEN <<"search \t" << Color::AQUA <<"- This will search the system for a variable" << endl;
        cout << Color::GREEN <<"info \t" << Color::AQUA <<"- This will display information about a famous programmer or computer (including connections)" << endl;
        cout << Color::GREEN <<"clear \t" << Color::AQUA <<"- This will clear the window"<<endl;
        cout << Color::GREEN <<"quit \t" << Color::AQUA <<"- This will quit the program"<< endl;
        cout << endl;
        cout << Color::RED << INPUT_ENDER << Color::AQUA <<"\t- You can write this at any point to return to this screen."<< endl;
        cout << endl;

        cout << Color::PURPLE;
        command = getInputString("Please enter a command:", SINGLE, VALID_COMMANDS);
        if(EXIT) continue;

        string choice;

        if(command == "change" || command == "search" || command == "sort" || command == "info")
        {
            cout << endl;
            choice = getInputString("Select one of the following: persons|computers", SINGLE, "persons|computers");
            if(EXIT) continue;
        }
        else if(command == "add" || command == "list" || command == "remove")
        {
            cout << endl;
            choice = getInputString("Select one of the following: " + VALID_ADD_COMMANDS, SINGLE);
            if(EXIT) continue;
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
            string conn_choice;

            cout << endl;
            cout << "Connections to persons or computers?" << endl;
            cout << endl;

            conn_choice = getInputString("persons|computers", SINGLE, "persons|computers");
            cout << endl;

            if(EXIT) return;

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
               cout << Color::LRED << n.at(i) << endl;
           }
        }
        else if(choice == "computer_types")
        {
           vector<string> ct = ps.getComputerTypes();

           cout << endl;

           for(size_t i = 0; i < ct.size(); i++)
           {
               cout << Color::YELLOW << ct.at(i) << endl;
           }
        }
        else
        {
            cout << endl << Color::RED << "Invalid command!" << Color::PURPLE << endl << endl;
            return;
        }

        cout << endl;
}

string consoleui::getValidNationality(string message) {
    bool running = true;
    string nationality;
    while (running) {
        cout << endl;
        nationality = getInputString(message, MULTI);
        if(EXIT) return "";

        while(nationality.empty())
        {
            cout << "The field cannot be empty" << endl;
            nationality = getInputString(message, MULTI);
            if(EXIT) return "";
        }

        string answer;
        int check = ps.getNationalityById(nationality);

        if(check == 0)
        {
            cout << endl << "Nationality type does not exist in database. Would you like to add this nationality to the database?" << endl << endl;
            answer = getInputString("y|n", SINGLE, "y|n");
            if(EXIT) return "";

            if(answer == "y")
            {
                while(nationality.empty())
                {
                    cout << "The field cannot be empty" << endl;
                    nationality = getInputString(message, MULTI);
                    if(EXIT) return "";
                }
                cout << endl;

                running = false;

                ps.addNationality(nationality);
            }
            else
            {
                continue;
            }
        } else {
            return nationality;
        }
    }
    return nationality;
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
        if(EXIT) return;

        while(name.empty())
        {
            cout << "The name field cannot be empty" << endl;
            name = getInputString("Name:", MULTI);
            if(EXIT) return;
        }

        cout << endl;
        sex = getInputString("Sex: m|f", SINGLE, "m|f");
        if(EXIT) return;

        cout << endl;
        birthyear = getInputInt("Enter year of birth: ", AL_KHWARIZMI, utils::getCurrentYear());
        if(EXIT) return;

        bool fail = true;
        do
        {
            cout << endl;
            deathyear = getInputInt("Year of death (if alive leave field empty):", AL_KHWARIZMI, utils::getCurrentYear(), true);
            if(EXIT) return;

            if(deathyear == 0)
            {
                fail = false;
            }

            if((birthyear > deathyear) && (deathyear != 0))
            {
                cout << endl << "Year of death cannot be before year of birth!" << endl;
            }
            else
            {
                fail = false;
            }
        }while(fail);

        cout << endl;

        nationality = getValidNationality("Nationality:");
        if (nationality.empty()) return;

        cout << endl;
        info = getInputString("Info:", MULTI);
        if(EXIT) return;

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
        if(EXIT) return;

        while(name.empty())
        {
            cout << "The name field cannot be empty" << endl;
            name = getInputString("Name:", MULTI);
            if(EXIT) return;
        }

        cout << endl;
        type = getInputString("Type:", MULTI);
        if(EXIT) return;

        while(type.empty())
        {
            cout << "The field cannot be empty" << endl;
            type = getInputString("Type:", MULTI);
            if(EXIT) return;
        }

        string answer;
        int check = ps.getComputerTypeById(type);

        if(check == 0)
        {
            cout << endl << "Computer type does not exist in database. Would you like to add this computer type to the database (y/n)?" << endl << endl;
            answer = getInputString(NO_MESS, SINGLE, "y|n");
            if(EXIT) return;

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
                    if(EXIT) return;
                }
                cout << endl;

                ps.addComputerType(type);
            }
        }

        cout << endl;
        built = ("y" == getInputString("Built: y|n", SINGLE, "y|n"));
        if(EXIT) return;

        cout << endl;
        if(built) build_year = getInputInt("Build year:", AL_KHWARIZMI, utils::getCurrentYear());
        if(EXIT) return;

        nationality = getValidNationality("Nationality:");
        if (nationality.empty()) return;

        cout << endl;
        info = getInputString("Info: ", MULTI);
        if(EXIT) return;

        cout << endl;

        ps.addComputer(name, build_year, type, built, nationality, info);

    }
    else if(choice == "connections")
    {
        int comp_id;
        int person_id;

        searchMenu("persons");
        if(EXIT) return;

        cout << endl;
        person_id = getInputInt("Please enter the ID of the person you want to connect:");
        if(EXIT) return;

        searchMenu("computers");
        if(EXIT) return;

        cout << endl;
        comp_id = getInputInt("Please enter the ID of the computer you want to connect to previusly selected person:");
        if(EXIT) return;

        cout << endl;

        bool noerr;

        ps.removeConnection(comp_id, person_id, noerr);

        if(!noerr)
        {
            cout << Color::RED << "Error, either computer or person is invalid." << endl;
            return;
        }

        ps.addConnection(comp_id, person_id);

    }
    else if(choice == "nationalities")
    {
        string nationality;

        cout << endl;
        nationality = getInputString("Nationality:", MULTI);
        if(EXIT) return;

        while(nationality.empty())
        {
            cout << Color::RED << "The field cannot be empty" << Color::PURPLE << endl;
            nationality = getInputString("Nationality:", MULTI);
            if(EXIT) return;
        }

        cout << endl;

        ps.addNationality(nationality);
    }
    else if(choice == "computer_types")
    {
        string comp_type;

        cout << endl;
        comp_type = getInputString("Computer type:", MULTI);
        if(EXIT) return;

        while(comp_type.empty())
        {
            cout << Color::RED << "The field cannot be empty" << Color::PURPLE << endl;
            comp_type = getInputString("Computer type:", MULTI);
            if(EXIT) return;
        }

        cout << endl;

        ps.addComputerType(comp_type);

    }
    else
    {
        //Should never happen
        cout << Color::RED << "Invalid command!" << Color::PURPLE << endl << endl;
        return;
    }

    cout << Color::GREEN << choice << " added!" << Color::PURPLE << endl;
}

/*
 *
 *
 *
 *
 *
 *
 * CANNOT CHANGE NATIONALITY ON COMPUTERS!
 *
 *
 *
 */

//This function allows you to change some, or all properties of a person/computer.
void consoleui::changeMenu(string choice)
{
    int res = searchMenu(choice);
    if(EXIT) return;

    int changeId;

    if(choice == "persons")
    {
        if (res == -1)
        {
            changeId = getInputInt("Please Enter ID of person you want to change. -1 to cancel");
            if(EXIT) return;
        }
        else
        {
            changeId = res;
        }

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
        if(EXIT) return;

        string nationality = getValidNationality("Enter nationality: (empty for no change)");
        if (nationality.empty()) return;

        string sex = getInputString("Enter sex(empty for no change): ", SINGLE);
        if(EXIT) return;

        int deathyear = getInputInt("Enter year of death (0 for not dead, -1 for unchanged): ",AL_KHWARIZMI, utils::getCurrentYear());
        if(EXIT) return;

        int birthyear;

        do
        {
            birthyear = getInputInt("Enter year of birth(-1 for unchanged, cannot be after death year): ", AL_KHWARIZMI, utils::getCurrentYear());
            if(EXIT) return;
        } while(birthyear > deathyear && deathyear != 0 && deathyear != -1);

        string info = getInputString("Enter info: (empty for no change)", MULTI);
        if(EXIT) return;

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
        {
            changeId = getInputInt("Please enter ID of computer you want to change. -1 to cancel");
            if(EXIT) return;
        }
        else
        {
            changeId = res;
        }

        if(changeId == -1) return;

        bool success;
        computer comp = ps.getComputerById(changeId, success);

        if (!success)
        {
            cout << endl << "Computer not found" << endl;
            return;
        }

        string name = getInputString("Enter name: ", MULTI);
        if(EXIT) return;

        string nationality = getValidNationality("Enter nationality: (empty for no change)");
        if (nationality.empty()) return;

        string info = getInputString("Enter info: ", MULTI);
        if(EXIT) return;

        bool built = getInputInt("Was it built, 0 for no, 1 for yes: ");
        if(EXIT) return;

        int buildyear = -1;

        if (built)
        {
            buildyear = getInputInt("When was it built: ", AL_KHWARIZMI, utils::getCurrentYear());
            if(EXIT) return;
        }
        else
        {
            buildyear = 0;
        }

        string type = getInputString("Enter machine type: ", MULTI);
        if(EXIT) return;

        if (!name.empty()) comp.setName(name);
        if (!nationality.empty()) comp.setNationality(nationality);
        if (!info.empty()) comp.setInfo(info);
        comp.setBuilt(built);
        if (buildyear != -1) comp.setBuildYear(buildyear);
        if (!type.empty()) comp.setType(type);

        ps.updateComputer(comp);
    }

    cout << Color::GREEN << choice << " changed!" << Color::PURPLE << endl;
}

//This function allows you to remove one or more persons/computers from the list.
void consoleui::removeMenu(string choice)
{
    int res, removeId;

    if (choice != "connections" && choice != "nationalities" && choice != "computer_types")
    {
        res = searchMenu(choice);
        if(EXIT) return;
    }

    if(choice == "persons")
    {
        if (res == -1)
        {
            removeId = getInputInt("Please Enter ID of person you want to remove. -1 to cancel");
            if(EXIT) return;
        }
        else
        {
            removeId = res;
        }

        if(removeId == -1) return;

        ps.removePerson(removeId);
    }
    else if(choice == "computers")
    {
        if (res == -1)
        {
            removeId = getInputInt("Please enter ID of computer you want to remove. -1 to cancel");
            if(EXIT) return;
        }
        else
        {
            removeId = res;
            if(EXIT) return;
        }

        if(removeId == -1) return;

        ps.removeComputer(removeId);
    }
    else if(choice == "connections")
    {
        string sub_choice = getInputString("persons|computers", SINGLE, "persons|computers");
        if(EXIT) return;

        int pid, cid;

        if(sub_choice == "persons")
        {
            pid = searchMenu(sub_choice);

            bool noerr;

            person p_temp = ps.getPersonById(pid, noerr);

            if(!noerr)
            {
                cout << Color::RED << "Invalid person" << Color::PURPLE << endl;
                removeMenu(choice);
                return;
            }

            vector<computer> connected_computers = ps.getComputersConnectedWithPerson(p_temp);

            printComputers(connected_computers);

            cid = getInputInt("Please enter ID of computer");

        }
        else if(sub_choice == "computers")
        {
            cid = searchMenu(sub_choice);

            bool noerr;

            computer c_temp = ps.getComputerById(cid, noerr);

            if(!noerr)
            {
                cout << Color::RED << "Invalid computer" << Color::PURPLE << endl;
                removeMenu(choice);
                return;
            }

            vector<person> connected_persons = ps.getPersonsConnectedWithComputer(c_temp);

            printPersons(connected_persons);

            pid = getInputInt("Please enter ID of person");
        }

        bool noerr;

        ps.removeConnection(pid, cid, noerr);

        if(!noerr)
        {
            cout << Color::RED << "Error, invalid selection" << Color::PURPLE << endl;
        }
    }
    else if(choice == "nationalities")
    {
        listMenu(choice);

        string to_remove = getInputString("Please specify the nationality to remove: ", MULTI);
        if(EXIT) return;

        if(ps.getNationalityById(to_remove) == 0)
        {
            cout << Color::RED << "That nationality does not exist." << Color::PURPLE << endl;
            cin.get();
            removeMenu(choice);
            return;
        }

        ps.removeNationality(to_remove);
    }
    else if(choice == "computer_types")
    {
        listMenu(choice);

        string to_remove = getInputString("Please specify the Computer Type to remove: ", MULTI);
        if(EXIT) return;

        if(ps.getComputerTypeById(to_remove) == 0)
        {
            cout << Color::RED << "That computer type does not exist." << Color::PURPLE << endl;
            cin.get();
            removeMenu(choice);
            return;
        }

        ps.removeComputerType(to_remove);
    }

    cout << Color::GREEN << choice << " removed!" << endl;
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
    if(EXIT) return;

    cout << endl;
    cout << VALID_SORT_COMMANDS << endl;
    cout << endl;

    order = getInputString(NO_MESS,SINGLE, VALID_SORT_COMMANDS);
    if(EXIT) return;

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
    if(EXIT) return -1;

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
        if(EXIT) return -1;
    }
    else if (column == "birth_year" || column == "death_year" || column == "build_year")
    {
        search_string = to_string(getInputInt("Input year: ", AL_KHWARIZMI, utils::getCurrentYear()));
        if(EXIT) return -1;
    }
    else if (column == "id")
    {
        search_string = to_string(getInputInt("Enter id: "));
        if(EXIT) return -1;
        column = choice + ".id";
    }
    else if(column == "built")
    {
        cout << endl;
        search_string = getInputString("true|false: ", MULTI);
        if(EXIT) return -1;
    }
    else
    {
        search_string = getInputString("Input searchstring: ", MULTI);
        if(EXIT) return -1;
    }

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
    if(EXIT) return;
    int infoId;

    if(choice == "persons")
    {
        person infoPerson;
        string infoPrint;

        if (res == -1)
        {
            infoId = getInputInt("Please enter ID of person you want information about. -1 to cancel");
            if(EXIT) return;
        }
        else
        {
            infoId = res;
        }

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
        {
            infoId = getInputInt("Please enter ID of computer you want information about -1 to cancel");
            if(EXIT) return;
        }
        else
        {
            infoId = res;
        }

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

    Color::Modifier primaryColor = Color::BLUE;
    Color::Modifier secondaryColor = Color::LBLUE;

    cout << primaryColor;
    tablePrint(to_string(p.getId()), restWidth);

    cout << secondaryColor;
    tablePrint(p.getName(), nameWidth);

    cout << primaryColor;
    tablePrint(sex, restWidth);

    cout << secondaryColor;
    tablePrint(to_string(p.getBirthYear()), restWidth);

    cout << primaryColor;
    tablePrint(death, restWidth);

    cout << secondaryColor;
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

    Color::Modifier primaryColor = Color::YELLOW;
    Color::Modifier secondaryColor = Color::LGREEN;

    cout << primaryColor;

    tablePrint(to_string(c.getId()), restWidth);

    cout << secondaryColor;
    tablePrint(c.getName(), nameWidth);

    cout << primaryColor;
    tablePrint(buildYear, restWidth);

    cout << secondaryColor;
    tablePrint(c.getType(), typeWidth);

    cout << primaryColor;
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

    tablePrint("Born: ", restWidth);
    tablePrint(birth, restWidth);
    cout << endl;

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

    cout << Color::BLUE;
    cout << utils::wordWrap(info, pageWidth);

    cout << Color::LBLUE;
    cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

    cout << endl;

    vector<computer> computers_connected = ps.getComputersConnectedWithPerson(p);

    if(computers_connected.size() > 0)
    {
        cout << Color::LBLUE;
        tablePrint("Associated Computers", restWidth);
        cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

        for(computer c : computers_connected)
        {
            cout << Color::BLUE;
            cout << c.getName() << endl;
        }

        cout << Color::LBLUE;
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

    cout << Color::LGREEN;
    tablePrint("Type: ", restWidth);
    tablePrint(type, restWidth);
    cout << endl;

    tablePrint("Nationality: ", restWidth);
    tablePrint(nationality, restWidth);
    cout << endl;

    tablePrint("Built: ", restWidth);
    tablePrint(buildYear, restWidth);
    cout << endl;

    cout << Color::YELLOW;
    cout << endl;
    tablePrint("Information ", restWidth);
    cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

    cout << Color::LGREEN;
    cout << utils::wordWrap(info, pageWidth);

    cout << Color::YELLOW;
    cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

    cout << endl;

    vector<person> persons_connected = ps.getPersonsConnectedWithComputer(c);

    if(persons_connected.size() > 0)
    {
        cout << Color::YELLOW;
        tablePrint("Associated People", restWidth);
        cout << endl << left << setw(pageWidth) << setfill('-') << "" << endl;

        for(person p : persons_connected)
        {
            cout << Color::LGREEN;
            cout << p.getName() << endl;
        }

        cout << Color::YELLOW;
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
    tablePrint("Built", restWidth);
    tablePrint("Computer Type", typeWidth);
    tablePrint("Nationality", restWidth);

    cout << endl << endl;

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
    tablePrint("Built", restWidth);
    tablePrint("Computer Type", typeWidth);
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
        {
            continue;
        }

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
        cout << Color::PURPLE << message << endl;
    }

    string input;
    getline(cin, input);

    input = utils::removeWhiteSpace(input);

    if(input == INPUT_ENDER)
    {
        EXIT = true;
        return input;
    }


    if(!multiToken && utils::split(input, ' ').size() > 1)
    {
        cout << endl << Color::RED << "Multiple tokens detected in buffer, please try again." << Color::PURPLE << endl;

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
        else if(allow_number && utils::isStrInt(input))
        {
            return input;
        }

        cout << endl << Color::RED << "Invalid input, please try again." << Color::PURPLE << endl << endl;

        return getInputString(message, multiToken, expected, allow_number);
    }

    cout << Color::PURPLE;
}

//Receives input from user and validates the input
int consoleui::getInputInt(string message, int low_bound, int high_bound, bool allow_empty)
{

    if(message != NO_MESS)
    {
        cout << Color::PURPLE << message << endl;
    }

    string input;
    getline(cin, input);
    input = utils::removeWhiteSpace(input);

    //LAZY HACK FIX
    if(input == "0") return 0;
    if(input == "-1") return -1;

    if(input == "" && allow_empty)
    {
        return 0;
    }

    if(input == INPUT_ENDER || (input == "0" && low_bound > 0))
    {
        EXIT = true;
        return INT_MIN;
    }

    while(utils::isStrInt(input) == false)
    {
            cout << endl << Color::RED << "Invalid input it must be a number." << endl;
            return getInputInt(message, low_bound, high_bound);
    }

    int input_as_int = stoi(input);

    if(input_as_int > high_bound || input_as_int < low_bound)
    {
        cout << Color::RED
             << "Input out of bounds, please try again."
             << Color::YELLOW
             << " Limits are: " << low_bound << ", " << high_bound
             << Color::PURPLE
             << endl;

        return getInputInt(message, low_bound, high_bound);
    }

    return input_as_int;
}
