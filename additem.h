#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>

namespace Ui {
class addItem;
}

class addItem : public QDialog
{
    Q_OBJECT

public:
    explicit addItem(QWidget *parent = 0);
    ~addItem();

private:
    Ui::addItem *ui;
};

#endif // ADDITEM_H
