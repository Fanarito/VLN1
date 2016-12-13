#include "infopagecomp.h"
#include "ui_infopagecomp.h"

infoPageComp::infoPageComp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoPageComp)
{
    ui->setupUi(this);
}

infoPageComp::~infoPageComp()
{
    delete ui;
}
