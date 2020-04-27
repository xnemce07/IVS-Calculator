/**********************************************************
 * @file dialoghelp.cpp
 * @author Leopold Nemcek, <xnemce07@stud.fit.vutbr.cz>
 * @brief help dialog
 * @date 22.4.2020
 **********************************************************/

#include "dialoghelp.h"
#include "ui_dialoghelp.h"

DialogHelp::DialogHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHelp)
{
    ui->setupUi(this);
}

DialogHelp::~DialogHelp()
{
    delete ui;
}
