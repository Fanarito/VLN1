#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
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
    void on_AddPersonButton_clicked();

private:
    Ui::addItem *ui;
    service c;
};


#endif // ADDITEM_H
