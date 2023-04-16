#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>

QString parsing(QByteArray inputString);

QString auth(QString log, QString pas);
QString reg(QString log, QString pas);

#endif // FUNCTIONS_H
