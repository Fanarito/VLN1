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

    img_path = constants::IMAGE_PATH + QString::fromStdString("p" + std::to_string(p.getId()));
    if (!QFile::exists(img_path))
        img_path = constants::IMAGE_PATH + QString::fromStdString("noimg");

    ui->picture->setPixmap(QPixmap(img_path).scaledToHeight(100));
}

void InfoPage::resizeEvent(QResizeEvent *event)
{
    //ui->picture->setPixmap(QPixmap(img_path).scaledToHeight(ui->picture->height()));
    QWidget::resizeEvent(event);
}

void InfoPage::enableFields()
{
    ui->infoPersName->setEnabled(true);
    ui->infoPersSex->setEnabled(true);
    ui->infoPersBirthYear->setEnabled(true);
    ui->infoPersDeathYear->setEnabled(true);
    ui->infoPersNationality->setEnabled(true);
    ui->infoPersInfo->setEnabled(true);
}

void InfoPage::disableFields()
{
    ui->infoPersName->setEnabled(false);
    ui->infoPersSex->setEnabled(false);
    ui->infoPersBirthYear->setEnabled(false);
    ui->infoPersDeathYear->setEnabled(false);
    ui->infoPersNationality->setEnabled(false);
    ui->infoPersInfo->setEnabled(false);
}

void InfoPage::on_editPersonCheckbox_stateChanged()
{
    if(ui->editPersonCheckbox->isChecked())
    {
        enableFields();
    }
    else
    {
        disableFields();
    }
}

void InfoPage::on_applyPersonButton_clicked()
{
    ui->editPersonCheckbox->setChecked(false);
    //s.removePerson(p.getId());
}
