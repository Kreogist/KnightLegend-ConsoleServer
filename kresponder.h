#ifndef KRESPONDER_H
#define KRESPONDER_H

#include <QObject>
#include"QTcpSocket"

#include"QThread"
class KResponder : public QObject
{
    Q_OBJECT
public:
    explicit KResponder(QObject *parent = 0);
    QTcpSocket *tcpSocket;

signals:

public slots:
    void analyzeMsg(QTcpSocket *tcpSocket);

};

#endif // KRESPONDER_H
