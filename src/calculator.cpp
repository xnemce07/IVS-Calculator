/*******************************************************
 * @file calculator.cpp
 * @author Leopold Nemcek, <xnemce07@stud.fit.vutbr.cz>
 * @brief calculator button press actions
 * @date 22.4.2020
 ******************************************************/

#include "calculator.h"
#include "ui_calculator.h"
#include "dialoghelp.h"
#include "CustomMath.h"

bool floatOnDisplay=false;
double prevOp=0.0;
char BinSymb=0;
bool binSymbJustPressed=false;
bool floatJustPressed=false;
bool lastPressedIsEq=false;
bool ERR=false;
double newOp;

CustomMath CMath;

/**
 * @brief constructor
 **/
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Display->setText("0");

    connect(ui->pushButton_0, SIGNAL (released()), this, SLOT (NumberPressed()));
    connect(ui->pushButton_1, SIGNAL (released()), this, SLOT (NumberPressed()));
    connect(ui->pushButton_2, SIGNAL (released()), this, SLOT (NumberPressed()));
    connect(ui->pushButton_3, SIGNAL (released()), this, SLOT (NumberPressed()));
    connect(ui->pushButton_4, SIGNAL (released()), this, SLOT (NumberPressed()));
    connect(ui->pushButton_5, SIGNAL (released()), this, SLOT (NumberPressed()));
    connect(ui->pushButton_6, SIGNAL (released()), this, SLOT (NumberPressed()));
    connect(ui->pushButton_7, SIGNAL (released()), this, SLOT (NumberPressed()));
    connect(ui->pushButton_8, SIGNAL (released()), this, SLOT (NumberPressed()));
    connect(ui->pushButton_9, SIGNAL (released()), this, SLOT (NumberPressed()));




    connect(ui->pushButton_div, SIGNAL (released()), this, SLOT (binarySymbolPressed()));
    connect(ui->pushButton_minus, SIGNAL (released()), this, SLOT (binarySymbolPressed()));
    connect(ui->pushButton_mul, SIGNAL (released()), this, SLOT (binarySymbolPressed()));
    connect(ui->pushButton_plus, SIGNAL (released()), this, SLOT (binarySymbolPressed()));
    connect(ui->pushButton_pow, SIGNAL (released()), this, SLOT (binarySymbolPressed()));
    connect(ui->pushButton_root, SIGNAL (released()), this, SLOT (binarySymbolPressed()));

    connect(ui->pushButton_fact, SIGNAL (released()), this, SLOT (unarySymbolPressed()));
    connect(ui->pushButton_sin, SIGNAL (released()), this, SLOT (unarySymbolPressed()));

    connect(ui->pushButton_clear, SIGNAL (released()), this, SLOT (clearPressed()));

    connect(ui->pushButton_float, SIGNAL (released()), this, SLOT (floatPressed()));

    connect(ui->pushButton_delete, SIGNAL (released()), this, SLOT (deletePressed()));

    connect(ui->pushButton_eq, SIGNAL (released()), this, SLOT (equalPressed()));

    connect(ui->pushButton_change, SIGNAL (released()), this, SLOT (changePressed()));





}

/**
 * @brief destructor
 **/
Calculator::~Calculator()
{
    delete ui;
}

/**
 * @brief shows number pressed on display
 **/
void Calculator::NumberPressed(){
    QPushButton *pressed=(QPushButton *)sender();
    QString newValS=pressed->text();
    //double newVal=newValS.toDouble();
    QString currentlyDisplayedS=ui->Display->text();
    double currentlyDisplayed=currentlyDisplayedS.toDouble();

    if(((currentlyDisplayed == 0 || binSymbJustPressed) && !floatOnDisplay) || lastPressedIsEq){
        ui->Display->setText(newValS);
        binSymbJustPressed=false;
        floatOnDisplay=false;
        lastPressedIsEq=false;
        binSymbJustPressed=false;
    }else if(currentlyDisplayedS.length()<=10){
        newValS=currentlyDisplayedS+newValS;
        ui->Display->setText(newValS);
        lastPressedIsEq=false;
        binSymbJustPressed=false;
    }

}

/**
 * Stores current display value as the first operand,
 * and waits for the next operand.
 * Button pressed indicates the function to be used ( + - * / )
 * @brief stores first operand, defines function to be used, then waits for the second operand
 **/
