#include "dbConnection.h"

bool dbConnection::connect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/subbu/KU/CS/1st year 2nd sem/second sem project/CMS/CMS/CMS_DB.db");
    //db.setDatabaseName("/home/subbu/Downloads/chinook.db");

    if (!db.open()) {
        qDebug() << "Error: Unable to setup connection with database!!!";
        qDebug() << db.lastError().text();
        return false;
    }

    qDebug() << "Database Connection Successful!!!";

    qDebug() << "Tables : " << db.tables();

    return true;
}

CMSDatabase::CMSDatabase() {
    // set database type. 
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool CMSDatabase::connect() {
    // connect the database.
    db.setDatabaseName("/home/subbu/KU/CS/1st year 2nd sem/second sem project/CMS/CMS/CMS_DB.db");
    
    // check if the database is open or not.
    if (!db.open()) {
        qDebug() << "Error: Unable to setup connection with database!!!";
        qDebug() << db.lastError().text();
        return false;
    }

    qDebug() << "Database connection successful!!!";
    qDebug() << "The tables of the database are : " << db.tables();

    return true;
}
