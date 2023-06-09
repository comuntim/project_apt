#ifndef SENDTOHOST_H
#define SENDTOHOST_H
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QObject>
#include <QDebug>

class sendToHost;

class sendToHostDestroyer
{
private:
    sendToHost * p_instance;
public:
    ~sendToHostDestroyer() { delete p_instance;}
    void initialize(sendToHost * p){p_instance = p;}
};


class sendToHost: public QObject
{
    Q_OBJECT
private:
    static sendToHost * p_instance;
    static sendToHostDestroyer destroyer;
    QTcpSocket* socket;
protected:
    sendToHost(QObject *parent = nullptr);
    sendToHost(const sendToHost& ) = delete;
    sendToHost& operator = (sendToHost &)=delete;
    ~sendToHost() {
        socket->close();
    }
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
    void sendMess(QString str);
    QString readMess();


public slots:
    void slotconnected();
};


#endif // SENDTOHOST_H
