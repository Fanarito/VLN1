#include "dataaccess.h"
#include <iostream>

dataaccess::dataaccess()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "CompSci.sqlite";
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

int dataaccess::getNationalityID(std::string nationality)
{
    QSqlQuery query(db);

    query.exec(QString::fromStdString("SELECT * FROM nationality n WHERE n.nationality = \"" + nationality + "\""));

    query.first();

    return query.value("ID").toUInt();
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
       std::string info = query.value("Info").toString().toStdString();

       persons.push_back(person(name, sex, birthyear, deathyear, nationality, info));
   }

   return persons;
}


std::vector<computer> dataaccess::getComputersByQuery(QString q)
{
   QSqlQuery query(db);

   query.exec(q);

   std::vector<computer> computers;

   while(query.next())
   {
       std::string name = query.value("Name").toString().toStdString();
       int build_year = query.value("Build_Year").toUInt();
       std::string computer_type = query.value("Computer_Type").toString().toStdString();
       bool built = query.value("Built").toBool();
       std::string nationality = query.value("Nationality").toString().toStdString();
       std::string info = query.value("Info").toString().toStdString();

       computers.push_back(computer(name, build_year, computer_type, built, nationality, info));
   }

   return computers;
}
void dataaccess::addPerson(person p)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO Persons(name, sex, birth_year, death_year, built, nationalityID, info) VALUES(:name,:sex,:birth_year,:death_year,:nationalityID,:info");
    query.bindValue(":name", QString::fromStdString(p.getName()));
    query.bindValue(":birth_year", QString::fromStdString(std::to_string(p.getBirthYear())));
    query.bindValue(":death_year", QString::fromStdString(std::to_string(p.getDeathYear())));
    query.bindValue(":nationalityID", QString::fromStdString(std::to_string(getNationalityID(p.getNationality()))));
    query.bindValue(":info", QString::fromStdString(p.getInfo()));

    query.exec();
}

void dataaccess::addComputer(computer c)
{
    QSqlQuery query(db);

    query.prepare("INSERT INTO Computers(name, build_year, computer_type, built, nationalityID, info) VALUES(:name,:build_year,:built,:nationalityID,:info");
    query.bindValue(":name", QString::fromStdString(c.getName()));
    query.bindValue(":build_year", QString::fromStdString(std::to_string(c.getBuildYear())));
    query.bindValue(":built", QString::fromStdString(c.getBuilt()?"TRUE":"FALSE"));
    query.bindValue(":nationalityID", QString::fromStdString(std::to_string(getNationalityID(c.getNationality()))));
    query.bindValue(":info", QString::fromStdString(c.getInfo()));

    query.exec();
}

void dataaccess::removePerson(person p)
{
    QSqlQuery query(db);

    query.prepare("DELETE FROM persons WHERE id = :id");
    query.bindValue(":id", p.getId());
    query.exec();
}
