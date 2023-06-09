#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QString>
#include <QDebug>




/*!
 * \mainpage Это документация для клиентской части нашего проекта QT. Подробнее вы можете ознакомиться с doxygen'ом во вкладке классов
 */

/*!
 * \class authorization
 * \brief authorization - авторизация пользователя
 * Происходит авторизация пользователя путем отправки логина и пароля на сервер, после чего мы можем узнать правильный ли логин и пароль или нет
 * \param [in] log
 * \param [in] pass
 */
QString authorization(QString log, QString pass);
/*!
 * \class registration
 * \brief registration - регистрация пользователя
 * Происходит регистрация пользователя путем отправки логина и пароля на сервер, после чего мы можем зарегистрировать пользователя с такими данными
 * \param [in] log
 * \param [in] pass
 * \param [in] mail
 */
void registration(QString log, QString pass, QString mail);
/*!
 * \class update_stat
 * \brief update_stat - функция, отвечающая за статистику
 * \param [in] log
 * \param [in] pass
 */
void update_stat(QString log, QString pass);

QString statisticBd();

QString read();

QString solve_task1(QString input);
QString solve_task2(QString input);
QString solve_task3(QString input);

QString generate_test_for_task_1(QString input);
QString generate_test_for_task_2(QString input);
QString generate_test_for_task_3(QString input);

QString generate_task_1();
QString generate_task_2();
QString generate_task_3();

void check_Task(int task_number, QString answer, QString input);

#endif // FUNCTIONS_H

