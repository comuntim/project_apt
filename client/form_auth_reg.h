#ifndef FORM_AUTH_REG_H
#define FORM_AUTH_REG_H

#include "functions.h"



#include <QWidget>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class Form_auth_reg;
}

class Form_auth_reg : public QWidget
{
    Q_OBJECT

public:
    explicit Form_auth_reg(QWidget *parent = nullptr);
    ~Form_auth_reg();

    QTcpSocket* socket;
    QString Data;

private slots:
    void on_pushButton_register_clicked();

    void on_pushButton_cancle_clicked();

    void on_pushButton_enter_clicked();

signals:
    void return_autrh_reg();

private:
    Ui::Form_auth_reg *ui;
};

#endif // FORM_AUTH_REG_H
