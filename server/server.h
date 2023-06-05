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
    MyTcpServer();              // Конструктор
    QTcpSocket *another_Socket; // Создание сокета

public slots:
    /*!
     * \class incomingConnection
     * \brief incomingConnection - используется для обработки поступающего подключения
     * Создает и определяет новый сокет. Выводит сообщение пользователю и устанавливает connect на соединение и отключение
     */
    void incomingConnection(qintptr socketDescriptor);
    /*!
     * \class slotClientDisconnected
     * \brief slotClientDisconnected - обрабатывает отключение от сервера
     */
    void slotClientDisconnected();
    /*!
     * \class slotServerRead
     * \brief slotServerRead - обрабатывет отключение или проводит parsing
     * Отправляет данные
     */
    void slotServerRead();
    //void slotReadClient();

private:                                // Создание приватных свойств
    QVector <QTcpSocket*> Sockets;      // Созданий списка (ассоциативного массива map) сокетов
    int server_status;
};
#endif // SERVER_H
