#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include <QAbstractListModel>
#include "person.h"
#include "service.h"

namespace Ui {
class addItem;
}

class addItem : public QDialog
{
    Q_OBJECT

public:
    explicit addItem(QWidget *parent = 0);
    ~addItem();
    void updateAddConnectionsList();

private slots:
    void on_AddPersonButton_clicked(bool checked);

    void on_AddComputerButton_clicked();

<<<<<<< HEAD
=======
    void on_AddConnectionButton_clicked();

>>>>>>> f390019b29244c6e1cfab06ce44d467c96050afb
private:
    Ui::addItem *ui;
    service s;

    void clearFields();
    void populateComboBoxes();
    void displayPersons(vector<person> persons);
    void displayComputers(vector<computer> computers);
    void displayAllComputers();
    void displayAllPersons();
    vector<person> currentlyDisplayedPersons;
    vector<computer> currentlyDisplayedComputers;

};


#endif // ADDITEM_H
