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

private slots:
    void on_AddPersonButton_clicked(bool checked);

private:
    Ui::addItem *ui;
    service s;
};


#endif // ADDITEM_H
