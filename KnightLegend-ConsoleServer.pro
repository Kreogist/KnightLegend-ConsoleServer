#-------------------------------------------------
#
# Project created by QtCreator 2014-02-16T20:39:16
#
#-------------------------------------------------

QT       += core network gui widgets


TARGET = KnightLegend-ConsoleServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    kserver.cpp \
    ksocket.cpp \
    kresponder.cpp

HEADERS += \
    kserver.h \
    ksocket.h \
    kresponder.h
