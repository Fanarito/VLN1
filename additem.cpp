#include "additem.h"
#include "ui_additem.h"

addItem::addItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addItem)
{
    ui->setupUi(this);
}

addItem::~addItem()
{
    delete ui;
}

void addItem::on_AddPersonButton_clicked(bool checked)
{
    ui->LabelErrorAddPersonName->setText("");

    bool thereWasAnError = false;

    QString name = ui->AddPersonNameInput->text();
    QString sex = ui->AddPersonSexInput->text();
    QString birthYear = ui->AddPersonBirthYearInput->text();
    QString deathYear = ui->AddPersonDeathYearInput->text();
    QString nationality = ui->AddPersonNationalityInput->text();
    QString info = ui->AddPersonInfoInput->toPlainText();

    int birthYearInt = birthYear.toInt();
    int deathYearInt = deathYear.toInt();

    if(name.isEmpty())
    {
        ui->LabelErrorAddPersonName->setText("<span style='color: red'>Name cannot be empty</span>");
        thereWasAnError = true;
    }

    if(thereWasAnError)
    {
        return;
    }

    s.addPerson(name, sex, birthYearInt, deathYearInt, nationality, info);

    ui->AddPersonNameInput->setText("");

}
