#include "additem.h"
#include "ui_additem.h"

addItem::addItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addItem)
{
    ui->setupUi(this);
    populateComboBoxes();
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
    QString nationality = ui->AddPersonNationalityDropdown->currentText();
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

void addItem::on_AddComputerButton_clicked()
{
    //TODO:LabelErrorAddComputer?

    bool thereWasAnError = false;

    QString name = ui->AddComputerNameInput->text();
    QString type = ui->AddComputerTypeInput->text();
    bool built = ui->AddComputerBuiltCheckBox->isChecked();
    int buildyear = ui->AddComputerBuildYearInput->text().toInt();
    QString nationality = ui->AddComputerNationalityDropdown->currentText();
    QString info = ui->AddComputerInfoInput->toPlainText();


    if(name.isEmpty())
    {
        thereWasAnError = true;
    }

    if(thereWasAnError)
    {
        return;
    }

    s.addComputer(name, buildyear, type, built, nationality, info);

    ui->AddPersonNameInput->setText("");

}

void addItem::populateComboBoxes()
{
    vector<QString> nationalities = s.getNationalities();

    for (auto nationality : nationalities)
    {
        ui->AddPersonNationalityDropdown->addItem(nationality);
        ui->AddComputerNationalityDropdown->addItem(nationality);
    }
}
