#include "mainwindow.h"
#include "dbConnection.h"
#include "schedule.h"
#include <QScreen>
#include <QGuiApplication>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cmsDb = new CMSDatabase();
    cmsDb->connect();

    user = new User();
    userWindow = new UserWindow();

    MainWindow w;

    // w.setMinimumSize(1920, 1080);
    // w.setMaximumSize(1920, 1080);

    w.show();
    return a.exec();
}

//MainWindow::MainWindow(QWidget *parent)
    //: QMainWindow(parent) {
    // Initialize UI elements
    //username_3 = new QLineEdit(this);
    //password_3 = new QLineEdit(this);
    //loginButton_2 = new QPushButton("Login", this);
    //errorLabel = new QLabel(this);

    // Layout and positioning code here...

    // Connect the login button's clicked signal to the slot
    //connect(loginButton_2, &QPushButton::clicked, this, &MainWindow::on_loginButton_2_clicked);
//}
