#include "functions.h"
#include "database.h"

#include <QString>
#include <QStringList>

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
        return auth(inputString_list.at(0), inputString_list.at(0));
    if (NameOfFunc == "reg")
        return reg(inputString_list.at(0), inputString_list.at(0));

    return 0;


}

QString auth(QString log, QString pas){
    DataBase::sendQuerry("kslaks");
    return "authorization \r\n";
}

QString reg(QString log, QString pas){
    return "registration \r\n";
}
