#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T12:42:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VLN1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    dataaccess.cpp \
    consoleui.cpp \
    object.cpp \
    person.cpp \
    service.cpp \
    utils.cpp

HEADERS  += mainwindow.h \
    dataaccess.h \
    computer.h \
    constants.h \
    object.h \
    person.h \
    service.h \
    utils.h

FORMS    += mainwindow.ui

DISTFILES += \
    VLN1.pro.user
