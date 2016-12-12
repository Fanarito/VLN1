#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

#include "person.h"
#include "service.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    service s;


    void displayAllPersons();
    void displayPersons(std::vector<person> persons);

    void displayAllComputers();
    void displayComputers(std::vector<computer> computers);

    void displayPersonsConnections();
    void displayComputersConnections();
};

#endif // MAINWINDOW_H
