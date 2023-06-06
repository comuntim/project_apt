#include "functions.h"


QString parsing(QString inputString){
    /* InputString = "NameOfFunc&Arg1&arg2"
       хотим возвратить NameOfFunc (Arg1, arg2);
    */

    qDebug() << inputString;
    QStringList inputString_list = inputString.split('&');
    qDebug() << inputString_list;
    QString NameOfFunc = inputString_list.front();
    inputString_list.pop_front(); //удаляет имя функции из списка NameOfFunc


    if (NameOfFunc == "auth")
        return auth(inputString_list.at(0), inputString_list.at(1));
    if (NameOfFunc == "reg")
        return reg(inputString_list.at(0), inputString_list.at(1), inputString_list.at(2));
    if (NameOfFunc == "updstat")
        return updstat(inputString_list.at(0), inputString_list.at(1), inputString_list.at(2));
    if (NameOfFunc == "stat")
        return statisticBd(inputString_list.at(0));

    return 0;


}


QString auth(QString log, QString pass){
    QString query =
            QString("SELECT * FROM data WHERE login='%1' AND pass='%2'").arg(log).arg(pass);

    QString result = DataBase::getInstance()->sendQuerry(query);
    qDebug() << result;
    if (result.isEmpty()){
        qDebug() << "you are not welcome. Run away!";
        return "auth&-&error";}
    else{
        qDebug() << "you are welcome";
        return "auth&+&"+log;}
}


QString reg(QString log, QString pass, QString mail){
    QString querry =
            QString("INSERT INTO data (login, pass, mail) VALUES ('%1', '%2', '%3');").arg(log).arg(pass).arg(mail);

    QString result = DataBase::getInstance()->sendQuerry(querry);
    qDebug() << result;
    if (result.isEmpty())
        return "registration";
    else
        return "error";
}


QString updstat(QString log, QString n, QString upd){
    qDebug() << log << n << upd;
    QString helpQuerry = QString("SELECT stat FROM data WHERE login='%1'").arg(log);
    QString helpStatistic = DataBase::getInstance() -> sendQuerry(helpQuerry);

    int n_int = n.toInt();
    if (upd == "+") {
        helpStatistic.replace(n_int - 1, 1, "1");
        QString querry =
            QString("UPDATE data SET stat = '%1' WHERE login = '%2';").arg(helpStatistic).arg(log);
        QString result = DataBase::getInstance()->sendQuerry(querry);
        qDebug() << "result "<< result;
    }
    else if (upd == "-"){
        helpStatistic.replace(n_int - 1, 1, "0");
        QString querry =
            QString("UPDATE data SET stat = '%1' WHERE login = '%2';").arg(helpStatistic).arg(log);
        QString result = DataBase::getInstance()->sendQuerry(querry);
    }


}


QString statisticBd(QString log){
    QString querry =
        QString("SELECT stat FROM data WHERE login = '%1';").arg(log);

    QString result = DataBase::getInstance()->sendQuerry(querry);
    return result;
}
