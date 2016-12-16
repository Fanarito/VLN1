#include "infopagecomp.h"
#include "ui_infopagecomp.h"

infoPageComp::infoPageComp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoPageComp)
{
    ui->setupUi(this);

    vector<QString> nationalities = s.getNationalities();

    for (auto nationality : nationalities)
    {
        ui->infoCompNationality->addItem(nationality);
    }

    vector<QString> computertypes = s.getComputerTypes();

    for (auto type : computertypes)
    {
        ui->infoCompType->addItem(type);
    }

    ui->infoCompBuiltYear->setMaximum(utils::getCurrentYear());

    disableFields();
}

infoPageComp::~infoPageComp()
{
    delete ui;
}

void infoPageComp::setComputer(computer comp)
{
    c = comp;

    ui->infoCompName->setText(c.getName());
    ui->infoCompType->setCurrentText(c.getType());
    ui->infoCompBuiltYear->setValue(c.getBuildYear());
    ui->infoCompNationality->setCurrentText(c.getNationality());
    ui->infoCompInfo->setText(c.getInfo());

    ui->InfoCompBuilt->setChecked(c.getBuilt());

    img_path = constants::IMAGE_PATH + QString::fromStdString("c" + std::to_string(c.getId()));
    if (!QFile::exists(img_path))
        img_path = constants::IMAGE_PATH + QString::fromStdString("noimg");

    ui->infoCompPic->setPixmap(QPixmap(img_path).scaledToHeight(100));
}

void infoPageComp::on_EditComputerCheckbox_stateChanged(int arg1)
{
    if(ui->EditComputerCheckbox->isChecked())
    {
        enableFields();
    }
    else
    {
        disableFields();
        setComputer(c);
    }
}

void infoPageComp::enableFields()
{
    ui->applyComputerButton->setEnabled(true);

    ui->infoCompName->setEnabled(true);
    ui->infoCompType->setEnabled(true);
    ui->infoCompBuiltYear->setEnabled(true);
    ui->infoCompNationality->setEnabled(true);
    ui->infoCompInfo->setEnabled(true);
    ui->InfoCompBuilt->setEnabled(true);

    ui->InfoCompBuilt->setVisible(true);
    ui->infoCompBuiltYear->setVisible(true);
}

void infoPageComp::disableFields()
{
    ui->applyComputerButton->setEnabled(false);

    ui->infoCompName->setEnabled(false);
    ui->infoCompType->setEnabled(false);
    ui->infoCompBuiltYear->setEnabled(false);
    ui->infoCompNationality->setEnabled(false);
    ui->infoCompInfo->setEnabled(false);
    ui->InfoCompBuilt->setEnabled(false);

    if(c.getBuilt())
    {
        ui->InfoCompBuilt->setVisible(false);
        ui->infoCompBuiltYear->setVisible(true);
    }
    else
    {
        ui->InfoCompBuilt->setVisible(true);
        ui->infoCompBuiltYear->setVisible(false);
    }

    ui->InfoCompErrName->setText("");
}

void infoPageComp::on_applyComputerButton_clicked()
{
    QString name, type, nationality, info;
    int build_year;
    bool built;

    name = ui->infoCompName->text();

    if(name.isEmpty())
    {
        ui->InfoCompErrName->setText("<span style='color: red'>Name cannot be empty.</span>");
        return;
    }

    nationality = ui->infoCompNationality->currentText();
    type = ui->infoCompType->currentText();

    info = ui->infoCompInfo->toPlainText();

    build_year = ui->infoCompBuiltYear->value();

    built = ui->InfoCompBuilt->isChecked();

    c = computer(name, build_year, type, built, info, nationality, c.getId());

    s.changeComputer(c);

    ui->EditComputerCheckbox->setChecked(false);
}

void infoPageComp::on_closeComputerButton_clicked()
{
    this->done(0);
}
