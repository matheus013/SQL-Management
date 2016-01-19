QT += core sql
QT -= gui

CONFIG += c++11

TARGET = AutoBuildSQL
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myclass.cpp \
    utilsql.cpp \
    connection.cpp \
    daogeneric.cpp

HEADERS += \
    myclass.h \
    utilsql.h \
    connection.h \
    daogeneric.h
