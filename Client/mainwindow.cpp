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


void MainWindow::on_pushButton_exit_clicked()
{
    close();
}


void MainWindow::on_actioneixt_triggered()
{
    on_pushButton_exit_clicked();
}


void MainWindow::on_pushButton_Task1_clicked()
{
    ui_task->show();
}


void MainWindow::on_actionTask1_triggered()
{
    on_pushButton_Task1_clicked();
}


void MainWindow::on_pushButton_Task2_clicked()
{
    ui_task->show();
}


void MainWindow::on_actionTask2_triggered()
{
    on_pushButton_Task2_clicked();
}




void MainWindow::on_pushButton_Task3_clicked()
{
    ui_task->show();
}


void MainWindow::on_actionTask3_triggered()
{
    on_pushButton_Task3_clicked();
}


void MainWindow::on_pushButton_statistic_clicked()
{
    QMessageBox msg_box_stat;
    msg_box_stat.setText("Statistics: \n task1: \n task2: \n task3: ");
    msg_box_stat.exec();

}

