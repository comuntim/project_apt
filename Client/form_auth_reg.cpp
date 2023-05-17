#include "form_auth_reg.h"
#include "ui_form_auth_reg.h"

Form_auth_reg::Form_auth_reg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_auth_reg)
{
    ui->setupUi(this);
    ui->lineEdit_mail->setVisible(false);
    ui->pushButton_cancle->setVisible(false);
}

Form_auth_reg::~Form_auth_reg()
{
    delete ui;
}

void Form_auth_reg::on_pushButton_register_clicked()
{
    ui->lineEdit_mail->setVisible(true);
    ui->pushButton_register->setVisible(false);
    ui->pushButton_cancle->setVisible(true);
}


void Form_auth_reg::on_pushButton_cancle_clicked()
{
    ui->lineEdit_mail->setVisible(false);
    ui->pushButton_register->setVisible(true);
    ui->pushButton_cancle->setVisible(false);
}


void Form_auth_reg::on_pushButton_enter_clicked()
{
    emit return_autrh_reg();
    hide();

}

