#include "kserver.h"

KServer::KServer(QObject *parent) :
    QObject(parent)
{
    KLServer.listen(QHostAddress::Any,9825);
}

void KServer::newConnect()
{
    int tNum=getFreeSocket();
    socketPool[tNum]=new KSocket(this);
    socketPool[tNum]->socket=KLServer.nextPendingConnection();

    connect(socketPool[tNum]->socket,SIGNAL(readyRead()),socketPool[tNum],SLOT(reciveMsg()));
    connect(socketPool[tNum]->socket,SIGNAL(disconnected()),socketPool[tNum],SLOT(connectionLost()));
}

int KServer::getFreeSocket()
{
    int i;
    for(i=0;i<1000;i++)
    {
        if(socketPool[i]->isFree())
        {
            socketPool[i]->freeTag=true;
            qDebug()<<i;
            return i;
        }
    }
    return -1;
}
