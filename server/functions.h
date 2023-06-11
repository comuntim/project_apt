#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include "database.h"
#include <QStringList>
#include <iostream>


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

QString updstat(QString log, QString n, QString upd);
QString task_number_2(int beginning, int ending);
QString statisticBd(QString log);

struct Node
{
    int inf;
    Node* next;
};

void push(Node*& st, int dat);
int pop(Node*& st);
int peek(Node* st);

void add(Node*& list, int data);
void del(Node*& l, int key);

int eiler(Node** gr, int num);
void eiler_path(Node** gr, QString& cycle);
QString task_number_3(int termin);

int printMST(int parent[], int graph[][4], int V);
int findMinKey(int key[], bool mstSet[], int V);
QString primMST(int graph[][4], int V);

QString task_number_1(int T);

#endif // FUNCTIONS_H

