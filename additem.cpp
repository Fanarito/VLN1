#include "additem.h"
#include "ui_additem.h"

addItem::addItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addItem)
{
    ui->setupUi(this);
    displayAllPersons();
    displayAllComputers();
    populateComboBoxes();
}

addItem::~addItem()
{
    delete ui;
}

void addItem::on_AddPersonButton_clicked(bool checked)
{
    ui->LabelErrorAddPersonName->setText("");
    ui->LabelErrorAddPersonBirthYear->setText("");
    ui->LabelErrorAddPersonDeathYear->setText("");

    bool thereWasAnError = false;

    QString name = ui->AddPersonNameInput->text();
    QString sex = ui->AddPersonSexDropdown->currentText();
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

    if(sex.isEmpty())
    {
        ui->LabelErrorAddPersonSex->setText("<span style='color: red'>Sex cannot be empty</span>");
        thereWasAnError = true;
    }

    if(birthYear.isEmpty())
    {
        ui->LabelErrorAddPersonBirthYear->setText("<span style='color: red'>Birth year cannot be empty</span>");
        thereWasAnError = true;
    }

    if((deathYearInt > 0) && (deathYearInt < 780))
    {
        ui->LabelErrorAddPersonDeathYear->setText("<span style='color: red'>Invalid year of death</span>");
        thereWasAnError = true;
    }
    if((deathYearInt < birthYearInt) && (deathYearInt != 0))
    {
        ui->LabelErrorAddPersonDeathYear->setText("<span style='color: red'>Invalid year of death</span>");
        thereWasAnError = true;
    }
    if(birthYearInt < 780)
    {
        ui->LabelErrorAddPersonBirthYear->setText("<span style='color: red'>Invalid year of birth</span>");
        thereWasAnError = true;
    }

    if(thereWasAnError)
    {
        return;
    }

    s.addPerson(name, sex, birthYearInt, deathYearInt, nationality, info);

    ui->AddPersonNameInput->setText("");
    ui->AddPersonInfoInput->setText("");

    this->done(0);

}

void addItem::populateComboBoxes()
{
    vector<QString> nationalities = s.getNationalities();

    for (auto nationality : nationalities)
    {
        ui->AddPersonNationalityDropdown->addItem(nationality);
        ui->AddComputerNationalityDropdown->addItem(nationality);
    }

    ui->AddPersonSexDropdown->addItem("f");
    ui->AddPersonSexDropdown->addItem("m");

    vector<QString> computerTypes = s.getComputerTypes();

    for (auto computerType : computerTypes)
    {
        ui->AddComputerTypeDropdown->addItem(computerType);
    }
}

void addItem::on_AddComputerButton_clicked()
{
    ui->LabelErrorAddComputerName->setText("");

    bool thereWasAnError = false;
    int built;

    QString name = ui->AddComputerNameInput->text();
    QString type = ui->AddComputerTypeDropdown->currentText();
    QString buildYear = ui->AddComputerBuildYearInput->text();
    QString nationality = ui->AddComputerNationalityDropdown->currentText();
    QString info = ui->AddComputerInfoInput->toPlainText();

    int buildYearInt = buildYear.toInt();

    if(name.isEmpty())
    {
        ui->LabelErrorAddComputerName->setText("<span style='color: red'>Name cannot be empty</span>");
        thereWasAnError = true;
    }

    if(buildYear.isEmpty())
    {
        ui->LabelErrorAddPersonBirthYear->setText("<span style='color: red'>Build year cannot be empty</span>");
        thereWasAnError = true;
    }

    if(buildYearInt == 0)
    {
        built = 0;
    }
    else
    {
        built = 1;
    }

    if(thereWasAnError)
    {
        return;
    }

    s.addComputer(name, buildYearInt, type, built, nationality, info);

    ui->AddComputerNameInput->setText("");
    ui->AddComputerInfoInput->setText("");

    this->done(0);
}

void addItem::displayPersons(vector<person> persons)
{
    ui->PersonConnections->clear();

    for (size_t row = 0; row < persons.size(); row++)
    {
        person currentPerson = persons.at(row);

        ui->PersonConnections->addItem(currentPerson.getName());

    }
}

void addItem::displayAllPersons()
{
    vector<person> persons = s.getPersons();
    displayPersons(persons);
}

void addItem::displayComputers(vector<computer> computers)
{
    ui->ComputerConnections->clear();

    for (size_t row = 0; row < computers.size(); row++)
    {
        computer currentComputer = computers.at(row);

        ui->ComputerConnections->addItem(currentComputer.getName());

    }
}

void addItem::displayAllComputers()
{
    vector<computer> computers = s.getComputers();
    displayComputers(computers);
}
