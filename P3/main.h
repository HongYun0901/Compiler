#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <memory.h>
#include <limits.h>
// #include <string.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <utility>
#include <fstream>

using namespace std;
extern ofstream jbfile;
// define type by integer
enum valueType
{
    intType,
    floatType,
    boolType,
    charType,
    stringType,
    valueTypeError,
    unknownType,
};

// Value struct
struct valueInfo
{
    // record the type of value
    int valueType = valueTypeError;
    int intval = 0;
    float floatval = 0;
    bool boolval = false;
    char charval = '\0';
    string *stringval = new string();
};

// function declare
valueInfo *stringValue(string *s);
valueInfo *intValue(int i);
valueInfo *boolValue(bool b);
valueInfo *floatValue(float f);
valueInfo *charValue(char c);


// should record id is array or function or const or variable
enum IDType
{
    arrayType,
    functionType,
    constType,
    variableType,
    idTypeError,
    objectType,
};

string idType2Str(int);
string valueType2Str(int);

// id struct
struct idInfo
{
    string id = "";
    valueInfo *value = NULL;
    int idType = idTypeError;
    // if id is an array
    vector<valueInfo *> arrayValue;
    int arrayValueType = unknownType;
    int arraySize = 0;
    // if id is an function
    int returnType = unknownType;
    // when declare function
    // record the id and its type
    map<string,idInfo*> argumentsInfo;
    // record sequence
    vector<pair<string, int> *> argumentsInfoSeq;
    map<string, idInfo *> insideIdMap;
    // vector<valueInfo*>
    // only if idtype is variable need check
    bool hasInit = false;
    int stackID = -1;
};

// define symbol table class
class SymbolTable
{
public:
    SymbolTable();
    // vector<string> ids;
    map<string, idInfo *> idMap;

    

    idInfo *lookup(string id);
    // insert for normal value(string float boolean int) and init it
    int insert(string id, int idType, valueInfo *valueInfo);
    // insert an id but dont have value to init it
    int insert(string id, int idType, int valueType);
    // inset an id array type
    int insert(string id, int idType, int arrayValueType, int arraySize);
    // insert an function variable
    int insert(string id, int idType);
};

class SymbolTableVector
{
public:
    SymbolTableVector();
    // all symbol table store in here
    vector<SymbolTable> vec;
    map<string, SymbolTable> functionSymbolTables;
    idInfo *lookup(string id);
    void push();
    void push(SymbolTable);
    int pop();
    void dump();
    int top = 0;
};

void jbGlobalVar(string id);
void jbGlobalVar(string id, int);
void jbPushInt(int);
void jbStore(int index);
void jbOperation(char op);
void jbLoad(int index);
void jbLogicalOperation(int op);


enum LogicalOperator
{
    IFLT,
    IFLE,
    IFEQ,
    IFNE,
    IFGT,
    IFGE,
};