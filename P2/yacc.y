%{
#include <iostream>
#include "main.h"
#include "lex.yy.cpp"
#define Trace(t)        {printf(t);printf("\n");}
// #define Error(t)    {printf(t);printf("\n");exit(-1);}
#define Warning(t)  {cout << "Warning: " <<  t << endl;} 
void yyerror(string s){
   cout << buf << " (" << s  << ')' << endl;
   exit(-1);
}
SymbolTableVector tables;



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

%type <idMap> BLOCK 






%left OR_OP
%left AND_OP
%left NOT
%left LT LE EQ GT GE NE
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%%
//start : ALL {
//        Trace("Reducing to program\n");
//    }
//   ;

//ALL : STMTS ALL
//    | FUNCTION ALL
//    | PROGRAM ALL
//    | 
//   ;


// Program 
PROGRAM : OBJECT ID {
            Trace("declare an id to objet type");
            int result = tables.vec[tables.top].insert(*$2,objectType);
            if(result == -1){
                yyerror(*$2 + " already exists");
            }
            //tables.push();
        } OBJ_BLOCK {
            Trace("OBJECT ID BLOCK");
        };


// methods
FUNCTION : DEF ID {
            Trace("create an function id");
            int result = tables.vec[tables.top].insert(*$2,functionType);
            if(result == -1){
                yyerror(*$2 + " already exists");
            }
            tables.push();
        } '(' ARGS ')' FUNCTION_OPTIONAL BLOCK {
            Trace("declare method end");
            idInfo * id = tables.lookup(*$2);
            if($7 != unknownType && $7 != valueTypeError){
                cout << "function return type is " << valueType2Str($7) << endl;
                id->returnType = $7;
                // check return value is same as declared 
               // if((*$8)["return"]->value->valueType != $7){
                    // yyerror("function type is different from declared");
                   // Warning("function return type is different from declared");
               // }
            }
            Trace("Saveing function arguments and inside id map");
            id->argumentsInfo = tables.vec[tables.top].idMap;
            // here is record return 
            // id->insideIdMap = *$8;
            cout << "size check : "<< id->argumentsInfo.size() << endl;
            // the answer include return idinfo
            cout << "size check : "<< id->insideIdMap.size() << endl;
            tables.pop();
            cout << $5->empty() << endl;
            for(int i = 0; i < $5->size(); ++i){
                cout << "id : " << (*$5)[i]->first << " type : " << valueType2Str((*$5)[i]->second) << endl;
            }
            // store the function declare arguments sequence
            // can check when function invocation
            id->argumentsInfoSeq = *$5;
        }

// return stmt declare
// FUNCTION_RETURN : RETURN EXPR {
//                     Trace("FUNCTION HAS RETURN VALUE");
//                     $$ = $2;
//                 }
//                 | RETURN {
//                     Trace("FUNCTION HAS NO RETURN VALUE");
//                     $$ = new valueInfo();
//                 }
//                 | {
//                     Trace("FUNCTION HAS NO RETURN VALUE");
//                     $$ = new valueInfo();
//                 }
// function block(last must be return or not)
// FUNCTION_BLOCK : '{' {
//         Trace("FUNCTION BLOCK START");
//         tables.push();
//       } STMTS  '}' {
//           Trace("FUNCTION BLOCK END");
//             $$ =  new map<string,idInfo*>();
//           *$$ = tables.vec[tables.top].idMap;
//          //  judge return
//           // (*$$)["return"] =  new idInfo();
//           // (*$$)["return"]->value = $4;
//           tables.dump();
//           if(tables.pop() == -1){
//               yyerror("symbol table error");
//           }
//       }

// can specify return type or not
FUNCTION_OPTIONAL : {
                    $$ = unknownType;
                  }
                  | ':' DATA_TYPE {
                    $$ = $2;
                  }
                 ;

// function invocation
FUNCTION_INVOCATION : ID '(' COMMA_SEP_EXPR ')' {
                        Trace("call function invocation");
                        idInfo* id = tables.lookup(*$1);
                        if(id == NULL){
                            yyerror(*$1 + "doesn't exist");
                        }
                        if(id->idType != functionType){
                            yyerror(*$1 + "is not a function");
                        }
                        cout << "parameter nums : " << $3->size() << endl;
                        for(int i = 0; i < $3->size(); ++i){
                            cout << "type : " << valueType2Str((*$3)[i]->valueType) << endl;
                        }
                        // check parameter is same as declared 
                        if($3->size()!= id->argumentsInfo.size()){
                            yyerror("parameter nums error");
                        }
                        // check type and assign
                        for(int i = 0; i < $3->size(); ++i){
                            if((*$3)[i]->valueType!=id->argumentsInfoSeq[i]->second){
                                yyerror("parameter type error");
                            }
                            // call by reference?...
                            id->argumentsInfo[id->argumentsInfoSeq[i]->first]->value =  (*$3)[i];
                        }
                        valueInfo* buf = new valueInfo();
                        // here need to push id's tow idmap into idmap
                        // $$ = id->insideIdMap["return"]->value; 
                        $$ = new valueInfo();
                        //if(id->returnType!=unknownType){
                           // $$->valueType = id->returnType;
                       // }
                        $$->valueType = id->returnType;
                        
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
        int result = tables.vec[tables.top].insert(*$1,variableType,$3);
        if(result == -1){
            yyerror("id has been used");
        }
        pair<string,int>* p = new pair<string,int>();
        p->first = *$1;
        p->second = $3;
        $$ = p;
    }

// define stmts
STMTS : STMT 
      | STMT STMTS 
      |
      ;

// define stmt
STMT : SIMPLE_STMT 
     | BLOCK 
     | CONDITIONAL_STMT 
     | LOOP_STMT 
    ;


V_DECLARE : VAR_DECLARE 
           | VAL_DECLARE 
           



// define simple stmt simple stmt include declare
SIMPLE_STMT : V_DECLARE
            | RETURN
            | RETURN EXPR;
            | ID ASSIGN EXPR {
                Trace("ID ASSIGN EXPR");
                idInfo* buf = new idInfo();
                // buf = tables.vec[tables.top].lookup(*$1);
                buf = tables.lookup(*$1);
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
            }
            | ID '[' EXPR ']' ASSIGN EXPR {
                Trace("ID '[' EXPR ']' ASSIGN EXPR");
                // idInfo* buf = tables.vec[tables.top].lookup(*$1);
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
                else{
                    *(buf->arrayValue[$3->intval]) = *($6);
                }
            }
            | PRINT  EXPR 
            | PRINTLN  EXPR 
            | READ ID 
            | EXPR
            ; 

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
            tables.dump();
          if(tables.pop() == -1){
              yyerror("symbol table error");
          }
      }

