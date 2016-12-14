#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "additem.h"
#include "computer.h"
#include "object.h"
#include "person.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QString>

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
    ui->personList->setSortingEnabled(false);

    ui->personList->clearContents();
    ui->personList->setRowCount(persons.size());

    for (size_t row = 0; row < persons.size(); row++)
    {
        person p = persons.at(row);

        QString name = p.getName();
        QString sex = p.getSex();
        if(p.getSex() == "m")
        {
            sex = "Male";
        }
        else
        {
            sex = "Female";
        }
        QString birth_year = QString::number(p.getBirthYear());
        QString death_year = QString::number(p.getDeathYear());
        if(p.getDeathYear() == 0)
        {
            death_year = "Alive";
        }
        QString nationality = p.getNationality();

        ui->personList->setItem(row, 0, new QTableWidgetItem(name));
        ui->personList->setItem(row, 1, new QTableWidgetItem(sex));
        ui->personList->setItem(row, 2, new QTableWidgetItem(birth_year));
        ui->personList->setItem(row, 3, new QTableWidgetItem(death_year));
        ui->personList->setItem(row, 4, new QTableWidgetItem(nationality));
    }

    ui->personList->setSortingEnabled(true);

    currentlyDisplayedPersons = persons;
}

void MainWindow::displayAllComputers()
{
    vector<computer> computers = s.getComputers();
    displayComputers(computers);
}

void MainWindow::displayComputers(std::vector<computer> computers)
{
    ui->computerList->setSortingEnabled(false);

    ui->computerList->clearContents();
    ui->computerList->setRowCount(computers.size());

    for (size_t row = 0; row < computers.size(); row++)
    {
        computer c = computers.at(row);

        QString name = c.getName();
        QString type = c.getType();
        QString built = QString::number(c.getBuildYear());
        if(c.getBuildYear() == 0)
        {
            built = "Not built";
        }
        QString nationality = c.getNationality();

        ui->computerList->setItem(row, 0, new QTableWidgetItem(name));
        ui->computerList->setItem(row, 1, new QTableWidgetItem(type));
        ui->computerList->setItem(row, 2, new QTableWidgetItem(built));
        ui->computerList->setItem(row, 3, new QTableWidgetItem(nationality));
    }

    ui->computerList->setSortingEnabled(true);

    currentlyDisplayedComputers = computers;
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
        auto row = new QStandardItem(p.getName());
        QList<QStandardItem *> rowItems;
        rowItems.append(row);

        vector<computer> computers = s.getComputersConnectedWithPerson(p);

        for (auto c : computers) {
            QList<QStandardItem *> computerRows;
            auto computerRow = new QStandardItem(c.getName());
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
        auto row = new QStandardItem(c.getName());
        QList<QStandardItem *> rowItems;
        rowItems.append(row);

        vector<person> persons = s.getPersonsConnectedWithComputer(c);

        for (auto p : persons) {
            QList<QStandardItem *> personsRows;
            auto personRow = new QStandardItem(p.getName());
            personsRows.append(personRow);
            rowItems.first()->appendRow(personRow);
        }
        root->appendRow(rowItems);
    }

    ui->ComputerConnectionView->setModel(model);
}

void MainWindow::on_personsFilter_textChanged(const QString &arg1)
{
    vector<person> persons = s.filterPersons(arg1);
    displayPersons(persons);
}

void MainWindow::on_computersFilter_textChanged(const QString &arg1)
{
    vector<computer> computers = s.filterComputers(arg1);
    displayComputers(computers);
}

void MainWindow::on_actionAdd_Person_triggered()
{
    add.exec();

    ui->personsFilter->setText("");
    ui->computersFilter->setText("");

    displayAllPersons();
    displayAllComputers();
    displayComputersConnections();
    displayPersonsConnections();
}

void MainWindow::on_removeComputerButton_clicked()
{
    int currentlySelectedComputerIndex = ui->computerList->currentIndex().row();

    computer currentlySelectedComputer = currentlyDisplayedComputers.at(currentlySelectedComputerIndex);

    int computerId = s.getIdOfComputer((currentlySelectedComputer));

    s.removeComputer(computerId);

    ui->personsFilter->setText("");
    ui->computersFilter->setText("");

    displayAllPersons();
    displayAllComputers();
    displayComputersConnections();
    displayPersonsConnections();
    add.updateAddConnectionsList();
}

void MainWindow::on_removePersonButton_clicked()
{
    int currentlySelectedPersonIndex = ui->personList->currentIndex().row();

    person currentlySelectedPerson = currentlyDisplayedPersons.at(currentlySelectedPersonIndex);

    int personId = s.getIdOfPerson((currentlySelectedPerson));

    s.removePerson(personId);

    ui->personsFilter->setText("");
    ui->computersFilter->setText("");

    displayAllPersons();
    displayAllComputers();
    displayComputersConnections();
    displayPersonsConnections();
    add.updateAddConnectionsList();
}

void MainWindow::on_computerList_doubleClicked(const QModelIndex &index)
{
    int currentlySelectedComputerIndex = ui->computerList->currentIndex().row();

    computer currentlySelectedComputer = currentlyDisplayedComputers.at(currentlySelectedComputerIndex);

    infoComp.setComputer(currentlySelectedComputer);
    infoComp.exec();
    }

void MainWindow::on_personList_doubleClicked(const QModelIndex &index)
{
    int currentlySelectedPersonIndex = ui->personList->currentIndex().row();

    person currentlySelectedPerson = currentlyDisplayedPersons.at(currentlySelectedPersonIndex);

    infoPers.setPerson(currentlySelectedPerson);
    infoPers.exec();
}

void MainWindow::on_removeConnectionButton_clicked()
{
    QVector<QModelIndex> currentlySelectedConnectionIndex = ui->PersonConnectionView->selectionModel()->selectedIndexes().toVector();

}

void MainWindow::on_actionActionHelp_triggered()
{

}
