#ifndef KPLAYERSTATUS_H
#define KPLAYERSTATUS_H

#include <QObject>
#include "map"
class kPlayerStatus : public QObject
{
    Q_OBJECT
public:
    explicit kPlayerStatus(QObject *parent = 0);
    bool isPlayerAlive[1000];

signals:

public slots:

};

#endif // KPLAYERSTATUS_H
