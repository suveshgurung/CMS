#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "dbConnection.h"
#include "schedule.h"
#include <QTimer>
#include <QDateTime>
#include <QTimeEdit>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include <QApplication>
#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>
#include <algorithm>
#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
#include "image_slider.h"

std::vector<Room> avRooms;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

    // Assuming you already have a QDateEdit object called 'dateEdit'
    
    ui->setupUi(this);

    QDate today = QDate::currentDate();  // Get the current date
    ui-> dateEdit->setDate(today);            // Set today's date


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    ui->book_button_1->setVisible(false);
    ui->book_button_2->setVisible(false);
    ui->book_button_3->setVisible(false);
    ui->book_button_4->setVisible(false);
    ui->book_button_5->setVisible(false);
    ui->book_button_6->setVisible(false);
    ui->book_button_7->setVisible(false);

    ui->dateEdit->setDate(today);

    // Loop for stackedWidget UI "SIDEBAR UI"
    for (int i = 1; i <= 20; ++i)
    {
        QString buttonName = "logout_button_" + QString::number(i);
        QString home_buttonName = "home_" + QString::number(i);
        QString schedule_buttonName = "schedule_" + QString::number(i);
        QString booking_buttonName = "booking_" + QString::number(i);

        QPushButton *h_button = findChild<QPushButton *>(home_buttonName);
        QPushButton *button = findChild<QPushButton *>(buttonName);
        QPushButton *sh_button = findChild<QPushButton *>(schedule_buttonName);
        QPushButton *b_button = findChild<QPushButton *>(booking_buttonName);

        if (button)
        {
            connect(button, &QPushButton::clicked, this, &MainWindow::handleLogout);
        }
        if (h_button)
        {
            connect(h_button, &QPushButton::clicked, this, &MainWindow::handleHome);
        }
        if (sh_button)
        {
            connect(sh_button, &QPushButton::clicked, this, &MainWindow::handleSchedule);
        }
        if (b_button)
        {
            connect(b_button, &QPushButton::clicked, this, &MainWindow::handleBooking);
        }
    }

    // room function call
    setupRoom106();
    setupRoom107();
    setupRoom108();
    setupRoom109();
    setupRoom207();
    setupRoom208();
    setupRoom209();
}

// image slider
void MainWindow::setupRoom106()
{
    QLabel *imageLabel = findChild<QLabel *>("image_holder");
    QPushButton *leftButton = findChild<QPushButton *>("left_swipe_button");
    QPushButton *rightButton = findChild<QPushButton *>("right_swipe_button");

    QStringList imagesPage = {":/resource/assets/room.jpg", ":/resource/assets/Knowledge.png"};
    ImageSlider *sliderPage1 = new ImageSlider(imageLabel, leftButton, rightButton, imagesPage, this);
}

void MainWindow::setupRoom107()
{
    QLabel *imageLabel = findChild<QLabel *>("image_holder_2");
    QPushButton *leftButton = findChild<QPushButton *>("left_swipe_button_2");
    QPushButton *rightButton = findChild<QPushButton *>("right_swipe_button_2");

    QStringList imagesPage = {":/resource/assets/school.jpg", ":/resource/assets/Knowledge.png"};
    ImageSlider *sliderPage2 = new ImageSlider(imageLabel, leftButton, rightButton, imagesPage, this);
}

void MainWindow::setupRoom108()
{
    QLabel *imageLabel = findChild<QLabel *>("image_holder_3");
    QPushButton *leftButton = findChild<QPushButton *>("left_swipe_button_3");
    QPushButton *rightButton = findChild<QPushButton *>("right_swipe_button_3");

    QStringList imagesPage = {":/resource/assets/school.jpg", ":/resource/assets/Knowledge.png"};
    ImageSlider *sliderPage3 = new ImageSlider(imageLabel, leftButton, rightButton, imagesPage, this);
}

void MainWindow::setupRoom109()
{
    QLabel *imageLabel = findChild<QLabel *>("image_holder_4");
    QPushButton *leftButton = findChild<QPushButton *>("left_swipe_button_4");
    QPushButton *rightButton = findChild<QPushButton *>("right_swipe_button_4");

    QStringList imagesPage = {":/resource/assets/school.jpg", ":/resource/assets/Knowledge.png"};
    ImageSlider *sliderPage4 = new ImageSlider(imageLabel, leftButton, rightButton, imagesPage, this);
}

