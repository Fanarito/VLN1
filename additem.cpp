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

void addItem::on_AddPersonButton_clicked()
{
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
        cout << "Name cannot be empty";
        return;
    }
    if(sex.isEmpty())
    {
        cout << "Sex cannot be empty";
        return;
    }
    if(birthYear.isEmpty())
    {
        cout << "Birth year cannot be empty";
        return;
    }

    s.addPerson(name, sex, birthYearInt, deathYearInt, nationality, info);

}
