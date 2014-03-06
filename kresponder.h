#ifndef KRESPONDER_H
#define KRESPONDER_H

#include <QObject>
#include"QTcpSocket"
#include"kserver.h"
#include"QThread"

class KResponder : public QObject
{
    Q_OBJECT
public:
    explicit KResponder(KServer *ser,QObject *parent = 0);
    QTcpSocket *tcpSocket;
    KServer *server;

signals:

public slots:
    void analyzeMsg(QTcpSocket *tcpSocket);

};

#endif // KRESPONDER_H
