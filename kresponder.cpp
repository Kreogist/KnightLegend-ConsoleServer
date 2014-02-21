#include "kresponder.h"

KResponder::KResponder(QObject *parent) :
    QObject(parent)
{
    //qDebug()<<tcpSocket->state();
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
    qDebug()<<QThread::currentThreadId();
    qDebug()<<userID+" "+cmdType+" "+cmd;
}
