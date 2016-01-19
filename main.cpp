#include <QCoreApplication>
#include <QDebug>
#include "myclass.h"
#include "utilsql.h"

int main(){
    MyClass *my = new MyClass();
    my->set_age(20);
    my->set_name("Matheus");
    my->setProperty("sexo","masculino");
    // INSERT INTO table_name (var_name,..,var_name) VALUES(var_value,...,var_value)
    UtilSQL sql(my,"person");
    //Build Insert
    qDebug() << sql.buildInsert();
    //Build Update
    qDebug() << sql.buildUpdate("id");
    //Build Delete
    qDebug() << sql.buildDetele("id");
    //Build Delete condition
    qDebug() << sql.buildDetele({"id","name","age"},"AND");
    //Build Delete all from table
    qDebug() << sql.buildDeleteAll();

}
