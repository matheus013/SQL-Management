#include "users.h"

Users::Users(){
    setObjectName("Users");
}

Users::Users(QString username, QString password, QString name, int level){
    setObjectName("Users");
    set_id(0);
    set_username(username);
    set_password(password);
    set_name(name);
    set_level(level);
}
