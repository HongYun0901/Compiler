#include "main.h"

// create a value
valueInfo *stringValue(string *s)
{
    valueInfo *tmp = new valueInfo();
    tmp->valueType = stringType;
    tmp->stringval = s;
    return tmp;
}

valueInfo *intValue(int i)
{
    valueInfo *tmp = new valueInfo();
    tmp->valueType = intType;
    tmp->intval = i;
    return tmp;
}

valueInfo *boolValue(bool b)
{
    valueInfo *tmp = new valueInfo();
    tmp->valueType = boolType;
    tmp->boolval = b;
    return tmp;
}

valueInfo *floatValue(float f)
{
    valueInfo *tmp = new valueInfo();
    tmp->valueType = floatType;
    tmp->floatval = f;
    return tmp;
}

valueInfo *charValue(char c)
{
    valueInfo *tmp = new valueInfo();
    tmp->valueType = charType;
    tmp->charval = c;
    return tmp;
}

SymbolTable::SymbolTable()
{
    idMap.clear();
}

// find id is exist or not, if exist return it
idInfo *SymbolTable::lookup(string s)
{
    if (idMap.find(s) != idMap.end())
    {
        return idMap[s];
    }
    return NULL;
}

// declare an normal id which is int or string or float or boolean
int SymbolTable::insert(string id, int idType, valueInfo *valueInfo)
{
    // already have same name
    if (idMap.find(id) != idMap.end())
    {
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
int SymbolTable::insert(string id, int idType, int valueType)
{
    // already have same name
    if (idMap.find(id) != idMap.end())
    {
        return -1;
    }
    idInfo *buf = new idInfo;
    buf->idType = idType;
    buf->id = id;
    buf->value = new valueInfo();
    buf->value->valueType = valueType;
    buf->hasInit = false;
    idMap[id] = buf;
    return 1;
}

// here to insert an array variable
int SymbolTable::insert(string id, int idType, int arrayValueType, int arraySize)
{
    // already have same name
    if (idMap.find(id) != idMap.end())
    {
        return -1;
    }
    idInfo *buf = new idInfo;
    buf->idType = idType;
    buf->id = id;
    buf->value = NULL;
    buf->hasInit = false;
    buf->arrayValueType = arrayValueType;
    buf->arraySize = arraySize;
    for (int i = 0; i < arraySize; ++i)
    {
        buf->arrayValue.push_back(new valueInfo());
    }
    idMap[id] = buf;
    return 1;
}

// here to insert an function/object variable
int SymbolTable::insert(string id, int idType)
{
    // already have same name
    if (idMap.find(id) != idMap.end())
    {
        return -1;
    }
    idInfo *buf = new idInfo;
    buf->idType = idType;
    buf->id = id;
    buf->value = NULL;
    buf->hasInit = false;
    //buf->returnType = intType;
    idMap[id] = buf;
    return 1;
}

// init symboltable vector
SymbolTableVector::SymbolTableVector()
{
    vec.push_back(SymbolTable());
}

void SymbolTableVector::push()
{
    vec.push_back(SymbolTable());
    ++top;
}
void SymbolTableVector::push(SymbolTable s)
{
    vec.push_back(s);
    ++top;
}






int SymbolTableVector::pop()
{
    if (vec.empty())
        return -1;
    vec.pop_back();
    --top;
    return 1;
}

// search all scope for id
idInfo *SymbolTableVector::lookup(string id)
{
    for (int i = top; i >= 0; --i)
    {
        idInfo *buf = vec[i].lookup(id);
        if (buf != NULL)
        {
            return buf;
        }
    }
    return NULL;
}

void SymbolTableVector::dump()
{
    cout << "--------------dump--------------" << endl;
    int count = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        if (!vec[i].idMap.empty())
        {
            // cout << "----------index:" << ++count << "--i:"<< i << "-----" << endl;
            cout << "----------index:" << ++count << "-----------" << endl;
            map<string, idInfo *>::iterator it;
            for (it = vec[i].idMap.begin(); it != vec[i].idMap.end(); it++)
            {
                cout << "id: " << it->first << "\ttype: " << idType2Str(it->second->idType);
                if(it->second->idType ==variableType){
                    cout << "\t type:" << valueType2Str(it->second->value->valueType);
                }
                cout << endl;
            }
            cout << "----------------------------" << endl;
        }
    }
    cout << "--------------------------------" << endl;
}

string idType2Str(int idType)
{
    switch (idType)
    {
    case 0:
        return "array";
    case 1:
        return "function";
    case 2:
        return "const";
    case 3:
        return "variable";
    case 4:
        return "error";
    case 5:
        return "object";
    default:
        return ("cant find idtype");
    }
}

string valueType2Str(int valueType)
{
    switch (valueType)
    {
    case 0:
        return "int";
    case 1:
        return "float";
    case 2:
    // original is boolean
        return "int";
    case 3:
        return "char";
    case 4:
        return "java.lang.String";
    case 5:
        return "error";
    case 6:
        return "unknown";
    default:
        return ("cant find valuetype");
    }
}



void jbGlobalVar(string id){
    jbfile << "\tfield static int " << id <<  endl;
}

void jbGlobalVar(string id ,int i){
    jbfile << "\tfield static int " << id << " = " << i <<  endl;

}



void jbPushInt(int i){
    jbfile << "\t\tsipush " << i << endl;
}


void jbStore(int index){
    jbfile << "\t\tistore " << index << endl;
}


void jbOperation(char op){

    switch(op){
        case 'm': jbfile << "\t\tineg" << endl; break;
        case '*': jbfile << "\t\timul" << endl; break;
        case '/': jbfile << "\t\tidiv" << endl; break;
        case '+': jbfile << "\t\tiadd" << endl; break;
        case '-': jbfile << "\t\tisub" << endl; break;
        case '!': jbfile << "\t\tldc 1" << endl << "\t\tixor" << endl; break;
        case '&': jbfile << "\t\tiand" << endl; break;
        case '|': jbfile << "\t\tior" << endl; break;

    }

}


void jbLogicalOperation(int op){

    jbfile << "\t\tisub" << endl;
    switch (op)
    {
    case IFLT:
        jbfile << "\t\tiflt" << endl;
        break;
    case IFLE:
        jbfile << "\t\tifle" << endl;
        break;
    case IFEQ:
        jbfile << "\t\tifeq" << endl;
        break;
    case IFGT:
        jbfile << "\t\tifgt" << endl;
        break;
    case IFGE:
        jbfile << "\t\tifge" << endl;
        break;
    case IFNE:
        jbfile << "\t\tifne" << endl;
        break;
    }

}


void jbLoad(int index){
    jbfile << "\t\tiload " << index << endl;
}

