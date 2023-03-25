#include "server.h"
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

        another_Socket -> write("I am start!\r\n");             // Выводим сообщение пользователю

        qDebug() << "Connect client: " << socketDescriptor;      // Вывод идентификатора подключённого клиента
        connect(another_Socket, &QTcpSocket::readyRead,         // коннект на получение сообщения
                this, &MyTcpServer::slotServerRead);            // при срабатывании запускаем slotServerRead

        connect(another_Socket, &QTcpSocket::disconnected,      // коннект на отключение сокета
                this, &MyTcpServer::slotClientDisconnected);                // при срабатывании запускаем deleteLater

        Sockets.push_back(another_Socket);                      // Добавление нового сокета в список сокетов

        /*
        Sockets[another_Socket->socketDescriptor()] = another_Socket;  Добавление нового сокета в список сокетов
                                                                           путём обращения к идентификатору */

}

void MyTcpServer::slotServerRead(){
    another_Socket = (QTcpSocket*)sender();         // Инициализация нового сокета
    std::string command;

    //qDebug() << Sockets << "\r\n";    // TEST LINE

    while(another_Socket->bytesAvailable()>0)
    {
        QByteArray symb = another_Socket->readAll();
        command = symb.trimmed().toStdString();
    }

    if (command == "auth")
        another_Socket -> write("Authorization\r\n");
    else if (command == "reg")
        another_Socket -> write("Registration\r\n");
    else if (command == "/log")
        qDebug() << another_Socket << "\r\n";
    else if (command[0] == '/')
        another_Socket -> write("Detected command type /<command>\r\n");
    else if (command == "disconnect")
    {
        another_Socket -> write("\r\nU r Disconnected\r\nBye Bye\r\n\r\n");
        slotClientDisconnected();
    }
    else
        another_Socket -> write("This is not a command\r\n");
}


void MyTcpServer::slotClientDisconnected(){
    another_Socket->disconnect();
}
