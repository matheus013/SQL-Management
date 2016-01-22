#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "daobject.h"
#include "connection.h"
#include "tablemanagement.h"

DAObject::DAObject(){
    connection = new Connection("mydata","admin","matheus23","localhost/phpmyadmin");
    connection->startConnection();
    if(connection->getDataConnection().isOpen()) qDebug() << "Successfully connected!";
}

DAObject::DAObject(QList<QObject *> list){
    DAObject();
    data = list;
}

QObject *DAObject::at(int id){return data.at(id);}

void DAObject::insert(QObject *object){
    TableManagement sql(object, object->objectName());
    QSqlQuery query;
    if(!query.exec(sql.buildCreateTable())) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
    query.prepare(sql.buildInsert());
    if(!query.exec()) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::update(QObject *object,QString where){
    TableManagement sql(object, object->objectName());
    QSqlQuery query;
    query.prepare(sql.buildUpdate(where));
    if(!query.exec()) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::remove(QObject *object, QString where){
    TableManagement sql(object, object->objectName());
    QSqlQuery query;
    query.prepare(sql.buildDetele(where));
    if(!query.exec()) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::remove(QObject *object, QStringList where, QString myOperator){
    TableManagement sql(object, object->objectName());
    QSqlQuery query;
    query.prepare(sql.buildDetele(where, myOperator));
    if(!query.exec()) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::removeAll(QObject *object){
    TableManagement sql(object, object->objectName());
    QSqlQuery query;
    query.prepare(sql.buildDeleteAll());
    if(!query.exec()) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::customCommand(QString strQuery){
    QSqlQuery query;
    query.prepare(strQuery);
    if(!query.exec()) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}
