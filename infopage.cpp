#include "infopage.h"
#include "ui_infopage.h"

InfoPage::InfoPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoPage)
{
    ui->setupUi(this);
}

InfoPage::~InfoPage()
{
    delete ui;
}
