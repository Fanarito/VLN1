#ifndef INFOPAGECOMP_H
#define INFOPAGECOMP_H

#include "computer.h"
#include "service.h"

#include <QDialog>

namespace Ui {
class infoPageComp;
}

class infoPageComp : public QDialog
{
    Q_OBJECT

public:
    explicit infoPageComp(QWidget *parent = 0);
    ~infoPageComp();

    void setComputer(computer comp);

private slots:
    void on_EditComputerCheckbox_stateChanged(int arg1);

    void on_applyComputerButton_clicked();

    void on_closeComputerButton_clicked();

private:
    Ui::infoPageComp *ui;
    computer c;
    service s;
    QString img_path;

    void enableFields();
    void disableFields();
};

#endif // INFOPAGECOMP_H
