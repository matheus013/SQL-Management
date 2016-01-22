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
    QString textQuery = sql.buildCreateTable();

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";

    textQuery = sql.buildInsert();

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::update(QObject *object,QString where){
    TableManagement sql(object, object->objectName());
    QSqlQuery query;
    QString textQuery = sql.buildUpdate(where);

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::remove(QObject *object, QString where){
    TableManagement sql(object, object->objectName());
    QSqlQuery query;
    QString textQuery = sql.buildDetele(where);

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::remove(QObject *object, QStringList where, QString myOperator){
    TableManagement sql(object, object->objectName());
    QSqlQuery query;
    QString textQuery = sql.buildDetele(where, myOperator);

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::removeAll(QObject *object){
    TableManagement sql(object, object->objectName());
    QSqlQuery query;
    QString textQuery = sql.buildDeleteAll();

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}

void DAObject::customCommand(QString textQuery){
    QSqlQuery query;

    if(!query.exec(textQuery)) qDebug() << query.lastError().text();
    else qDebug() << "Successfully completed operation!";
}
