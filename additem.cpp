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
    resetFields();
    resetErrorLabels();
}

addItem::~addItem()
{
    resetErrorLabels();
    delete ui;
}

void addItem::resetFields()
{
    ui->AddPersonBirthYearInput->setMaximum(utils::getCurrentYear());
    ui->AddPersonBirthYearInput->setMinimum(0);
    ui->AddPersonDeathYearInput->setMaximum(utils::getCurrentYear());

    //Persons
    ui->AddPersonNameInput->setText("");
    ui->AddPersonSexDropdown->setCurrentIndex(0);
    ui->AddPersonBirthYearInput->setValue(0);
    ui->AddPersonDeathYearInput->setValue(0);
    ui->AddPersonAliveCheckbox->setChecked(false);
    ui->AddPersonNationalityDropdown->setCurrentIndex(0);
    ui->AddPersonInfoInput->setText("");

    //Computer
    ui->AddComputerNameInput->setText("");
    ui->AddComputerTypeDropdown->setCurrentIndex(0);
    ui->AddComputerBuiltCheckbox->setChecked(false);
    ui->AddComputerBuildYearInput->setValue(0);
    ui->AddComputerBuildYearInput->setEnabled(false);
    ui->AddComputerNationalityDropdown->setCurrentIndex(0);

    //Connections
    displayAllPersons();
    displayAllComputers();

    ui->BrowseImageComputerButton->setText("Browse Image");
    ui->BrowseImagePersonButton->setText("Browse Image");

    person_picture_path = "";
    computer_picture_path = "";
}

void addItem::resetErrorLabels()
{
    ui->LabelErrorAddPersonName->setText("");
    ui->LabelErrorAddPersonBirthYear->setText("");
    ui->LabelErrorAddPersonDeathYear->setText("");
    ui->LabelErrorAddPersonSex->setText("");
    ui->LabelErrorAddPersonNationality->setText("");

    ui->LabelErrorAddComputerName->setText("");
    ui->LabelErrorAddComputerBuildYear->setText("");
    ui->LabelErrorAddComputerNationality->setText("");
    ui->LabelErrorAddComputerType->setText("");

    ui->LabelErrorAddPersonConnection->setText("");
    ui->LabelErrorAddComputerConnection->setText("");

    ui->ComputerResult->setText("");
    ui->ConnectionsResult->setText("");
    ui->PersonResult->setText("");
}

void addItem::on_AddPersonButton_clicked()
{
    resetErrorLabels();

    ui->LabelErrorAddPersonName->setText("");
    ui->LabelErrorAddPersonBirthYear->setText("");
    ui->LabelErrorAddPersonDeathYear->setText("");

    bool thereWasAnError = false;

    QString name, sex, birthYear, deathYear, nationality, info;
    bool alive;
    int birthYearInt;
    int deathYearInt;

    name = ui->AddPersonNameInput->text();

    if(ui->AddPersonSexDropdown->currentText() == "Male")
    {
        sex = "m";
    }
    else
    {
        sex = "f";
    }

    birthYear = ui->AddPersonBirthYearInput->text();
    deathYear = ui->AddPersonDeathYearInput->text();
    alive = ui->AddPersonAliveCheckbox->isChecked();
    nationality = ui->AddPersonNationalityDropdown->currentText();
    info = ui->AddPersonInfoInput->toPlainText();

    birthYearInt = birthYear.toInt();
    deathYearInt = 0;

    if(!alive)
    {
        deathYearInt = deathYear.toInt();
    }

    if(ui->AddPersonSexDropdown->currentIndex() == 0)
    {
        ui->LabelErrorAddPersonSex->setText("<span style='color: red'>Please select a sex</span>");
        thereWasAnError = true;
    }

    if(ui->AddPersonNationalityDropdown->currentIndex() == 0)
    {
        ui->LabelErrorAddPersonNationality->setText("<span style='color: red'>Please select a nationality</span>");
        thereWasAnError = true;
    }

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

    if((deathYearInt < birthYearInt))
    {
        ui->LabelErrorAddPersonDeathYear->setText("<span style='color: red'>Invalid year of death; cannot be before year of birth</span>");
        thereWasAnError = true;
    }

    if(thereWasAnError)
    {
        return;
    }

    int result = s.addPerson(name, sex, birthYearInt, deathYearInt, alive, nationality, info);

    if (!result)
        ui->PersonResult->setText("<span style='color: red'>Person was not added!</span>");
    else
        ui->PersonResult->setText("<span style='color: green'>Person added successfully</span>");

    QString path = constants::IMAGE_PATH + QString::fromStdString("p" + to_string(result));
    if (QFile::exists(path)) {
        QFile::remove(path);
    }
    QFile::copy(person_picture_path, path);

    resetFields();
}

void addItem::on_AddComputerButton_clicked()
{
    resetErrorLabels();

    bool err = false;

    QString name = ui->AddComputerNameInput->text();
    QString type = ui->AddComputerTypeDropdown->currentText();
    QString nationality = ui->AddComputerNationalityDropdown->currentText();
    QString info = ui->AddComputerInfoInput->toPlainText();

    bool built = ui->AddComputerBuiltCheckbox->isChecked();

    QString buildYear = ui->AddComputerBuildYearInput->text();
    int buildYearInt = buildYear.toInt();

    if(ui->AddComputerTypeDropdown->currentIndex() == 0)
    {
        ui->LabelErrorAddComputerType->setText("<span style='color: red'>Please select computer type</span>");
        err = true;
    }

    if(ui->AddComputerTypeDropdown->currentIndex() == 0)
    {
        ui->LabelErrorAddComputerNationality->setText("<span style='color: red'>Please select computer nationality</span>");
        err = true;
    }

    if(buildYear.isEmpty())
    {
        ui->LabelErrorAddPersonBirthYear->setText("<span style='color: red'>Build year cannot be empty</span>");
        err = true;
    }

    if(name.isEmpty())
    {
        ui->LabelErrorAddComputerName->setText("<span style='color: red'>Name cannot be empty</span>");
        err = true;
    }

    if(err)
    {
        return;
    }

    bool result = s.addComputer(name, buildYearInt, type, built, nationality, info);

    if (!result)
        ui->ComputerResult->setText("<span style='color: red'>Computer not added!</span>");
    else
        ui->ComputerResult->setText("<span style='color: green'>Computer added successfully</span>");

    QString path = constants::IMAGE_PATH + QString::fromStdString("c" + to_string(result));
    if (QFile::exists(path)) {
        QFile::remove(path);
    }
    QFile::copy(computer_picture_path, path);

    resetFields();
}

