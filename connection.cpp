#include "connection.h"
#include <QDebug>

QSqlDatabase Connection::getDataConnection() const
{
    return dataConnection;
}

Connection::Connection(QString dataBaseName, QString userName,
                       QString password, QString hostName, QString database){
    dataConnection = QSqlDatabase::addDatabase(database);
    dataConnection.setConnectOptions(dataBaseName);
    dataConnection.setHostName(hostName);
    dataConnection.setPassword(password);
    dataConnection.setUserName(userName);

}

bool Connection::startConnection(){
    if (!dataConnection.open()) return false;
    else return true;

}