void MainWindow::setupRoom207()
{
    QLabel *imageLabel = findChild<QLabel *>("image_holder_5");
    QPushButton *leftButton = findChild<QPushButton *>("left_swipe_button_5");
    QPushButton *rightButton = findChild<QPushButton *>("right_swipe_button_5");

    QStringList imagesPage = {":/resource/assets/school.jpg", ":/resource/assets/Knowledge.png"};
    ImageSlider *sliderPage5 = new ImageSlider(imageLabel, leftButton, rightButton, imagesPage, this);
}

void MainWindow::setupRoom208()
{
    QLabel *imageLabel = findChild<QLabel *>("image_holder_6");
    QPushButton *leftButton = findChild<QPushButton *>("left_swipe_button_6");
    QPushButton *rightButton = findChild<QPushButton *>("right_swipe_button_6");

    QStringList imagesPage = {":/resource/assets/school.jpg", ":/resource/assets/Knowledge.png"};
    ImageSlider *sliderPage6 = new ImageSlider(imageLabel, leftButton, rightButton, imagesPage, this);
}

void MainWindow::setupRoom209()
{
    QLabel *imageLabel = findChild<QLabel *>("image_holder_7");
    QPushButton *leftButton = findChild<QPushButton *>("left_swipe_button_7");
    QPushButton *rightButton = findChild<QPushButton *>("right_swipe_button_7");

    QStringList imagesPage = {":/resource/assets/school.jpg", ":/resource/assets/Knowledge.png"};
    ImageSlider *sliderPage7 = new ImageSlider(imageLabel, leftButton, rightButton, imagesPage, this);
}

void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss");
    ui->time->setText(time_text);

    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeText = dateTime.toString("ddd MMM dd");
    ui->date->setText(dateTimeText);

    for (int i = 1; i <= 10; i++)
    {
        QString timeName = "time_" + QString::number(i);
        QLabel *time_button = findChild<QLabel *>(timeName);

        QString dateName = "date_" + QString::number(i);
        QLabel *date_button = findChild<QLabel *>(dateName);

        if (date_button)
        {
            date_button->setText(dateTimeText);
        }

        if (time_button)
        {
            time_button->setText(time_text);
        }
    }

    if (time.second() % 2 == 0)
    {
        time_text[3] = ' ';
        time_text[8] = ' ';
    }
    // ui->Digital_Clock->setText(time_text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    // retrieve info from the frontend.
    QString email = ui->login_email_2->text();
    QString password = ui->login_password_2->text();

    int uid;
    std::string fname, lname, mail, phone, dept;
    std::string mname = "";

    // check for empty fields.
    if (email == "" || password == "")
    {
        QMessageBox::information(this, "button clicked", "Email or password is missing!!!");
        return;
    }

    std::unordered_map<std::string, std::vector<std::string>> userData;
    int userId;
    bool isUserValid = false;

    std::string condition = QString("WHERE Email='%1'")
                                .arg(email)
                                .toStdString();

    // retrieve data from the database.
    userData = cmsDb->getData("User_Info", condition);
    for (const auto &key : userData)
    {

        if (key.second.size() == 0)
        {
            QMessageBox::information(this, "button clicked", "User not found!!!");
            return;
        }
        else
        {
            if (key.first == "Password")
            {
                if (key.second.at(0) == password.toStdString())
                {
                    isUserValid = true;
                }
                else
                {
                    QMessageBox::information(this, "button clicked", "Incorrect Password!!!");
                    return;
                }
            }
            if (key.first == "User_ID")
            {
                userId = std::stoi(key.second.at(0));
            }
            if (key.first == "First_Name")
            {
                fname = (key.second.at(0));
                // std::cout<<"FNAME:"<<fname<<std::endl;
            }
            if (key.first == "Middle_Name")
            {
                mname = (key.second.at(0));
                // std::cout<<"MNAME:"<<mname<<std::endl;
            }
            if (key.first == "Last_Name")
            {
                lname = key.second.at(0);
                // std::cout<<"LNAME:"<<lname<<std::endl;
            }
            if (key.first == "Email")
            {
                mail = key.second.at(0);
                // std::cout<<"Email:"<<mail<<std::endl;
            }
            if (key.first == "Department")
            {
                dept = key.second.at(0);
                // std::cout<<"Department:"<<dept<<std::endl;
            }
            if (key.first == "Phone_Number")
            {
                phone = key.second.at(0);
            }
        }
    }

    userId = std::stoi(userData["User_ID"][0]);
    fname = userData["First_Name"][0];
    mname = userData["Middle_Name"][0];
    lname = userData["Last_Name"][0];
    dept = userData["Department"][0];
    if (isUserValid)
    {
        // user->setUserId(userId);
        // user->setUser(userId,fname,mname,lname,mail,dept,phone);
        userWindow->getSchedule();
        update_room_status();
        // ui->stackedWidget->setCurrentIndex(4);
    }

    // Debugging output
    // qDebug() << "First Name:" << QString::fromStdString(fname);
    // qDebug() << "Middle Name:" << QString::fromStdString(mname);
    // qDebug() << "Last Name:" << QString::fromStdString(lname);
    // qDebug() << "Department:" << QString::fromStdString(dept);

    if (user != nullptr)
    {
        user->setUser(userId, fname, mname, lname, email.toStdString(), dept, userData["Phone_Number"][0]);
    }
    else
    {
        QMessageBox::information(this, "Error", "User object is null!!!");
        return;
    }

    QString departmentText = QString::fromStdString(dept);

    // this because error mname bhayena bhane tesko index access garda program crash khayo
    QString usernameText;
    if (!mname.empty())
    {
        usernameText = QString::fromStdString(fname) + " " + QString::fromStdString(mname)[0] + "." + " " + QString::fromStdString(lname);
    }
    else
    {
        usernameText = QString::fromStdString(fname) + " " + QString::fromStdString(lname);
    }

    // Debugging output
    // qDebug() << "Username Text:" << usernameText;
    // qDebug() << "Department Text:" << departmentText;

    if (ui->username != nullptr)
    {
        ui->username->setText(usernameText);
    }
    else
    {
        qDebug() << "Username UI element is null!";
    }

    if (ui->department != nullptr)
    {
        ui->department->setText(departmentText);
    }
    else
    {
        qDebug() << "Department UI element is null!";
    }

    ui->dashboard_username->setText(usernameText);
    ui->phonenumber->setText( QString::fromStdString(phone));
    ui->firstname->setText( QString::fromStdString(fname));
    if(!mname.empty())
    {
        ui->middlename->setText(QString::fromStdString(mname));
    }
    ui->lastname->setText(QString::fromStdString(lname));
    ui->mail->setText(QString::fromStdString(mail));




    for (int i = 1; i <= 10; i++)
    {
        QString usernameElementName = "username_" + QString::number(i);
        QString departmentElementName = "department_" + QString::number(i);

        QLabel *usernameLabel = findChild<QLabel *>(usernameElementName);
        QLabel *departmentLabel = findChild<QLabel *>(departmentElementName);

        if (usernameLabel)
        {
            usernameLabel->setText(usernameText);
        }
        else
        {
            qDebug() << "Username Label not found:" << usernameElementName;
        }

        if (departmentLabel)
        {
            departmentLabel->setText(departmentText);
        }
        else
        {
            qDebug() << "Department Label not found:" << departmentElementName;
        }
    }

    if (ui->stackedWidget != nullptr && ui->stackedWidget->count() > 4)
    {
        ui->stackedWidget->setCurrentIndex(4);
    }
    else
    {
        qDebug() << "Stacked Widget or Index is invalid!";
    }
}

