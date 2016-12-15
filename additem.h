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
    void on_AddPersonButton_clicked();

    void on_AddComputerButton_clicked();

    void on_AddConnectionButton_clicked();

    void on_AddComputerBuiltCheckbox_stateChanged();

    void on_AddPersonAliveCheckbox_stateChanged();

private:
    Ui::addItem *ui;
    service s;

    vector<person> currentlyDisplayedPersons;
    vector<computer> currentlyDisplayedComputers;

    void populateComboBoxes();

    void resetFields();
    void resetErrorLabels();

    void displayPersons(vector<person> persons);
    void displayComputers(vector<computer> computers);

    void displayAllComputers();
    void displayAllPersons();


};


#endif // ADDITEM_H
