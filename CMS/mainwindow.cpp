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
#include <unordered_map>
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


void MainWindow::on_loginButton_clicked()
{
    QMessageBox:: information(this, "button clicked", "Logged In Successfully");
    ui->stackedWidget->setCurrentIndex(4);
        // Get the text from the username and password fields
        //QString username = username_3->text();
        //QString password = password_3->text();

        // Validate the input
        //if (username.isEmpty() || password.isEmpty()) {
            // Display an error message if either field is empty
        //    errorLabel->setText("Invalid username or password");
        //    errorLabel->setStyleSheet("QLabel { color : red; }");  // Make error message red
        //} else {
            // Proceed with login process
        //    errorLabel->clear();
            // Add login handling code here
        //}
}



void MainWindow::on_register_redirect_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}




void MainWindow::on_login_redirect_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_login_redirect_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_signup_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_signup_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}



void MainWindow::on_back_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

