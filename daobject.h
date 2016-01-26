#pragma once

#include <queue>
#include <QObject>
#include <QList>
#include "connection.h"


class DAObject : QObject{
    Q_OBJECT
    QList<QObject*> data;
    Connection *connection;
public:
    DAObject();
    DAObject(QList<QObject*> list);
    QObject* at(int id);
    void insert(QObject *object);
    void update(QObject *object, QString where);
    void remove(QObject *object, QString where);
    void remove(QObject *object, QStringList where, QString myOperator);
    void removeAll(QObject *object);
    void customCommand(QString textQuery);
    void loadData(QString nameTable);
};
