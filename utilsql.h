#ifndef UTILSQL_H
#define UTILSQL_H

#include <QObject>

class UtilSQL : public QObject{
    Q_OBJECT
public:
    UtilSQL();
    static QString buildInsert(QObject* object,QString nameTable);

};

#endif // UTILSQL_H
