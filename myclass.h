#pragma once

#include <QObject>
#include "QQmlHelpers"

class MyClass : public QObject{
    Q_OBJECT
    QML_WRITABLE_PROPERTY(QString,name)
    QML_WRITABLE_PROPERTY(int, age)
//    QML_WRITABLE_PROPERTY(QString,sexo)
    QML_WRITABLE_PROPERTY(int, id)
public:
    MyClass();
    MyClass(QString name,int age);

};
