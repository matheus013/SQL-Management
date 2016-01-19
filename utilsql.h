#pragma once

#include <QObject>
#include "QQmlHelpers"

class UtilSQL : public QObject{
    Q_OBJECT
protected:
    QObject * m_object;
    QString m_nameTable;
public:
    UtilSQL();
    UtilSQL(QObject * object, QString nameTable);
    QString buildInsert();
    QString buildUpdate(QString where);
    QString buildDetele(QString where);
    QString buildDetele(QStringList where, QString myOperator);
    QString buildDeleteAll();


    QString nameTable() const;
    void setNameTable(const QString &nameTable);
    QObject *object() const;
    void setObject(QObject *object);
};

