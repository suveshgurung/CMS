#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "dbConnection.h"
#include "schedule.h"
#include <QTimer>
#include <QDateTime>
#include <QTimeEdit>
#include <QMainWindow>
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

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();
    QTimeEdit *timeEdit = new QTimeEdit;
    timeEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);

    timeEdit->setMinimumTime(QTime(0, 0, 0));
    timeEdit->setMaximumTime(QTime(23, 59, 59));

    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeText = dateTime.toString("ddd MMM dd");
    ui->date_4->setText(dateTimeText);
    ui->date->setText(dateTimeText);
    ui->date_5->setText(dateTimeText);

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
        "}");

    QString usernameText = "Himesh Dulal"; // firstname + lastname retrieved from db
    QString departmentText = "COMP";       // department name using a function

    // Page number for development phase
    QStackedWidget *stackedWidget = ui->stackedWidget;
    int currentIndex = stackedWidget->currentIndex();
    ui->index->setText(QString::number(currentIndex));

    // Set the department text for specific UI elements
    ui->username->setText(usernameText);
    ui->department->setText(departmentText);

    // Loop to set the text of multiple username and department elements
    for (int i = 1; i <= 10; i++)
    {
        QString elementName = "username_" + QString::number(i);
        QString d_elementName = "department_" + QString::number(i);
        QString i_elementName = "index_" + QString::number(i);

        QLabel *departmentLabel = findChild<QLabel *>(d_elementName);
        QLabel *usernameLabel = findChild<QLabel *>(elementName);
        QLabel *indexLabel = findChild<QLabel *>(i_elementName);

        if (indexLabel)
        {
            indexLabel->setText(QString::number(currentIndex));
        }

        if (usernameLabel)
        {
            usernameLabel->setText(usernameText);
        }

        if (departmentLabel)
        {
            departmentLabel->setText(departmentText);
        }
    }

    // loop for stackedWidget UI "SIDEBAR UI"
    for (int i = 1; i <= 5; ++i)
    {
        QString buttonName = "logout_button_" + QString::number(i);
        QString home_buttonName = "home_" + QString::number(i);
        QString schedule_buttonName = "schedule_" + QString::number(i);
        QString booking_buttonName = "booking_" + QString::number(i);

        QPushButton *h_button = findChild<QPushButton *>(home_buttonName);
        QPushButton *button = findChild<QPushButton *>(buttonName);
        QPushButton *sh_button = findChild<QPushButton *>(schedule_buttonName);
        QPushButton *b_button = findChild<QPushButton *>(booking_buttonName);

        if (button)
        {
            connect(button, &QPushButton::clicked, this, &MainWindow::handleLogout);
        }
        if (h_button)
        {
            connect(h_button, &QPushButton::clicked, this, &MainWindow::handleHome);
        }
        if (sh_button)
        {
            connect(sh_button, &QPushButton::clicked, this, &MainWindow::handleSchedule);
        }
        if (b_button)
        {
            connect(b_button, &QPushButton::clicked, this, &MainWindow::handleBooking);
        }
    }
}

