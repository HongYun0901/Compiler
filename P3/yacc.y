%{
#include <iostream>
#include "main.h"
#include "lex.yy.cpp"
#define Trace(t)        { /*printf("%d  ",linenum);printf(t);printf("\n"); */}
// #define Error(t)    {printf(t);printf("\n");exit(-1);}
#define Warning(t)  {cout << "Warning at line: " << linenum << " :" <<  t << endl;} 
#define GLOBAL 1

void yyerror(string s){
   cout << "error at line: " << linenum  << " (" << s  << ')' << endl;
  // exit(-1);
}
SymbolTableVector tables;

extern int linenum;

int methodNumCount = 0;
int labelCount = 0;




vector<vector<int>> ifLabelsVector;
bool elseifFlag = false;

bool valFlag = false;

vector<vector<int>> loopLabelsVector;
vector<vector<int>> forLabelsVector;
vector<idInfo*> forIdVector;


int varStackID = 0;
int tabCounts = 1;
ofstream jbfile;
string className = "";
bool returnFlag = false;
bool ifEndFlag = false;

%}

// show detail error message
%error-verbose
// declare my union
%union {
    float floatval;
    int intval;
    bool boolval;
    string* stringval;
    int valueType;
    valueInfo* value;
    char charval;
    // here is record for the function on called
    vector<valueInfo*>* valueInfoVec;
    vector<pair<string,int>*>* argumentsInfo;
    map<string, idInfo*>* idMap;
    pair<string,int>* argumentInfo;

}

/* tokens */
%token SEMICOLON
%token BOOLEAN
%token BREAK
%token CHAR
%token CASE
%token CLASS
%token CONTINUE
%token DEF
%token DO
%token ELSE
%token EXIT
%token FALSE
%token FLOAT
%token FOR
%token IF
%token INT
%token _NULL
%token OBJECT
%token PRINT
%token PRINTLN
%token READ
%token REPEAT
%token RETURN
%token STRING
%token TO
%token TRUE
%token TYPE
%token VAL
%token VAR
%token WHILE
%token ASSIGN


// lex.l will return value
%token <boolval> BOOL_VALUE

%token <intval> INT_VALUE 
%token <stringval> STRING_VALUE
%token <floatval> FLOAT_VALUE
%token <stringval> ID
%token <charval> CHAR_VALUE
// %type <value>    FUNCTION_RETURN

%type <value> VALUE EXPR FUNCTION_INVOCATION 
// define data type token and return value is enum type
%type <valueType> DATA_TYPE
%type <argumentsInfo> ARGS
%type <argumentInfo> ARG 
%type <valueType> FUNCTION_OPTIONAL
%type <valueInfoVec> COMMA_SEP_EXPR 
// %type <idMap>  FUNCTION_BLOCK

%type <boolval> BLOCK_OR_SIMPLE while_block_or_simplestmt for_block_or_simplestmt

%type <idMap> BLOCK 






%left OR_OP
%left AND_OP
%left NOT
%left LT LE EQ GT GE NE
%left '+' '-'
%left '*' '/' '%'

%nonassoc UMINUS

%start PROGRAM
%%
// Program 
PROGRAM : OBJECT_DECLARE PROGRAM
        | 
        

OBJECT_DECLARE : OBJECT ID {
            Trace("declare an id to objet type");
            tables.push();
            int result = tables.vec[tables.top].insert(*$2,objectType);
            if(result == -1){
                yyerror(*$2 + " already exists");
            }
            className = *$2;
            jbfile << "class " << *$2 << "{"  << endl; 
        
        } OBJ_BLOCK {
            Trace("OBJECT ID BLOCK");
            tables.dump();

            if(methodNumCount == 0){
                yyerror("object must contain one method");

            }
            methodNumCount = 0;
            if(tables.vec[tables.top].idMap.find("main") == tables.vec[tables.top].idMap.end() ){
                    yyerror("must declare main function");
            }
            else{
                idInfo *buf = tables.vec[tables.top].idMap["main"];
                if(buf->idType != functionType){
                    yyerror("must declare main function");
                }
            }
            // tables.dump();
            tables.pop();
            jbfile << "}" << endl;


        };



// arguments when declare
// u can also pass zero/one/more arguments in function
ARGS : {
           Trace("ARGS empty");
           vector<pair<string,int>*>* buf = new vector<pair<string,int>*>();
           buf->clear(); 
           $$ = buf;

       }
       | ARG ',' ARGS{
         Trace("ARG , ARGS");  
         $$ = $3;
        $$->push_back($1);

       }
       | ARG {
           Trace("ARG");
           vector<pair<string,int>*>* buf = new vector<pair<string,int>*>();
           $$ = buf;
           $$->push_back($1);
           
       }

// argument
ARG : ID ':' DATA_TYPE {
        Trace("ID : DataType");
        cout << "when arg table top is" << tables.top << endl;
        int result = tables.vec[tables.top].insert(*$1,variableType,$3);
        if(result == -1){
            yyerror("id has been used");
        }
        idInfo* id = tables.lookup(*$1);
        id->stackID = varStackID++;
        pair<string,int>* p = new pair<string,int>();
        p->first = *$1;
        p->second = $3;
        $$ = p;
    }




