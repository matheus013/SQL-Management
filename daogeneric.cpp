#include "daogeneric.h"
#include "connection.h"
#include "utilsql.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

DAOGeneric::DAOGeneric(){
    connection = new Connection("mydata","admin","matheus23");
}

DAOGeneric::DAOGeneric(QList<QObject *> list){
    data = list;
    connection = new Connection("mydata","admin","matheus23");
}

QObject *DAOGeneric::at(int id){
    return data.at(id);
}

void DAOGeneric::insert(QObject *object){
    UtilSQL sql(object, object->objectName());
    if(connection->startConnection()){
        QSqlQuery query;
        query.prepare(sql.buildInsert());
        qDebug() << query.isValid();
        if(!query.exec()) qDebug() << query.lastError();
        else qDebug() << "Successfully completed operation!";
    }
}

void DAOGeneric::update(QObject *object,QString where){
    UtilSQL sql(object, object->objectName());
    if(connection->startConnection()){
        QSqlQuery query;
        query.prepare(sql.buildUpdate(where));
        if(!query.exec()) qDebug() << query.lastError();
        else qDebug() << "Successfully completed operation!";
    }
}

void DAOGeneric::remove(QObject *object, QString where){
    UtilSQL sql(object, object->objectName());
    if(connection->startConnection()){
        QSqlQuery query;
        query.prepare(sql.buildDetele(where));
        if(!query.exec()) qDebug() << query.lastError();
        else qDebug() << "Successfully completed operation!";
    }
}

void DAOGeneric::remove(QObject *object, QStringList where, QString myOperator){
    UtilSQL sql(object, object->objectName());
    if(connection->startConnection()){
        QSqlQuery query;
        query.prepare(sql.buildDetele(where, myOperator));
        if(!query.exec()) qDebug() << query.lastError();
        else qDebug() << "Successfully completed operation!";
    }
}

void DAOGeneric::removeAll(QObject *object){
    UtilSQL sql(object, object->objectName());
    if(connection->startConnection()){
        QSqlQuery query;
        query.prepare(sql.buildDeleteAll());
        if(!query.exec()) qDebug() << query.lastError();
        else qDebug() << "Successfully completed operation!";
    }
}
