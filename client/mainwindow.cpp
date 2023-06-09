#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_task = new FormTask;
    ui_auth_reg = new Form_auth_reg;

    connect(ui_auth_reg, &Form_auth_reg::return_autrh_reg, this, &MainWindow::show);
    ui_auth_reg->show();
}

MainWindow::~MainWindow()
{
    delete ui_task;
    delete ui_auth_reg;
    delete ui;
}

// =================кнопка выхода в окне=================
void MainWindow::on_pushButton_exit_clicked()
{
    close();
}

// =================кнопка выхода в меню=================
void MainWindow::on_actioneixt_triggered()
{
    on_pushButton_exit_clicked();
}



// =================кнопки заданий в окне=================
void MainWindow::on_pushButton_Task1_clicked()
{
    ui_task->set_task(1);
    ui_task->show();
}
void MainWindow::on_pushButton_Task2_clicked()
{
    ui_task->set_task(2);
    ui_task->show();
}
void MainWindow::on_pushButton_Task3_clicked()
{
    ui_task->set_task(3);
    ui_task->show();
}


// =================кнопки заданий в меню=================
void MainWindow::on_actionTask1_triggered()
{
    on_pushButton_Task1_clicked();
}

void MainWindow::on_actionTask2_triggered()
{
    on_pushButton_Task2_clicked();
}

void MainWindow::on_actionTask3_triggered()
{
    on_pushButton_Task3_clicked();
}


void MainWindow::on_pushButton_statistic_clicked()
{
    QString res = statisticBd();
    QMessageBox msg_box_stat;
    QString text = QString("Statistics: \n task1:'%1' \n task2:'%2' \n task3:'%3' ").arg(res[0]).arg(res[1]).arg(res[2]);
    msg_box_stat.setText(text);
    msg_box_stat.exec();
}
