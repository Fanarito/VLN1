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

void InfoPage::setPerson(person pers)
{
    p = pers;

    ui->infoPersName->setText(p.getName());
    ui->infoPersSex->setText(p.getSex());
    QString birth_year = QString::number(p.getBirthYear());
    ui->infoPersBirthYear->setText(birth_year);
    QString Death_year = QString::number(p.getDeathYear());
    ui->infoPersDeathYear->setText(Death_year);
    ui->infoPersNationality->setText(p.getNationality());
    ui->infoPersInfo->setText(p.getInfo());
    ui->picture->setPixmap(QPixmap(":/images/GraceHopper.jpg").scaledToHeight(ui->picture->height()));
}

void InfoPage::resizeEvent(QResizeEvent *event)
{
    ui->picture->setPixmap(QPixmap(":/images/GraceHopper.jpg").scaledToHeight(ui->picture->height()));
    QWidget::resizeEvent(event);
}