// methods
FUNCTION : DEF ID {
            Trace("create an function id");
            int result = tables.vec[tables.top].insert(*$2,functionType);
            if(result == -1){
                yyerror(*$2 + " already exists");
                *$2 = *$2 + "(error)";
                tables.vec[tables.top].insert(*$2,functionType);
            }
            cout << "method id is " << *$2 << endl;
            tables.push();
            returnFlag = false;
            varStackID = 0;

        } '(' ARGS {
            idInfo *id = tables.lookup(*$2);
            id->argumentsInfoSeq = *$5;
            id->argumentsInfo = tables.vec[tables.top].idMap;
        } ')' FUNCTION_OPTIONAL {
            idInfo *id = tables.lookup(*$2);
            id->returnType = $8;

            if(*$2 == "main"){
                jbfile << "\tmethod public static void main(java.lang.String[])" << endl;
                jbfile << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl;
                jbfile << "\t{" << endl;
            }
            else{
                if(id->returnType == unknownType){
                    jbfile << "\tmethod public static void " << *$2;
                }
                else{
                    jbfile << "\tmethod public static " << valueType2Str($8) << " " <<  *$2;
                }
                    if($5->size() == 0){
                        jbfile << "()" << endl;
                    }
                    else{
                        jbfile << "(";
                        for(int i=$5->size()-1;i>=0;--i){
                            if(i == $5->size()-1){
                                jbfile << valueType2Str((*$5)[i]->second);
                            }
                            else{
                                jbfile << "," <<  valueType2Str((*$5)[i]->second);
                            }
                        }
                        jbfile << ")" << endl;

                    }
                    jbfile << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl; 
                    jbfile << "\t{" << endl;
            }

            

        } BLOCK {
            Trace("declare method end");
            idInfo *id = tables.lookup(*$2);
            for(int i = 0; i < $5->size(); ++i){
                cout << "id : " << (*$5)[i]->first << " type : " << valueType2Str((*$5)[i]->second) << endl;
            }

            tables.functionSymbolTables[*$2] = tables.vec[tables.top];
            tables.pop(); 
            methodNumCount ++ ;

            if($8 == unknownType && !returnFlag){
                jbfile << "\t\treturn" << endl;
            }
            jbfile << "\t}" << endl;
            
        }



// can specify return type or not
FUNCTION_OPTIONAL : {
                    $$ = unknownType;
                  }
                  | ':' DATA_TYPE {
                    $$ = $2;
                    Trace(": DataType");
                  }
                 ;

// function invocation
FUNCTION_INVOCATION : ID {
                        // tables.push(tables.functionSymbolTables[*$1]);
                    } '(' COMMA_SEP_EXPR ')' {
                        Trace("call function invocation");
                    
                        idInfo* id = tables.lookup(*$1);
                        //cout << "after lookup " <<  id->id << " address " << &id << " " << tables.top << endl;
                        if(id == NULL){
                            yyerror(*$1 + "doesn't exist");
                        }
                        if(id->idType != functionType){
                            yyerror(*$1 + "is not a function");
                        }
                        cout << "parameter nums : " << $4->size() << endl;
                        for(int i = 0; i < $4->size(); ++i){
                            cout << "type : " << valueType2Str((*$4)[i]->valueType) << endl;
                        }

                        // cout << $4->size() << " " << id->argumentsInfoSeq.size() << endl;
                        // check parameter is same as declared 
                        if($4->size() != id->argumentsInfo.size()){
                            yyerror("parameter nums error");
                        }
                        // check type
                        for(int i = 0; i < $4->size(); ++i){
                            if((*$4)[i]->valueType!= id->argumentsInfoSeq[i]->second){
                                yyerror("parameter type error");
                            }
                        }
                        $$ = new valueInfo();
                        $$->valueType = id->returnType;
                        jbfile << "\t\tinvokestatic int " << className << "." << *$1 << "(" ;

                        for(int i=$4->size()-1;i>=0;--i){
                            if(i == $4->size()-1){
                                jbfile << valueType2Str((*$4)[i]->valueType);
                            }
                            else{
                                jbfile << "," <<  valueType2Str((*$4)[i]->valueType);
                            }
                        }
                        jbfile << ")" << endl;
                        
                        
                    }

// comma-separated expressions
COMMA_SEP_EXPR : {
                    Trace("check arugment start");
                    vector<valueInfo*>* buf = new vector<valueInfo*>();
                    $$ = buf;
                }
               | EXPR ',' COMMA_SEP_EXPR {
                   Trace("checking argument...");
                   $3->push_back($1);
                   $$ = $3;
               }
               | EXPR {
                   Trace("check arugment start");
                    vector<valueInfo*>* buf = new vector<valueInfo*>();
                    buf->push_back($1);
                    $$ = buf;
               }
               ;

// define stmts
STMTS : STMT 
      | STMT STMTS 
      ;

