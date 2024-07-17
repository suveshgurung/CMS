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
    currDate = QDate::currentDate();
    currTime = QTime::currentTime();

    // day name
    QString dayName = currDate.toString("dddd");

    if (dayName == "Sunday") {
        this->dayName = SUNDAY;
    }
    else if (dayName == "Monday") {
        this->dayName = MONDAY;
    }
    else if (dayName == "Tuesday") {
        this->dayName = TUESDAY;
    }
    else if (dayName == "Wednesday") {
        this->dayName = WEDNESDAY;
    }
    else if (dayName == "Thursday") {
        this->dayName = THURSDAY;
    }
    else if (dayName == "Friday") {
        this->dayName = FRIDAY;
    }

    qDebug() << this->dayName;
}
