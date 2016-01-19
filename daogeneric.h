#pragma once

#include <QObject>
#include <QList>
#include "connection.h"


class DAOGeneric : QObject{
    Q_OBJECT
    QList<QObject*> data;
    Connection *connection;
public:
    DAOGeneric();
    DAOGeneric(QList<QObject*> list);
    QObject* at(int id);
    void insert(QObject *object);
    void update(QObject *object, QString where);
    void remove(QObject *object, QString where);
    void remove(QObject *object, QStringList where, QString myOperator);
    void removeAll(QObject *object);
};
