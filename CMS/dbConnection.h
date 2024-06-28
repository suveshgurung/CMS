#ifndef DB_CONNECTION
#define DB_CONNECTION

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

class CMSDatabase {
private:
    QSqlDatabase db;

public:
    // constructor
    CMSDatabase();

    // method to connect to the database.
    bool connect();
};

namespace dbConnection {
    bool connect(); 
}


#endif // !
