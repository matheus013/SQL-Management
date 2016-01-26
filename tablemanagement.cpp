#include <QMetaObject>
#include <QMetaProperty>
#include <QDebug>
#include <QStringList>
#include "tablemanagement.h"

QString TableManagement::nameTable() const {return m_nameTable;}
void TableManagement::setNameTable(const QString &nameTable) {m_nameTable = nameTable;}
QObject *TableManagement::object() const{return m_object;}
void TableManagement::setObject(QObject *object){m_object = object;}

TableManagement::TableManagement(){}

TableManagement::TableManagement(QObject *object, QString nameTable){
    if(nameTable == "") setNameTable(object->objectName());
    else setNameTable(nameTable);
    setObject(object);
}

QString TableManagement::buildInsert(QString identifier){
    QString tag = "INSERT INTO " + nameTable() + " (";
    const QMetaObject *metaObject = object()->metaObject();

    for (int i = 1; i < metaObject->propertyCount(); ++i) {

        QString nameProperty = QString::fromUtf8(metaObject->property(i).name());

        if(nameProperty != identifier){
            tag += nameProperty;
            if(i < metaObject->propertyCount() - 1) tag += ", ";
            else tag += ')';
        }
    }
    tag += " VALUES (";
    for (int i = 1; i < metaObject->propertyCount(); ++i) {

        QString nameProperty = QString::fromUtf8(metaObject->property(i).name());

        if(nameProperty != identifier){
            tag += '\'' + object()->property(nameProperty.toLatin1().constData()).toString() + '\'';
            if(i != metaObject->propertyCount() - 1) tag += ", ";
            else tag += ')';
        }
    }
    qDebug() << tag;
    return tag;
}

QString TableManagement::buildUpdate(QString where){
    QString tag = "UPDATE " + nameTable() + " SET ";
    const QMetaObject *metaObject = object()->metaObject();
    for (int i = 1; i < metaObject->propertyCount(); ++i) {

        QString nameProperty = QString::fromUtf8(metaObject->property(i).name());

        if(nameProperty != where){
            tag += nameProperty + "='" +
                    object()->property(nameProperty.toLatin1().constData()).toString() + '\'';
            if(i != metaObject->propertyCount() - 2) tag += ", ";
        }
    }
    tag += " WHERE " + where + "='" +
            object()->property(where.toLocal8Bit().data()).toString() + '\'';
    return tag;
}

QString TableManagement::buildDetele(QString where){
    return "DELETE FROM " + nameTable() + " WHERE " + where +
            "='" + object()->property(where.toLatin1().constData()).toString() + '\'';
}

QString TableManagement::buildDetele(QStringList where, QString myOperator){
    QString tag = "DELETE FROM " + nameTable() + " WHERE ";
    for(int i = 0;i < where.length(); ++i){
        tag += where.at(i) +"='"+
                object()->property(where.at(i).toLatin1().constData()).toString() + '\'';
        if(i < where.length() - 1) tag += ' ' + myOperator + ' ';
    }
    return tag;
}

QString TableManagement::buildDeleteAll(){
    return "DELETE FROM " + nameTable();
}

QString TableManagement::buildCreateTable(){
    QString tag = "CREATE TABLE IF NOT EXISTS " + nameTable() + " (";
    const QMetaObject *metaObject = object()->metaObject();
    for (int i = 1; i < metaObject->propertyCount(); ++i) {

        QString propertyName = QString::fromUtf8(metaObject->property(i).name());

        tag += propertyName + ' ' +
                readType(object()->property(propertyName.toLatin1().constData()));
        if(i != metaObject->propertyCount() - 1) tag += ", ";
        else tag += ')';
    }
    return tag;
}

QString TableManagement::readType(const QVariant variant,int length){
    QString tagType;
    tagType =  QString(variant.typeName()) + '(' + QString::number(length) + ')';
    tagType.replace("QString","varchar",Qt::CaseInsensitive);
    return tagType;
}
