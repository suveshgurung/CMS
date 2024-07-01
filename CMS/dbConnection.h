#ifndef DB_CONNECTION
#define DB_CONNECTION


#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <unordered_map>
#include <string>


class CMSDatabase {
private:
    QSqlDatabase db;

public:
    // constructor
    CMSDatabase();

    // method to connect to the database.
    bool connect();

    // method to insert data into database.
    bool insertData(const std::unordered_map<std::string, std::string>& dataList, const std::string tableName);
};

extern CMSDatabase* cmsDb;

#endif // !
