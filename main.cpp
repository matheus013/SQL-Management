#include <QCoreApplication>
#include <QDebug>
#include "myclass.h"
#include "utilsql.h"
#include "daogeneric.h"

int main(){
    MyClass *my = new MyClass();
    my->set_age(20);
    my->set_name("Matheus");
//    my->set_id(1);
    // INSERT INTO table_name (var_name,..,var_name) VALUES(var_value,...,var_value)
    DAOGeneric *dao = new DAOGeneric();
    dao->insert(my);
}
