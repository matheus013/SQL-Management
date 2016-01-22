#pragma once

#include <QObject>
#include "QQmlHelpers"

class Users : public QObject{
    Q_OBJECT
    QML_WRITABLE_PROPERTY(int,id)
    QML_WRITABLE_PROPERTY(QString, username)
    QML_WRITABLE_PROPERTY(QString, password)
    QML_WRITABLE_PROPERTY(QString, name)
    QML_WRITABLE_PROPERTY(int, level)

public:
    Users();
    Users(QString username,QString password,QString name, int level);

};
