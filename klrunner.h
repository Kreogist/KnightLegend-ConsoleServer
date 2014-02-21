#ifndef KLRUNNER_H
#define KLRUNNER_H

#include <QObject>
#include"kserver.h"
#include"QThread"
class KLRunner : public QObject
{
    Q_OBJECT
public:
    explicit KLRunner(QObject *parent = 0);
    KServer server;
    void work();

signals:

public slots:

};

#endif // KLRUNNER_H
