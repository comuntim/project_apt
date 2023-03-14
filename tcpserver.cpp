#include "tcpserver.h"
#include <QDebug>
#include <QCoreApplication>

//using namespace std;

MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
    mTcpServer->close();
    server_status=0;
}
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
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
        mTcpSocket = mTcpServer->nextPendingConnection();
        mTcpSocket->write("I am!!!!!!!!!!!!! NOT !!!!!!!!!!!!!!!!echo server!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
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
