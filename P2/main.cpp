#include "main.h"


// create a value
valueInfo* stringValue(string *s){
    valueInfo *tmp = new valueInfo();
    tmp->valueType = stringType;
    tmp->stringval = s;
    return tmp;
}

valueInfo* intValue(int i){
    valueInfo *tmp = new valueInfo();
    tmp->valueType = intType;
    tmp->intval = i;
    return tmp;
}

valueInfo* boolValue(bool b){
    valueInfo *tmp = new valueInfo();
    tmp->valueType = boolType;
    tmp->boolval = b;
    return tmp;
}

valueInfo* floatValue(float f){
    valueInfo *tmp = new valueInfo();
    tmp->valueType = floatType;
    tmp->floatval = f;
    return tmp;
}


SymbolTable::SymbolTable(){
    ids.clear();
    idMap.clear();
}

// find id is exist or not, if exist return it 
idInfo* SymbolTable::lookup(string s ){
    if(idMap.find(s)!=idMap.end()){
        return idMap[s];
    }
    return NULL;
}

// declare an normal id which is int or string or float or boolean
int SymbolTable::insert(string id,int idType,valueInfo* valueInfo){
    // already have same name
    if(idMap.find(id)!=idMap.end()){
        return -1;
    }
    idInfo *buf = new idInfo;
    buf->idType = idType;
    buf->id = id;
    buf->value = valueInfo;
    buf->hasInit = true;
    idMap[id] = buf;
    return 1;
}

// declare an normal id which is int or string or float or boolean
// but not init
int SymbolTable::insert(string id,int idType){
    // already have same name
    if(idMap.find(id)!=idMap.end()){
        return -1;
    }
    idInfo *buf = new idInfo;
    buf->idType = idType;
    buf->id = id;
    buf->value = NULL;
    buf->hasInit = false;
    idMap[id] = buf;
    return 1;
}


// here to insert an array variable
int SymbolTable::insert(string id, int idType, int arrayValueType, int arraySize){
    // already have same name
    if(idMap.find(id)!=idMap.end()){
        return -1;
    }

    idInfo *buf = new idInfo;
    buf->idType = idType;
    buf->id = id;
    buf->value = NULL;
    buf->hasInit = false;
    buf->arrayValueType = arrayValueType;
    buf->arraySize = arraySize;
    idMap[id] = buf;
    return 1;


}

// init symboltable vector
SymbolTableVector::SymbolTableVector(){
    vec.push_back(SymbolTable());
}


void SymbolTableVector::push(){
    vec.push_back(SymbolTable());
    ++top;
}


// search all scope for id
idInfo* SymbolTableVector::lookup(string id){
    for (int i = top; i >= 0; --i)
    {
        idInfo *buf = vec[i].lookup(id);
        if (buf!=NULL){
            return buf;
        }
    }
    return NULL;
}