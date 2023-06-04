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

    return 0;


}


QString auth(QString log, QString pass){
    QString query =
            QString("SELECT * FROM data WHERE login='%1' AND pass='%2'").arg(log).arg(pass);

    QString result = DataBase::getInstance()->sendQuerry(query);
    qDebug() << result;
    if (result.isEmpty()){
        qDebug() << "you are not welcome. Run away!";
        return "auth- error \r\n";}
    else{
        qDebug() << "you are welcome";
        return "auth+ "+ log+"\r\n";}
}


QString reg(QString log, QString pass, QString mail){
    QString querry =
            QString("INSERT INTO data (login, pass, mail) VALUES ('%1', '%2', '%3');").arg(log).arg(pass).arg(mail);

    QString result = DataBase::getInstance()->sendQuerry(querry);
    qDebug() << result;
    if (result.isEmpty())
        return "registration \r\n";
    else
        return "error \r\n";
}
