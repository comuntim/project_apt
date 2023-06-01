/********************************************************************************
** Form generated from reading UI file 'formtask.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
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
    QTextBrowser *textBrowser_Task;
    QTextBrowser *textBrowser_Quest;

    void setupUi(QWidget *FormTask)
    {
        if (FormTask->objectName().isEmpty())
            FormTask->setObjectName("FormTask");
        FormTask->resize(844, 413);
        gridLayoutWidget = new QWidget(FormTask);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 30, 781, 351));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lineEdit_answer = new QLineEdit(gridLayoutWidget);
        lineEdit_answer->setObjectName("lineEdit_answer");

        horizontalLayout->addWidget(lineEdit_answer);

        pushButton_Okanswer = new QPushButton(gridLayoutWidget);
        pushButton_Okanswer->setObjectName("pushButton_Okanswer");

        horizontalLayout->addWidget(pushButton_Okanswer);


        gridLayout_2->addLayout(horizontalLayout, 5, 0, 1, 1);

        textBrowser_Task = new QTextBrowser(gridLayoutWidget);
        textBrowser_Task->setObjectName("textBrowser_Task");

        gridLayout_2->addWidget(textBrowser_Task, 2, 0, 1, 1);

        textBrowser_Quest = new QTextBrowser(gridLayoutWidget);
        textBrowser_Quest->setObjectName("textBrowser_Quest");

        gridLayout_2->addWidget(textBrowser_Quest, 3, 0, 1, 1);


        retranslateUi(FormTask);

        QMetaObject::connectSlotsByName(FormTask);
    } // setupUi

    void retranslateUi(QWidget *FormTask)
    {
        FormTask->setWindowTitle(QCoreApplication::translate("FormTask", "Form", nullptr));
        lineEdit_answer->setPlaceholderText(QCoreApplication::translate("FormTask", "\320\262\320\260\321\210 \320\276\321\202\320\262\320\265\321\202", nullptr));
        pushButton_Okanswer->setText(QCoreApplication::translate("FormTask", "send", nullptr));
        textBrowser_Task->setHtml(QCoreApplication::translate("FormTask", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textBrowser_Quest->setHtml(QCoreApplication::translate("FormTask", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Cantarell'; font-size:11pt;\">\320\221\320\273\320\260-\320\261\320\273\320\260-\320\261\320\273\320\260 </span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Cantarell'; font-size:11pt;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormTask: public Ui_FormTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMTASK_H
