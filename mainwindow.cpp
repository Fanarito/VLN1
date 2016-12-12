#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllPersons();
    displayAllComputers();
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
    vector<person> persons = s.getPersons();
}

