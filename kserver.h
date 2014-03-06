#ifndef KSERVER_H
#define KSERVER_H

#include <QObject>
#include"QTcpServer"
#include"QTcpSocket"
#include"ksocket.h"
#include"kplayerstatus.h"

#include"QDebug"
class KServer : public QObject
{
    Q_OBJECT
public:
    explicit KServer(QObject *parent = 0);
    QTcpSocket pendingSocket;
    QTcpServer KLServer;
    KSocket *socketPool[1000];
    kPlayerStatus playerStatus;
    //******************
    int getFreeSocket();

public slots:
    void newConnect();

};

#endif // KSERVER_H
