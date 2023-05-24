#include "formtask.h"
#include "ui_formtask.h"

FormTask::FormTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTask)
{
    ui->setupUi(this);
}

FormTask::~FormTask()
{
    delete ui;
}

void FormTask::on_pushButton_Okanswer_clicked()
{
    check_Task(task_num, ui->lineEdit_answer->text(), input);
    hide();
}

void FormTask::set_task(int n) {
    task_num = n;
    QString task = "";
    switch (task_num) {
    case 1:
        input = generate_task_1();
        task = generate_test_for_task_1(input);
        break;
    case 2:
        input = generate_task_2();
        task = generate_test_for_task_2(input);
        break;
    case 3:
        input = generate_task_3();
        task = generate_test_for_task_3(input);
        break;
    }

    ui->textBrowser_Task->setText(task);
}
