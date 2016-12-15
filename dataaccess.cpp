#include "dataaccess.h"

dataaccess::dataaccess()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = QString::fromStdString(DATABASE);
    db.setDatabaseName(dbName);

    if(!db.open()) std::cerr << "Error: SQL did not open properly!" << std::endl;
}

dataaccess::~dataaccess()
{
    db.close();
}

//Searches for nationality and if found returns the nationality's ID
//else it returns 0 which is the id for Unkown
int dataaccess::getNationalityID(QString nationality)
{
    QSqlQuery query(db);

    query.prepare(QString::fromStdString("SELECT * FROM nationality n WHERE n.nationality LIKE :nat"));
    query.bindValue(":nat", nationality);
    query.exec();

    //If country is found, return first match
    if(query.next()) return query.value("ID").toUInt();

    return 0;
}

//Searches for computer type and if found returns the computer type's ID
//if it is not found it returns 0
int dataaccess::getComputer_TypeID(QString computer_type)
{
    QSqlQuery query(db);

    query.prepare(QString::fromStdString("SELECT * FROM Computer_Types cp WHERE cp.Computer_Type LIKE :comp_type"));
    query.bindValue(":comp_type", computer_type);
    query.exec();

    //If computer type is found, return first match
    if(query.next()) return query.value("ID").toUInt();

    //If no match, return id for computer type "UNKNOWN"
    return 0;
}

std::vector<person> dataaccess::getPersons()
{
    QSqlQuery query(db);

    QString q = "SELECT * FROM Persons p JOIN Nationality n ON p.NationalityID = n.ID";

    bool noerr = query.prepare(q);
    if(!noerr) std::cerr << "Query did not prepare successfully" << std::endl;

    return execQueryPerson(query);
}

std::vector<computer> dataaccess::getComputers()
{
    QSqlQuery query(db);

    QString q =  "SELECT * FROM Computers c JOIN Nationality n ON c.NationalityID = n.ID JOIN Computer_Types cp ON c.Computer_TypeID = cp.ID";

    bool noerr = query.prepare(q);
    if(!noerr) std::cerr << "Query did not prepare successfully" << std::endl;

    return execQueryComputer(query);
}

std::vector<QString> dataaccess::getNationalities()
{
    QSqlQuery query(db);

    QString q =  "SELECT Nationality FROM Nationality ORDER BY Nationality";

    bool noerr = query.prepare(q);
    if(!noerr) std::cerr << "Query did not prepare successfully" << std::endl;

    return execQueryNat(query);
}

std::vector<QString> dataaccess::getComputerTypes()
{
    QSqlQuery query(db);

    QString q =  "SELECT Computer_Type FROM Computer_Types";

    bool noerr = query.prepare(q);
    if(!noerr) std::cerr << "Query did not prepare successfully" << std::endl;

    return execQueryComp(query);
}

std::vector<person> dataaccess::getPersonsByQuery(QString q)
{
   QSqlQuery query(db);

   query.exec(q);

   return execQueryPerson(query);
}

std::vector<computer> dataaccess::getComputersByQuery(QString q)
{
   QSqlQuery query(db);

   query.exec(q);

   return execQueryComputer(query);
}

//Adds an instance of person to the Persons table in the database
int dataaccess::addPerson(person p)
{
    QSqlQuery query(db);

    bool noerr;

    noerr = query.prepare("INSERT INTO Persons (name, sex, birth_year, death_year, nationalityID, info) "
                          "VALUES (:name, :sex, :birth_year, :death_year, :nationalityID, :info)");
    if(!noerr) std::cerr << "Query did not prepare successfully." << std::endl;

    query.bindValue(":name", p.getName());
    query.bindValue(":sex", p.getSex());
    query.bindValue(":birth_year", QString::number(p.getBirthYear()));
    query.bindValue(":death_year", QString::number(p.getDeathYear()));
    query.bindValue(":nationalityID", QString::number(getNationalityID(p.getNationality())));
    query.bindValue(":info", p.getInfo());

    query.exec();
    if (query.lastInsertId() > 1)
        return query.lastInsertId().toInt();
    else
        return 0;
}

