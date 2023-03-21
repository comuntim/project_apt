#include "tcpserver.h"
#include <QDebug>
#include <QCoreApplication>

//using namespace std;

MyTcpServer::~MyTcpServer() // Деструктор
{
    //TcpSocket->close();
    TcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent) // Конструктор
{
    TcpServer = new QTcpServer(this);
    connect(TcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!TcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        TcpSocket = TcpServer->nextPendingConnection(); // Инициализация сокета
        TcpSocket->write("I am!!!!!!!!!!!!! NOT !!!!!!!!!!!!!!!!echo server!\r\n"); // Выводим сообщение пользователю
        
        connect(TcpSocket, &QTcpSocket::readyRead,             // коннект на получение сообщения
                this,&MyTcpServer::slotServerRead);             // при срабатывании запускаем slotServerRead
        
        connect(TcpSocket,&QTcpSocket::disconnected,           // коннект на отключение сокета
                this,&MyTcpServer::slotClientDisconnected);     // при срабатывании запускаем slotClientDisconnected
    }
}

void MyTcpServer::slotServerRead(){
    std::string command;
    while(TcpSocket->bytesAvailable()>0)
    {
        QByteArray symb = TcpSocket->readAll();
        command = symb.trimmed().toStdString();
    }

    if (command == "auth")
        TcpSocket->write("Authorization\r\n");
    else if (command == "reg")
        TcpSocket->write("Registration\r\n");
    else if (command[0] == '/')
        TcpSocket->write("Send command\r\n");
    else if (command == "disconnect")
            slotClientDisconnected();

}

void MyTcpServer::slotClientDisconnected(){
    TcpSocket->close();
}
