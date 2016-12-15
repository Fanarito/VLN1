#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "additem.h"
#include "computer.h"
#include "object.h"
#include "person.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <QString>
#include <QTreeWidget>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // firstfresh.exe
    refresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refresh()
{
    displayAllPersons();
    displayAllComputers();
    displayComputersConnections();
    displayPersonsConnections();
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
        bool alive = p.getAlive();

        if(alive)
        {
            death_year = "Alive";
        }

        QString nationality = p.getNationality();

        ui->personList->setItem(row, 0, new QTableWidgetItem(name, p.getId())); //Origin of hack
        ui->personList->setItem(row, 1, new QTableWidgetItem(sex));
        ui->personList->setItem(row, 2, new QTableWidgetItem(birth_year));
        ui->personList->setItem(row, 3, new QTableWidgetItem(death_year));
        ui->personList->setItem(row, 4, new QTableWidgetItem(nationality));
    }

    ui->personList->setSortingEnabled(true);
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

        ui->computerList->setItem(row, 0, new QTableWidgetItem(name, c.getId())); //Origin of hack
        ui->computerList->setItem(row, 1, new QTableWidgetItem(type));
        ui->computerList->setItem(row, 2, new QTableWidgetItem(built));
        ui->computerList->setItem(row, 3, new QTableWidgetItem(nationality));
    }

    ui->computerList->setSortingEnabled(true);
}

void MainWindow::displayPersonsConnections()
{
    displayPersonsConnections(s.getPersons());
}

void MainWindow::displayPersonsConnections(vector<person> persons)
{
    ui->personsConnectionView->setSortingEnabled(false);
    ui->personsConnectionView->clear();
    ui->personsConnectionView->setColumnCount(1);

    for (person p : persons)
    {
        QTreeWidgetItem *compItem = new QTreeWidgetItem(ui->personsConnectionView, p.getId());

        compItem->setText(0, p.getName());
        compItem->setExpanded(true);
        compItem->setFlags(compItem->flags() & ~Qt::ItemIsSelectable);

        std::vector<computer> computers = s.getComputersConnectedWithPerson(p);

        for(computer c : computers)
        {
            QTreeWidgetItem *persItem = new QTreeWidgetItem(compItem, c.getId());

            persItem->setText(0, c.getName());

            compItem->addChild(persItem);
        }
    }

    ui->personsConnectionView->setSortingEnabled(true);
}

void MainWindow::displayComputersConnections()
{
    displayComputersConnections(s.getComputers());
}

void MainWindow::displayComputersConnections(std::vector<computer> computers)
{
    ui->personsConnectionView->setSortingEnabled(false);
    ui->computersConnectionView->clear();
    ui->computersConnectionView->setColumnCount(1);

    for (computer c : computers)
    {

        QTreeWidgetItem *compItem = new QTreeWidgetItem(ui->computersConnectionView, c.getId());

        compItem->setText(0, c.getName());
        compItem->setExpanded(true);
        compItem->setFlags(compItem->flags() & ~Qt::ItemIsSelectable);

        std::vector<person> persons = s.getPersonsConnectedWithComputer(c);

        for(person p : persons)
        {
            QTreeWidgetItem *persItem = new QTreeWidgetItem(compItem, p.getId());

            persItem->setText(0, p.getName());

            compItem->addChild(persItem);
        }
    }

    ui->computersConnectionView->setSortingEnabled(true);
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
    add.resetErrorLabels();

    ui->personsFilter->setText("");
    ui->computersFilter->setText("");

    displayAllPersons();
    displayAllComputers();
    displayComputersConnections();
    displayPersonsConnections();
}

void MainWindow::on_computerList_doubleClicked(const QModelIndex &index)
{
    //Begin dirty hack mk.2

    int currentlySelectedComputerRow = ui->computerList->currentRow();
    int cid = ui->computerList->item(currentlySelectedComputerRow,0)->type(); //Not how this is supposed to be used.

    bool success = true;
    computer currentlySelectedComputer = s.getComputerById(cid,success);
    if(!success)
    {
        std::cerr << "Error: Invalid Computer Selection" << std::endl;
    }

    //End dirty hack

    infoComp.setComputer(currentlySelectedComputer);
    infoComp.exec();
}

void MainWindow::on_personList_doubleClicked(const QModelIndex &index)
{
    //Dirty hack volume ... IV?

    int currentlySelectedPersonRow = ui->personList->currentRow();
    int pid = ui->personList->item(currentlySelectedPersonRow,0)->type(); //Not how this is supposed to be used.

    bool success = true;
    person currentlySelectedPerson = s.getPersonById(pid,success);
    if(!success)
    {
        std::cerr << "Error: Invalid Person Selection" << std::endl;
    }

    infoPers.setPerson(currentlySelectedPerson);
    infoPers.exec();
}

void MainWindow::on_actionActionHelp_triggered()
{
    help.exec();

    ui->personsFilter->setText("");
    ui->computersFilter->setText("");

    refresh();
}

void MainWindow::on_actionRemove_triggered()
{
    switch(ui->tabMenuBar->currentIndex())
    {
        case constants::TabType::Persons:
        {
            int row = ui->personList->currentRow();
            int pid = ui->personList->item(row,0)->type();
            s.removePerson(pid);
        }
        break;
        case constants::TabType::Computers:
        {
            int row = ui->computerList->currentRow();
            int cid = ui->computerList->item(row,0)->type();
            s.removePerson(cid);
        }
        break;
        case constants::TabType::Connections:
        {
            int pid=-1, cid=-1;

            if(ui->computersConnectionView->hasFocus())
            {
                std::cout << "Entered computersconnectionview" << std::endl;

                if((ui->computersConnectionView->currentIndex().column() == -1))
                {
                    std::cout << (ui->computersConnectionView->currentIndex().column() == -1) << std::endl;
                    return;
                }

                std::cout << (ui->computersConnectionView->currentIndex().column() == -1) << std::endl;

                pid = ui->computersConnectionView->currentItem()->type();
                cid = ui->computersConnectionView->currentItem()->parent()->type();

                bool success;
                std::cout << (s.getPersonById(pid,success).getName()).toStdString() << pid << std::endl;
                std::cout << (s.getComputerById(cid,success).getName()).toStdString() << cid << std::endl;
            }
            else if(ui->personsConnectionView->hasFocus())
            {
                if(ui->personsConnectionView->currentIndex().column() == -1)
                {
                    return;
                }

                pid = ui->personsConnectionView->currentItem()->parent()->type();
                cid = ui->personsConnectionView->currentItem()->type();

                bool success;
                std::cout << (s.getPersonById(pid,success).getName()).toStdString() << pid << std::endl;
                std::cout << (s.getComputerById(cid,success).getName()).toStdString() <<cid<< std::endl;
            }
            else
            {
                return;
            }

            bool success;

            std::cout << pid <<", " << cid << std::endl;
            s.removeConnection(pid, cid, success);
            if(!success)
            {
                std::cerr << "Removing connection failed" << endl;
            }
        }
        break;
    }

    refresh();
}
