#ifndef FORMTASK_H
#define FORMTASK_H

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

private slots:
    void on_pushButton_Okanswer_clicked();

private:
    Ui::FormTask *ui;
};

#endif // FORMTASK_H
