#include <QGuiApplication>
#include <QDebug>
#include "myclass.h"
#include "tablemanagement.h"
#include "daobject.h"
#include "users.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc,argv);
    TableManagement *table =
            new TableManagement(new Users("lonesome","matheus23","Matheus Inácio",10));
    qDebug() << table->buildCreateTable();
    qDebug() << table->buildDeleteAll();
    qDebug() << table->buildDetele();
    qDebug() << table->buildInsert();
    qDebug() << table->buildUpdate();
    return app.exec();
}
