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

    w.setMinimumSize(1920, 1080);
    w.setMaximumSize(1920, 1080);

    w.show();
    return a.exec();
}
