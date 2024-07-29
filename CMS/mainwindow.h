#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "logowidget.h"

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

    void update_room_status();

    // void book_room();
    //
    // void on_wow_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    LogoWidget *logoWidget;
};

#endif // MAINWINDOW_H
