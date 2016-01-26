#include <QGuiApplication>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include "myclass.h"
#include "tablemanagement.h"
#include "daobject.h"
#include "users.h"

int main(int argc, char *argv[]){
    //    QGuiApplication app(argc,argv);
    //    DAObject dao;
    //    dao.insert(new Users("lonesome","123456","Matheus",10));
    //    return app.exec();
    DAObject dao;
    dao.removeAll(new MyClass(0,"andressa"));
}
