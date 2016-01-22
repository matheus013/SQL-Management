#pragma once

#include <QObject>
#include "QQmlHelpers"

class TableManagement : public QObject{
    Q_OBJECT
protected:
    QObject * m_object;
    QString m_nameTable;
    QString readType(const QVariant variant, int length = 255);
public:
    TableManagement();
    TableManagement(QObject * object, QString nameTable = "");
    QString buildInsert(QString identifier = "id");
    QString buildUpdate(QString where = "id");
    QString buildDetele(QString where = "id");
    QString buildDetele(QStringList where , QString myOperator);
    QString buildDeleteAll();
    QString buildSelect();
    QString buildCreateTable();


    QString nameTable() const;
    void setNameTable(const QString &nameTable);
    QObject *object() const;
    void setObject(QObject *object);
};

