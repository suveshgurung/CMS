#include "schedule.h"
#include "dbConnection.h"

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

    date = currDate.toString();
    time = currTime.toString();

    std::string tempTime = time.toStdString().substr(0, 2);
    hour = std::stoi(tempTime);

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

}

UserWindow::~UserWindow() {
    delete userWindow;
}


int UserWindow::getDay() {
    return dayName;
}

void UserWindow::getSchedule() {

    std::unordered_map<std::string, std::vector<std::string>> scheduleData;
    QString startTime = QString::number(hour) + ":00";
    QString endTime = QString::number(hour+1) + ":00";

    std::string condition = QString("WHERE start_time='%1' AND end_time='%2' AND day_id='%3'")
        .arg(startTime)
        .arg(endTime)
        .arg(dayName)
        .toStdString();

    // qDebug() << condition;

    scheduleData = cmsDb->getData("Schedule", condition);

    for (const auto& pair : scheduleData) {
        qDebug() << pair.first;
        for (size_t i = 0; i < pair.second.size(); i++) {
            qDebug() << pair.second.at(i);
        }
        // qDebug() << pair.second;
    }

}
