#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include "database.h"
#include <QStringList>

QString parsing(QString inputString);
QString create(QString str);

QString auth(QString log, QString pas);
QString reg(QString log, QString pas);

#endif // FUNCTIONS_H
