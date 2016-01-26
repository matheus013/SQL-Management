#include "myclass.h"

MyClass::MyClass(){
    setObjectName("test");
}

MyClass::MyClass(int id, QString login){
    setObjectName("x_user");
    set_id(id);
    set_login(login);
}
