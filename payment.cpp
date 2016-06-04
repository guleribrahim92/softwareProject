#include "payment.h"
#include "ui_payment.h"

Payment::Payment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Payment)
{
    ui->setupUi(this);

    QPixmap  pix("C:/Users/Ozgur/Desktop/master.png");
    ui->label_pic->setPixmap(pix);

    QPixmap  pix2("C:/Users/Ozgur/Desktop/pp2.png");
    ui->label_pic2->setPixmap(pix2);

    ui->comboBox->addItem("Credit Card / Bank Card");
    ui->comboBox->addItem("Paypal Account");
}

Payment::~Payment()
{
    delete ui;
}



void Payment::on_pushButton_2_clicked()
{
    QString name = ui->nameInput->text();
    QString surname = ui->surnameInput->text();
    QString emailAddress = ui->emailAddressInput->text();
    QString cardNo = ui->cardNoInput->text();
    QString securityCode = ui->securityCodeInput->text();
    QString emailAdd = ui->emailAddressInput_2->text();
    QString password = ui->passwordInput->text();
    QString gender = "";
    QString paymentMethod = "";
    QString expirationDate = "";

    expirationDate = "1-"+ui->comboMonth->currentText() + "-" + ui->comboYear->currentText();
    qDebug()<<"Selected year is "<<expirationDate;

    // exception handling in case of gender selection
    if(ui->maleRadioButton->isChecked())
        gender = "male";
    else if (ui->femaleRadioButton->isChecked())
        gender = "female";

    // exception hnadling in case of payment method
    if(ui->creditCardRadioButton->isChecked())
        paymentMethod = "credit_card";
    else if (ui->bankCardRadioButton->isChecked())
        paymentMethod = "bank_card";

    // exception handling is user left one of the fields empty
    if(name.isEmpty() == true || name.trimmed() == ""
       || surname.isEmpty() == true || surname.trimmed() == ""
       || emailAddress.isEmpty() == true || emailAddress.trimmed() == ""
       || cardNo.isEmpty() == true || cardNo.trimmed() == ""
       || securityCode.isEmpty() == true || securityCode.trimmed() == ""
       || emailAdd.isEmpty() == true || emailAdd.trimmed()== ""
       || password.isEmpty() == true || password.trimmed() == ""
       || gender.isEmpty() == true || paymentMethod.isEmpty() == true || expirationDate.isEmpty() == true   ){
        QMessageBox::warning(this,"Error with input","You did not provided input for all fields. Please check again form!");
    }
    // eveything fine, store in database data
    else{
        qDebug()<<"User with"<<name<<","<<surname<<","<<emailAddress<<","<<cardNo<<","<<securityCode<<","<<password<<","<<gender<<","<<expirationDate;
        database.setDatabaseName(DB_Path);


        if(database.open()){
             QSqlQuery query(database);
             QString q = "INSERT INTO CreditCard VALUES ('"+name+"','"+surname+"','"+emailAddress+"','"+gender+"',"+cardNo+","+expirationDate+",'"+securityCode+"','"+emailAdd+"','"+password+"')";
             qDebug()<<q;
             query.prepare(q);
             query.exec();
             while(query.next())
             //QString = db.lastError().text();
             QMessageBox::critical(this, "Database Error","hello");   //1-1-1991
             qDebug()<<query.lastError().text();

         }
     }

 }


void Payment::on_pushButton_clicked()
{
    QString link = "www.paypal.com";
    QDesktopServices::openUrl(QUrl(link));
}
