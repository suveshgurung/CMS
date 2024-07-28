#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
#include "qlineedit.h"
#include "qpushbutton.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void showTime();  // Declare showTime function

    //void on_test_clicked();

    //void on_loginButton_clicked();

    void on_new_account_clicked();

    void on_sign_in_clicked();

    void on_back_login_clicked();

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
    //QLineEdit *username_3;
    //QLineEdit *password_3;
    // QPushButton *loginButton_2;
    // QLabel *errorLabel;
};

#endif // MAINWINDOW_H
