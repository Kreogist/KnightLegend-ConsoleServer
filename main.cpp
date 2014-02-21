#include <QApplication>
#include"QThread"
#include"QObject"
#include"QTextStream"
#include"kserver.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug()<<"main thread:"<<QThread::currentThreadId();

    QThread serverThread;
    KServer server;
    //testClass t;
    server.moveToThread(&serverThread);

    QObject::connect(&server.KLServer,SIGNAL(newConnection()),&server,SLOT(newConnect()));

    //QObject::connect(&t,SIGNAL(t()),&server,SLOT(newConnect()));
    serverThread.start();

    //t.emits();

    QTextStream cin(stdin);

    QString iptCmd;
    a.exec();
    while(1)
    {
        //qDebug()<<server.KLServer.isListening();
        cin>>iptCmd;
    }
    return 0;
}

