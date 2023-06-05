#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include "database.h"
#include <QStringList>

/*!
 * \mainpage Это документация для серверной части нашего проекта QT. Подробнее вы можете ознакомиться с doxygen'ом во вкладке классов
 */

/*!
 * \class parsing
 * \brief parsing - обрабатывает входящую строку inputString
 * \param [in] inputString - разбивает на название функции и ее аргументы
 * \return возвращает определенную функцию в зависимости от того, какой аргумент отвечал за имя функции
 * Функция, которая отвечает за обработку отправляемых данных с клиента. Например авторизация, регистрация и обработка статистики
 */
QString parsing(QString inputString);

/*!
 * \class auth
 * \brief auth - авторизация пользователя
 * \param [in] log - логин пользователя
 * \param [in] pas - пароль пользователя
 * \return возвращает успешно ли прошла авторизация
 */
QString auth(QString log, QString pas);
/*!
 * \class reg
 * \brief reg - регистрация пользователя
 * \param [in] log - логин пользователя
 * \param [in] pas - пароль пользователя
 * \param [in] mail - почта пользователя
 * \return возвращает, что регистрация прошла успешно в том случае, если пользователь с таким же легином не зарегистрирован
 */
QString reg(QString log, QString pas, QString mail);

#endif // FUNCTIONS_H
