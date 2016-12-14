#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T12:42:00
#
#-------------------------------------------------

QT       += core gui sql

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
    utils.cpp \
    additem.cpp \
    infopage.cpp \
    infopagecomp.cpp

HEADERS  += mainwindow.h \
    dataaccess.h \
    computer.h \
    constants.h \
    object.h \
    person.h \
    service.h \
    utils.h \
    color.h \
    consoleui.h \
    additem.h \
    infopage.h \
    infopagecomp.h

FORMS    += mainwindow.ui \
    additem.ui \
    infopage.ui \
    infopagecomp.ui \
    help.ui

DISTFILES += \
    VLN1.pro.user \
    CompSci.sqlite

RESOURCES += \
    resource.qrc \
    CompSci.sqlite
