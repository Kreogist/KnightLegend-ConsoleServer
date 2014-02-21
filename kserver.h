#ifndef KSERVER_H
#define KSERVER_H

#include <QObject>
#include"QTcpServer"
#include"QTcpSocket"
#include"ksocket.h"

#include"QDebug"
class KServer : public QObject
{
    Q_OBJECT
public:
    explicit KServer(QObject *parent = 0);
    QTcpSocket pendingSocket;
    QTcpServer KLServer;
    KSocket socketPool[1000];
    //******************
    int getFreeSocket();

public slots:
    void newConnect();

};

#endif // KSERVER_H
