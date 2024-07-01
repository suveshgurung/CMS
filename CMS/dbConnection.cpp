#include "dbConnection.h"

CMSDatabase* cmsDb = nullptr;

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


/*
* @brief    method to insert data into a Database
* @params   (std::unordered_map<std::string, std::string>& dataList, std::string tableName)
*           reference variable to the key value pair containing the data to be inserted.
*           name of the table in which we want to enter the data.
* @retval   bool
*           true->data insertion was successful
*           false->data insertion was unsuccessful
*/
bool CMSDatabase::insertData(const std::unordered_map<std::string, std::string>& dataList, const std::string tableName) {

    QSqlQuery query;
    QStringList columns, values;

    for (const auto& pair : dataList) {
        columns << QString::fromStdString(pair.first);
        values << QString("'%1'").arg(QString::fromStdString(pair.second));
    }

    QString insertQuery = QString("INSERT INTO %1 (%2) VALUES (%3)")
        .arg(QString::fromStdString(tableName))
        .arg(columns.join(", "))
        .arg(values.join(", "));

    if (!query.exec(insertQuery)) {
        qDebug() << "Error: Unable to execute query." << query.lastError();
        return false;
    } else {
        qDebug() << "Successfully entered data!!!";
    }

    return true;
}



