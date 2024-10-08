#include "schedule.h"
#include "dbConnection.h"
#include <cstddef>

User* user = nullptr;
UserWindow* userWindow = nullptr;
UserWindow* bookingWindow = nullptr;

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

void User::setUser(int id, std::string fname, std::string mname, std::string lname, std::string email, std::string department , std::string phone)
{
    userId=id;
    fname=FirstName;
    mname=MiddleName;
    lname=LastName;
    email=email;
    Department=department;
    PhoneNumber=phone;
    // std::cout<<"User logged in with proper credentials"<<std::endl;
}

std::string User::getFirstName() const {
    return FirstName;
}

std::string User::getMiddleName() const {
    return MiddleName;
}

std::string User::getLastName() const {
    return LastName;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getDepartment() const {
    return Department;
}

std::string User::getPhoneNumber() const {
    return PhoneNumber;
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

    // get only the hour part of the time.
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

QString UserWindow::getStartTime() {
    return startTime;
}

QString UserWindow::getEndTime() {
    return endTime;
}

void UserWindow::getSchedule() {

    std::unordered_map<std::string, std::vector<std::string>> defaultScheduleData;
    std::unordered_map<std::string, std::vector<std::string>> bookedScheduleData;
    std::unordered_map<std::string, std::vector<std::string>> combinedScheduleData;
    startTime = QString::number(hour) + ":00";
    endTime = QString::number(hour+1) + ":00";

    // get the default schedule.
    std::string defaultCondition = QString("WHERE start_time='8:00' AND end_time='9:00' AND day_id='6' AND default_schedule='y'")
        .arg(startTime)
        .arg(endTime)
        .arg(dayName)
        .toStdString();

    defaultScheduleData = cmsDb->getData("Schedule", defaultCondition);

    
    // get the booked schedule.
    std::string bookedCondition = QString("WHERE start_time='8:00' AND end_time='9:00' AND day_id='6' AND default_schedule='n'")
        .arg(startTime)
        .arg(endTime)
        .arg(dayName)
        .toStdString();

    bookedScheduleData = cmsDb->getData("Schedule", bookedCondition);


    // initialize the combined schedule unordered_map.
    for (const auto& pair : defaultScheduleData) {
        if (pair.first == "room_id" || pair.first == "group_id" || pair.first == "subject_id" || pair.first == "start_time_actual" || pair.first == "end_time_actual") {
            combinedScheduleData[pair.first] = std::vector<std::string>();
        }
    }

    // add data of the default schedule to the combined schedule.
    for (const auto& pair : defaultScheduleData) {

        if (pair.first == "room_id") {
            for (const auto& val : pair.second) {
                combinedScheduleData[pair.first].push_back(val);
            }
        }
        if (pair.first == "group_id") {
            for (const auto& val : pair.second) {
                combinedScheduleData[pair.first].push_back(val);
            }
        }
        if (pair.first == "subject_id") {
            for (const auto& val : pair.second) {
                combinedScheduleData[pair.first].push_back(val);
            }
        }
        if (pair.first == "start_time_actual") {
            for (const auto& val : pair.second) {
                combinedScheduleData[pair.first].push_back(val);
            }
        }
        if (pair.first == "end_time_actual") {
            for (const auto& val : pair.second) {
                combinedScheduleData[pair.first].push_back(val);
            }
        }

    }

    // add data of the booked schedule to the combined schedule.
    for (const auto& pair : bookedScheduleData) {

        if (pair.first == "room_id") {
            for (const auto& val : pair.second) {
                combinedScheduleData[pair.first].push_back(val);
            }
        }
        if (pair.first == "group_id") {
            for (const auto& val : pair.second) {
                combinedScheduleData[pair.first].push_back(val);
            }
        }
        if (pair.first == "subject_id") {
            for (const auto& val : pair.second) {
                combinedScheduleData[pair.first].push_back(val);
            }
        }
        if (pair.first == "start_time_actual") {
            for (const auto& val : pair.second) {
                combinedScheduleData[pair.first].push_back(val);
            }
        }
        if (pair.first == "end_time_actual") {
            for (const auto& val : pair.second) {
                combinedScheduleData[pair.first].push_back(val);
            }
        }

    }

    // set the global data members of the class.
    for (const auto& pair : combinedScheduleData) {

        if (pair.first == "room_id") {
            userWindow->setRooms(pair.second);
        }
        if (pair.first == "group_id") {
            userWindow->setGroups(pair.second);
        }
        if (pair.first == "subject_id") {
            userWindow->setSubjects(pair.second);
        }
        if (pair.first == "start_time_actual") {
            userWindow->setStartTimeVec(pair.second);
        }
        if (pair.first == "end_time_actual") {
            userWindow->setEndTimeVec(pair.second);
        }

    }

    linkSubjects();
    linkTime();
}

void UserWindow::setRooms(std::vector<std::string> roomsVec) {


    for (size_t i = 0; i < roomsVec.size(); i++) {

        switch (std::stoi(roomsVec.at(i))) {
            case ROOM_106:
                rooms.push_back(ROOM_106);
                break;
            case ROOM_107:
                rooms.push_back(ROOM_107);
                break;
            case ROOM_108:
                rooms.push_back(ROOM_108);
                break;
            case ROOM_109:
                rooms.push_back(ROOM_109);
                break;
            case ROOM_207:
                rooms.push_back(ROOM_207);
                break;
            case ROOM_208:
                rooms.push_back(ROOM_208);
                break;
            case ROOM_209:
                rooms.push_back(ROOM_209);
                break;
            case ROOM_202:
                rooms.push_back(ROOM_202);
                break;
            case ROOM_203:
                rooms.push_back(ROOM_203);
                break;
            case ROOM_402:
                rooms.push_back(ROOM_402);
                break;
            default:
                break;
        }

    }
}

void UserWindow::setGroups(std::vector<std::string> groupsVec) {

    for (size_t i = 0; i < groupsVec.size(); i++) {

        if (groupsVec.at(i).empty()) {
            return;
        }

        switch(std::stoi(groupsVec.at(i))) {
            case BI:
                groups.push_back(BI);
                break;
            case BT:
                groups.push_back(BT);
                break;
            case CM_AP:
                groups.push_back(CM_AP);
                break;
            case CS:
                groups.push_back(CS);
                break;
            case ES:
                groups.push_back(ES);
                break;
            default:
                break;
        }
    }

}

void UserWindow::setSubjects(std::vector<std::string> subjectsVec) {
    
    for (size_t i = 0; i < subjectsVec.size(); i++) {
       
        switch (std::stoi(subjectsVec.at(i))) {
            case COMP116:
                subjects.push_back(COMP116); 
                break;
            case COMP117:
                subjects.push_back(COMP117); 
                break;
            case MATH103:
                subjects.push_back(MATH103); 
                break;
            case MATH102:
                subjects.push_back(MATH102); 
                break;
            case MATH104:
                subjects.push_back(MATH104); 
                break;
            case PHYS102:
                subjects.push_back(PHYS102); 
                break;
            case PHYS105:
                subjects.push_back(PHYS105); 
                break;
            case EDRG102:
                subjects.push_back(EDRG102); 
                break;
            case EDRG103:
                subjects.push_back(EDRG103); 
                break;
            case ENGT105:
                subjects.push_back(ENGT105); 
                break;
            case ENVE101:
                subjects.push_back(ENVE101); 
                break;
            case ENGG112:
                subjects.push_back(ENGG112); 
                break;
            case CHEM102:
                subjects.push_back(CHEM102); 
                break;
            case CHEM103:
                subjects.push_back(CHEM103); 
                break;
            case BINF101:
                subjects.push_back(BINF101); 
                break;
            case BINF102:
                subjects.push_back(BINF102); 
                break;
            case BIOT101:
                subjects.push_back(BIOT101); 
                break;
            case BIOT102:
                subjects.push_back(BIOT102); 
                break;
            case ENVS101:
                subjects.push_back(ENVS101); 
                break;
            case ENVS102:
                subjects.push_back(ENVS102); 
                break;
            case ENVS141:
                subjects.push_back(ENVS141); 
                break;
            case PHYS102_Practical:
                subjects.push_back(PHYS102_Practical);
                break;
            case PHAR204:
                subjects.push_back(PHAR204); 
                break;
            case PHAR402:
                subjects.push_back(PHAR402); 
                break;
            case CHEM203:
                subjects.push_back(CHEM203); 
                break;
            case MGTS402:
                subjects.push_back(MGTS402); 
                break;
            case CHEM215:
                subjects.push_back(CHEM215); 
                break;
            case MEEEG306:
                subjects.push_back(MEEEG306); 
                break;
            case ENVE303:
                subjects.push_back(ENVE303); 
                break;
            default:
                break;
        }

    }
}

void UserWindow::setStartTimeVec(std::vector<std::string> vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        startTimeVec.push_back(vec.at(i));
    }
}

void UserWindow::setEndTimeVec(std::vector<std::string> vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        endTimeVec.push_back(vec.at(i));
    }
}

