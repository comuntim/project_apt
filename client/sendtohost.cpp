#include "sendtohost.h"
#include "mainwindow.h"

sendToHost::sendToHost(QObject * parent):QObject(parent)
{
    socket = new QTcpSocket();
    socket->connectToHost("127.0.0.1", 33333);
    connect(socket, SIGNAL(connected()), SLOT(slotconnected()));
    //connect(socket, SIGNAL(readyRead()), this,SLOT(readMess()));
}

void sendToHost::sendMess(QString mess)
{
    qDebug() << mess << "send";
    socket-> write(mess.toUtf8());
}

QString sendToHost::readMess()
{
    QString dataIn;
    dataIn.clear();
    while(socket->bytesAvailable()>0)
        dataIn += socket->readAll();
    qDebug()<<dataIn<<"read";
    return dataIn;

}

void sendToHost::slotconnected()
{
    qDebug() << "Received the connected() signal";
}

sendToHost * sendToHost::p_instance;
sendToHostDestroyer sendToHost::destroyer;
