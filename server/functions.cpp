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
        return reg(inputString_list.at(0), inputString_list.at(1));

    return 0;


}


QString auth(QString log, QString pass){
    QString querry =
            QString("SELECT * FROM data WHERE login='%1' AND pass='%2'").arg(log).arg(pass);

    QString result = DataBase::getInstance()->sendQuerry(querry);
    qDebug() << result;
    if (result.isEmpty())
        return "authorization completed \r\n";
    else
        return "error \r\n";
}

QString reg(QString log, QString pass){
    QString querry =
            QString("INSERT INTO data (login, pass) VALUES ('%1', '%2');").arg(log).arg(pass);

    qDebug() << querry;
    QString result = DataBase::getInstance()->sendQuerry(querry);
    qDebug() << result;
    if (result.isEmpty())
        return "registration \r\n";
    else
        return "error \r\n";
}
