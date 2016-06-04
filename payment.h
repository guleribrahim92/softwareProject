#ifndef PAYMENT_H
#define PAYMENT_H

#include <QDialog>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QMessageBox>
#include <QtSql>


namespace Ui {
class Payment;
}

class Payment : public QDialog
{
    Q_OBJECT

public:
    explicit Payment(QWidget *parent = 0);
    ~Payment();
    QSqldatabase mydb;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Payment *ui;
};

#endif // PAYMENT_H
