#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_submitButton_clicked()
//{
//    QString fname = ui->firstName->toPlainText();
//    QString mname = ui->middleName->toPlainText();
//    QString lname = ui->lastName->toPlainText();
//    QString email = ui->email->toPlainText();
//    QString password = ui->password->toPlainText();
//
//    QSqlQuery query;
//
//    QString insertQuery= QString("INSERT INTO User_Info (First_Name, Last_Name, Email, Password) "
//                               "VALUES ('%1', '%2', '%3', '%4')")
//                                .arg(fname)
//                                .arg(lname)
//                                .arg(email)
//                                .arg(password);
//
//    if (!query.exec(insertQuery)) {
//        qDebug() << "Error: Unable to execute query." << query.lastError();
//        return;
//    }
//
//    if (mname != "") {
//        insertQuery = QString("INSERT INTO User_Info (Middle_Name)"
//                              "VALUES ('%1')")
//                                .arg(mname);
//
//        if (!query.exec(insertQuery)) {
//            qDebug() << "Error: Unable to execute query." << query.lastError();
//            return;
//        }
//    }
//
//    qDebug() << "Successfully entered data!!!";
//}

//void MainWindow::on_firstName_textChanged()
//{
//
//}
