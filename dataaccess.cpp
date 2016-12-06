#include "dataaccess.h"
#include <iostream>

dataaccess::dataaccess()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = QString::fromStdString(DATABASE);
    db.setDatabaseName(dbName);

    if(!db.open()) std::cerr << "Error: SQL did not open properly!" << std::endl;
}

int dataaccess::getNationalityID(std::string nationality)
{
    QSqlQuery query(db);

    query.exec(QString::fromStdString("SELECT * FROM nationality n WHERE n.nationality = \"" + nationality + "\""));

    //If country is found, return first match
    if(query.next()) return query.value("ID").toUInt();

    //If no match, return id for nationality "UNKNOWN"
    return 0;
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

    bool noerr;

    noerr = query.prepare("INSERT INTO Persons (name, sex, birth_year, death_year, nationalityID, info) "
                          "VALUES (:name, :sex, :birth_year, :death_year, :nationalityID, :info)");
    if(!noerr) std::cerr << "Query did not prepare successfully." << std::endl;

    query.bindValue(":name", QString::fromStdString(p.getName()));
    query.bindValue(":sex", QString::fromStdString(p.getSex()));
    query.bindValue(":birth_year", QString::fromStdString(std::to_string(p.getBirthYear())));
    query.bindValue(":death_year", QString::fromStdString(std::to_string(p.getDeathYear())));
    query.bindValue(":nationalityID", QString::fromStdString(std::to_string(getNationalityID(p.getNationality()))));
    query.bindValue(":info", QString::fromStdString(p.getInfo()));

    query.exec();
}

void dataaccess::addComputer(computer c)
{
    QSqlQuery query(db);

    bool noerr;

    noerr = query.prepare("INSERT INTO Computers(name, build_year, computer_type, built, nationalityID, info) "
                          "VALUES(:name,:build_year, :computer_type, :built,:nationalityID,:info)");
    if(!noerr) std::cerr << "Query did not prepare successfully." << std::endl;

    query.bindValue(":name", QString::fromStdString(c.getName()));
    query.bindValue(":build_year", QString::fromStdString(std::to_string(c.getBuildYear())));
    query.bindValue(":computer_type", QString::fromStdString(c.getType()));
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

std::vector<person> dataaccess::execQueryPerson(QSqlQuery query)
{
    query.exec();

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

std::vector<computer> dataaccess::execQueryComputer(QSqlQuery query)
{
    query.exec();

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


std::vector<person> dataaccess::searchPersons(std::vector<std::string> args)
{
    if (args.size() < 3) {
        std::cerr << "Too few arguments to searchPersons";
        return std::vector<person>();
    }

    QString q_string = QString::fromStdString("SELECT * FROM persons JOIN Nationality n ON n.id = nationalityid WHERE " + args[1]);
    QSqlQuery query(db);

    bool noerr;

    if (args[1] == "birth_year" || args[1] == "death_year") {
        q_string += QString::fromStdString(" = :arg");
        noerr = query.prepare(q_string);
        query.bindValue(":arg", std::stoi(args[2]));
    } else {
        q_string += QString::fromStdString(" LIKE :arg");
        args[2] = "%" + args[2] + "%";
        noerr = query.prepare(q_string);
        query.bindValue(":arg", QString::fromStdString(args[2]));
    }

    if (noerr)
        std::cerr << "SHITTING SHIT" << endl;

    return execQueryPerson(query);
}

std::vector<computer> dataaccess::searchComputers(std::vector<std::string> args)
{
    if (args.size() < 3) {
        std::cerr << "Too few arguments to searchPersons";
        return std::vector<computer>();
    }

    QString q_string = QString::fromStdString("SELECT * FROM computers JOIN Nationality n ON n.id = nationalityid WHERE " + args[1]);
    QSqlQuery query(db);

    bool noerr;

    if (args[1] == "build_year") {
        q_string += QString::fromStdString(" = :arg");
        noerr = query.prepare(q_string);
        query.bindValue(":arg", std::stoi(args[2]));
    } else {
        q_string += QString::fromStdString(" LIKE :arg");
        args[2] = "%" + args[2] + "%";
        noerr = query.prepare(q_string);
        query.bindValue(":arg", QString::fromStdString(args[2]));
    }

    if (noerr)
        std::cerr << "SHITTING SHIT" << endl;

    return execQueryComputer(query);
}
