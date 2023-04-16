#include "functions.h"

#include <QString>
#include <QStringList>

QString parsing(QByteArray inputString_arr){
    /* InputString = "NameOfFunc&Arg1&arg2"
       хотим возвратить NameOfFunc (Arg1, arg2);
    */

    QString inputString_str = QString(inputString_arr);
    //QStringList inputString_list = inputString_str.split(QLatin1Char("&"));    НЕ РАБОТАЕТ СТРОКА
    QStringList inputString_list = inputString_str.split('&');
    QString NameOfFunc = inputString_list.front();
    inputString_list.pop_front(); //удаляет имя функции из списка NameOfFunc

    if (NameOfFunc == "auth")
        return auth(inputString_list.at(0), inputString_list.at(1));
    if (NameOfFunc == "reg")
        return reg(inputString_list.at(0), inputString_list.at(1));

    return "";
}

QString auth(QString log, QString pas){
    return "authorization\n";
}

QString reg(QString log, QString pas){
    return "registration\n";
}
