#include "kresponder.h"

KResponder::KResponder(KServer *ser, QObject *parent) :
    QObject(parent)
{
    server=ser;
}

void KResponder::analyzeMsg(QTcpSocket *tcpSocket)
{
    qDebug()<<"a";
    QString fullMsg,cmdType,secondPart,userID,cmd;
    fullMsg=tcpSocket->readAll();

    userID=fullMsg.split(",").first();
    fullMsg=fullMsg.split(",").last();

    cmdType=fullMsg.split(",").first();
    cmd=fullMsg.split(",").last();

    if(cmdType=="alive")
    {

    }
    else if(cmdType=="chat")
    {
        for(int i=0;i<1000;i++)
        {
            if(!server->socketPool[i]->isFree())
            {
                server->socketPool[i]->socket->write("chat,"+cmd);
            }
        }
    }
    qDebug()<<QThread::currentThreadId();
    qDebug()<<userID+" "+cmdType+" "+cmd;
}
