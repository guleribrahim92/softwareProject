#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "bus.h"



namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    void connClose();
    bool connOpen();

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_log_clicked();

   // void on_label_stat_linkActivated(const QString &link);


    void on_pushButton_register_clicked();

private:
    Ui::Login *ui;
    QSqlDatabase mydb;
};

#endif // LOGIN_H
