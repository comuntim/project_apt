/********************************************************************************
** Form generated from reading UI file 'form_auth_reg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_AUTH_REG_H
#define UI_FORM_AUTH_REG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_auth_reg
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_log;
    QLineEdit *lineEdit_pass;
    QLineEdit *lineEdit_mail;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_enter;
    QPushButton *pushButton_cancle;
    QPushButton *pushButton_register;

    void setupUi(QWidget *Form_auth_reg)
    {
        if (Form_auth_reg->objectName().isEmpty())
            Form_auth_reg->setObjectName("Form_auth_reg");
        Form_auth_reg->resize(339, 291);
        gridLayoutWidget = new QWidget(Form_auth_reg);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(30, 20, 281, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_log = new QLineEdit(gridLayoutWidget);
        lineEdit_log->setObjectName("lineEdit_log");

        verticalLayout->addWidget(lineEdit_log);

        lineEdit_pass = new QLineEdit(gridLayoutWidget);
        lineEdit_pass->setObjectName("lineEdit_pass");

        verticalLayout->addWidget(lineEdit_pass);

        lineEdit_mail = new QLineEdit(gridLayoutWidget);
        lineEdit_mail->setObjectName("lineEdit_mail");

        verticalLayout->addWidget(lineEdit_mail);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_enter = new QPushButton(gridLayoutWidget);
        pushButton_enter->setObjectName("pushButton_enter");

        horizontalLayout->addWidget(pushButton_enter);

        pushButton_cancle = new QPushButton(gridLayoutWidget);
        pushButton_cancle->setObjectName("pushButton_cancle");

        horizontalLayout->addWidget(pushButton_cancle);

        pushButton_register = new QPushButton(gridLayoutWidget);
        pushButton_register->setObjectName("pushButton_register");

        horizontalLayout->addWidget(pushButton_register);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Form_auth_reg);

        QMetaObject::connectSlotsByName(Form_auth_reg);
    } // setupUi

    void retranslateUi(QWidget *Form_auth_reg)
    {
        Form_auth_reg->setWindowTitle(QCoreApplication::translate("Form_auth_reg", "Form", nullptr));
        lineEdit_log->setPlaceholderText(QCoreApplication::translate("Form_auth_reg", "Login", nullptr));
        lineEdit_pass->setPlaceholderText(QCoreApplication::translate("Form_auth_reg", "Password", nullptr));
        lineEdit_mail->setPlaceholderText(QCoreApplication::translate("Form_auth_reg", "Email", nullptr));
        pushButton_enter->setText(QCoreApplication::translate("Form_auth_reg", "enter", nullptr));
        pushButton_cancle->setText(QCoreApplication::translate("Form_auth_reg", "cancle", nullptr));
        pushButton_register->setText(QCoreApplication::translate("Form_auth_reg", "register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form_auth_reg: public Ui_Form_auth_reg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_AUTH_REG_H
