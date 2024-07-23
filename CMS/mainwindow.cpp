#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "dbConnection.h"
#include "schedule.h"
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
#include <cstddef>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // logoWidget = new LogoWidget(this);
    //
    QTimer *timer=new QTimer(this);
    connect (timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
    QTimeEdit *timeEdit = new QTimeEdit;
    timeEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);

    timeEdit->setMinimumTime(QTime(0, 0, 0));
    timeEdit->setMaximumTime(QTime(23, 59, 59));
    // QMainWindow mainWindow;
    // mainWindow.resize(1920, 1080);
    // QStackedWidget stackedWidget(&mainWindow);
    // stackedWidget.setGeometry(0, 0, 1920, 1080);

    // QWidget featureWidget(&stackedWidget);
    // QLabel label("Feature Widget", &featureWidget);
    // label.setAlignment(Qt::AlignCenter);
    //
    // stackedWidget.addWidget(&featureWidget);
    // stackedWidget.setCurrentWidget(&featureWidget);
    //
    // mainWindow.setCentralWidget(&stackedWidget);
    // mainWindow.show();
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
}



void MainWindow::on_loginButton_clicked()
{

    // retrieve info from the frontend.
    QString email = ui->login_email->text();
    QString password = ui->login_password->text();

    // check for empty fields.
    if (email == "" || password == "") {
        QMessageBox::information(this, "button clicked", "Email or password is missing!!!");
        return;
    }

    std::unordered_map<std::string, std::vector<std::string>> userData;
    std::vector<std::string> userEmails;
    std::vector<std::string> userPasswords;
    std::vector<int> userId;
    bool isUserValid = false;
    int index = 0;

    // retrieve data from the database.
    userData = cmsDb->getData("User_Info");
    for (const auto& key : userData) {
        for (const auto& value : key.second) {
            
            if (key.first == "Email") {
                userEmails.push_back(value);
            }
            if (key.first == "Password") {
                userPasswords.push_back(value);
            }
            if (key.first == "User_ID") {
                userId.push_back(std::stoi(value));
            }

        }
    }

    // check if the user email exists.
    for (size_t i = 0; i < userEmails.size(); i++) {
        if (userEmails.at(i) == email.toStdString()) {
            isUserValid = true;
            index = i;

            break;
        }
    }

    // check if the user entered correct password.
    if (isUserValid) {
        
        if (userPasswords.at(index) == password.toStdString()) {
            user->setUserId(userId.at(index));
            
            userWindow->setUserId(userId.at(index));

            userWindow->getSchedule();
            update_room_status();
            ui->stackedWidget->setCurrentIndex(3);
        } else {
            QMessageBox::information(this, "button clicked", "Incorrect Password!!!");
        }
    } else {
        QMessageBox::information(this, "button clicked", "User not found!!!");
        return;
    }

}


void MainWindow::on_new_account_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_sign_in_clicked()
{

    QString fname = ui->sign_in_fname->text();
    QString mname = ui->sign_in_mname->text();
    QString lname = ui->sign_in_lname->text();
    QString email = ui->sign_in_email->text();
    QString phoneNumber = ui->sign_in_phoneNumber->text();
    QString department = ui->sign_in_department->text();
    QString password = ui->sign_in_password->text();
    bool male = ui->sign_in_male->isChecked();
    bool female = ui->sign_in_female->isChecked();

    if (fname == "" || lname == "" || email == "" || phoneNumber == "" || department == "" || password == "" || (!male && !female)) {
        QMessageBox::information(this, "button clicked", "Please enter all the required fileds!!!");
        return;
    }

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

    QMessageBox::information(this, "button clicked", "SignedIn Successfully");

    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_back_login_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::update_room_status() {
    
    std::vector<Room> rooms = userWindow->getRooms();

    for (size_t i = 0; i < rooms.size(); i++) {

        switch (rooms.at(i)) {
            case ROOM_106:
                ui->room_106->setStyleSheet("background-color: rgb(224, 27, 36);");
                break;
            case ROOM_107:
                ui->room_107->setStyleSheet("background-color: rgb(224, 27, 36);");
                break;
            case ROOM_108:
                ui->room_108->setStyleSheet("background-color: rgb(224, 27, 36);");
                break;
            case ROOM_109:
                ui->room_109->setStyleSheet("background-color: rgb(224, 27, 36);");
                break;
            case ROOM_207:
                ui->room_207->setStyleSheet("background-color: rgb(224, 27, 36);");
                break;
            case ROOM_208:
                ui->room_208->setStyleSheet("background-color: rgb(224, 27, 36);");
                break;
            case ROOM_209:
                ui->room_209->setStyleSheet("background-color: rgb(224, 27, 36);");
                break;
            default:
                break;
        }

    }
}
