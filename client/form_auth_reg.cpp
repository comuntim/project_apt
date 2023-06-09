#include "form_auth_reg.h"
#include "ui_form_auth_reg.h"
#include "sendtohost.h"

//static QString serv_addr = "127.0.0.1";
//const int serv_port = 33333;


Form_auth_reg::Form_auth_reg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_auth_reg)
{
    ui->setupUi(this);
    ui->lineEdit_mail->setVisible(false);
    ui->pushButton_cancle->setVisible(false);
    Data = sendToHost::getInstance() -> readMess();
    qDebug() << "data:" << Data;
}

Form_auth_reg::~Form_auth_reg()
{
    delete ui;
}

//void Form_auth_reg::slotDisconnected() {
//    socket->deleteLater();
//}

//void Form_auth_reg::slotClientRead() {

//}




void Form_auth_reg::on_pushButton_register_clicked()
{
    ui->lineEdit_mail->setVisible(true);
    ui->pushButton_register->setVisible(false);
    ui->pushButton_cancle->setVisible(true);

//    QString user_log = "";
//    QString user_pass = "";
//

//    user_log = ui->lineEdit_log->text();
//    user_pass = ui->lineEdit_pass->text();
//    user_mail =


//    registration(user_log, user_pass, user_mail);

}


void Form_auth_reg::on_pushButton_cancle_clicked()
{
    ui->lineEdit_mail->setVisible(false);
    ui->pushButton_register->setVisible(true);
    ui->pushButton_cancle->setVisible(false);
}


void Form_auth_reg::on_pushButton_enter_clicked()
{

    QString user_log = ui->lineEdit_log->text();
    QString user_pass = ui->lineEdit_pass->text();


    if (ui->lineEdit_mail->isVisible()){
        QString user_mail = ui->lineEdit_mail->text();
        registration(user_log, user_pass, user_mail);
        Data = sendToHost::getInstance() -> readMess();
        qDebug() << "data:" << Data;
        ui->lineEdit_mail->setVisible(false);
        ui->pushButton_cancle->setVisible(false);
    }
    else {
        authorization(user_log, user_pass);
        Data = sendToHost::getInstance() -> readMess();
        qDebug() << "data:" << Data;
        emit return_autrh_reg();
        hide();
    }

}

