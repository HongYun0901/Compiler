#include "main.h"


// create a value
valueInfo* stringValue(string *s){
    valueInfo *tmp = new valueInfo();
    tmp->type = stringType;
    tmp->stringval = s;
    return tmp;
}

valueInfo* intValue(int i){
    valueInfo *tmp = new valueInfo();
    tmp->type = intType;
    tmp->intval = i;
    return tmp;
}

valueInfo* boolValue(bool b){
    valueInfo *tmp = new valueInfo();
    tmp->type = boolType;
    tmp->boolval = b;
    return tmp;
}

valueInfo* floatValue(float f){
    valueInfo *tmp = new valueInfo();
    tmp->type = floatType;
    tmp->floatval = f;
    return tmp;
}