#include "tcpserver.h"

//using namespace std;

MyTcpServer::~MyTcpServer() // Деструктор
{
    //mTcpSocket->close();
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
        QTcpSocket *another_Socket; // Объявление очередного нового сокета
        qDebug() << TcpSocket << "\r\n"; // TEST LINE

        another_Socket = TcpServer->nextPendingConnection(); // Инициализируем новый сокет
        another_Socket -> write("I am!!!!!!!!!!!!! NOT !!!!!!!!!!!!!!!!echo server!\r\n"); // Выводим сообщение пользователю

        connect(another_Socket, &QTcpSocket::readyRead,     // коннект на получение сообщения
                this,&MyTcpServer::slotServerRead);         // при срабатывании запускаем slotServerRead

        connect(another_Socket,&QTcpSocket::disconnected,   // коннект на отключение сокета
                this,&MyTcpServer::slotClientDisconnected); // при срабатывании запускаем slotClientDisconnected

        TcpSocket[another_Socket->socketDescriptor()] = another_Socket; /* Добавление нового сокета в список сокетов
                                                                           путём обращения к идентификатору */
        }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket *another_Socket = TcpSocket[TcpServer->socketDescriptor()]; // Инициализация нового сокета
    std::string command;
    qDebug() << TcpSocket << "\r\n";    // TEST LINE
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
        another_Socket -> write("Send command\r\n");
    else if (command == "disconnect")
            slotClientDisconnected();

}

void MyTcpServer::slotClientDisconnected()
{
    QTcpSocket *another_Socket = TcpSocket[TcpServer->socketDescriptor()];
    another_Socket->close();
}
