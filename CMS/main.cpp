#include "mainwindow.h"
#include "dbConnection.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CMSDatabase cmsDb;
    cmsDb.connect();

    MainWindow w;
    w.show();
    return a.exec();
}
