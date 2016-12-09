QT += core sql
QT -= gui

CONFIG += c++11

TARGET = VLN1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    dataaccess.cpp \
    person.cpp \
    computer.cpp \
    object.cpp \
    utils.cpp \
    service.cpp

HEADERS += \
    consoleui.h \
    dataaccess.h \
    person.h \
    computer.h \
    object.h \
    utils.h \
    constants.h \
    color.h \
    service.h

