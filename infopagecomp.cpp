#include "infopagecomp.h"
#include "ui_infopagecomp.h"

infoPageComp::infoPageComp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infoPageComp)
{
    ui->setupUi(this);
}

infoPageComp::~infoPageComp()
{
    delete ui;
}

void infoPageComp::setComputer(computer comp)
{
    c = comp;

    ui->infoCompName->setText(c.getName());
    ui->infoCompType->setText(c.getType());
    QString build_year = QString::number(c.getBuildYear());
    ui->infoCompBuiltYear->setText(build_year);
    ui->infoCompNationality->setText(c.getNationality());
    ui->infoCompInfo->setText(c.getInfo());

    img_path = constants::IMAGE_PATH + QString::fromStdString("c" + std::to_string(c.getId()));
    if (!QFile::exists(img_path))
        img_path = constants::IMAGE_PATH + QString::fromStdString("noimg");

    ui->infoCompPic->setPixmap(QPixmap(img_path).scaledToHeight(100));
}

