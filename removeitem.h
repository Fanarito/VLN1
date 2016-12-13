#ifndef REMOVEITEM_H
#define REMOVEITEM_H

#include <QDialog>

namespace Ui {
class RemoveItem;
}

class RemoveItem : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveItem(QWidget *parent = 0);
    ~RemoveItem();

private:
    Ui::RemoveItem *ui;
};

#endif // REMOVEITEM_H
