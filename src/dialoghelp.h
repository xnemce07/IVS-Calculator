/********************************************************
 * @file dialoghelp.h
 * @author Leopold Nemcek, <xnemce07@stud.fit.vutbr.cz>
 * @brief help dialog header
 * @date 22.4.2020
 ********************************************************/

#ifndef DIALOGHELP_H
#define DIALOGHELP_H

#include <QDialog>

namespace Ui {
class DialogHelp;
}

class DialogHelp : public QDialog
{
    Q_OBJECT

public:
    explicit DialogHelp(QWidget *parent = nullptr);
    ~DialogHelp();

private:
    Ui::DialogHelp *ui;
};

#endif // DIALOGHELP_H
