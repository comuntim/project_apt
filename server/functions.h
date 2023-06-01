#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include "database.h"
#include <QStringList>

QString parsing(QString inputString);

QString auth(QString log, QString pas);
QString reg(QString log, QString pas, QString mail);

#endif // FUNCTIONS_H
