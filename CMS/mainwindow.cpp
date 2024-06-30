#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTimer>
#include<QDateTime>
#include <QString>
#include <QSqlError>
#include <unordered_map>
#include "dbConnection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect (timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}

void MainWindow::showTime(){
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    if(time.second()%2==0){
        time_text[3]=' ';
        time_text[8]=' ';
    }
    ui->Digital_Clock->setText(time_text);

}
MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_test_clicked()
//{
//    std::unordered_map<std::string, std::string> test;
//
//    test["First_name"] = "Suvesh";
//    test["Middle_name"] = "Bahadur";
//    test["Last_name"] = "Gurung";
//    test["Email"] = "suveshgurung2@gmail.com";
//    test["Faculty"] = "COMP102";
//    test["Phone_Number"] = "9860654346";
//    test["Password"] = "GHemaOp12<3";
//
//
//    cmsDb->insertData(test, "user_info");
//}