void addItem::on_AddConnectionButton_clicked()
{
    QList<QListWidgetItem *> personSelected = ui->PersonConnections->selectedItems();
    QList<QListWidgetItem *> computerSelected = ui->ComputerConnections->selectedItems();

    if((personSelected.isEmpty()) && (computerSelected.isEmpty()))
    {
        ui->LabelErrorAddPersonConnection->setText("<span style='color: red'>No person selected</span>");
        ui->LabelErrorAddComputerConnection->setText("<span style='color: red'>No computer selected</span>");
    }
    else if(personSelected.isEmpty())
    {
        ui->LabelErrorAddPersonConnection->setText("<span style='color: red'>No person selected</span>");
    }
    else if(computerSelected.isEmpty())
    {
        ui->LabelErrorAddComputerConnection->setText("<span style='color: red'>No computer selected</span>");
    }
    else
    {
        int currentlySelectedPersonIndex = ui->PersonConnections->currentIndex().row();

        person currentlySelectedPerson = currentlyDisplayedPersons.at(currentlySelectedPersonIndex);

        int personId = s.getIdOfPerson(currentlySelectedPerson);

        int currentlySelectedComputerIndex = ui->ComputerConnections->currentIndex().row();

        computer currentlySelectedComputer = currentlyDisplayedComputers.at(currentlySelectedComputerIndex);

        int computerId = s.getIdOfComputer(currentlySelectedComputer);

        bool added = s.addConnection(computerId, personId);

        if (!added)
            ui->ConnectionsResult->setText("<span style='color: red'>Connection not added, it may be present already</span>");
        else
            ui->ConnectionsResult->setText("<span style='color: green'>Connection added successfully</span>");
    }

}

void addItem::populateComboBoxes()
{
    vector<QString> nationalities = s.getNationalities();

    ui->AddPersonNationalityDropdown->addItem("-");
    ui->AddComputerNationalityDropdown->addItem("-");

    for (auto nationality : nationalities)
    {
        ui->AddPersonNationalityDropdown->addItem(nationality);
        ui->AddComputerNationalityDropdown->addItem(nationality);
    }

    ui->AddPersonSexDropdown->addItem("-");
    ui->AddPersonSexDropdown->addItem("Male");
    ui->AddPersonSexDropdown->addItem("Female");

    vector<QString> computerTypes = s.getComputerTypes();

    ui->AddComputerTypeDropdown->addItem("-");

    for (auto computerType : computerTypes)
    {
        ui->AddComputerTypeDropdown->addItem(computerType);
    }
}

void addItem::displayPersons(vector<person> persons)
{
    ui->PersonConnections->clear();

    for (size_t row = 0; row < persons.size(); row++)
    {
        person currentPerson = persons.at(row);

        ui->PersonConnections->addItem(currentPerson.getName());

    }

    currentlyDisplayedPersons = persons;
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

    currentlyDisplayedComputers = computers;
}

void addItem::displayAllComputers()
{
    vector<computer> computers = s.getComputers();
    displayComputers(computers);
}

void addItem::updateAddConnectionsList()
{
    displayAllComputers();
    displayAllPersons();
}

void addItem::on_AddComputerBuiltCheckbox_stateChanged()
{
    if(ui->AddComputerBuiltCheckbox->isChecked())
    {
        ui->AddComputerBuildYearInput->setEnabled(true);
    }
    else
    {
        ui->AddComputerBuildYearInput->setValue(0);
        ui->AddComputerBuildYearInput->setEnabled(false);
    }
}

void addItem::on_AddPersonAliveCheckbox_stateChanged()
{
    if(ui->AddPersonAliveCheckbox->isChecked())
    {
        ui->AddPersonDeathYearInput->setEnabled(false);
    }
    else
    {
        ui->AddPersonDeathYearInput->setEnabled(true);
    }
}

void addItem::on_AddPersonBirthYearInput_valueChanged(int arg1)
{
    ui->AddPersonDeathYearInput->setMinimum(arg1);
}

void addItem::on_BrowseImagePersonButton_clicked()
{
    person_picture_path = QFileDialog::getOpenFileName(this, tr("Select Picture"), "/home", tr("Images (*.png *.jpg *.tiff *.jpeg)"));
    QDir().mkpath(QDir::currentPath() + QString::fromStdString("/images"));
    ui->BrowseImagePersonButton->setText(person_picture_path);
}

void addItem::on_BrowseImageComputerButton_clicked()
{
    computer_picture_path = QFileDialog::getOpenFileName(this, tr("Select Picture"), "/home", tr("Images (*.png *.jpg *.tiff *.jpeg)"));
    QDir().mkpath(QDir::currentPath() + QString::fromStdString("/images"));
    ui->BrowseImageComputerButton->setText(computer_picture_path);
}
