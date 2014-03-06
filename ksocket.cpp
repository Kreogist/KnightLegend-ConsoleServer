#include "ksocket.h"

KSocket::KSocket(KServer *ser, QObject *parent) :
    QObject(parent)
{
    freeTag=false;
    //socket=new QTcpSocket(this);
    responder=new KResponder(ser);
    connect(this,SIGNAL(proccesMsg(QTcpSocket*)),responder,SLOT(analyzeMsg(QTcpSocket*)));
}

void KSocket::reciveMsg()
{
    qDebug()<<"Recieved Msg";
    responder->moveToThread(&resThread);
    resThread.start();

    //qDebug()<<socket->readAll();

    emit proccesMsg(socket);
}

bool KSocket::isFree()
{
    return !freeTag;
}

void KSocket::connectionLost()
{
    qDebug()<<"connection lost";
    freeTag=false;
}
