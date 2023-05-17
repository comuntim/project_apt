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
    hide();
}