//Adds an instance of computer to the Computers table in the database
int dataaccess::addComputer(computer c)
{
    QSqlQuery query(db);

    bool noerr;

    noerr = query.prepare("INSERT INTO Computers(name, build_year, computer_typeID, built, nationalityID, info) "
                          "VALUES(:name,:build_year, :computer_typeID, :built,:nationalityID,:info)");
    if(!noerr) std::cerr << "Query did not prepare successfully." << std::endl;

    query.bindValue(":name", c.getName());
    query.bindValue(":build_year", QString::number(c.getBuildYear()));
    query.bindValue(":computer_typeID", QString::number(getComputer_TypeID(c.getType())));
    query.bindValue(":built", c.getBuilt()?"TRUE":"FALSE");
    query.bindValue(":nationalityID", QString::number(getNationalityID(c.getNationality())));
    query.bindValue(":info", c.getInfo());

    query.exec();
    if (query.lastInsertId() > 1)
        return query.lastInsertId().toInt();
    else
        return 0;
}

//Adds a connection to the Connections table in the database
void dataaccess::addConnection(int comp_id, int person_id)
{
    QSqlQuery query(db);

    bool noerr;

    noerr = query.prepare("INSERT INTO Connections(ComputersID, PersonsID) "
                          "VALUES(:comp_id,:person_id)");
    if(!noerr) std::cerr << "Query did not prepare successfully." << std::endl;

    query.bindValue(":comp_id", comp_id);
    query.bindValue(":person_id", person_id);

    query.exec();
}

//Adds a nationality to the Nationality table in the database
void dataaccess::addNationality(QString nationality)
{
    QSqlQuery query(db);

    bool noerr;

    noerr = query.prepare("INSERT INTO Nationality(Nationality) "
                          "VALUES(:nationality)");
    if(!noerr) std::cerr << "Query did not prepare successfully." << std::endl;

    query.bindValue(":nationality", nationality);

    query.exec();
}

//Adds a computer type to the Computer_Types table in the database
void dataaccess::addComputerType(QString comp_type)
{
    QSqlQuery query(db);

    bool noerr;

    noerr = query.prepare("INSERT INTO Computer_Types(Computer_Type) "
                          "VALUES(:comp_type)");
    if(!noerr) std::cerr << "Query did not prepare successfully." << std::endl;

    query.bindValue(":comp_type", (comp_type));

    query.exec();
}

//Removes a person from the Persons table in the database
void dataaccess::removePerson(int id)
{
    QSqlQuery query(db);

    bool noerr;

    noerr = query.prepare("DELETE FROM persons WHERE id = :id");

    if(!noerr) std::cerr << "Query did not prepare successfully" << std::endl;

    query.bindValue(":id", id);
    query.exec();
}

//Removes a computer from the Computers table in the database
void dataaccess::removeComputer(int id)
{
    QSqlQuery query(db);

    bool noerr;

    noerr = query.prepare("DELETE FROM computers WHERE id = :id");

    if(!noerr) std::cerr << "Query did not prepare successfully" << std::endl;

    query.bindValue(":id", id);
    query.exec();
}

//Removes a connection from the Connections table in the database
void dataaccess::removeConnection(int pid, int cid)
{
    QSqlQuery query(db);

    bool noerr = query.prepare("DELETE FROM connections WHERE computersid = :cid AND personsid = :pid");
    if(!noerr) std::cerr << "Query did not prepare successfully" << std::endl;

    query.bindValue(":cid", cid);
    query.bindValue(":pid", pid);

    query.exec();
}

