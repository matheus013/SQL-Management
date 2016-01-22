#include "myclass.h"

MyClass::MyClass(){
    setObjectName("test");
}

MyClass::MyClass(QString name, int age){
    setObjectName("test");
    set_name(name);
    set_age(age);
}
