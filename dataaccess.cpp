#include "dataaccess.h"
#include <iostream>

dataaccess::dataaccess()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "FamousProgrammers.sqlite";
    db.setDatabaseName(dbName);

    if(!db.open()) std::cerr << "Error: SQL did not open properly!" << std::endl;
}

// Splits a string into a vector of strings with a specified delimiter.
// Example: split this string becomes [split, this, string]
std::vector<std::string> split(const std::string &s, char delim)
{

    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> tokens;

    while (std::getline(ss, item, delim))
    {
        tokens.push_back(item);
    }

    return tokens;
}

int getNationalityID(std::string nationality)
{
    QSqlQuery query(db);

    query.exec("SELECT id FROM nationality n WHERE n.nationality = " + nationality);

    return query.value("id");
}

std::vector<person> dataaccess::getPersonsByQuery(QString q)
{
   QSqlQuery query(db);

   query.exec(q);

   std::vector<person> persons;

   while(query.next())
   {
       std::string name = query.value("Name").toString().toStdString();
       std::string sex = query.value("Sex").toString().toStdString();
       int birthyear = query.value("Birth_Year").toUInt();
       int deathyear = query.value("Death_Year").toUInt();
       std::string nationality = query.value("Nationality").toString().toStdString();
       std::string info = query.value("Description").toString().toStdString();

       persons.push_back(person(name, sex, birthyear, deathyear, nationality, info));
   }

   return persons;
}

void dataaccess::addPerson(person p)
{
    QSqlQuery query(db);

    QString q = QString::fromStdString("INSERT INTO persons(name, sex, birthyear, deathyear, nationality, info) VALUES("
                + p.getName() + "," + p.getSex() + "," + std::to_string(p.getBirthYear()) + ","
                + std::to_string(p.getDeathYear()) + "," + std::to_string(getNationalityID(p.getNationality())) + "," + p.getInfo() + ")");

    query.exec(q);
}

void dataaccess::addComputer(computer c)
{
    QSqlQuery query(db);

    QString

    QString q = QString::fromStdString("INSERT INTO Computers(name, build_year, computer_type, built, nationalityID, info) VALUES("
                + p.getName() + "," + p.getSex() + "," + std::to_string(p.getBirthYear()) + ","
                + std::to_string(p.getBuilt()) + "," + std::to_string(getNationalityID(p.getNationality())) + "," + p.getInfo() + ")");

    query.exec(q);
}
