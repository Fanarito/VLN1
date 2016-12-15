#ifndef INFOPAGE_H
#define INFOPAGE_H
#include "person.h"
#include <QDialog>
#include <QResizeEvent>
#include <string>

namespace Ui {
class InfoPage;
}

class InfoPage : public QDialog
{
    Q_OBJECT

public:
    explicit InfoPage(QWidget *parent = 0);
    ~InfoPage();
    void setPerson(person pers);

private:
    Ui::InfoPage *ui;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    person p;
    QString img_path;
};

#endif // INFOPAGE_H
