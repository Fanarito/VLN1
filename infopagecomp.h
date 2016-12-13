#ifndef INFOPAGECOMP_H
#define INFOPAGECOMP_H

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

private:
    Ui::infoPageComp *ui;
};

#endif // INFOPAGECOMP_H
