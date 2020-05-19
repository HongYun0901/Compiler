#include <vector>
#include <string>
#include <map>

using namespace std;
enum type
{
    intType,
    realType,
    boolType,
    charType,
    stringType,
    arrType,
};

class SymbolTable(){
        public:
            SymbolTable();
            vector<string> symbols;
            map<string, idinfo> idMap;
            int insert();
            void dump();
            int lookup(string id);
            
};