#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include <QStandardItem>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllPersons();
    displayAllComputers();
    displayPersonsConnections();
    displayComputersConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllPersons()
{
    vector<person> persons = s.getPersons();
    displayPersons(persons);
}

void MainWindow::displayPersons(vector<person> persons)
{
    ui->personList->clearContents();
    ui->personList->setRowCount(persons.size());

    for (size_t row = 0; row < persons.size(); row++)
    {
        person p = persons.at(row);

        QString name = QString::fromStdString(p.getName());
        QString sex = QString::fromStdString(p.getSex());
        QString birth_year = QString::number(p.getBirthYear());
        QString death_year = QString::number(p.getDeathYear());
        QString nationality = QString::fromStdString(p.getNationality());

        ui->personList->setItem(row, 0, new QTableWidgetItem(name));
        ui->personList->setItem(row, 1, new QTableWidgetItem(sex));
        ui->personList->setItem(row, 2, new QTableWidgetItem(birth_year));
        ui->personList->setItem(row, 3, new QTableWidgetItem(death_year));
        ui->personList->setItem(row, 4, new QTableWidgetItem(nationality));
    }
}

void MainWindow::displayAllComputers()
{
    vector<computer> computers = s.getComputers();
    displayComputers(computers);
}

void MainWindow::displayComputers(std::vector<computer> computers)
{
    ui->computerList->clearContents();
    ui->computerList->setRowCount(computers.size());

    for (size_t row = 0; row < computers.size(); row++)
    {
        computer c = computers.at(row);

        QString name = QString::fromStdString(c.getName());
        QString type = QString::fromStdString(c.getType());
        QString built = QString::number(c.getBuildYear());
        QString nationality = QString::fromStdString(c.getNationality());

        ui->computerList->setItem(row, 0, new QTableWidgetItem(name));
        ui->computerList->setItem(row, 1, new QTableWidgetItem(type));
        ui->computerList->setItem(row, 2, new QTableWidgetItem(built));
        ui->computerList->setItem(row, 3, new QTableWidgetItem(nationality));
    }
}

void MainWindow::displayPersonsConnections()
{
    QStringList string_list;
    string_list.append("Persons");
    auto model = new QStandardItemModel;
    model->setHorizontalHeaderLabels(string_list);
    auto root = model->invisibleRootItem();


    vector<person> persons = s.getPersons();

    for (auto p : persons) {
        auto row = new QStandardItem(QString::fromStdString(p.getName()));
        QList<QStandardItem *> rowItems;
        rowItems.append(row);

        vector<computer> computers = s.getComputersConnectedWithPerson(p);

        for (auto c : computers) {
            QList<QStandardItem *> computerRows;
            auto computerRow = new QStandardItem(QString::fromStdString(c.getName()));
            computerRows.append(computerRow);
            rowItems.first()->appendRow(computerRow);
        }
        root->appendRow(rowItems);
    }

    ui->PersonConnectionView->setModel(model);
}


void MainWindow::displayComputersConnections()
{
    QStringList string_list;
    string_list.append("Computers");
    auto model = new QStandardItemModel;
    model->setHorizontalHeaderLabels(string_list);
    auto root = model->invisibleRootItem();

    vector<computer> computers = s.getComputers();

    for (auto c : computers) {
        auto row = new QStandardItem(QString::fromStdString(c.getName()));
        QList<QStandardItem *> rowItems;
        rowItems.append(row);

        vector<person> persons = s.getPersonsConnectedWithComputer(c);

        for (auto p : persons) {
            QList<QStandardItem *> personsRows;
            auto personRow = new QStandardItem(QString::fromStdString(p.getName()));
            personsRows.append(personRow);
            rowItems.first()->appendRow(personRow);
        }
        root->appendRow(rowItems);
    }

    ui->ComputerConnectionView->setModel(model);
}

