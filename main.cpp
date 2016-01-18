#include <QCoreApplication>
#include <QDebug>
#include "myclass.h"
#include "utilsql.h"

int main(){
    MyClass *my = new MyClass();
    my->set_age(20);
    my->set_name("Matheus");
    my->setProperty("sexo","masculino");
    qDebug() << my->property("sexo");
    // INSERT INTO table_name (var_name,..,var_name) VALUES(var_value,...,var_value)
    qDebug() << UtilSQL::buildInsert(my, "person");

}