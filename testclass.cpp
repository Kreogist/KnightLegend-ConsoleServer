#include "testclass.h"
#include"QThread"
#include"QDebug"
testClass::testClass(QObject *parent) :
    QObject(parent)
{
}
void testClass::slot()
{
    qDebug()<<QThread::currentThreadId();
}
void testClass::emits()
{
    emit t();
}
