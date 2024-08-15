#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "logowidget.h"
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVector>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showTime(); // Declare showTime function

    // himesh
    void on_logout_button_clicked();
    void on_home_clicked();
    void on_booking_clicked();
    void on_schedule_clicked();
    void handleLogout();
    void handleHome();
    void handleSchedule();
    void handleBooking();

    // aryan
    void on_sign_in_clicked();
    void on_loginButton_clicked();

    void on_register_redirect_clicked();
    void on_login_redirect_clicked();
    void on_login_redirect_2_clicked();
    void on_signup_redirect_clicked();

    void on_room_106_redirect_clicked();
     void on_room_107_redirect_clicked();
      void on_room_108_redirect_clicked();
       void on_room_109_redirect_clicked();
        void on_room_207_redirect_clicked();
         void on_room_208_redirect_clicked();
          void on_room_209_redirect_clicked();

    void update_room_status();

    void book_room();

    void bookedClassesEval(QString start_time, QString end_time, std::string day);

    void on_booking_search_clicked();

    void on_book_button_1_clicked();
    void on_book_button_2_clicked();
    void on_book_button_3_clicked();
    void on_book_button_4_clicked();
    void on_book_button_5_clicked();
    void on_book_button_6_clicked();
    void on_book_button_7_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    LogoWidget *logoWidget;

    void setupRoom106();
    void setupRoom107();
    void setupRoom108();
    void setupRoom109();
    void setupRoom207();
    void setupRoom208();
    void setupRoom209();
};

#endif // MAINWINDOW_H
