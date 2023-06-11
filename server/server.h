/*#ifndef SERVER_H
#define SERVER_H


#include "functions.h"

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QVector>


class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    MyTcpServer();              // Конструктор
    QTcpSocket *another_Socket; // Создание сокета

public slots:
    void incomingConnection(qintptr socketDescriptor);

    void slotClientDisconnected();

    void slotServerRead();
    //void slotReadClient();

private:                                // Создание приватных свойств
    QVector <QTcpSocket*> Sockets;      // Созданий списка (ассоциативного массива map) сокетов
    int server_status;
};
#endif // SERVER_H*/

#ifndef SERVER_H
#define SERVER_H

#include "functions.h"

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QVector>

class MyTcpServer : public QTcpServer
{
    Q_OBJECT
public:
    MyTcpServer();
    QTcpSocket *another_Socket;

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotClientDisconnected();
    void slotServerRead();

private:
    QVector<QTcpSocket*> Sockets;
    int server_status;
};

#endif // SERVER_H


