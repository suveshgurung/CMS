#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include<QTimer>
#include<QDateTime>
#include<QTimeEdit>
#include<QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include <QApplication>
#include <QString>
#include <QSqlError>
#include "dbConnection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect (timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
    QTimeEdit *timeEdit = new QTimeEdit;
    timeEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);

    timeEdit->setMinimumTime(QTime(0, 0, 0));
    timeEdit->setMaximumTime(QTime(23, 59, 59));
    QMainWindow mainWindow;
    mainWindow.resize(1920, 1080);
    QStackedWidget stackedWidget(&mainWindow);
    stackedWidget.setGeometry(0, 0, 1920, 1080);

    QWidget featureWidget(&stackedWidget);
    QLabel label("Feature Widget", &featureWidget);
    label.setAlignment(Qt::AlignCenter);

    stackedWidget.addWidget(&featureWidget);
    stackedWidget.setCurrentWidget(&featureWidget);

    mainWindow.setCentralWidget(&stackedWidget);
    mainWindow.show();
    QPushButton *findDate = new QPushButton("Find");

    // Apply a stylesheet with a hover effect
    findDate->setStyleSheet(
        "QPushButton {"
        "border: 2px solid black;"
        "border-radius: 10px;" // Curved border
        "padding: 10px;"
        "background-color: lightgreen;"
        "}"
        "QPushButton:hover {"
        "background-color: darkgreen;"
        "color: white;"
        "}"
        );




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

    cmsDb->close();
    delete cmsDb;

    qDebug() << "Database closed Successfully";
}



void MainWindow::on_loginButton_clicked()
{
    QMessageBox:: information(this, "button clicked", "Logged In Successfully");
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_new_account_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_sign_in_clicked()
{
     QMessageBox:: information(this, "button clicked", "Logged In Successfully");
}


void MainWindow::on_back_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

