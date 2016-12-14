#ifndef INFOPAGECOMP_H
#define INFOPAGECOMP_H

#include "computer.h"

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

private:
    Ui::infoPageComp *ui;
    computer c;
};

#endif // INFOPAGECOMP_H