// define stmt
STMT : BLOCK 
     | IF_STMT
     | LOOP_STMT 
     | SIMPLE_STMT
    ;


V_DECLARE : VAR_DECLARE 
           | VAL_DECLARE 
           


// define block but in this block cant declare methods
// example u cant define method in method
BLOCK : '{' {
        Trace("BLOCK START");
        tables.push();
      }  STMTS 
      '}' {
          Trace("BLOCK END");
            $$ =  new map<string,idInfo*>();
          *$$ = tables.vec[tables.top].idMap;
            // tables.dump();
          if(tables.pop() == -1){
              yyerror("symbol table error");
          }
      }

// object block can declare methods  and stmts inside
// example u can define a methods in object





OBJ_CONTENTS : FUNCTION OBJ_CONTENTS
             | V_DECLARE OBJ_CONTENTS
             | 


OBJ_BLOCK : '{' OBJ_CONTENTS  '}' 


// constant variables declarations
VAL_DECLARE : VAL ID ASSIGN EXPR{
                Trace("VAL ID ASSIGN EXPR");
                int result = tables.vec[tables.top].insert(*$2,constType,$4);
                if(result == -1){
                    yyerror("id has been used");
                }

                idInfo *id = tables.lookup(*$2);

                id->value = $4;

            }
            | VAL ID ':' DATA_TYPE ASSIGN EXPR {
                Trace("VAL ID : DATA_TYPE ASSIGN EXPR");
                if($4 != $6->valueType){
                    yyerror("data type and value type doesn't match");
                }
                int result = tables.vec[tables.top].insert(*$2,constType,$6);
                if(result == -1){
                    yyerror("id has been used");
                }

                idInfo *id = tables.lookup(*$2);
                id->value = $6;
            }

VAR_DECLARE : VAR ID ASSIGN EXPR {
                Trace("VAR ID ASSIGN EXPR");
                // declare var with value
                int result = tables.vec[tables.top].insert(*$2,variableType,$4);
                if(result == -1){
                    yyerror("id has been used");
                }
                idInfo* id = tables.lookup(*$2);
                

                if(tables.top == GLOBAL){
                    jbGlobalVar(*$2);
                    jbfile << "\t\tputstatic int " << className << "." << *$2 << endl;

                }
                else{
                    id->stackID = varStackID;
                    jbStore(varStackID++);
                }

            }
            | VAR ID ':' DATA_TYPE {
                Trace("VAR ID ':' DATA_TYPE");
                // declare var but only have type
                int result = tables.vec[tables.top].insert(*$2,variableType,$4);

                idInfo* id = tables.lookup(*$2);

                if(result == -1){
                    yyerror("id has been used");
                }


                if(tables.top == GLOBAL){
                    jbGlobalVar(*$2);
                }
                else{
                    jbPushInt(0);
                    id->stackID = varStackID;
                    jbStore(varStackID++);
                }



            }
            | VAR ID ':' DATA_TYPE ASSIGN EXPR{
                Trace("VAR ID : DATA_TYPE ASSIGN EXPR");
                if($6->valueType == unknownType){
                     Warning("unknownType!!!!");
                }
                else if($4 != $6->valueType){
                    yyerror("data type and value type doesn't match");
                }
                // declare var with sepcific data type and value
                int result = tables.vec[tables.top].insert(*$2,variableType,$6);
                if(result == -1){
                    yyerror("id has been used");
                }
                idInfo* id = tables.lookup(*$2);
            

                if(tables.top == GLOBAL){
                    jbGlobalVar(*$2);
                    jbfile << "\t\tputstatic int " << className << "." << *$2 << endl;

                }
                else{
                    id->stackID = varStackID;
                    jbStore(varStackID++);
                }
            }
            | VAR ID ':' DATA_TYPE '[' INT_VALUE ']' {
                Trace("VAR ID : DATA_TYPE [ INT_VALUE ]");
                int result = tables.vec[tables.top].insert(*$2,arrayType,$4,$6);
                if(result == -1){
                    yyerror("id has been used");
                }
            }
            | VAR ID {
                Trace("VAR ID");
                // declare unknownType var
                int result = tables.vec[tables.top].insert(*$2,variableType,unknownType);
                if(result == -1){
                    yyerror("id has been used");
                }
                idInfo* id = tables.lookup(*$2);
                if(tables.top == GLOBAL){
                    jbGlobalVar(*$2);
                }
                else{
                    jbPushInt(0);
                    id->stackID = varStackID;
                    jbStore(varStackID++);
                }
            }



