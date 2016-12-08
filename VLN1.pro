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
    personservice.cpp \
    computer.cpp \
    object.cpp \
    utils.cpp

HEADERS += \
    consoleui.h \
    dataaccess.h \
    person.h \
    personservice.h \
    computer.h \
    object.h \
    utils.h \
    constants.h \
    color.h

