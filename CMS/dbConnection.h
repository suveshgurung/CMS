#pragma once

#ifndef DB_CONNECTION
#define DB_CONNECTION

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <unordered_map>
#include <string>
#include <vector>


class CMSDatabase {
private:
    QSqlDatabase db;

public:
    // constructor and destructor.
    CMSDatabase();
    ~CMSDatabase();

    // method to connect to the database.
    bool connect();

    // method to insert data into database.
    bool insertData(const std::unordered_map<std::string, std::string>& dataList, const std::string tableName);
    
    // method to get data from the database;
    std::unordered_map<std::string, std::vector<std::string>> getData(const std::string& tableName);
    std::unordered_map<std::string, std::vector<std::string>> getData(const std::string& tableName, const std::string& condition);

};

extern CMSDatabase* cmsDb;

#endif // !
