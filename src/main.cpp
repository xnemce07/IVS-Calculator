/*********************************************************
 * @file main.cpp
 * @author Leopold Nemcek, <xnemce07@stud.fit.vutbr.cz>
 * @brief main function, used to run the app
 * @date 22.4.2020
 ********************************************************/

#include "calculator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.show();
    return a.exec();
}
