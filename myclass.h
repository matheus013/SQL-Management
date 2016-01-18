#pragma once
#include "QQmlHelpers"

#include <QObject>

class MyClass : public QObject{
    Q_OBJECT
    QML_WRITABLE_PROPERTY(QString,name)
    QML_WRITABLE_PROPERTY(int, age)
    QML_WRITABLE_PROPERTY(QString,sexo)
public:
    MyClass();

};
