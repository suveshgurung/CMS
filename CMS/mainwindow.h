#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

// private slots:
//     void on_toggleButton_clicked();
// private:

//     void applyStyleSheet();


private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    // LogoWidget *logoWidget;
};

#endif // MAINWINDOW_H