void MainWindow::handleLogout()
{

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton)
    {
        on_logout_button_clicked();
    }
}

void MainWindow::handleSchedule()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton)
    {
        on_schedule_clicked();
    }
}

void MainWindow::handleHome()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton)
    {
        on_home_clicked();
    }
}

void MainWindow::handleBooking()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    if (clickedButton)
    {
        on_booking_clicked();
    }
}

void MainWindow::on_schedule_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_home_clicked()
{
    userWindow->getSchedule();
    update_room_status();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_booking_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_logout_button_clicked()
{

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_room_106_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_room_107_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_room_108_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_room_109_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_room_207_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_room_208_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_room_209_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_sign_in_clicked()
{

    QString fname = ui->first_name_7->text();
    QString mname = ui->middle_name_7->text();
    QString lname = ui->last_name_7->text();
    QString email = ui->email_7->text();
    QString phoneNumber = ui->phone_number_7->text();
    QString department = ui->department_comboBox_7->currentText();
    QString password = ui->password_7->text();

    if (fname == "" || lname == "" || email == "" || phoneNumber == "" || department == "" || password == "")
    {
        QMessageBox::information(this, "button clicked", "Please enter all the required fileds!!!");
        return;
    }

    std::unordered_map<std::string, std::string> signInData;

    signInData["First_Name"] = fname.toStdString();
    if (mname != "")
    {
        signInData["Middle_Name"] = mname.toStdString();
    }
    signInData["Last_Name"] = lname.toStdString();
    signInData["Email"] = email.toStdString();
    signInData["Department"] = department.toStdString();
    signInData["Phone_Number"] = phoneNumber.toStdString();
    signInData["Password"] = password.toStdString();

    if (cmsDb->insertData(signInData, "User_Info"))
    {
        QMessageBox::information(this, "button clicked", "Signed Up Successfully");
    }
    else
    {
        QMessageBox::information(this, "button clicked", "Sign Up Unsuccessfull");
        return;
    }

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_register_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_login_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_login_redirect_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_signup_redirect_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::update_room_status()
{

    std::vector<Room> rooms = userWindow->getRooms();
    std::unordered_map<Room, std::string> subjects = userWindow->getSubjectsUM();
    std::unordered_map<Room, std::string> startTime = userWindow->getStartTimeUM();
    std::unordered_map<Room, std::string> endTime = userWindow->getEndTimeUM();

    QString timeRange;

     for (size_t i = 0; i < rooms.size(); i++)
          {

        switch (rooms.at(i))
        {
        case ROOM_106:
            ui->room_106_status->setStyleSheet("background-color:#ef4444;padding:5px;width:auto;color:white;");
            ui->room_106_status->setText("Not Available");
            ui->room_106_class_name->setText(QString::fromStdString(subjects[rooms.at(i)]));
            timeRange = QString::fromStdString(startTime[rooms.at(i)]) + "-" + QString::fromStdString(endTime[rooms.at(i)]);
            ui->room_106_class_time->setText(timeRange);
            ui->Subject_name->setText(QString::fromStdString(subjects[rooms.at(i)]));
            ui->start_time->setText(QString::fromStdString(startTime[rooms.at(i)]));
            ui->end_time->setText(QString::fromStdString(endTime[rooms.at(i)]));
            ui->availability_status->setText("Not Available");
            break;
        case ROOM_107:
            ui->room_107_status->setStyleSheet("background-color:#ef4444;padding:5px;width:auto;color:white;");
            ui->room_107_status->setText("Not Available");
            ui->room_107_class_name->setText(QString::fromStdString(subjects[rooms.at(i)]));
            timeRange = QString::fromStdString(startTime[rooms.at(i)]) + "-" + QString::fromStdString(endTime[rooms.at(i)]);
            ui->room_107_class_time->setText(timeRange);
            ui->Subject_name_2->setText(QString::fromStdString(subjects[rooms.at(i)]));
            ui->start_time_2->setText(QString::fromStdString(startTime[rooms.at(i)]));
            ui->end_time_2->setText(QString::fromStdString(endTime[rooms.at(i)]));
            ui->availability_status_2->setText("Not Available");
            break;
        case ROOM_108:
            ui->room_108_status->setStyleSheet("background-color:#ef4444;padding:5px;width:auto;color:white;");
            ui->room_108_status->setText("Not Available");
            ui->room_108_class_name->setText(QString::fromStdString(subjects[rooms.at(i)]));
            timeRange = QString::fromStdString(startTime[rooms.at(i)]) + "-" + QString::fromStdString(endTime[rooms.at(i)]);
            ui->room_108_class_time->setText(timeRange);
            ui->Subject_name_3->setText(QString::fromStdString(subjects[rooms.at(i)]));
            ui->start_time_3->setText(QString::fromStdString(startTime[rooms.at(i)]));
            ui->end_time_3->setText(QString::fromStdString(endTime[rooms.at(i)]));
            ui->availability_status_3->setText("Not Available");
            break;
        case ROOM_109:
            ui->room_109_status->setStyleSheet("background-color:#ef4444;padding:5px;width:auto;color:white;");
            ui->room_109_status->setText("Not Available");
            ui->room_109_class_name->setText(QString::fromStdString(subjects[rooms.at(i)]));
            timeRange = QString::fromStdString(startTime[rooms.at(i)]) + "-" + QString::fromStdString(endTime[rooms.at(i)]);
            ui->room_109_class_time->setText(timeRange);
            ui->Subject_name_4->setText(QString::fromStdString(subjects[rooms.at(i)]));
            ui->start_time_4->setText(QString::fromStdString(startTime[rooms.at(i)]));
            ui->end_time_4->setText(QString::fromStdString(endTime[rooms.at(i)]));
            ui->availability_status_4->setText("Not Available");
            break;
        case ROOM_207:
            ui->room_207_status->setStyleSheet("background-color:#ef4444;padding:5px;width:auto;color:white;");
            ui->room_207_status->setText("Not Available");
            ui->room_207_class_name->setText(QString::fromStdString(subjects[rooms.at(i)]));
            timeRange = QString::fromStdString(startTime[rooms.at(i)]) + "-" + QString::fromStdString(endTime[rooms.at(i)]);
            ui->room_207_class_time->setText(timeRange);
            ui->Subject_name_5->setText(QString::fromStdString(subjects[rooms.at(i)]));
            ui->start_time_5->setText(QString::fromStdString(startTime[rooms.at(i)]));
            ui->end_time_5->setText(QString::fromStdString(endTime[rooms.at(i)]));
            ui->availability_status_5->setText("Not Available");
            break;
        case ROOM_208:
            ui->room_208_status->setStyleSheet("background-color:#ef4444;padding:5px;width:auto;color:white;");
            ui->room_208_status->setText("Not Available");
            ui->room_208_class_name->setText(QString::fromStdString(subjects[rooms.at(i)]));
            timeRange = QString::fromStdString(startTime[rooms.at(i)]) + "-" + QString::fromStdString(endTime[rooms.at(i)]);
            ui->room_208_class_time->setText(timeRange);
            ui->Subject_name_6->setText(QString::fromStdString(subjects[rooms.at(i)]));
            ui->start_time_6->setText(QString::fromStdString(startTime[rooms.at(i)]));
            ui->end_time_6->setText(QString::fromStdString(endTime[rooms.at(i)]));
            ui->availability_status_6->setText("Not Available");
            break;
        case ROOM_209:
            ui->room_209_status->setStyleSheet("background-color:#ef4444;padding:5px;width:auto;color:white;");
            ui->room_209_status->setText("Not Available");
            ui->room_209_class_name->setText(QString::fromStdString(subjects[rooms.at(i)]));
            timeRange = QString::fromStdString(startTime[rooms.at(i)]) + "-" + QString::fromStdString(endTime[rooms.at(i)]);
            ui->room_209_class_time->setText(timeRange);
            ui->Subject_name_7->setText(QString::fromStdString(subjects[rooms.at(i)]));
            ui->start_time_7->setText(QString::fromStdString(startTime[rooms.at(i)]));
            ui->end_time_7->setText(QString::fromStdString(endTime[rooms.at(i)]));
            ui->availability_status_7->setText("Not Available");
            break;
        default:
            break;
        }
    }
}

int dayStrToEnum(std::string dayName) {
    if (dayName == "Sunday") {
        return SUNDAY;
    }
    if (dayName == "Monday") {
        return MONDAY;
    }
    if (dayName == "Tuesday") {
        return TUESDAY;
    }
    if (dayName == "Wednesday") {
        return WEDNESDAY;
    }
    if (dayName == "Thursday") {
        return THURSDAY;
    }
    if (dayName == "Friday") {
        return FRIDAY;
    }

    // indicating no day. 
    return 0;
}

QString roomEnumToStr(Room room) {

    switch (room) {
        case ROOM_106:
            return "Room 106";
            break;
        case ROOM_107:
            return "Room 107";
            break;
        case ROOM_108:
            return "Room 108";
            break;
        case ROOM_109:
            return "Room 109";
            break;
        case ROOM_207:
            return "Room 207";
            break;
        case ROOM_208:
            return "Room 208";
            break;
        case ROOM_209:
            return "Room 209";
            break;
    }
}

Room roomStrToEnum(QString room) {

    if (room == "Room 106") {

        return ROOM_106;
    }
    if (room == "Room 107") {

        return ROOM_107;
    }
    if (room == "Room 108") {

        return ROOM_108;
    }
    if (room == "Room 109") {

        return ROOM_109;
    }
    if (room == "Room 207") {

        return ROOM_207;
    }
    if (room == "Room 208") {

        return ROOM_208;
    }
    if (room == "Room 209") {

        return ROOM_209;
    }
}

void addAvailableRooms(std::vector<std::string> data, std::vector<Room> &availableRoomVec) {
    std::vector<Room> allRooms = {ROOM_106, ROOM_107, ROOM_108, ROOM_109, ROOM_207, ROOM_208, ROOM_209};

    for (const auto& roomStr : data) {
        int roomNumber = std::stoi(roomStr);
        auto it = std::find(allRooms.begin(), allRooms.end(), roomNumber);

        if (it != allRooms.end()) {
            allRooms.erase(it);
        }
    }

    for (int roomNumber : allRooms) {
        availableRoomVec.push_back(Room(roomNumber));
    }

}

void MainWindow::bookedClassesEval(QString start_time, QString end_time, std::string day) {
    std::string getRoomCondition = QString("WHERE start_time_actual='%1' AND day_id='%2'")
        .arg(start_time)
        .arg(QString::number(dayStrToEnum(day)))
        .toStdString();

    qDebug() << getRoomCondition;

    std::unordered_map<std::string, std::vector<std::string>> tableData;
    std::vector<Room> availableRooms;

    tableData = cmsDb->getData("Schedule", getRoomCondition);

    for (const auto& pair : tableData) {
        if (pair.first == "room_id") {
            addAvailableRooms(pair.second, availableRooms);
        }
    }

    int j = 1;
    for (size_t i = 0; i < availableRooms.size(); i++) {
        if (j == 1) {
            ui->book1->setText(roomEnumToStr(availableRooms.at(i)));
            ui->book_button_1->setVisible(true);
            j++;
        }
        else if (j == 2) {
            ui->book2->setText(roomEnumToStr(availableRooms.at(i)));
            ui->book_button_2->setVisible(true);
            j++;
        }
        else if (j == 3) {
            ui->book3->setText(roomEnumToStr(availableRooms.at(i)));
            ui->book_button_3->setVisible(true);
            j++;
        }
        else if (j == 4) {
            ui->book4->setText(roomEnumToStr(availableRooms.at(i)));
            ui->book_button_4->setVisible(true);
            j++;
        }
        else if (j == 5) {
            ui->book5->setText(roomEnumToStr(availableRooms.at(i)));
            ui->book_button_5->setVisible(true);
            j++;
        }
        else if (j == 6) {
            ui->book6->setText(roomEnumToStr(availableRooms.at(i)));
            ui->book_button_6->setVisible(true);
            j++;
        }
        else if (j == 7) {
            ui->book7->setText(roomEnumToStr(availableRooms.at(i)));
            ui->book_button_7->setVisible(true);
            j++;
        }
    }

    avRooms = availableRooms;
}

void MainWindow::book_room() {

    QString startTime = ui->booking_start_time->currentText();
    QString endTime = ui->booking_end_time->currentText();
    QDate date = ui->dateEdit->date();

    // get and format the time according to the database structure.
    QString dateStr = date.toString("dddd");
    std::string dayName = dateStr.toStdString();

    // dbStartTime = "9:00";

    bookedClassesEval(startTime, endTime, dateStr.toStdString());
}

void MainWindow::on_booking_search_clicked()
{
    ui->book_button_1->setVisible(false);
    ui->book_button_2->setVisible(false);
    ui->book_button_3->setVisible(false);
    ui->book_button_4->setVisible(false);
    ui->book_button_5->setVisible(false);
    ui->book_button_6->setVisible(false);
    ui->book_button_7->setVisible(false);

    ui->book1->setText("");
    ui->book2->setText("");
    ui->book3->setText("");
    ui->book4->setText("");
    ui->book5->setText("");
    ui->book6->setText("");
    ui->book7->setText("");

    book_room();
}

Subject subjectStrToEnum(QString s) {
    
    if (s == "COMP116"){
        return COMP116;
    }
    else if (s == "COMP117") {
        return COMP117;
    }
    else if(s == "MATH103") {
        return MATH103;
    }
    else if (s == "MATH102") {
        return MATH102;
    }
    else if (s == "MATH104") {

        return MATH104;
    }
    else if (s == "PHYS102") {

        return PHYS102;
    }
    else if (s == "PHYS105") {

        return PHYS105;
    }
    else if (s == "EDRG102") {

        return EDRG102;
    }
    else if (s == "EDRG103") {

        return EDRG103;
    }
    else if (s == "ENGT105") {

        return ENGT105;
    }
    else if (s == "ENVE101") {

        return ENVE101;
    }
    else if (s == "ENGG112") {

        return ENGG112;
    }
    else if (s == "CHEM102") {

        return CHEM102;
    }
    else if (s == "CHEM103") {

        return CHEM103;
    }
    else if (s == "BINF101") {

        return BINF101;
    }
    else if (s == "BINF102") {

        return BINF102;
    }
    else if (s == "BIOT101") {

        return BIOT101;
    }
    else if (s == "BIOT102") {

        return BIOT102;
    }
    else if (s == "ENVS101") {

        return ENVS101;
    }
    else if (s == "ENVS102") {

        return ENVS102;
    }
    else if (s == "ENVS141") {

        return ENVS141;
    }
    else if (s == "PHYS102_Practical") {

        return PHYS102_Practical;
    }
    else if (s == "PHAR204") {

        return PHAR204;
    }
    else if (s == "CHEM203") {

        return CHEM203;
    }
    else if (s == "PHAR402") {

        return PHAR402;
    }
    else if (s == "MGTS402") {

        return MGTS402;
    }
    else if (s == "CHEM215") {

        return CHEM215;
    }
    else if (s == "MEEEG306") {

        return MEEEG306;
    }
    else if (s == "ENVE303") {

        return ENVE303;
    }
}

void MainWindow::on_book_button_1_clicked()
{
    // book the selected room.
    std::unordered_map<std::string, std::string> bookingData;
    QString startTime = ui->booking_start_time->currentText();
    QString endTime = ui->booking_end_time->currentText();
    QString subject = ui->booking_subject->currentText();
    QDate date = ui->dateEdit->date();

    // get and format the time according to the database structure.
    QString dateStr = date.toString("dddd");
    std::string dayName = dateStr.toStdString();

    QStringList startTimeParts = startTime.split(":");
    QStringList endTimeParts = endTime.split(":");
    
    int startTimeHour = startTimeParts[0].toInt();
    int endTimeHour = endTimeParts[0].toInt();

    if (endTimeHour - startTimeHour >= 2) {
        int eTimeHour;
        eTimeHour = startTimeHour + 1;
    
        QString eTime = QString::number(eTimeHour) + ":00";

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book1->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = eTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            // QMessageBox::information(this, "button clicked", "Room booked successfuly");
            //
            // on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book1->text())).toStdString();
        bookingData["start_time"] = eTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }
    else {
        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book1->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }
}

void MainWindow::on_book_button_2_clicked()
{
    // book the selected room.
    std::unordered_map<std::string, std::string> bookingData;
    QString startTime = ui->booking_start_time->currentText();
    QString endTime = ui->booking_end_time->currentText();
    QString subject = ui->booking_subject->currentText();
    QDate date = ui->dateEdit->date();

    // get and format the time according to the database structure.
    QString dateStr = date.toString("dddd");
    std::string dayName = dateStr.toStdString();

    QStringList startTimeParts = startTime.split(":");
    QStringList endTimeParts = endTime.split(":");
    
    int startTimeHour = startTimeParts[0].toInt();
    int endTimeHour = endTimeParts[0].toInt();

    if (endTimeHour - startTimeHour >= 2) {
        int eTimeHour;
        eTimeHour = startTimeHour + 1;
    
        QString eTime = QString::number(eTimeHour) + ":00";

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book2->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = eTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            // QMessageBox::information(this, "button clicked", "Room booked successfuly");
            //
            // on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book2->text())).toStdString();
        bookingData["start_time"] = eTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }
    else {
        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book2->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }

}

void MainWindow::on_book_button_3_clicked()
{
    // book the selected room.
    std::unordered_map<std::string, std::string> bookingData;
    QString startTime = ui->booking_start_time->currentText();
    QString endTime = ui->booking_end_time->currentText();
    QString subject = ui->booking_subject->currentText();
    QDate date = ui->dateEdit->date();

    // get and format the time according to the database structure.
    QString dateStr = date.toString("dddd");
    std::string dayName = dateStr.toStdString();

    QStringList startTimeParts = startTime.split(":");
    QStringList endTimeParts = endTime.split(":");
    
    int startTimeHour = startTimeParts[0].toInt();
    int endTimeHour = endTimeParts[0].toInt();

    if (endTimeHour - startTimeHour >= 2) {
        int eTimeHour;
        eTimeHour = startTimeHour + 1;
    
        QString eTime = QString::number(eTimeHour) + ":00";

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book3->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = eTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            // QMessageBox::information(this, "button clicked", "Room booked successfuly");
            //
            // on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book3->text())).toStdString();
        bookingData["start_time"] = eTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }
    else {
        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book3->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }

}


void MainWindow::on_book_button_4_clicked()
{
    // book the selected room.
    std::unordered_map<std::string, std::string> bookingData;
    QString startTime = ui->booking_start_time->currentText();
    QString endTime = ui->booking_end_time->currentText();
    QString subject = ui->booking_subject->currentText();
    QDate date = ui->dateEdit->date();

    // get and format the time according to the database structure.
    QString dateStr = date.toString("dddd");
    std::string dayName = dateStr.toStdString();

    QStringList startTimeParts = startTime.split(":");
    QStringList endTimeParts = endTime.split(":");
    
    int startTimeHour = startTimeParts[0].toInt();
    int endTimeHour = endTimeParts[0].toInt();

    if (endTimeHour - startTimeHour >= 2) {
        int eTimeHour;
        eTimeHour = startTimeHour + 1;
    
        QString eTime = QString::number(eTimeHour) + ":00";

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book4->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = eTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            // QMessageBox::information(this, "button clicked", "Room booked successfuly");
            //
            // on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book4->text())).toStdString();
        bookingData["start_time"] = eTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }
    else {
        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book4->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }

}


void MainWindow::on_book_button_5_clicked()
{
    // book the selected room.
    std::unordered_map<std::string, std::string> bookingData;
    QString startTime = ui->booking_start_time->currentText();
    QString endTime = ui->booking_end_time->currentText();
    QString subject = ui->booking_subject->currentText();
    QDate date = ui->dateEdit->date();

    // get and format the time according to the database structure.
    QString dateStr = date.toString("dddd");
    std::string dayName = dateStr.toStdString();

    QStringList startTimeParts = startTime.split(":");
    QStringList endTimeParts = endTime.split(":");
    
    int startTimeHour = startTimeParts[0].toInt();
    int endTimeHour = endTimeParts[0].toInt();

    if (endTimeHour - startTimeHour >= 2) {
        int eTimeHour;
        eTimeHour = startTimeHour + 1;
    
        QString eTime = QString::number(eTimeHour) + ":00";

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book5->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = eTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            // QMessageBox::information(this, "button clicked", "Room booked successfuly");
            //
            // on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book5->text())).toStdString();
        bookingData["start_time"] = eTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }
    else {
        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book5->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }

}


void MainWindow::on_book_button_6_clicked()
{
    // book the selected room.
    std::unordered_map<std::string, std::string> bookingData;
    QString startTime = ui->booking_start_time->currentText();
    QString endTime = ui->booking_end_time->currentText();
    QString subject = ui->booking_subject->currentText();
    QDate date = ui->dateEdit->date();

    // get and format the time according to the database structure.
    QString dateStr = date.toString("dddd");
    std::string dayName = dateStr.toStdString();

    QStringList startTimeParts = startTime.split(":");
    QStringList endTimeParts = endTime.split(":");
    
    int startTimeHour = startTimeParts[0].toInt();
    int endTimeHour = endTimeParts[0].toInt();

    if (endTimeHour - startTimeHour >= 2) {
        int eTimeHour;
        eTimeHour = startTimeHour + 1;
    
        QString eTime = QString::number(eTimeHour) + ":00";

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book6->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = eTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            // QMessageBox::information(this, "button clicked", "Room booked successfuly");
            //
            // on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book6->text())).toStdString();
        bookingData["start_time"] = eTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }
    else {
        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book6->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }
}


void MainWindow::on_book_button_7_clicked()
{
    // book the selected room.
    std::unordered_map<std::string, std::string> bookingData;
    QString startTime = ui->booking_start_time->currentText();
    QString endTime = ui->booking_end_time->currentText();
    QString subject = ui->booking_subject->currentText();
    QDate date = ui->dateEdit->date();

    // get and format the time according to the database structure.
    QString dateStr = date.toString("dddd");
    std::string dayName = dateStr.toStdString();

    QStringList startTimeParts = startTime.split(":");
    QStringList endTimeParts = endTime.split(":");
    
    int startTimeHour = startTimeParts[0].toInt();
    int endTimeHour = endTimeParts[0].toInt();

    if (endTimeHour - startTimeHour >= 2) {
        int eTimeHour;
        eTimeHour = startTimeHour + 1;
    
        QString eTime = QString::number(eTimeHour) + ":00";

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book7->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = eTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            // QMessageBox::information(this, "button clicked", "Room booked successfuly");
            //
            // on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }

        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book7->text())).toStdString();
        bookingData["start_time"] = eTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }
    else {
        bookingData["day_id"] = QString::number(dayStrToEnum(dayName)).toStdString();
        bookingData["subject_id"] = QString::number(subjectStrToEnum(subject)).toStdString();
        bookingData["room_id"] = QString::number(roomStrToEnum(ui->book7->text())).toStdString();
        bookingData["start_time"] = startTime.toStdString();
        bookingData["end_time"] = endTime.toStdString();
        bookingData["start_time_actual"] = startTime.toStdString();
        bookingData["end_time_actual"] = endTime.toStdString();
        bookingData["date"] = dateStr.toStdString();
        bookingData["default_schedule"] = "n";

        if (cmsDb->insertData(bookingData, "Schedule")) {
            qDebug() << "Successfull";
            QMessageBox::information(this, "button clicked", "Room booked successfuly");

            on_booking_search_clicked();
        } else {
            qDebug() << "ONOOOO";
        }
    }


}

