#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>

class testClass : public QObject
{
    Q_OBJECT
public:
    explicit testClass(QObject *parent = 0);
    void emits();

signals:
    void t();

public slots:
    void slot();

};

#endif // TESTCLASS_H
