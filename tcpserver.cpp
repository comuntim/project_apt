#include "tcpserver.h"
#include <QDebug>
#include <QCoreApplication>

//using namespace std;

MyTcpServer::~MyTcpServer() // Деструктор
{
    //mTcpSocket->close();
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent) // Конструктор
{
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33333)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        mTcpSocket = mTcpServer->nextPendingConnection(); // Инициализация сокета
        mTcpSocket->write("I am!!!!!!!!!!!!! NOT !!!!!!!!!!!!!!!!echo server!\r\n"); // Выводим сообщение пользователю
        
        connect(mTcpSocket, &QTcpSocket::readyRead,             // коннект на получение сообщения
                this,&MyTcpServer::slotServerRead);             // при срабатывании запускаем slotServerRead
        
        connect(mTcpSocket,&QTcpSocket::disconnected,           // коннект на отключение сокета
                this,&MyTcpServer::slotClientDisconnected);     // при срабатывании запускаем slotClientDisconnected
    }
}

void MyTcpServer::slotServerRead(){
    std::string command;
    while(mTcpSocket->bytesAvailable()>0)
    {
        QByteArray symb = mTcpSocket->readAll();
        command = symb.trimmed().toStdString();
    }

    if (command == "auth")
        mTcpSocket->write("Authorization\r\n");
    else if (command == "reg")
        mTcpSocket->write("Registration\r\n");
    else if (command[0] == '/')
        mTcpSocket->write("Send command\r\n");
    else if (command == "disconnect")
            slotClientDisconnected();

}

void MyTcpServer::slotClientDisconnected(){
    mTcpSocket->close();
}
