#ifndef HELPSCREEN_H
#define HELPSCREEN_H

#include <QDialog>

namespace Ui {
class helpscreen;
}

class helpscreen : public QDialog
{
    Q_OBJECT

public:
    explicit helpscreen(QWidget *parent = 0);
    ~helpscreen();

private:
    Ui::helpscreen *ui;
};

#endif // HELPSCREEN_H
