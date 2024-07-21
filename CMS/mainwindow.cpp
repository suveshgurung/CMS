#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "dbConnection.h"
#include<QTimer>
#include<QDateTime>
#include<QTimeEdit>
#include<QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include <QApplication>
#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    logoWidget = new LogoWidget(this);

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
    // ui->Digital_Clock->setText(time_text);

}
MainWindow::~MainWindow()
{
    delete ui;

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
     // QMessageBox:: information(this, "button clicked", "Logged In Successfully");

    QString fname = ui->sign_in_fname->text();
    QString mname = ui->sign_in_mname->text();
    QString lname = ui->sign_in_lname->text();
    QString email = ui->sign_in_email->text();
    QString phoneNumber = ui->sign_in_phoneNumber->text();
    QString department = ui->sign_in_department->text();
    QString password = ui->sign_in_password->text();
    bool male = ui->sign_in_male->isChecked();
    bool female = ui->sign_in_female->isChecked();

    std::unordered_map<std::string, std::string> signInData;

    signInData["First_Name"] = fname.toStdString();
    if (mname != "") {
        signInData["Middle_Name"] = mname.toStdString();
    }
    signInData["Last_Name"] = lname.toStdString();
    signInData["Email"] = email.toStdString();
    signInData["Department"] = department.toStdString();
    signInData["Phone_Number"] = phoneNumber.toStdString();
    signInData["Password"] = password.toStdString();
    if (male) {
        signInData["Gender"] = "Male";
    } else if (female) {
        signInData["Gender"] = "Female";
    }

    if (cmsDb->insertData(signInData, "User_Info")) {
        qDebug() << "Successfull";
    } else {
        qDebug() << "Unsuccessful";
    }
}


void MainWindow::on_back_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