void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->time_2->setText(time_text);
    ui->time->setText(time_text);
    ui->time_4->setText(time_text);
    if (time.second() % 2 == 0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    // ui->Digital_Clock->setText(time_text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{

    QMessageBox::information(this, "button clicked", "Logged In Successfully");
    ui->stackedWidget->setCurrentIndex(4);
    // retrieve info from the frontend.
    // QString email = ui->login_email->text();
    // QString password = ui->login_password->text();

    // // check for empty fields.
    // if (email == "" || password == "") {
    //     QMessageBox::information(this, "button clicked", "Email or password is missing!!!");
    //     return;
    // }

    // std::unordered_map<std::string, std::vector<std::string>> userData;
    // std::vector<std::string> userEmails;
    // std::vector<std::string> userPasswords;
    // std::vector<int> userId;
    // bool isUserValid = false;
    // int index = 0;

    // // retrieve data from the database.
    // userData = cmsDb->getData("User_Info");
    // for (const auto& key : userData) {
    //     for (const auto& value : key.second) {

    //         if (key.first == "Email") {
    //             userEmails.push_back(value);
    //         }
    //         if (key.first == "Password") {
    //             userPasswords.push_back(value);
    //         }
    //         if (key.first == "User_ID") {
    //             userId.push_back(std::stoi(value));
    //         }

    //     }
    // }

    // // check if the user email exists.
    // for (size_t i = 0; i < userEmails.size(); i++) {
    //     if (userEmails.at(i) == email.toStdString()) {
    //         isUserValid = true;
    //         index = i;

    //         break;
    //     }
    // }

    // // check if the user entered correct password.
    // if (isUserValid) {

    //     if (userPasswords.at(index) == password.toStdString()) {
    //         user->setUserId(userId.at(index));

    //         userWindow->setUserId(userId.at(index));

    //         userWindow->getSchedule();
    //         ui->stackedWidget->setCurrentIndex(2);
    //     } else {
    //         QMessageBox::information(this, "button clicked", "Incorrect Password!!!");
    //     }
    // } else {
    //     QMessageBox::information(this, "button clicked", "User not found!!!");
    //     return;
    // }
}

void MainWindow::handleLogout()
{

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton)
    {
        on_logout_button_clicked();
    }
}

void MainWindow::handleSchedule()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton)
    {
        on_schedule_clicked();
    }
}

void MainWindow::handleHome()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton)
    {
        on_home_clicked();
    }
}

void MainWindow::handleBooking()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton)
    {
        on_booking_clicked();
    }
}

void MainWindow::on_schedule_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_booking_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_logout_button_clicked()
{

    ui->stackedWidget->setCurrentIndex(3);
}

// void MainWindow::on_new_account_clicked()
// {
//     ui->stackedWidget->setCurrentIndex(4);
// }

void MainWindow::on_sign_in_clicked()
{

    // QString fname = ui->sign_in_fname->text();
    // QString mname = ui->sign_in_mname->text();
    // QString lname = ui->sign_in_lname->text();
    // QString email = ui->sign_in_email->text();
    // QString phoneNumber = ui->sign_in_phoneNumber->text();
    // QString department = ui->sign_in_department->text();
    // QString password = ui->sign_in_password->text();
    // bool male = ui->sign_in_male->isChecked();
    // bool female = ui->sign_in_female->isChecked();

    // if (fname == "" || lname == "" || email == "" || phoneNumber == "" || department == "" || password == "" || (!male && !female)) {
    //     QMessageBox::information(this, "button clicked", "Please enter all the required fileds!!!");
    //     return;
    // }

    // std::unordered_map<std::string, std::string> signInData;

    // signInData["First_Name"] = fname.toStdString();
    // if (mname != "") {
    //     signInData["Middle_Name"] = mname.toStdString();
    // }
    // signInData["Last_Name"] = lname.toStdString();
    // signInData["Email"] = email.toStdString();
    // signInData["Department"] = department.toStdString();
    // signInData["Phone_Number"] = phoneNumber.toStdString();
    // signInData["Password"] = password.toStdString();
    // if (male) {
    //     signInData["Gender"] = "Male";
    // } else if (female) {
    //     signInData["Gender"] = "Female";
    // }

    // if (cmsDb->insertData(signInData, "User_Info")) {
    //     qDebug() << "Successfull";
    // } else {
    //     qDebug() << "Unsuccessful";
    // }

    QMessageBox::information(this, "button clicked", "SignedIn Successfully");

    ui->stackedWidget->setCurrentIndex(3);
}

// void MainWindow::on_back_login_clicked()
// {
//     ui->stackedWidget->setCurrentIndex(0);
// }

void MainWindow::on_register_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_login_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_login_redirect_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

// void MainWindow::on_signup_clicked()
// {
//     ui->stackedWidget->setCurrentIndex(1);
// }

void MainWindow::on_signup_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
