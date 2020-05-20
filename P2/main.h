#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <memory.h>
#include <limits.h>
// #include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;



// define type by integer
enum valueType
{
    intType,
    floatType,
    boolType,
    charType,
    stringType,
    valueTypeError,
};


// Value Class
struct valueInfo
{
    // record the type of value
    int valueType = valueTypeError;
    int intval = 0;
    float floatval = 0;
    bool boolval = false;
    string *stringval = new string();
};

// function declare 
valueInfo *stringValue(string *s);
valueInfo *intValue(int i);
valueInfo *boolValue(bool b);
valueInfo *floatValue(float f);


// should record id is array or function or const or variable
enum IDType
{
    arrayType,
    functionType,
    constType,
    variableType,
    idTypeError,
};


struct idInfo {
    string id = "";
    valueInfo *value = NULL;
    int idType = idTypeError;
    // if id is an array
    vector<valueInfo *> arrayValue;
    int arrayValueType = valueTypeError;
    int arraySize = 0;
    // only if idtype is variable need check
    bool hasInit = false;
};

// define symbol table class
class SymbolTable
{
public:
    SymbolTable();
    vector<string> ids;
    map<string, idInfo*> idMap;
    int insert();
    void dump();
    idInfo* lookup(string id);
    // insert for normal value
    int insert(string id, int idType, valueInfo* valueInfo);
    int insert(string id, int idType);
    int insert(string id, int idType, int arrayValueType,int arraySize);

};

class SymbolTableVector{
    public:
        SymbolTableVector();
        // all symbol table store in here
        vector<SymbolTable> vec;
        idInfo* lookup(string id);
        void push();
        int top = 0;
        
};