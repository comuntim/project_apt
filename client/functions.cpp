#include "functions.h"
#include "form_auth_reg.h"
#include "sendtohost.h"

QString loginUser;

QString authorization(QString log, QString pass){
    QString res = "auth&"+log+"&"+pass;
//    qDebug() << res;
    loginUser = log;
    sendToHost::getInstance() -> sendMess(res);
    QString res2 = sendToHost::getInstance() -> readMess();
    qDebug() << res2;
    return res2;
//    sendToServer(res);
}

QString read() {
    qDebug() << "i'm read! ";
    QString res = sendToHost::getInstance() -> readMess();
    // qDebug() << res;
    return res;
}

void registration(QString log, QString pass, QString mail){
    QString res = "reg&"+log+"&"+pass+"&"+mail;
//    qDebug() << res;
    sendToHost::getInstance() -> sendMess(res);
    //Client::sendToServer(res);
}


void update_stat(int n, QString upd){
    QString res = "updstat&"+loginUser+"&"+QString::number(n)+"&"+upd;
    qDebug() << res;
    sendToHost::getInstance() -> sendMess(res);
//    qDebug() << res;
    //Client::sendToServer(res);
}

QString statisticBd(){
    QString res = "stat&"+loginUser;
    sendToHost::getInstance() -> sendMess(res);

    QString res2 = sendToHost::getInstance() -> readMess();
    return res2;
}















QString solve_task1(QString input){
    return "anc1";
}

QString solve_task2(QString input){
    return "anc2";
}

QString solve_task3(QString input){
    return "anc3";
}


QString generate_test_for_task_1(QString input){
    return "test_for_task_1 \n"+input;
}

QString generate_test_for_task_2(QString input){
    return "test_for_task_2 \n"+input;
}

QString generate_test_for_task_3(QString input){
    return "test_for_task_3 \n"+input;
}


QString generate_task_1(){
    return "task1";
}

QString generate_task_2(){
    return "task2";
}

QString generate_task_3(){
    return "task3";
}


void check_Task(int task_number, QString answer, QString input){
    QString solution = "";
    switch (task_number) {
    case 1:
        solution = solve_task1(input);
        break;
    case 2:
        solution= solve_task2(input);
        break;
    case 3:
        solution= solve_task3(input);
        break;
    }

    if (answer == solution)
        update_stat(task_number, "+");
    else
        update_stat(task_number, "-");

}