// define simple stmt simple stmt include declare
SIMPLE_STMT : V_DECLARE
            | ID ASSIGN EXPR {
                Trace("ID ASSIGN EXPR");
                idInfo* buf = tables.lookup(*$1);
                if(buf == NULL){
                    yyerror(*$1 + " doesn't exist");
                }

                if(buf->idType != variableType){
                    yyerror(*$1 + " can not be assign");
                }
                if(buf->hasInit){
                    if($3->valueType == intType && buf->value->valueType == floatType){
                        *(buf->value) = *$3;
                    }
                    else if($3->valueType == floatType && buf->value->valueType == intType){
                        *(buf->value) = *$3;
                    }
                    else if($3->valueType == unknownType){
                        Warning("unknownType!!!");
                    }
                    else if(buf->value->valueType != $3->valueType){
                        yyerror(*$1 + " already assigen other data type");
                    }
                    *(buf->value) = *$3;
                }
                else{
                    buf->value = new valueInfo();
                    *(buf->value) = *$3;
                    buf->hasInit = true;
                }
                
                if(buf->stackID == -1){
                    jbfile << "\t\tputstatic int " << className << "." << *$1 << endl;
                }
                else{
                    jbfile << "\t\tistore " << buf->stackID << endl;
                }
                


            }
            | ID '[' EXPR ']' ASSIGN EXPR {
                Trace("ID '[' EXPR ']' ASSIGN EXPR");
                idInfo* buf = tables.lookup(*$1);
                if(buf == NULL){
                    yyerror("id does not exist");
                }
                if(buf->idType != arrayType){
                    yyerror(*$1 + " is not an array");
                }
                if($3->valueType == unknownType){
                    Warning("unknownType!!!!");
                }
                else if($3->valueType != intType){
                    yyerror("only can assess int index");
                }
                else if($3->intval >= buf->arraySize || $3->intval <0){
                    yyerror("access array out of range");
                }
                if(buf->arrayValueType != $6->valueType){
                    yyerror("assign different value type in array");
                }
                
            }
            | PRINT {
                jbfile << "\t\tgetstatic java.io.PrintStream java.lang.System.out" << endl;
            }  EXPR {
                jbfile << "\t\tinvokevirtual void java.io.PrintStream.print(" << valueType2Str($3->valueType) <<")" << endl;
            }
            | PRINTLN{
                jbfile << "\t\tgetstatic java.io.PrintStream java.lang.System.out" << endl;
            }  EXPR {
                jbfile << "\t\tinvokevirtual void java.io.PrintStream.println(" << valueType2Str($3->valueType) <<")" << endl;

            }
            | READ ID 
            | RETURN EXPR{
                returnFlag = true;
                jbfile << "\t\tireturn" << endl; 
            }
            | RETURN {
                returnFlag = true;
                jbfile << "\t\treturn" << endl;
                
            }
            
            

