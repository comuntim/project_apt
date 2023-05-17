#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "formtask.h"
#include <QMessageBox>
#include "form_auth_reg.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_exit_clicked();

    void on_actioneixt_triggered();

    void on_pushButton_Task1_clicked();

    void on_actionTask1_triggered();

    void on_pushButton_Task2_clicked();

    void on_actionTask2_triggered();

    void on_pushButton_Task3_clicked();

    void on_actionTask3_triggered();

    void on_pushButton_statistic_clicked();

private:
    Ui::MainWindow *ui;
    FormTask *ui_task;
    Form_auth_reg *ui_auth_reg;
};
#endif // MAINWINDOW_H
