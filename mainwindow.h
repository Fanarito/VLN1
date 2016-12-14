#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

#include "person.h"
#include "service.h"
#include "additem.h"
#include "infopagecomp.h"
#include "infopage.h"
#include "computer.h"
#include "object.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_personsFilter_textChanged(const QString &arg1);

    void on_computersFilter_textChanged(const QString &arg1);

    void on_actionAdd_Person_triggered();

    void on_removeComputerButton_clicked();

    void on_removePersonButton_clicked();

    void on_computerList_doubleClicked(const QModelIndex &index);

<<<<<<< HEAD
    void on_personList_doubleClicked(const QModelIndex &index);
=======
    void on_removeConnectionButton_clicked();
>>>>>>> 28c0308c194b49dd22ce3c454322cdc9f783418d

private:
    Ui::MainWindow *ui;
    service s;
    addItem add;
    infoPageComp infoComp;
    InfoPage infoPers;

    vector<person> currentlyDisplayedPersons;
    vector<computer> currentlyDisplayedComputers;


    void displayAllPersons();
    void displayPersons(std::vector<person> persons);

    void displayAllComputers();
    void displayComputers(std::vector<computer> computers);

    void displayPersonsConnections();
    void displayComputersConnections();
};

#endif // MAINWINDOW_H
