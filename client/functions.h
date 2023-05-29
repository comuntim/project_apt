#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>
#include <QDebug>

void authorization(QString log, QString pass);
void registration(QString log, QString pass, QString mail);
void update_stat(QString log, QString pass);

QString solve_task1(QString input);
QString solve_task2(QString input);
QString solve_task3(QString input);

QString generate_test_for_task_1(QString input);
QString generate_test_for_task_2(QString input);
QString generate_test_for_task_3(QString input);

QString generate_task_1();
QString generate_task_2();
QString generate_task_3();

void check_Task(int task_number, QString answer, QString input);

#endif // FUNCTIONS_H