/*void dataaccess::removeNationality(QString nationality)
{
    QSqlQuery query(db);

    bool noerr = query.prepare("DELETE FROM Nationality WHERE nationality = :nationality");
    if(!noerr) std::cerr << "Query did not prepare successfully" << std::endl;

    query.bindValue(":nationality", nationality);

    query.exec();
}

void dataaccess::removeComputerType(QString computer_type)
{
    QSqlQuery query(db);

    bool noerr = query.prepare("DELETE FROM Computer_Types WHERE Computer_Type = :comptype");
    if(!noerr) std::cerr << "Query did not prepare successfully" << std::endl;

    query.bindValue(":comptype", computer_type);

    query.exec();
}*/

std::vector<person> dataaccess::execQueryPerson(QSqlQuery query)
{
    query.exec();

    std::vector<person> persons;

    while(query.next())
    {
        int id = query.value("ID").toUInt();
        QString name = query.value("Name").toString();
        QString sex = query.value("Sex").toString();
        int birthyear = query.value("Birth_Year").toUInt();
        int deathyear = query.value("Death_Year").toUInt();
        bool alive = query.value("alive").toBool();
        QString nationality = query.value("Nationality").toString();
        QString info = query.value("Info").toString();

        persons.push_back(person(name, sex, birthyear, deathyear, alive, nationality, info, id));
    }

    return persons;

}

std::vector<computer> dataaccess::execQueryComputer(QSqlQuery query)
{
    query.exec();

    std::vector<computer> computers;

    while(query.next())
    {
        QString name = query.value("Name").toString();
        int build_year = query.value("Build_Year").toUInt();
        QString computer_type = query.value("Computer_Type").toString();
        bool built = query.value("Built").toBool();
        QString nationality = query.value("Nationality").toString();
        QString info = query.value("Info").toString();
        unsigned int id = query.value("ID").toUInt();

        computers.push_back(computer(name, build_year, computer_type, built, nationality, info, id));
    }

    return computers;

}

std::vector<QString> dataaccess::execQueryNat(QSqlQuery query)
{
    query.exec();

    std::vector<QString> nationalities;

    while(query.next())
    {
        QString nationality = query.value("Nationality").toString();

        nationalities.push_back(nationality);
    }

    return nationalities;
}

std::vector<QString> dataaccess::execQueryComp(QSqlQuery query)
{
    query.exec();

    std::vector<QString> comp_types;

    while(query.next())
    {
        QString comp_type = query.value("Computer_Type").toString();

        comp_types.push_back(comp_type);
    }

    return comp_types;
}

std::vector<person> dataaccess::searchPersons(std::vector<QString> args)
{
    if (args.size() < 3) {
        std::cerr << "Too few arguments to searchPersons";
        return std::vector<person>();
    }

    QString q_string = "SELECT * FROM persons JOIN Nationality n ON n.id = nationalityid WHERE " + args[1];
    QSqlQuery query(db);

    bool noerr;

    if (args[1] == "birth_year" || args[1] == "death_year" || args[1] == "persons.id") {
        q_string += QString::fromStdString(" = :arg");
        noerr = query.prepare(q_string);
        query.bindValue(":arg", args[2].toUInt());
    } else {
        q_string += QString::fromStdString(" LIKE :arg");
        args[2] = "%" + args[2] + "%";
        noerr = query.prepare(q_string);
        query.bindValue(":arg", args[2]);
    }

    if (!noerr)
        std::cerr << "Query did not prepare successfully." << std::endl;

    return execQueryPerson(query);
}

std::vector<computer> dataaccess::searchComputers(std::vector<QString> args)
{
    if (args.size() < 3) {
        std::cerr << "Too few arguments to searchComputers";
        return std::vector<computer>();
    }

    QString q_string = "SELECT * FROM computers c JOIN Nationality n ON n.id = c.nationalityid JOIN Computer_Types cp ON c.Computer_TypeID = cp.ID WHERE " + args[1];
    QSqlQuery query(db);

    bool noerr;

    if (args[1] == "build_year" || args[1] == "computers.id") {
        q_string += QString::fromStdString(" = :arg");
        noerr = query.prepare(q_string);
        query.bindValue(":arg", args[2].toUInt());
    } else {
        q_string += QString::fromStdString(" LIKE :arg");
        args[2] = "%" + args[2] + "%";
        noerr = query.prepare(q_string);
        query.bindValue(":arg", args[2]);
    }

    if (!noerr)
        std::cerr << "Query did not prepare successfully." << std::endl;

    return execQueryComputer(query);
}

