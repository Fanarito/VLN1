#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include <QFileDialog>
#include <QAbstractListModel>
#include "person.h"
#include "service.h"
#include "constants.h"

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
    void resetErrorLabels();

private slots:
    void on_AddPersonButton_clicked();

    void on_AddComputerButton_clicked();

    void on_AddConnectionButton_clicked();

    void on_AddComputerBuiltCheckbox_stateChanged();

    void on_AddPersonAliveCheckbox_stateChanged();

    void on_AddPersonBirthYearInput_valueChanged(int arg1);

    void on_BrowseImageComputerButton_clicked();

    void on_BrowseImagePersonButton_clicked();

private:
    Ui::addItem *ui;
    service s;

    vector<person> currentlyDisplayedPersons;
    vector<computer> currentlyDisplayedComputers;

    void populateComboBoxes();

    void resetFields();

    void displayPersons(vector<person> persons);
    void displayComputers(vector<computer> computers);

    void displayAllComputers();
    void displayAllPersons();

    bool p_picture_added;
    bool c_picture_added;

    QString person_picture_path;
    QString computer_picture_path;
};


#endif // ADDITEM_H
