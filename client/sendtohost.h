#ifndef SENDTOHOST_H
#define SENDTOHOST_H

#include <mainwindow.h>
#include <QTcpSocket>

//Улучшенная реализация
class sendToHost;

class sendToHostDestroyer
{
    private:
        sendToHost* p_instance;
    public:
        ~sendToHostDestroyer() { delete p_instance;}
        void initialize(sendToHost * p){p_instance = p;};
};


class sendToHost {
    private:
        static sendToHost* p_instance;
        static sendToHostDestroyer destroyer;
        QTcpSocket* socket;
    protected:
        sendToHost(){

            socket = new QTcpSocket();
            socket -> connectToHost("127.0.0.1", 33333);
        }
        sendToHost(const sendToHost& );
        sendToHost& operator = (sendToHost &);
        ~sendToHost() {}
        friend class sendToHostDestroyer;
    public:
        static sendToHost* getInstance(){
            if (!p_instance)
            {
                p_instance = new sendToHost();
                destroyer.initialize(p_instance);


            }
            return p_instance;
        }

        QString sendClient(QString res){
//            socket = (QTcpSocket*)sender();
            QByteArray resArray = res.toUtf8();
            socket -> write(resArray);
            return res;
        }
};

#endif // SENDTOHOST_H