std::vector<person> dataaccess::filterPersons(QString search_string)
{
    QString q_string = "SELECT * FROM persons p JOIN Nationality n ON n.id = p.nationalityid WHERE "
                       "name LIKE :name OR sex LIKE :sex OR n.nationality LIKE :nationality OR "
                       "birth_year LIKE :birth_year OR death_year LIKE :death_year";

    QSqlQuery query(db);

    bool noerr = query.prepare(q_string);

    QString search_as_string = "%" + search_string + "%";
    query.bindValue(":name", search_as_string);
    query.bindValue(":sex", search_as_string);
    query.bindValue(":nationality", search_as_string);
    query.bindValue(":birth_year", search_as_string);
    query.bindValue(":death_year", search_as_string);

    if (!noerr)
        std::cerr << "Query did not prepare successfully." << std::endl;

    return execQueryPerson(query);
}

std::vector<computer> dataaccess::filterComputers(QString search_string)
{
    QString q_string = "SELECT * FROM computers c JOIN Nationality n ON n.id = c.nationalityid JOIN Computer_Types cp ON c.Computer_TypeID = cp.ID WHERE "
                       "name LIKE :name OR cp.computer_type LIKE :type OR n.nationality LIKE :nationality OR "
                       "build_year LIKE :build_year OR built LIKE :built";

    QSqlQuery query(db);

    bool noerr = query.prepare(q_string);

    QString search_as_string = "%" + search_string + "%";
    query.bindValue(":name", search_as_string);
    query.bindValue(":type", search_as_string);
    query.bindValue(":nationality", search_as_string);
    query.bindValue(":build_year", search_as_string);
    query.bindValue(":built", search_as_string);

    if (!noerr)
        std::cerr << "Query did not prepare successfully." << std::endl;

    return execQueryComputer(query);
}

person dataaccess::getPersonById(unsigned int id, bool &success)
{
    QString q_string = QString::fromStdString("SELECT * FROM persons JOIN Nationality n ON n.id = nationalityid WHERE persons.id = :id");
    QSqlQuery query(db);

    success = query.prepare(q_string);
    query.bindValue(0, id);

    std::vector<person> p = execQueryPerson(query);
    if (p.size() > 0)
    {
        success = true;
        return p.at(0);
    }
    else
    {
        success = false;
        return person();
    }
}

computer dataaccess::getComputerById(unsigned int id, bool &success)
{
    QString q_string = "SELECT * FROM computers c JOIN Nationality n ON n.id = nationalityid JOIN Computer_Types cp ON c.Computer_TypeID = cp.ID WHERE c.id = :id";
    QSqlQuery query(db);

    success = query.prepare(q_string);
    query.bindValue(0, id);

    std::vector<computer> c = execQueryComputer(query);
    if (c.size() > 0)
    {
        success = true;
        return c.at(0);
    }
    else
    {
        success = false;
        return computer();
    }
}

std::vector<person> dataaccess::getPersonsByComputerId(unsigned int id, bool &success)
{
    QSqlQuery query(db);
    QString q_string =    "SELECT * FROM Persons p "
                          "JOIN Nationality n ON n.id = p.nationalityid "
                          "JOIN Connections con ON con.personsid = p.id "
                          "JOIN Computers c ON con.computersid = c.id "
                          "JOIN Computer_Types cp ON c.Computer_TypeID = cp.ID "
                          "WHERE c.id = :id";

    success = query.prepare(q_string);
    query.bindValue(0, id);

    std::vector<person> p = execQueryPerson(query);

    return p;
}

