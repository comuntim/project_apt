#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QMap>

class MyTcpServer : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpServer(QObject *parent = nullptr); // Конструктор
    ~MyTcpServer();                                  // Деструктор
public slots:
    void slotNewConnection();          
    void slotClientDisconnected();

    void slotServerRead();
    //void slotReadClient();
private:                                // Создание приватных свойств 
    QTcpServer * TcpServer;
    QTcpSocket * TcpSocket;     // Созданий списка (ассоциативного массива map) сокетов
    int server_status;
};
#endif // TCPSERVER_H
