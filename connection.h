#pragma once

#include <QQmlHelpers>
#include <QObject>
#include <QSqlDatabase>

class Connection : public QObject{
    Q_OBJECT
    QSqlDatabase dataConnection;
public:
    Connection(QString dataBaseName, QString userName,
               QString password, QString hostName = "localhost",
               QString database = "QSQLITE");
    bool startConnection();

    QSqlDatabase getDataConnection() const;
};