std::vector<computer> dataaccess::getComputersByPersonId(unsigned int id, bool &success)
{
    QSqlQuery query(db);
    QString q_string = "SELECT * FROM Computers c "
                                              "JOIN Nationality n ON n.id = c.nationalityid "
                                              "JOIN Connections con ON con.computersid = c.id "
                                              "JOIN Persons p ON con.personsid = p.id "
                                              "JOIN Computer_Types cp ON c.Computer_TypeID = cp.ID "
                                              "WHERE p.id = :id";

    success = query.prepare(q_string);
    query.bindValue(0, id);

    std::vector<computer> c = execQueryComputer(query);

    return c;
}

void dataaccess::updatePerson(person p)
{

    QSqlQuery query(db);

    bool noerr;

    noerr = query.prepare("UPDATE Persons "
                          "SET "
                          "name=:name, "
                          "sex=:sex, "
                          "nationalityid=:nationalityid, "
                          "birth_year=:birth_year, "
                          "death_year=:death_year, "
                          "alive=:alive, "
                          "info=:info "
                          "WHERE id = :id");
    if(!noerr) std::cerr << "Query did not prepare successfully." << std::endl;

    query.bindValue(":name", p.getName());
    query.bindValue(":sex", p.getSex());
    query.bindValue(":nationalityid", getNationalityID(p.getNationality()));
    query.bindValue(":birth_year", QString::number(p.getBirthYear()));
    query.bindValue(":death_year", QString::number(p.getDeathYear()));
    query.bindValue(":alive", (p.getAlive())?("TRUE"):("FALSE"));
    query.bindValue(":info", p.getInfo());
    query.bindValue(":id", p.getId());

    query.exec();
}

void dataaccess::updateComputer(computer c)
{
    QSqlQuery query(db);

    bool noerr;

    noerr = query.prepare("UPDATE Computers "
                          "SET "
                          "name=:name, "
                          "nationalityid=:nationalityid, "
                          "build_year=:build_year, "
                          "computer_typeID=:computer_typeID, "
                          "built=:built, "
                          "info=:info "
                          "WHERE id = :id");
    if(!noerr) std::cerr << "Query did not prepare successfully." << std::endl;

    query.bindValue(":name", c.getName());
    query.bindValue(":nationalityid", getNationalityID(c.getNationality()));
    query.bindValue(":build_year", QString::number(c.getBuildYear()));
    query.bindValue(":computer_typeID", getComputer_TypeID(c.getType()));
    query.bindValue(":built", c.getBuilt()?"TRUE":"FALSE");
    query.bindValue(":info", c.getInfo());
    query.bindValue(":id", c.getId());

    query.exec();
}

std::vector<person> dataaccess::sortPersons(QString column, QString order)
{
    QSqlQuery query(db);

    QString q_string = "SELECT * FROM Persons p JOIN Nationality n ON p.NationalityId = n.id ORDER BY " + column + " COLLATE NOCASE " + order;
    // cannot bind order, cuz stuff
    bool noerr = query.prepare(q_string);
    if (!noerr) std::cerr << "Query did not prepare successfully";
    //query.bindValue(":column", column);

    return execQueryPerson(query);
}

std::vector<computer> dataaccess::sortComputers(QString column, QString order)
{
    QSqlQuery query(db);

    QString q_string = "SELECT * FROM Computers c JOIN Nationality n ON c.NationalityId = n.id JOIN Computer_Types cp ON c.Computer_TypeID = cp.ID ORDER BY " + column + " COLLATE NOCASE " + order;
    // cannot bind order, cuz stuff
    bool noerr = query.prepare(q_string);
    if (!noerr) std::cerr << "Query did not prepare successfully";
    //query.bindValue(":column", column));

    return execQueryComputer(query);
}
