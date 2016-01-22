#pragma once

#include <QObject>
#include "QQmlHelpers"

class TableManagement : public QObject{
    Q_OBJECT
protected:
    QObject * m_object;
    QString m_nameTable;
public:
    TableManagement();
    TableManagement(QObject * object, QString nameTable = "");
    QString buildInsert(QString identifier = "id");
    QString buildUpdate(QString where);
    QString buildDetele(QString where);
    QString buildDetele(QStringList where, QString myOperator);
    QString buildDeleteAll();
    QString buildSelect();
    QString buildCreateTable();
    QString readType(const QVariant variant, int length = 255);


    QString nameTable() const;
    void setNameTable(const QString &nameTable);
    QObject *object() const;
    void setObject(QObject *object);
};

