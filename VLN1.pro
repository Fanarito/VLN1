QT += core
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
    computerservice.cpp \
    object.cpp

HEADERS += \
    consoleui.h \
    dataaccess.h \
    person.h \
    personservice.h \
    computer.h \
    computerservice.h \
    object.h
