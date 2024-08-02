#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
#include "qlineedit.h"
#include "qpushbutton.h"
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

    void on_home_2_clicked();

    void on_loginButton_clicked();

    void on_register_redirect_clicked();

    void on_login_redirect_clicked();

    void on_Backlogin_clicked();

    void on_backlogin_clicked();

    void on_sign_upbutton_clicked();

    void on_login_redirect_2_clicked();

    void on_signup_clicked();

    void on_signup_redirect_clicked();

   // void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_back_button_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    LogoWidget *logoWidget;

protected:
    std::string firstName;
    std::string lastName;
    std::string department;
};

#endif // MAINWINDOW_H
