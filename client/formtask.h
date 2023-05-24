#ifndef FORMTASK_H
#define FORMTASK_H

#include "functions.h"
#include <QWidget>

namespace Ui {
class FormTask;
}

class FormTask : public QWidget
{
    Q_OBJECT

public:
    explicit FormTask(QWidget *parent = nullptr);
    ~FormTask();
    void set_task(int n);

private slots:
    void on_pushButton_Okanswer_clicked();

private:
    Ui::FormTask *ui;
    int task_num;
    QString input;
};

#endif // FORMTASK_H
