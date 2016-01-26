#pragma once

#include <QObject>
#include "QQmlHelpers"

class MyClass : public QObject{
    Q_OBJECT
    QML_WRITABLE_PROPERTY(int,id)
    QML_WRITABLE_PROPERTY(QString, login)
    //    QML_WRITABLE_PROPERTY(QString,sexo)
    //    QML_WRITABLE_PROPERTY(int, id)
public:
    MyClass();
    MyClass(int id,QString login);

};
