#ifndef KSOCKET_H
#define KSOCKET_H

#include <QObject>
#include"QTcpSocket"
#include"QThread"
#include"kresponder.h"

#include"QDebug"
class KSocket : public QObject
{
    Q_OBJECT
public:
    explicit KSocket(QObject *parent = 0);
    QTcpSocket *socket;
    QThread resThread;
    KResponder *responder;
    bool freeTag;
    bool isFree();

signals:
    void proccesMsg(QTcpSocket*);

public slots:
    void reciveMsg();
    void connectionLost();
};

#endif // KSOCKET_H
