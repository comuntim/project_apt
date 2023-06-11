/*#include "server.h"
const int port = 33333;



MyTcpServer::MyTcpServer() // Конструктор
{
    if(this->listen(QHostAddress::Any, port)){
        server_status=1;
        qDebug() << "\r\nserver is started in port #" << port;
        qDebug() << "putty -telnet localhost" << port << "\r\n";
    } else {
        qDebug() << "server is not started";
    }
    server_status=0;
}



void MyTcpServer::incomingConnection(qintptr socketDescriptor){
        another_Socket = new QTcpSocket;                        // Создание очередного нового сокета
        another_Socket->setSocketDescriptor(socketDescriptor);  // Определение идентификатора сокета

//        another_Socket -> write("I am start!");             // Выводим сообщение пользователю

        qDebug() << "Connect client: " << socketDescriptor;      // Вывод идентификатора подключённого клиента
        connect(another_Socket, &QTcpSocket::readyRead,         // коннект на получение сообщения
                this, &MyTcpServer::slotServerRead);            // при срабатывании запускаем slotServerRead

        connect(another_Socket, &QTcpSocket::disconnected,      // коннект на отключение сокета
                this, &MyTcpServer::slotClientDisconnected);                // при срабатывании запускаем deleteLater

        Sockets.push_back(another_Socket);                      // Добавление нового сокета в список сокетов


        Sockets[another_Socket->socketDescriptor()] = another_Socket;  Добавление нового сокета в список сокетов
                                                                           путём обращения к идентификатору

}

void MyTcpServer::slotServerRead(){
    another_Socket = (QTcpSocket*)sender();         // Инициализация нового сокета

    QString res = another_Socket->readAll();

    if (res == "disconnect")
        {
            another_Socket -> write("U r Disconnected Bye Bye ");
            slotClientDisconnected();
        }
    else
        another_Socket -> write(parsing(res.toUtf8()).toUtf8());
}


void MyTcpServer::slotClientDisconnected(){
    another_Socket->disconnect();
}*/

#include "server.h"

MyTcpServer::MyTcpServer()
{
    if(this->listen(QHostAddress::Any, 33333)){
        server_status=1;
    } else {
        qDebug() << "server is not started";
    }
    server_status=0;
}

void MyTcpServer::incomingConnection(qintptr socketDescriptor)
{
    another_Socket = new QTcpSocket;
    another_Socket->setSocketDescriptor(socketDescriptor);

    qDebug() << "Connect client: " << socketDescriptor;

    connect(another_Socket, &QTcpSocket::readyRead,
            this, &MyTcpServer::slotServerRead);

    connect(another_Socket, &QTcpSocket::disconnected,
            this, &MyTcpServer::slotClientDisconnected);

    Sockets.push_back(another_Socket);
}

void MyTcpServer::slotClientDisconnected()
{
    QTcpSocket* disconnectedSocket = static_cast<QTcpSocket*>(sender());
    Sockets.removeOne(disconnectedSocket);
    disconnectedSocket->deleteLater();
}

void MyTcpServer::slotServerRead()
{
    QTcpSocket* senderSocket = static_cast<QTcpSocket*>(sender());
    QString res = senderSocket->readAll();

    if (res == "disconnect")
    {
        senderSocket->write("U r Disconnected Bye Bye ");
        slotClientDisconnected();
    }
    else
    {
        QString response = parsing(res);
        senderSocket->write(response.toUtf8());
    }
}

