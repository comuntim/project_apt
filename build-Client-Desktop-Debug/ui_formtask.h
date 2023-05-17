/********************************************************************************
** Form generated from reading UI file 'formtask.ui'
**
** Created by: Qt User Interface Compiler version 5.15.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMTASK_H
#define UI_FORMTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormTask
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_answer;
    QPushButton *pushButton_Okanswer;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *FormTask)
    {
        if (FormTask->objectName().isEmpty())
            FormTask->setObjectName(QString::fromUtf8("FormTask"));
        FormTask->resize(844, 413);
        gridLayoutWidget = new QWidget(FormTask);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 30, 781, 351));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_answer = new QLineEdit(gridLayoutWidget);
        lineEdit_answer->setObjectName(QString::fromUtf8("lineEdit_answer"));

        horizontalLayout->addWidget(lineEdit_answer);

        pushButton_Okanswer = new QPushButton(gridLayoutWidget);
        pushButton_Okanswer->setObjectName(QString::fromUtf8("pushButton_Okanswer"));

        horizontalLayout->addWidget(pushButton_Okanswer);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 0, 0, 1, 1);


        retranslateUi(FormTask);

        QMetaObject::connectSlotsByName(FormTask);
    } // setupUi

    void retranslateUi(QWidget *FormTask)
    {
        FormTask->setWindowTitle(QCoreApplication::translate("FormTask", "Form", nullptr));
        lineEdit_answer->setPlaceholderText(QCoreApplication::translate("FormTask", "\320\262\320\260\321\210 \320\276\321\202\320\262\320\265\321\202", nullptr));
        pushButton_Okanswer->setText(QCoreApplication::translate("FormTask", "send", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("FormTask", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\227\320\260\320\264\320\260\321\207\320\260 1</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\221\320\273\320\260-\320\261\320\273\320\260-\320\261\320\273\320\260 \321\200\320\276\320\274\320\260\320\275 \321\201\320\273\320\260\320\261\321\213\320\271 \320\274\320\260\320\273\321\214\321\207\320\270\320\272<"
                        "/p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormTask: public Ui_FormTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMTASK_H
