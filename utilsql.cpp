#include "utilsql.h"
#include <QMetaObject>
#include <QMetaProperty>
#include <QDebug>
#include <QStringList>

QString UtilSQL::nameTable() const {return m_nameTable;}
void UtilSQL::setNameTable(const QString &nameTable) {m_nameTable = nameTable;}
QObject *UtilSQL::object() const{return m_object;}
void UtilSQL::setObject(QObject *object){m_object = object;}

UtilSQL::UtilSQL(){}

UtilSQL::UtilSQL(QObject *object, QString nameTable){
    setObject(object);
    setNameTable(nameTable);
}

QString UtilSQL::buildInsert(){
    QString tagSQLInsert = "INSERT INTO " + nameTable() + " (";
    const QMetaObject *metaObject = object()->metaObject();
    for (int i = 1; i < metaObject->propertyCount(); ++i) {
        tagSQLInsert += QString::fromUtf8(metaObject->property(i).name());
        if(i != metaObject->propertyCount() - 1) tagSQLInsert += ", ";
        else tagSQLInsert += ')';
    }
    tagSQLInsert += " VALUES (";
    for (int i = 1; i < metaObject->propertyCount(); ++i) {
        tagSQLInsert += '\'' +
                object()->property(metaObject->property(i).name()).toString() + '\'';
        if(i != metaObject->propertyCount() - 1) tagSQLInsert += ", ";
        else tagSQLInsert += ')';
    }
    qDebug() << tagSQLInsert;
    return tagSQLInsert;
}

QString UtilSQL::buildUpdate(QString where){
    QString tagSQLUpdate = "UPDATE " + nameTable() + " SET ";
    const QMetaObject *metaObject = object()->metaObject();
    for (int i = 1; i < metaObject->propertyCount(); ++i) {
        if(QString::fromUtf8(metaObject->property(i).name()) != where){
            tagSQLUpdate += QString::fromUtf8(metaObject->property(i).name()) + "='" +
                    object()->property(metaObject->property(i).name()).toString() + '\'';
            if(i != metaObject->propertyCount() - 2) tagSQLUpdate += ", ";
        }
    }
    tagSQLUpdate += " WHERE " + where + "='" +
            object()->property(where.toLocal8Bit().data()).toString() + '\'';
    return tagSQLUpdate;
}

QString UtilSQL::buildDetele(QString where){
    return "DELETE FROM " + nameTable() + " WHERE " + where +
            "='" + object()->property(where.toLocal8Bit().data()).toString() + '\'';
}

QString UtilSQL::buildDetele(QStringList where, QString myOperator){
    QString tagSQLDelete = "DELETE FROM " + nameTable() + " WHERE ";

    for(int i = 0;i < where.length(); ++i){
        tagSQLDelete += where.at(i) +"='"+
                object()->property(where.at(i).toLocal8Bit().data()).toString() + '\'';
       if(i < where.length() - 1) tagSQLDelete += ' ' + myOperator + ' ';
    }

    return tagSQLDelete;
}

QString UtilSQL::buildDeleteAll(){
    return "DELETE * FROM " + nameTable();
}
