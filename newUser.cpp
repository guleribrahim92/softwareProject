#include "newuser.h"
#include "ui_newuser.h"
#include "login.h"
#include "qmessagebox.h"

newUser::newUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newUser)
{
    ui->setupUi(this);
}

newUser::~newUser()
{
    delete ui;
}

void newUser::on_buttonBox_accepted()
{
    Login w;

     QString fullName, username, password, password2, dOB, country, add, city, zip, telephone, email;
     fullName = ui->lineEdit->text();
     username = ui->lineEdit_9->text();
     password = ui->lineEdit_10->text();
     password2 = ui->lineEdit_11->text();
     dOB = ui->dateEdit->text();
     country = ui->lineEdit_2->text();
     add = ui->lineEdit_4->text();
     city = ui->lineEdit_3->text();
     zip = ui->lineEdit_5->text();
     telephone = ui->lineEdit_6->text();
     email = ui->lineEdit_7->text();

     if(username == NULL || password == NULL || password != password2 || fullName == NULL)
     {
         QMessageBox::critical(this,tr("Error::"), "Missing Information!");
         return;
     }

     bool conn = w.connOpen();

     if(!conn)
     {
         cout << "Failed to open the database";
         return;
     }

     QSqlQuery* qry = new QSqlQuery(w.mydb);

     qry->prepare("INSERT INTO users(username, password) VALUES('"+username+"', '"+password+"')");
     bool users = qry->exec();

     qry->prepare("INSERT INTO customers(full_name, date_of_birth, country, city, address, post_code, phone, email) VALUES('"+fullName+"', '"+dOB+"'"
     ", '"+country+"', '"+add+"', '"+city+"', '"+zip+"', '"+telephone+"', '"+email+"')");

     if(users && qry->exec())
     {

         QMessageBox::information(this,tr("Save"), tr("Saved"));
          w.connClose();
     }
     else
     {

         QMessageBox::critical(this,tr("Error::"),qry->lastError().text());
     }
}
