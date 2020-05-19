#include <vector>
#include <string>
#include <map>
#include <stdio.h>
#include <memory.h>
#include <limits.h>
// #include <string.h>
#include <stdlib.h>

using namespace std;



// define type by integer
enum type
{
    intType,
    floatType,
    boolType,
    charType,
    stringType,
};


// Value Class
struct valueInfo
{
    // valueInfo();
    // record the type of value
    int type = 0;
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


struct idInfo {
    // idInfo();
    string id;
    int type;
    valueInfo value;
};

// define symbol table class
class SymbolTable
{
public:
    SymbolTable();
    vector<string> ids;
    map<string, idInfo> idMap;
    int insert();
    void dump();
    int lookup(string id);
};