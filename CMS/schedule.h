#pragma once

#ifndef SCHEDULE
#define SCHEDULE

#include <QDateTime>
#include <unordered_map>
#include <vector>
#include <string>

// all of these enumeration variables need to be in the order of the database to maintain id linkage.
typedef enum {
    ROOM_106 = 1,
    ROOM_107,
    ROOM_108,
    ROOM_109,
    ROOM_207,
    ROOM_208,
    ROOM_209,
}Room;

typedef enum  {
    COMP116 = 1,
    COMP117,
    MATH103,
    MATH102,
    MATH104,
    PHYS102,
    PHYS105,
    EDRG102,
    EDRG103,
    ENGT105,
    ENVE101,
    ENGG112,
    CHEM102,
    CHEM103,
    BINF101,
    BINF102,
    BIOT101,
    BIOT102,
    ENVS101,
    ENVS102,
    ENVS141
}Subject;

typedef enum {
    BI = 1,
    BT,
    CM_AP,
    CS,
    ES
}Group;

typedef enum {
    SUNDAY = 1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
}Day;



// class to store logged in user info.
class User{
protected:
    int userId;

public:
    User();
    ~User();

    void setUserId(int id);
    int getUserId();
};

class UserWindow : public User{
protected:
    std::vector<Room> rooms;
    std::vector<Subject> subjects;
    std::vector<Group> groups;
    Day dayName;

    QDate currDate; 
    QTime currTime;
    QString date;
    QString time;
    int hour;

public:
    UserWindow(); 
    ~UserWindow();

    // methods to get data of the schedule.
    int getDay();
    void getSchedule();
    void setRooms(std::vector<std::string> roomsVec);
    void setGroups(std::vector<std::string> groupsVec);
    void setSubjects(std::vector<std::string> subjectsVec);

    std::vector<Room> getRooms(); 
    std::vector<Group> getGroups(); 
    std::vector<Subject> getSubjects();
};

extern User* user;
extern UserWindow* userWindow;

#endif
