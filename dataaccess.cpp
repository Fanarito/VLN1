#include "dataaccess.h"
#include <iostream>

dataaccess::dataaccess()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "student_db.sqlite";
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

std::vector<person> dataaccess::getPersonsByQuery(string q)
{
   QSqlQuery query(db);

   query.exec(q);

   std::vector<person> persons;

   while(query.next())
   {
       string name = query.value("name").toString().toStdString();
       string sex = query.value("sex").toString().toStdString();
       int birthyear = query.value("birthyear").toUInt();
       int deathyear = query.value("deathyear").toUInt();
       string nationality = query.value("nationality").toString.toStdString();
       string info = query.value("info").toString.toStdString();

       persons.push_back(person(name, sex, birthyear, deathyear, nationality, info));
   }

   return persons;
}
