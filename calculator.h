#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;

private slots:
    void NumberPressed();
    void binarySymbolPressed();
    void clearPressed();
    void equalPressed();
    void changePressed();
    void floatPressed();
    void deletePressed();
    void unarySymbolPressed();
};
#endif // CALCULATOR_H
