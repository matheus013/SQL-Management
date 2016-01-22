QT += core sql quick
QT -= gui

CONFIG += c++11

TARGET = AutoBuildSQL
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myclass.cpp \
    connection.cpp \
    database.cpp \
    tablemanagement.cpp \
    daobject.cpp \
    users.cpp

HEADERS += \
    myclass.h \
    connection.h \
    database.h \
    tablemanagement.h \
    daobject.h \
    users.h
