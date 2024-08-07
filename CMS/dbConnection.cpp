#include "dbConnection.h"
#include <string>
#include <unordered_map>

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
    db.setDatabaseName("CMS_DB.db");

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

CMSDatabase::~CMSDatabase() {
    db.close();
    QSqlDatabase::removeDatabase("CMSConnection");

    delete cmsDb;
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

    // get the keys and the corresponding values and put them in a QStringList
    for (const auto& pair : dataList) {
        columns << QString::fromStdString(pair.first);
        values << QString("'%1'").arg(QString::fromStdString(pair.second));
    }

    // prepare the insert query
    QString insertQuery = QString("INSERT INTO %1 (%2) VALUES (%3)")
        .arg(QString::fromStdString(tableName))
        .arg(columns.join(", "))
        .arg(values.join(", "));

    // execute the query
    if (!query.exec(insertQuery)) {
        qDebug() << "Error: Unable to insert data."; 
        qDebug() << query.lastError();
        return false;
    } else {
        qDebug() << "Successfully entered data!!!";
    }

    return true;
}



/*
* @brief    method to get data from a table.
* @params   const std::string tableName
*           name of the table from where the data is needed.
*           const std::string condition = "" 
*           extra condition for the query.
* @retval   std::unordered_map<std::string, std::vector<std::string>>
*           the ouput of the select query kept in a key value pair.
*/
std::unordered_map<std::string, std::vector<std::string>> CMSDatabase::getData(const std::string& tableName) {

    QSqlQuery query;
    std::unordered_map<std::string, std::vector<std::string>> tableData;

    QString selectQuery;

    // get all data from the table.
    selectQuery = QString("SELECT * FROM %1")
        .arg(QString::fromStdString(tableName));

    // execute the query.
    if (!query.exec(selectQuery)) {
        qDebug() << "Error: Unable to fetch data.";
        qDebug() << query.lastError();
        return tableData;
    }

    // get the returned value from the query and the number of fields returned.
    QSqlRecord record = query.record();
    int colNumber = query.record().count();
    
    QString columnName;

    for (int i = 0; i < colNumber; i++) {
        columnName = record.fieldName(i);

        tableData[columnName.toStdString()] = std::vector<std::string>(); 
    }

    // iterate over every row of the table.
    while (query.next()) {
        for (int i = 0; i < colNumber; i++) {
            columnName = record.fieldName(i);

            // push data of each row in the corresponding field.
            std::string data = QString(query.value(i).toString()).toStdString();
            tableData[columnName.toStdString()].push_back(data);
        }
    }

    // reference to show how to access the field name and the values of the corresponding field. Later needed in application.
    //for (const auto& key : tableData) {
    //    qDebug() << key.first << ": ";

    //    for (const auto& value : key.second) {
    //        qDebug() << value << " ";
    //    }
    //}

    return tableData;
    
}


std::unordered_map<std::string, std::vector<std::string>> CMSDatabase::getData(const std::string& tableName, const std::string& condition) {

    QSqlQuery query;
    std::unordered_map<std::string, std::vector<std::string>> tableData;

    QString selectQuery;

    // get all data from the table.
    selectQuery = QString("SELECT * FROM %1 %2")
        .arg(QString::fromStdString(tableName))
        .arg(QString::fromStdString(condition));

    // execute the query.
    if (!query.exec(selectQuery)) {
        qDebug() << "Error: Unable to fetch data.";
        qDebug() << query.lastError();
        return tableData;
    }

    // get the returned value from the query and the number of fields returned.
    QSqlRecord record = query.record();
    int colNumber = query.record().count();
    
    QString columnName;

    for (int i = 0; i < colNumber; i++) {
        columnName = record.fieldName(i);

        tableData[columnName.toStdString()] = std::vector<std::string>(); 
    }

    // iterate over every row of the table.
    while (query.next()) {
        for (int i = 0; i < colNumber; i++) {
            columnName = record.fieldName(i);

            // push data of each row in the corresponding field.
            std::string data = QString(query.value(i).toString()).toStdString();
            tableData[columnName.toStdString()].push_back(data);
        }
    }

    // reference to show how to access the field name and the values of the corresponding field. Later needed in application.
    //for (const auto& key : tableData) {
    //    qDebug() << key.first << ": ";

    //    for (const auto& value : key.second) {
    //        qDebug() << value << " ";
    //    }
    //}

    return tableData;
}
