#include "connection.h"
#include <QDebug>

Connection::Connection(QString dataBaseName, QString userName,
                       QString password, QString hostName, QString database){
    dataConnection = QSqlDatabase::addDatabase(database);
    dataConnection.setConnectOptions(dataBaseName);
    dataConnection.setHostName(hostName);
    dataConnection.setPassword(password);
    dataConnection.setUserName(userName);

}

bool Connection::startConnection(){
    if (!dataConnection.open()) {
        qDebug() << "Database error occurred";
        return false;
    }
    qDebug() << "Database connected";
    return true;
}
