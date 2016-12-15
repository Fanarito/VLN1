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
#include "helpscreen.h"

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

    void on_computerList_doubleClicked(const QModelIndex &index);

    void on_personList_doubleClicked(const QModelIndex &index);

    void on_actionActionHelp_triggered();

    void on_actionRemove_triggered();

private:
    Ui::MainWindow *ui;
    service s;
    addItem add;
    infoPageComp infoComp;
    InfoPage infoPers;
    helpscreen help;

    void refresh();

    void displayAllPersons();
    void displayPersons(std::vector<person> persons);

    void displayAllComputers();
    void displayComputers(std::vector<computer> computers);

    void displayPersonsConnections();
    void displayComputersConnections();
};

#endif // MAINWINDOW_H
