#include "schedule.h"

User* user = nullptr;
UserWindow* userWindow = nullptr;

User::User() {
    // user id 0 means no user is present.
    // later can be used for conditional rendering.
    userId = 0;
}

User::~User() {
    delete user;
}

void User::setUserId(int id) {
    userId = id;
}

int User::getUserId() {
    return userId;
}


UserWindow::UserWindow() {
    // date and time of the day.
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    // day name
    QString day = date.toString("dddd");
    qDebug() << day;
    qDebug() << time.toString("HH:mm:ss");
    qDebug() << date.toString("yyyy-MM-dd");
}
