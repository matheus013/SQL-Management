QT += core
QT -= gui

CONFIG += c++11

TARGET = AutoBuildSQL
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myclass.cpp \
    utilsql.cpp

HEADERS += \
    myclass.h \
    utilsql.h