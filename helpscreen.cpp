#include "helpscreen.h"
#include "ui_helpscreen.h"

helpscreen::helpscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::helpscreen)
{
    ui->setupUi(this);
    this->setFixedSize(size());
}

helpscreen::~helpscreen()
{
    delete ui;
}