std::string UserWindow::subjectEnumToStr(Subject s) {
    
    switch (s) {
        case COMP116:
            return "COMP116";
        case COMP117:
            return "COMP117";
        case MATH103:
            return "MATH103";
        case MATH102:
            return "MATH102";
        case MATH104:
            return "MATH104";
        case PHYS102:
            return "PHYS102";
        case PHYS105:
            return "PHYS105";
        case EDRG102:
            return "EDRG102";
        case EDRG103:
            return "EDRG103";
        case ENGT105:
            return "ENGT105";
        case ENVE101:
            return "ENVE101";
        case ENGG112:
            return "ENGG112";
        case CHEM102:
            return "CHEM102";
        case CHEM103:
            return "CHEM103";
        case BINF101:
            return "BINF101";
        case BINF102:
            return "BINF102";
        case BIOT101:
            return "BIOT101";
        case BIOT102:
            return "BIOT102";
        case ENVS101:
            return "ENVS101";
        case ENVS102:
            return "ENVS102";
        case ENVS141:
            return "ENVS141";
        case PHYS102_Practical:
            return "PHYS102_Practical";
        case PHAR204:
            return "PHAR204";
        case CHEM203:
            return "CHEM203";
        case PHAR402:
            return "PHAR402";
        case MGTS402:
            return "MGTS402";
        case CHEM215:
            return "CHEM215";
        case MEEEG306:
            return "MEEEG306";
        case ENVE303:
            return "ENVE303";
    }

}

std::vector<Room> UserWindow::getRooms() {
    return rooms;
}

std::vector<Group> UserWindow::getGroups() {
    return groups;
}

std::vector<Subject> UserWindow::getSubjects() {
    return subjects;
}

std::unordered_map<Room, std::string> UserWindow::getSubjectsUM() {
    return subjectsUM;
}

std::unordered_map<Room, std::string> UserWindow::getStartTimeUM() {
    return startTimeUM;
}

std::unordered_map<Room, std::string> UserWindow::getEndTimeUM() {
    return endTimeUM;
}

void UserWindow::linkSubjects() {
    
    for (size_t i = 0; i < subjects.size(); i++) {
        subjectsUM[rooms.at(i)] = subjectEnumToStr(subjects.at(i));
    }

}

void UserWindow::linkTime() {
    for (size_t i = 0; i < startTimeVec.size(); i++) {
        startTimeUM[rooms.at(i)] = startTimeVec.at(i);
        endTimeUM[rooms.at(i)] = endTimeVec.at(i);
    }
}
