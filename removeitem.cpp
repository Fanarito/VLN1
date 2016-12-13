#include "removeitem.h"
#include "ui_removeitem.h"

RemoveItem::RemoveItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveItem)
{
    ui->setupUi(this);
}

RemoveItem::~RemoveItem()
{
    delete ui;
}
