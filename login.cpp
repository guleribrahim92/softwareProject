
#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/Ibrahim/Desktop/Qt Project/bck2.png");
    ui->label_pic->setPixmap(pix);

mydb=QSqlDatabase::addDatabase("QSQLITE");
mydb.setDatabaseName("C:\\Users\\Ibrahim\\Documents\\BosnaBus\\BosnaBus.db");

if(!mydb.open())
    ui->label_stat->setText("Failed to connect to DB");
else
    ui->label_stat->setText("Success!");

}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_log_clicked()
{
    QString username,password;
    username=ui->lineEdit_usern->text();
    password=ui->lineEdit_pass->text();

    if(!mydb.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    QSqlQuery qry;
    if(qry.exec("select * from users where username='"+username +"'and password='"+password+"'" ))
     {

                int count=0;
                while(qry.next())
                {
                 count++;
                }
                if(count==1){
                ui->label_stat->setText("logged in");
                this->hide();
                Bus bus;
                bus.setModal(true);
                bus.exec();

                }
                if(count>1)
                ui->label_stat->setText("Duplicate username and password");
                if(count<1)
                ui->label_stat->setText("username password not matched");
}


}



void Login::on_pushButton_register_clicked()
{

}