void Calculator::binarySymbolPressed(){
    QPushButton *pressed=(QPushButton *)sender();
    QString symb=pressed->objectName();

    QString prevOpS=ui->Display->text();
    prevOp=prevOpS.toDouble();

    binSymbJustPressed=true;

    if(QString::compare(symb, "pushButton_plus",Qt::CaseSensitive)==0){
        BinSymb=1;
    }else if(QString::compare(symb, "pushButton_minus",Qt::CaseSensitive)==0){
        BinSymb=2;
    }else if(QString::compare(symb, "pushButton_mul",Qt::CaseSensitive)==0){
        BinSymb=3;
    }else if(QString::compare(symb, "pushButton_div",Qt::CaseSensitive)==0){
        BinSymb=4;
    }else if(QString::compare(symb, "pushButton_pow",Qt::CaseSensitive)==0){
        BinSymb=5;
    }else{
        BinSymb=6;
    }
    floatOnDisplay=false;
    lastPressedIsEq=false;
}

/**
 * @brief clear display and reset the calculator's state
 **/
void Calculator::clearPressed(){
    ui->Display->setText("0");
    floatOnDisplay=false;
    BinSymb=0;
    floatOnDisplay=false;
    lastPressedIsEq=false;
    prevOp=0.0;
}

/**
 * @brief add floating point
 **/
void Calculator::floatPressed(){
    if (binSymbJustPressed || lastPressedIsEq){
        ui->Display->setText("0.");
        floatOnDisplay=true;
    }else
    if (!floatOnDisplay){
       // floatJustPressed=true;
        QString onDisp=ui->Display->text();
        onDisp=onDisp+".";
        ui->Display->setText(onDisp);
        floatOnDisplay=true;
    }
    lastPressedIsEq=false;
    binSymbJustPressed=false;
}

/**
 * @brief delete last character
 **/
void Calculator::deletePressed(){
    QString onDisp=ui->Display->text();
    QString mostright=onDisp.right(1);
    if (mostright==".")floatOnDisplay=false;
    onDisp.chop(1);
    ui->Display->setText(onDisp);
    lastPressedIsEq=false;
    binSymbJustPressed=false;
}

/**
 * @brief show result
 **/
void Calculator::equalPressed(){
    double result=0.0;
    QString newOpS=ui->Display->text();

    if (!lastPressedIsEq){
        newOp=newOpS.toDouble();
    }else prevOp=newOpS.toDouble();




    switch (BinSymb) {
        case 1:
        try
        {
            result=CMath.addition(prevOp,newOp);
        }catch(...){ERR=true;}
        break;
        case 2:
        try
        {
            result=CMath.substraction(prevOp,newOp);
        }catch(...){ERR=true;}
        break;
        case 3:
        try
        {
            result=CMath.multiplication(prevOp,newOp);
        }catch(...){ERR=true;}
        break;
        case 4:
        try
        {
            result=CMath.division(prevOp,newOp);
        }catch(...){ERR=true;}
        break;
        case 5:
        try
        {
            result=CMath.power(prevOp,newOp);
        }catch(...){ERR=true;}
        break;
        case 6:
        try
        {
            result=CMath.root(prevOp,newOp);
        }catch(...){ERR=true;}
        break;
        default: result=newOp;break;
    }



    if(!ERR){
    ui->Display->setText(QString::number(result, 'g',10));
    }else{ui->Display->setText("ERR");}
    lastPressedIsEq=true;
    binSymbJustPressed=false;
    ERR=false;
}

/**
 * @brief show inversed value of current number (+/-)
 **/
void Calculator::changePressed(){

    QString displayedS=ui->Display->text();
    double displayed=displayedS.toDouble();
    displayed*=-1;
    ui->Display->setText(QString::number(displayed, 'g',10));

}

/**
 * @brief factorial or sin button press - show result
 **/
void Calculator::unarySymbolPressed(){
    QPushButton *pressed=(QPushButton *)sender();
    QString pressedName=pressed->objectName();
    QString unOpS=ui->Display->text();
    double unOp=unOpS.toDouble();
    double result;

    if(QString::compare(pressedName, "pushButton_fact",Qt::CaseSensitive)==0){
        try
        {
            result=CMath.factorial(unOp);
        }catch(...){ERR=true;}
    }else{
        try
        {
            result=CMath.mySin(unOp);
        }catch(...){ERR=true;}
    }
    if(!ERR){
    ui->Display->setText(QString::number(result, 'g',10));
    }else{ui->Display->setText("ERR");}
    ERR=false;
    lastPressedIsEq=true;
    binSymbJustPressed=false;
}

/**
 * @brief opens dialog help window
 **/
void Calculator::on_actionHelp_triggered()
{

    DialogHelp DialogHelp;
    DialogHelp.setModal(true);
    DialogHelp.exec();
}
