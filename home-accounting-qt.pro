#-------------------------------------------------
#
# Project created by QtCreator 2017-06-21T17:49:26
#
#-------------------------------------------------

QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = home-accounting-qt
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    accountform.cpp \
    account.cpp

HEADERS += \
        mainwindow.h \
    dbconnection.h \
    accountform.h \
    account.h

FORMS += \
        mainwindow.ui \
    accountform.ui
