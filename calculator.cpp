#include "calculator.h"
#include "ui_calculator.h"

bool floatOnDisplay=false;
double prevOp=0.0;
char BinSymb=0;
bool binSymbJustPressed=false;
bool floatJustPressed=false;
bool lastPressedIsEq=false;
double newOp;


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

Calculator::~Calculator()
{
    delete ui;
}


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
    }else if(currentlyDisplayedS.length()<=16){
        newValS=currentlyDisplayedS+newValS;
        ui->Display->setText(newValS);
        lastPressedIsEq=false;
        binSymbJustPressed=false;
    }

}




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

void Calculator::clearPressed(){
    ui->Display->setText("0");
    floatOnDisplay=false;
    BinSymb=0;
    floatOnDisplay=false;
    lastPressedIsEq=false;
    prevOp=0.0;
}

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



void Calculator::deletePressed(){
    QString onDisp=ui->Display->text();
    QString mostright=onDisp.right(1);
    if (mostright==".")floatOnDisplay=false;
    onDisp.chop(1);
    ui->Display->setText(onDisp);
    lastPressedIsEq=false;
    binSymbJustPressed=false;
}

void Calculator::equalPressed(){
    double result=0.0;
    QString newOpS=ui->Display->text();

    if (!lastPressedIsEq){
        newOp=newOpS.toDouble();
    }else prevOp=newOpS.toDouble();




    switch (BinSymb) {
        case 1: result=prevOp+newOp;break;
        case 2: result=prevOp-newOp;break;
        case 3: result=prevOp*newOp;break;
        case 4: result=prevOp/newOp;break;
        case 5: result=prevOp+newOp;break;
        case 6: result=prevOp+newOp;break;
        default: result=newOp;break;
    }



    lastPressedIsEq=true;
    ui->Display->setText(QString::number(result, 'g',12));
    binSymbJustPressed=false;
}

void Calculator::changePressed(){
    QString displayedS=ui->Display->text();
    double displayed=displayedS.toDouble();
    displayed*=-1;
    ui->Display->setText(QString::number(displayed, 'g',12));

}

void Calculator::unarySymbolPressed(){
    QPushButton *pressed=(QPushButton *)sender();
    QString pressedName=pressed->objectName();
    if(QString::compare(pressedName, "pushButton_fact",Qt::CaseSensitive)==0){
        ui->Display->setText("Fact");
    }else{
        ui->Display->setText("Sin");
    }
}
