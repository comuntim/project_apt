/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTask1;
    QAction *actionTask2;
    QAction *actionTask3;
    QAction *actioneixt;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Task1;
    QPushButton *pushButton_Task2;
    QPushButton *pushButton_Task3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_statistic;
    QPushButton *pushButton_exit;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuabout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(401, 343);
        actionTask1 = new QAction(MainWindow);
        actionTask1->setObjectName("actionTask1");
        actionTask2 = new QAction(MainWindow);
        actionTask2->setObjectName("actionTask2");
        actionTask3 = new QAction(MainWindow);
        actionTask3->setObjectName("actionTask3");
        actioneixt = new QAction(MainWindow);
        actioneixt->setObjectName("actioneixt");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(60, 130, 256, 84));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_Task1 = new QPushButton(gridLayoutWidget);
        pushButton_Task1->setObjectName("pushButton_Task1");

        horizontalLayout->addWidget(pushButton_Task1);

        pushButton_Task2 = new QPushButton(gridLayoutWidget);
        pushButton_Task2->setObjectName("pushButton_Task2");

        horizontalLayout->addWidget(pushButton_Task2);

        pushButton_Task3 = new QPushButton(gridLayoutWidget);
        pushButton_Task3->setObjectName("pushButton_Task3");

        horizontalLayout->addWidget(pushButton_Task3);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton_statistic = new QPushButton(gridLayoutWidget);
        pushButton_statistic->setObjectName("pushButton_statistic");

        horizontalLayout_2->addWidget(pushButton_statistic);

        pushButton_exit = new QPushButton(gridLayoutWidget);
        pushButton_exit->setObjectName("pushButton_exit");

        horizontalLayout_2->addWidget(pushButton_exit);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 401, 28));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        menuabout = new QMenu(menubar);
        menuabout->setObjectName("menuabout");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuabout->menuAction());
        menuMenu->addAction(actionTask1);
        menuMenu->addAction(actionTask2);
        menuMenu->addAction(actionTask3);
        menuMenu->addSeparator();
        menuMenu->addAction(actioneixt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionTask1->setText(QCoreApplication::translate("MainWindow", "Task1", nullptr));
        actionTask2->setText(QCoreApplication::translate("MainWindow", "Task2", nullptr));
        actionTask3->setText(QCoreApplication::translate("MainWindow", "Task3", nullptr));
        actioneixt->setText(QCoreApplication::translate("MainWindow", "eixt", nullptr));
        pushButton_Task1->setText(QCoreApplication::translate("MainWindow", "Task 1", nullptr));
        pushButton_Task2->setText(QCoreApplication::translate("MainWindow", "Task 2", nullptr));
        pushButton_Task3->setText(QCoreApplication::translate("MainWindow", "Task 3", nullptr));
        pushButton_statistic->setText(QCoreApplication::translate("MainWindow", "Statistic", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("MainWindow", "exit", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuabout->setTitle(QCoreApplication::translate("MainWindow", "about", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
