#include "mainwindow.h"
#include "dbConnection.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cmsDb = new CMSDatabase();
    cmsDb->connect();

    MainWindow w;
    w.show();
    return a.exec();
}
