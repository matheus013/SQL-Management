#include <QGuiApplication>
#include "myclass.h"
#include "tablemanagement.h"
#include "daobject.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc,argv);
    MyClass *my = new MyClass("admin",0);
    DAObject *dao = new DAObject();
    dao->insert(my);

    return app.exec();
}
