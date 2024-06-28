#include "dbConnection.h"


/*
* @brief    contructor definition of class CMSDatabase
* @params   null
* @retval   null
*/
CMSDatabase::CMSDatabase() {
    // set database type. 
    db = QSqlDatabase::addDatabase("QSQLITE");
}


/*
* @brief    method to connect the application to the Database
* @params   null
* @retval   bool
*           true->connection successful
*           false->connection unsuccessful
*/
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
