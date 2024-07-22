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
}Rooms;

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
}Subjects;

typedef enum {
    BI = 1,
    BT,
    CM_AP,
    CS,
    ES
}Groups;

typedef enum {
    SUNDAY = 1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
}Days;



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
private:
    Rooms windowRooms; 
    Subjects windowSubjects;
    Groups windowGroups;
    Days dayName;

    QDate currDate; 
    QTime currTime;
    QString date;
    QString time;
    int hour;

public:
    UserWindow(); 
    ~UserWindow();

    int getDay();
    void getSchedule();
};

extern User* user;
extern UserWindow* userWindow;

#endif
