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
    void showTime();  // Declare showTime function

    //void on_test_clicked();

    void on_loginButton_clicked();

    void on_new_account_clicked();

    void on_sign_in_clicked();

    void on_back_login_clicked();

    void on_loginButton_2_clicked();

    void on_new_account_3_clicked();

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