//  define expr
EXPR : '(' EXPR ')' {
        $$ = $2;
    }
    | ID {
        Trace("ID");
        idInfo* buf = tables.lookup(*$1);
        if( buf == NULL){
            yyerror("ID does not exist");
        }

        // if id is array 
        if(buf->idType == arrayType){
            yyerror(*$1 + " is array make grammar error");
        }

        // if id is function
        if(buf->idType == functionType){
            Trace("call function invocation");
            // check parameter is same as declared 
            if(0 != buf->argumentsInfo.size()){
                yyerror("parameter nums error");
            }
            else{
                // call function deal here
            }
            valueInfo* v = new valueInfo();
            // here need to push id's tow idmap into idmap
            $$ = v;

        }
        // check has init or not
        else if(!buf->hasInit){
            Warning(*$1 + " may  has not been init");
        }
        if(buf->value == NULL){
            $$ = new valueInfo();
        }
        else{
            $$ = buf->value;
            int val; 

            if(buf->idType == constType){
                if(buf->value->valueType){
                    val = buf->value->intval;
                    jbPushInt(val);
                }
                else if( buf->value->valueType == boolType){
                    val = buf->value->boolval ? 1 : 0;
                    jbPushInt(val);
                }
                else if(buf->value->valueType == stringType){
                    jbfile << "\t\tldc " << "\"" << buf->value->stringval << "\"" << endl;
                }
            }
            else{
                // is global
                if(buf->stackID == -1){
                    jbfile << "\t\tgetstatic int " << className << "." << *$1 << endl;
                }
                else{
                    jbLoad(buf->stackID);
                }

            }

            
            
        }
    }
    | '-' EXPR %prec UMINUS {
        Trace("- EXPR")
        valueInfo* buf = new valueInfo();
        if ($2->valueType == intType) {
            *buf = *$2;
            buf->intval = -1 * buf->intval;
        }
        else if($2->valueType== floatType){
            *buf = *$2;
            buf->floatval = -1 * buf->floatval;
        }
        else if($2->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("- EXPR type error");
        }
        $$ = buf;
        jbOperation('m');
    }
    | FUNCTION_INVOCATION
    | EXPR '+' EXPR{
        Trace("EXPR + EXPR");
        valueInfo* buf = new valueInfo();
        if($1->valueType==intType && $3->valueType==intType){
            buf->valueType = intType;
            buf->intval = ($1->intval + $3->intval);
        }
        else if($1->valueType==floatType && $3->valueType==intType){
            buf->valueType = floatType;
            //buf->floatval = ($1->floatval + (float)$3->intval);
        }
        else if($1->valueType==intType && $3->valueType==floatType){
            buf->valueType = floatType;
            //buf->floatval = ((float)$1->intval + $3->floatval);
        }
        else if($1->valueType==floatType && $3->valueType==floatType){
            buf->valueType = floatType;
            //buf->floatval = ($1->floatval + $3->floatval);
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR + EXPR TYPE ERROR");
        }
        $$ = buf;
        jbOperation('+');
        
    }
    | EXPR '-' EXPR{
        Trace("EXPR - EXPR");
        valueInfo* buf = new valueInfo();
        if($1->valueType==intType && $3->valueType==intType){
            buf->valueType = intType;
            buf->intval = ($1->intval - $3->intval);
        }
        else if($1->valueType==floatType && $3->valueType==intType){
            buf->valueType = floatType;
            buf->floatval = ($1->floatval - (float)$3->intval);
        }
        else if($1->valueType==intType && $3->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ((float)$1->intval - $3->floatval);
        }
        else if($1->valueType==floatType && $3->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ($1->floatval - $3->floatval);
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR - EXPR TYPE ERROR");
        }
        $$ = buf;
        jbOperation('-');


    }
    | EXPR '*' EXPR{
        Trace("EXPR * EXPR");
        valueInfo* buf = new valueInfo();
        if($1->valueType==intType && $3->valueType==intType){
            buf->valueType = intType;
            buf->intval = ($1->intval * $3->intval);
        }
        else if($1->valueType==floatType && $3->valueType==intType){
            buf->valueType = floatType;
            buf->floatval = ($1->floatval * (float)$3->intval);
        }
        else if($1->valueType==intType && $3->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ((float)$1->intval * $3->floatval);
        }
        else if($1->valueType==floatType && $3->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ($1->floatval * $3->floatval);
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR * EXPR TYPE ERROR");
        }
        $$ = buf;
        jbOperation('*');


    }
    | EXPR '/' EXPR{
        Trace("EXPR / EXPR");
        valueInfo* buf = new valueInfo();
        if($1->valueType==intType && $3->valueType==intType){
            buf->valueType = intType;
            buf->intval = ($1->intval / $3->intval);
        }
        else if($1->valueType==floatType && $3->valueType==intType){
            buf->valueType = floatType;
            buf->floatval = ($1->floatval / (float)$3->intval);
        }
        else if($1->valueType==intType && $3->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ((float)$1->intval / $3->floatval);
        }
        else if($1->valueType==floatType && $3->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ($1->floatval / $3->floatval);
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR / EXPR TYPE ERROR");
        }
        $$ = buf;
        jbOperation('/');

    }
    | EXPR '%' EXPR{
        Trace("EXPR / EXPR");
        valueInfo* buf = new valueInfo();
        if($1->valueType==intType && $3->valueType==intType){
            buf->valueType = intType;
            buf->intval = ($1->intval % $3->intval);
        }
        else if($1->valueType==floatType && $3->valueType==intType){
            buf->valueType = floatType;
            buf->floatval = fmod((double)$1->floatval,(double)$3->intval);
        }
        else if($1->valueType==intType && $3->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = fmod((double)$1->intval,(double)$3->floatval);
        }
        else if($1->valueType==floatType && $3->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = fmod((double)$1->floatval,(double)$3->floatval);
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR / EXPR TYPE ERROR");
        }
        $$ = buf;

    }
    | EXPR OR_OP EXPR {
        Trace("EXPR OR_OP EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if($1->valueType!=boolType || $3->valueType!=boolType){
            yyerror("EXPR OR_OP EXPR type must be bool");
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            buf->boolval = $1->boolval || $3->boolval;
        }
        $$ = buf;
        jbOperation('|');

    }
    | EXPR AND_OP EXPR {
        Trace("EXPR AND_OP EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if($1->valueType!=boolType || $3->valueType!=boolType){
            yyerror("EXPR OR_OP EXPR type must be bool");
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            buf->boolval = $1->boolval && $3->boolval;
        }
        $$ = buf;
        jbOperation('&');


    }
    | EXPR LT EXPR {
        Trace("EXPR LT EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if($1->valueType==intType && $3->valueType==intType){
            buf->boolval = ($1->intval < $3->intval);
        }
        else if($1->valueType==floatType && $3->valueType==intType){
            buf->boolval = ($1->floatval < (float)$3->intval);
        }
        else if($1->valueType==intType && $3->valueType==floatType){
            buf->boolval = ((float)$1->intval < $3->floatval);
        }
        else if($1->valueType==floatType && $3->valueType==floatType){
            buf->boolval = ($1->floatval < $3->floatval);
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR LT EXPR TYPE ERROR");
        }
        $$ = buf;
        jbLogicalOperation(IFLT);


    }
    | EXPR LE EXPR {
        Trace("EXPR LE EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if($1->valueType==intType && $3->valueType==intType){
            buf->boolval = ($1->intval <= $3->intval);
        }
        else if($1->valueType==floatType && $3->valueType==intType){
            buf->boolval = ($1->floatval <= (float)$3->intval);
        }
        else if($1->valueType==intType && $3->valueType==floatType){
            buf->boolval = ((float)$1->intval <= $3->floatval);
        }
        else if($1->valueType==floatType && $3->valueType==floatType){
            buf->boolval = ($1->floatval <= $3->floatval);
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR LE EXPR TYPE ERROR");
        }
        $$ = buf;
        jbLogicalOperation(IFLE);


    }
    | EXPR EQ EXPR {
        Trace("EXPR EQ EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if($1->valueType != $3->valueType){
            yyerror("EXPR EQ EXPR type mismatch");
        }
        else if($1->valueType==intType){
            buf->boolval = ($1->intval == $3->intval);
        }
        else if($1->valueType==floatType){
            buf->boolval = ($1->floatval == $3->floatval);
        }
        else if($1->valueType==boolType){
            buf->boolval = ($1->boolval == $3->boolval);
        }
        else if($1->valueType==stringType){
            buf->boolval = (*($1->stringval) == *($3->stringval));
        }
        else if($1->valueType==charType){
            buf->boolval = (($1->charval) == ($3->charval));
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR EQ EXPR TYPE ERROR");
        }
        $$ = buf;
        jbLogicalOperation(IFEQ);

    }
    | EXPR GT EXPR {
        Trace("EXPR GT EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;

        if($1->valueType==intType && $3->valueType==intType){
            buf->boolval = ($1->intval > $3->intval);
        }
        else if($1->valueType==floatType && $3->valueType==intType){
            buf->boolval = ($1->floatval > (float)$3->intval);
        }
        else if($1->valueType==intType && $3->valueType==floatType){
            buf->boolval = ((float)$1->intval > $3->floatval);
        }
        else if($1->valueType==floatType && $3->valueType==floatType){
            buf->boolval = ($1->floatval > $3->floatval);
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR GT EXPR TYPE ERROR");
        }
        $$ = buf;
        jbLogicalOperation(IFGT);


    }
    | EXPR GE EXPR {
        Trace("EXPR GE EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if($1->valueType==intType && $3->valueType==intType){
            buf->boolval = ($1->intval >= $3->intval);
        }
        else if($1->valueType==floatType && $3->valueType==intType){
            buf->boolval = ($1->floatval >= (float)$3->intval);
        }
        else if($1->valueType==intType && $3->valueType==floatType){
            buf->boolval = ((float)$1->intval >= $3->floatval);
        }
        else if($1->valueType==floatType && $3->valueType==floatType){
            buf->boolval = ($1->floatval >= $3->floatval);
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR GE EXPR TYPE ERROR");
        }
        $$ = buf;
        jbLogicalOperation(IFGE);


    }
    | EXPR NE EXPR {
        Trace("EXPR NE EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if($1->valueType != $3->valueType){
            yyerror("EXPR EQ EXPR type mismatch");
        }
        else if($1->valueType==intType){
            buf->boolval = ($1->intval != $3->intval);
        }
        else if($1->valueType==floatType){
            buf->boolval = ($1->floatval != $3->floatval);
        }
        else if($1->valueType==boolType){
            buf->boolval = ($1->boolval != $3->boolval);
        }
        else if($1->valueType==stringType){
            buf->boolval = (*($1->stringval) != *($3->stringval));
        }
        else if($1->valueType==charType){
            buf->boolval = (($1->charval) != ($3->charval));
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR NE EXPR TYPE ERROR");
        }
        $$ = buf;
        jbLogicalOperation(IFNE);

    }
    | NOT EXPR {
        Trace("NOT EXPR");
        cout << valueType2Str($2->valueType) << endl;
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        
        if($2->valueType != boolType){
            yyerror("NOT EXPR type error");
        }
        else if($2->valueType == unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            buf->boolval = !($2->boolval);
        }
        $$ = buf;
        jbOperation('!');

    }
    | ID '[' EXPR ']' {
        Trace("ID [ EXPR ]");
        idInfo* buf = tables.lookup(*$1);
        // cant find id
        if(buf == NULL){
            yyerror("cant find " + *$1);

        }
        if(buf->idType != arrayType){
            yyerror("ID is not an array");
        }
        if($3->valueType != intType){
            yyerror("ID[EXPR] must be int");
        }
        // if access out of range
        if($3->intval>=buf->arraySize || $3->intval<0){
            yyerror("access out of range");
        }
        // get id array value
        $$ = new valueInfo();
        
        $$->valueType = buf->arrayValueType;
    }
    | VALUE {
        Trace("value ")
        $$ = $1;
    }


// define keyword data type
//  The predefined data types are char, string, int, boolean, and float.
DATA_TYPE : CHAR {
            $$ = charType;
         }
         | STRING {
             $$ = stringType;
         }
         | INT {
             $$ = intType;

         }
         | BOOLEAN {
             $$ = boolType;

         }
         | FLOAT {
            $$ = floatType;
         }
         ;

// define values
VALUE : STRING_VALUE {
        Trace("string value");
        $$ = stringValue($1);
        jbfile << "\t\tldc "  << *$1  << endl;
    }
      | INT_VALUE {
        Trace("int value");
        $$ = intValue($1);
        jbPushInt($1);
      }
      | BOOL_VALUE {
        Trace(" boolean value");
        $$ = boolValue($1);
        jbPushInt($1 ? 1 : 0);
      }
      | FLOAT_VALUE {
            Trace(" float value");
            $$  = floatValue($1);
      }
      | CHAR_VALUE {
          Trace(" char value");
          $$  = charValue($1);
      }
      ;

// define conditional stmt



BLOCK_OR_SIMPLE : BLOCK {
                    $$ = false;

                    vector<int> top = ifLabelsVector[ifLabelsVector.size()-1];
                    int l = top[0];
                    jbfile << "\t\tgoto L" << l << endl;
                }
                | PUSH SIMPLE_STMT {
                    $$ = true;
                    vector<int> top = ifLabelsVector[ifLabelsVector.size()-1];
                    int l = top[0];
                    jbfile << "\t\tgoto L" << l << endl;
                }

PUSH : {
    tables.push();
}

if_dosomething : {
    //      這次數是一般的 if 近來
            if(!elseifFlag){
                vector<int> buf;
                ifLabelsVector.push_back(buf); 
                ifLabelsVector[ifLabelsVector.size()-1].push_back(labelCount++);
                ifLabelsVector[ifLabelsVector.size()-1].push_back(labelCount++);
            }
            else{
                // 這次是else if近來這邊的
                ifLabelsVector[ifLabelsVector.size()-1].push_back(labelCount++);

            }
            elseifFlag = false;
            vector<int> top = ifLabelsVector[ifLabelsVector.size()-1];
            int l = top[top.size()-1];
            jbfile << "\t\tifeq L" << l << endl;
    }



IF_STMT : IF '(' EXPR ')' if_dosomething BLOCK_OR_SIMPLE {
            if($3->valueType != boolType){
                yyerror("if expr must be a boolean");
            }
            if($6){
                tables.pop();
            }
            vector<int> top = ifLabelsVector[ifLabelsVector.size()-1];
            int l = top[0];
            jbfile << "\tL" << l <<  ":" << endl;
            ifLabelsVector.pop_back();
        }
        | IF '(' EXPR ')' if_dosomething BLOCK_OR_SIMPLE {
            if($6){
                tables.pop();
            }
            // declare LX label
            if($3->valueType != boolType){
                yyerror("if expr must be a boolean");
            }

            vector<int> top = ifLabelsVector[ifLabelsVector.size()-1];
            int l = top[top.size()-1];
            top.pop_back();
            ifLabelsVector[ifLabelsVector.size()-1] = top;
            jbfile << "\tL" << l <<  ":" << endl;

        }  ELSEIF_STMT 





ELSEIF_STMT : ELSE {
                elseifFlag = true;
            } IF_STMT  
            | ELSE BLOCK_OR_SIMPLE {
                if($2){
                    tables.pop();
                }
                vector<int> top = ifLabelsVector[ifLabelsVector.size()-1];
                int l = top[0];
                jbfile << "\tL" << l << ":" << endl; 
                ifLabelsVector.pop_back();
            }








// define loop stmt 

LOOP_STMT : WHILE_STMT
          | FOR_STMT


while_block_or_simplestmt : PUSH SIMPLE_STMT {
                                $$ = true;
                                vector<int> top = loopLabelsVector[loopLabelsVector.size()-1];
                                int l = top[0];
                                jbfile << "\t\tgoto Lbegin" << l << endl;
                            }
                          | BLOCK{
                              $$ = false;
                              vector<int> top = loopLabelsVector[loopLabelsVector.size()-1];
                                int l = top[0];
                                jbfile << "\t\tgoto Lbegin" << l << endl;
                          }

// define while stmt
WHILE_STMT : WHILE {
                vector<int> buf;
                // Lbegin
                buf.push_back(labelCount++);
                // Ltrue
                buf.push_back(labelCount++);
                // Lfalse
                buf.push_back(labelCount++);
                // Lexit
                buf.push_back(labelCount++);
                loopLabelsVector.push_back(buf);

                vector<int> top = loopLabelsVector[loopLabelsVector.size()-1];
                int l = top[0];
                jbfile << "\t\tgoto Lbegin" << l << endl;
                jbfile << "\tLbegin" << l << ":" << endl;

            } '(' EXPR ')' {
                vector<int> top = loopLabelsVector[loopLabelsVector.size()-1];
                int l = top[3];
                jbfile << "\t\tifeq Lexit" << l << endl;
                jbfile << "\t\tgoto Ltrue" << l << endl;
                jbfile << "\tLtrue" << l << ":" << endl;

            }  while_block_or_simplestmt {
                if($4->valueType == unknownType){
                    Warning("unknownType!!!!");
                }
                else if($4->valueType != boolType){
                    yyerror("while EXPR must be boolean");
                }
                if($7){
                    tables.pop();
                }

                vector<int> top = loopLabelsVector[loopLabelsVector.size()-1];
                int l = top[3];
                jbfile << "\tLexit" << l << ":" << endl;
                loopLabelsVector.pop_back();
            }


// define for stmt
for_block_or_simplestmt : PUSH SIMPLE_STMT {
                                $$ = true;
                                vector<int> top = forLabelsVector[forLabelsVector.size()-1];
                                idInfo *id = forIdVector[forIdVector.size()-1];
                                jbfile << "\t\ticonst_1" << endl;
                               // Golbal
                                if(id->stackID == -1){
                                    jbfile << "\t\tgetstatic int " << className << "." << id->id << endl;
                                    jbfile << "\t\tiadd" << endl;
                                    jbfile << "\t\tputstatic int " << className << "." << id->id << endl;
                                }
                                else{
                                    jbfile << "\t\tiload " << id->stackID << endl;
                                    jbfile << "\t\tiadd" << endl;
                                    jbfile << "\t\tistore " << id->stackID << endl;
                                }
                                int l = top[0];
                                // assign id
                                jbfile << "\t\tgoto Lbegin" << l << endl;
                            }
                          | BLOCK{
                              $$ = false;
                              vector<int> top = forLabelsVector[forLabelsVector.size()-1];
                              idInfo *id = forIdVector[forIdVector.size()-1];
                                jbfile << "\t\ticonst_1" << endl;
                               // Golbal
                                if(id->stackID == -1){
                                    jbfile << "\t\tgetstatic int " << className << "." << id->id << endl;
                                    jbfile << "\t\tiadd" << endl;
                                    jbfile << "\t\tputstatic int " << className << "." << id->id << endl;
                                }
                                else{
                                    jbfile << "\t\tiload " << id->stackID << endl;
                                    jbfile << "\t\tiadd" << endl;
                                    jbfile << "\t\tistore " << id->stackID << endl;
                                }
                                int l = top[0];
                                // assign id
                                jbfile << "\t\tgoto Lbegin" << l << endl;
                          }


FOR_STMT : FOR '(' ID {
                vector<int> buf;
                // Lbegin
                buf.push_back(labelCount++);
                // Ltrue
                buf.push_back(labelCount++);
                // Lfalse
                buf.push_back(labelCount++);
                // Lexit
                buf.push_back(labelCount++);
                // Lbegin_init
                buf.push_back(labelCount++);

                idInfo * id = tables.lookup(*$3);
                if(id == NULL){
                    yyerror(*$3 +" does not exist");
                }
                forIdVector.push_back(id);
                forLabelsVector.push_back(buf);


            }  LT '-' EXPR TO EXPR ')' {
                if($7->valueType == unknownType || $9->valueType == unknownType){
                    Warning("unknownType!!!");
                }
                else if($7->valueType != intType || $9->valueType != intType){
                    yyerror("for loop args must be int");
                }
                idInfo * id = tables.lookup(*$3);
                forLabelsVector[forLabelsVector.size()-1].push_back($9->intval);
                vector<int> top = forLabelsVector[forLabelsVector.size()-1];
                int l = top[0];
                int l_init = top[4];
                int l_exit = top[3];
                
                jbfile << "\t\tgoto Lbegin_init" << l_init << endl;
                jbfile << "\tLbegin_init" << l_init << ":" << endl;

                jbfile << "\t\tisub" << endl;
                jbfile << "\t\tifeq Lbegin" << l << endl;
                jbfile << "\t\tgoto Lexit" << l_exit << endl;
                
                
                jbfile << "\tLbegin" << l << ":" << endl;
                if(id->stackID == -1){
                    jbfile << "\t\tgetstatic int " << className << "." << id->id << endl;
                }
                else{
                    jbfile << "\t\tiload " << id->stackID << endl;
                }
                jbPushInt($9->intval);
                jbfile << "\t\tisub" << endl;
                jbfile << "\t\tifeq Lexit" << l << endl;
                jbfile << "\t\tgoto Ltrue" << l << endl;
                jbfile << "\tLtrue" << l << ":" << endl;
            } for_block_or_simplestmt {
            if($12){
                tables.pop();
            }
            vector<int> top = forLabelsVector[forLabelsVector.size()-1];
            int l = top[3];
            jbfile << "\tLexit" << l << ":" << endl;
            forLabelsVector.pop_back();
            forIdVector.pop_back();

         }


%%
int main(int argc, char *argv[])
{
    /* open the source program file */
    if(argc == 1){
        yyin = stdin;
    }
    else if (argc == 2){
        yyin = fopen(argv[1], "r");         /* open input file */
    }
    else{
        printf ("Usage: sc filename\n");
        exit(1);
    }

    string filename;
    if(argc > 1){
        filename = string(argv[1]);
        filename = filename + ".jasm";
		jbfile.open(filename,ios::out);
    }
	else{
        jbfile.open("example.jasm",ios::out);
    }

    if(!jbfile){
        cout << "open jbfile error" << endl;
        exit(1);
    }

    /* perform parsing */
    if (yyparse() == 1)                /* parsing */
        yyerror("Parsing error !");     /* syntax error */
    else{
        printf("Parsing Success \n");
        cout << filename << endl;
    }
    
}
