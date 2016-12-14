#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

#include "person.h"
#include "service.h"
#include "additem.h"

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

    void on_actionRemove_Item_triggered();

private:
    Ui::MainWindow *ui;
    service s;
    addItem add;

    vector<person> currentlyDisplayedPersons;


    void displayAllPersons();
    void displayPersons(std::vector<person> persons);

    void displayAllComputers();
    void displayComputers(std::vector<computer> computers);

    void displayPersonsConnections();
    void displayComputersConnections();
};

#endif // MAINWINDOW_H