// object block can declare methods  and stmts inside
// example u can define a methods in object


OBJ_CONTENTS : 
             |FUNCTION OBJ_CONTENTS
             | V_DECLARE OBJ_CONTENTS
             ;

OBJ_BLOCK : '{' {
        // tables.push();
      } OBJ_CONTENTS 
      '}' {
          // tables.dump();
          //if(tables.pop() == -1){
          //    yyerror("symbol table error");
          //}
      }


// constant variables declarations
VAL_DECLARE : VAL ID ASSIGN EXPR{
                Trace("VAL ID ASSIGN EXPR");
                int result = tables.vec[tables.top].insert(*$2,constType,$4);
                if(result == -1){
                    yyerror("id has been used");
                }
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
            }

VAR_DECLARE : VAR ID ASSIGN EXPR {
                Trace("VAR ID ASSIGN EXPR");
                // declare var with value
                int result = tables.vec[tables.top].insert(*$2,variableType,$4);
                if(result == -1){
                    yyerror("id has been used");
                }
            }
            | VAR ID ':' DATA_TYPE {
                Trace("VAR ID ':' DATA_TYPE");
                // declare var but only have type
                int result = tables.vec[tables.top].insert(*$2,variableType,$4);
                if(result == -1){
                    yyerror("id has been used");
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
            valueInfo* v = new valueInfo();
            // here need to push id's tow idmap into idmap
            $$ = v;

            // yyerror(*$1 + " is function make grammar error");
        }
        // check has init or not
        else if(!buf->hasInit){
            // yyerror(*$1 + " has not init");
            Warning(*$1 + " has not init");
        }
        $$ = buf->value;
    }
    | '-' EXPR %prec UMINUS {
        Trace("- EXPR")
        valueInfo* buf = new valueInfo();
        if ($2->valueType== intType) {
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
            buf->floatval = ($1->floatval + (float)$3->intval);
        }
        else if($1->valueType==intType && $3->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ((float)$1->intval + $3->floatval);
        }
        else if($1->valueType==floatType && $3->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ($1->floatval + $3->floatval);
        }
        else if($1->valueType==unknownType || $3->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR + EXPR TYPE ERROR");
        }
        $$ = buf;
        
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

    }
    | NOT EXPR {
        Trace("NOT EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if($2->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else if($2->valueType != boolType){
            yyerror("NOT EXPR type error");
        }
        else{
            buf->boolval = !($2->boolval);
        }
        $$ = buf;
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
        $$ = buf->arrayValue[$3->intval];
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
    }
      | INT_VALUE {
        Trace("int value");
        $$ = intValue($1);
      }
      | BOOL_VALUE {
        Trace(" boolean value");
        $$ = boolValue($1);
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
CONDITIONAL_STMT : IF_STMT
                 | IF_STMT ELSE_STMT

IF_STMT : IF '(' EXPR ')' {
            tables.push();

        } SIMPLE_STMT {
            tables.dump();
            tables.pop();
        }
        | IF '(' EXPR ')' BLOCK

ELSE_STMT : ELSE {
            tables.push();
        } SIMPLE_STMT {
            tables.dump();
            tables.pop();
        }
          | ELSE BLOCK 
          | ELSE IF_STMT
          | ELSE IF_STMT ELSE_STMT


// define loop stmt 

LOOP_STMT : WHILE_STMT
          | FOR_STMT

// define while stmt
WHILE_STMT : WHILE '(' EXPR ')' {
                    tables.push();
                } SIMPLE_STMT {
                tables.dump();
                tables.pop();
                Trace(" while without block");
                if($3->valueType == unknownType){
                    Warning("unknownType!!!!");
                }
                else if($3->valueType != boolType){
                    yyerror("while EXPR must be boolean");
                }
           }
           | WHILE '(' EXPR ')' BLOCK{
                Trace(" while with block");
                if($3->valueType == unknownType){
                    Warning("unknownType!!!!");
                }
                else if($3->valueType != boolType){
                    yyerror("while EXPR must be boolean");
                }
           }

// define for stmt
FOR_STMT : FOR '(' ID LT '-' EXPR TO EXPR ')' {
                tables.push();

            } SIMPLE_STMT {
                tables.dump();
                tables.pop();
                Trace("for stmt without block");
            if($6->valueType == unknownType || $8->valueType == unknownType){
                Warning("unknownType!!!");
            }
            else if($6->valueType != intType || $8->valueType != intType){
                yyerror("for loop args must be int");
            }
         }
         | FOR '(' ID LT '-' EXPR TO EXPR ')' BLOCK {
             Trace("for stmt with block");
             if($6->valueType == unknownType || $8->valueType == unknownType){
                Warning("unknownType!!!");
             }
             else if($6->valueType != intType || $8->valueType != intType){
                yyerror("for loop args must be int");
            }
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

    /* perform parsing */
    if (yyparse() == 1)                /* parsing */
        yyerror("Parsing error !");     /* syntax error */


    printf("Parsing Success \n");
    tables.dump();
}
