#include "utilsql.h"
#include <QMetaObject>
#include <QMetaProperty>

UtilSQL::UtilSQL(){}

QString UtilSQL::buildInsert(QObject *object, QString nameTable){
    QString tagSQLInsert = "INSERT INTO " + nameTable + " (";
    const QMetaObject *metaObject = object->metaObject();
    for (int i = 1; i < metaObject->propertyCount(); ++i) {
        tagSQLInsert += QString::fromUtf8(metaObject->property(i).name());
        if(i != metaObject->propertyCount() - 1) tagSQLInsert += ", ";
        else tagSQLInsert += ')';
    }
    tagSQLInsert += " VALUES (";
    for (int i = 1; i < metaObject->propertyCount(); ++i) {
        tagSQLInsert += '\'' + object->property(metaObject->property(i).name()).toString() + '\'';
        if(i != metaObject->propertyCount() - 1) tagSQLInsert += ", ";
        else tagSQLInsert += ')';
    }
    return tagSQLInsert;
}
