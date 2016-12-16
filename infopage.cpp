#include "infopage.h"
#include "ui_infopage.h"

InfoPage::InfoPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoPage)
{
    ui->setupUi(this);

    vector<QString> nationalities = s.getNationalities();

    for (auto nationality : nationalities)
    {
        ui->infoPersNationality->addItem(nationality);
    }

    ui->infoPersSex->addItem("Male");
    ui->infoPersSex->addItem("Female");

    ui->infoPersBirthYear->setMaximum(utils::getCurrentYear());
    ui->infoPersDeathYear->setMaximum(utils::getCurrentYear());

    disableFields();
}

InfoPage::~InfoPage()
{
    delete ui;
}

void InfoPage::setPerson(person pers)
{
    p = pers;

    ui->infoPersName->setText(p.getName());
    ui->infoPersSex->setCurrentText(p.getSex());
    QString birth_year = QString::number(p.getBirthYear());
    ui->infoPersBirthYear->setValue(p.getBirthYear());
    ui->infoPersDeathYear->setValue(p.getDeathYear());

    if(p.getAlive())
    {
        ui->infoPersAlive->setChecked(true);
        ui->infoPersDeathYear->setVisible(false);
    }
    else
    {
        ui->infoPersAlive->setVisible(false);
        ui->infoPersDeathYear->setVisible(true);
    }

    ui->infoPersNationality->setCurrentText(p.getNationality());
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
    ui->applyPersonButton->setEnabled(true);

    ui->infoPersName->setEnabled(true);
    ui->infoPersSex->setEnabled(true);
    ui->infoPersBirthYear->setEnabled(true);
    ui->infoPersDeathYear->setEnabled(true);
    ui->infoPersNationality->setEnabled(true);
    ui->infoPersInfo->setEnabled(true);
    ui->infoPersAlive->setEnabled(true);

    ui->infoPersAlive->setVisible(true);
    ui->infoPersDeathYear->setVisible(true);
}

void InfoPage::disableFields()
{
    ui->applyPersonButton->setEnabled(false);

    ui->infoPersName->setEnabled(false);
    ui->infoPersSex->setEnabled(false);
    ui->infoPersBirthYear->setEnabled(false);
    ui->infoPersDeathYear->setEnabled(false);
    ui->infoPersNationality->setEnabled(false);
    ui->infoPersInfo->setEnabled(false);
    ui->infoPersAlive->setEnabled(false);

    if(p.getAlive())
    {
        ui->infoPersAlive->setVisible(true);
        ui->infoPersDeathYear->setVisible(false);
    }
    else
    {
        ui->infoPersAlive->setVisible(false);
        ui->infoPersDeathYear->setVisible(true);
    }

    ui->infoPersErrName->setText("");
    ui->infoPersErrBirthYear->setText("");
    ui->infoPersErrDeathYear->setText("");
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
        setPerson(p);
    }
}

void InfoPage::on_applyPersonButton_clicked()
{
    QString name, sex, nationality, info;
    int birthyear, deathyear;
    bool alive;

    name = ui->infoPersName->text();

    if(name.isEmpty())
    {
        ui->infoPersErrName->setText("<span style='color: red'>Name cannot be empty.</span>");
        return;
    }

    if(ui->infoPersSex->currentText() == "Male")
    {
        sex = "m";
    }
    else
    {
        sex = "f";
    }

    nationality = ui->infoPersNationality->currentText();

    info = ui->infoPersInfo->toPlainText();

    birthyear = ui->infoPersBirthYear->value();
    deathyear = ui->infoPersDeathYear->value();

    if(birthyear < deathyear)
    {
        ui->infoPersErrDeathYear->setText("<span style='color: red'>Death year cannot be before birth year.</span>");
    }

    alive = ui->infoPersAlive->isChecked();

    p = person(name, sex, birthyear, deathyear, alive, nationality, info, p.getId());

    s.changePerson(p);

    ui->editPersonCheckbox->setChecked(false);
}

void InfoPage::on_closePersonButton_clicked()
{
    this->done(0);
}

void InfoPage::on_picture_linkActivated(const QString &link)
{
    std::cerr << "Picture clicked!" << std::endl;
}

void InfoPage::on_infoPersAlive_stateChanged(int arg1)
{
    if(ui->infoPersAlive->isChecked())
    {
        ui->infoPersDeathYear->setEnabled(false);
    }
    else
    {
        ui->infoPersDeathYear->setEnabled(true);
    }
}
