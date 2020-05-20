%{
#include <iostream>
#include "main.h"
#include "lex.yy.cpp"
#define Trace(t)        {printf(t);printf("\n");}
// #define Error(t)    {printf(t);printf("\n");exit(-1);}
#define Warning(t)  {printf(t);printf("\n");} 
void yyerror(string s){
   cout << buf << " (" << s  << ')' << endl;
   exit(-1);
}

SymbolTableVector tables;



%}

%error-verbose

// declare my union
%union {
    float floatval;
    int intval;
    bool boolval;
    string* stringval;
    int valueType;
    valueInfo* value;
    
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




%type <value> VALUE EXPR
// define data type token and return value is enum type
%type <valueType> DATA_TYPE




%left OR_OP
%left AND_OP
%left NOT
%left LT LE EQ GT GE NE
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%%
program:        STMTS
                {
                Trace("Reducing to program\n");
                }
                ;

// define stmts
STMTS : STMT {

      }
      | STMT STMTS {

      };

// define stmt
STMT : SIMPLE_STMT {

     }
     | BLOCK {

     }
     | CONDITIONAL_STMT {

     }
     | LOOP_STMT {

     }



// define simple stmt simple stmt include declare
SIMPLE_STMT : VAL_DECLARE {

            }
            | VAR_DECLARE {

            }
            | ID ASSIGN EXPR {
                Trace("reducing id assign expr");

            }
            | ID '[' EXPR ']' ASSIGN EXPR {

            }
            | PRINT '(' EXPR ')' {

            }
            | PRINTLN '(' EXPR ')' {

            }
            | READ ID {

            }
            | RETURN EXPR {

            }
            | RETURN {

            }
            | EXPR {

            }

// define block
BLOCK : '{' STMTS '}' 



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
                int result = tables.vec[tables.top].insert(*$2,variableType,$4);
                if(result == -1){
                    yyerror("id has been used");
                }
            }
            | VAR ID ':' DATA_TYPE {
                Trace("VAR ID ':' DATA_TYPE");
                int result = tables.vec[tables.top].insert(*$2,variableType);
                if(result == -1){
                    yyerror("id has been used");
                }
            }
            | VAR ID ':' DATA_TYPE ASSIGN EXPR{
                Trace("VAR ID : DATA_TYPE ASSIGN EXPR");
                if($4 != $6->valueType){
                    yyerror("data type and value type doesn't match");
                }
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

//  define expr
EXPR : '(' EXPR ')' {
        $$ = $2;
    }
    | EXPR '+' EXPR{
        
    }
    | EXPR '-' EXPR{

    }
    | EXPR '*' EXPR{

    }
    | EXPR '/' EXPR{

    }
    | EXPR '%' EXPR{

    }
    | '-' EXPR %prec UMINUS {
        Trace("- EXPR")
        valueInfo* buf;
        if ($2->valueType== intType) {
            *buf = *$2;
            buf->intval = -1 * buf->intval;
        }
        else if($2->valueType== floatType){
            *buf = *$2;
            buf->floatval = -1 * buf->floatval;
        }
        else{
            yyerror("- EXPR type error");
        }

    }
    | EXPR OR_OP EXPR {

    }
    | EXPR AND_OP EXPR {

    }
    | EXPR LT EXPR {
        Trace("EXPR LT EXPR");
        valueInfo* buf;
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
        else{
            yyerror("EXPR LT EXPR TYPE ERROR");
        }

    }
    | EXPR LE EXPR {
        Trace("EXPR LE EXPR");
        valueInfo* buf;
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
        else{
            yyerror("EXPR LE EXPR TYPE ERROR");
        }
    }
    | EXPR EQ EXPR {
        Trace("EXPR EQ EXPR");
        valueInfo* buf;
        buf->valueType = boolType;
        if($1->valueType==intType && $3->valueType==intType){
            buf->boolval = ($1->intval == $3->intval);
        }
        else if($1->valueType==floatType && $3->valueType==intType){
            buf->boolval = ($1->floatval == (float)$3->intval);
        }
        else if($1->valueType==intType && $3->valueType==floatType){
            buf->boolval = ((float)$1->intval == $3->floatval);
        }
        else if($1->valueType==floatType && $3->valueType==floatType){
            buf->boolval = ($1->floatval == $3->floatval);
        }
        else{
            yyerror("EXPR EQ EXPR TYPE ERROR");
        }

    }
    | EXPR GT EXPR {
        Trace("EXPR GT EXPR");
        valueInfo* buf;
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
        else{
            yyerror("EXPR GT EXPR TYPE ERROR");
        }

    }
    | EXPR GE EXPR {
        Trace("EXPR GE EXPR");
        valueInfo* buf;
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
        else{
            yyerror("EXPR GE EXPR TYPE ERROR");
        }

    }
    | EXPR NE EXPR {
        Trace("EXPR NE EXPR");
        valueInfo* buf;
        buf->valueType = boolType;
        if($1->valueType==intType && $3->valueType==intType){
            buf->boolval = ($1->intval != $3->intval);
        }
        else if($1->valueType==floatType && $3->valueType==intType){
            buf->boolval = ($1->floatval != (float)$3->intval);
        }
        else if($1->valueType==intType && $3->valueType==floatType){
            buf->boolval = ((float)$1->intval != $3->floatval);
        }
        else if($1->valueType==floatType && $3->valueType==floatType){
            buf->boolval = ($1->floatval != $3->floatval);
        }
        else if($1->valueType==boolType && $3->valueType==boolType){
            buf->boolval =($1->boolval != $3->boolval);
        }
        else{
            yyerror("EXPR NE EXPR TYPE ERROR");
        }

    }
    | NOT EXPR {
        Trace("NOT EXPR");
        valueInfo* buf;
        buf->valueType = boolType;
        if($2->valueType != boolType){
            yyerror("NOT EXPR type error");
        }
        else{
            buf->boolval = !($2->boolval);
        }
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
            yyerror(*$1 + " is function make grammar error");
        }
        // check has init or not
        if(!buf->hasInit){
            yyerror(*$1 + " has not init");
        }
        $$ = buf->value;
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
        Trace("Expr : value ")
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
      ;

// define conditional stmt
CONDITIONAL_STMT : IF_STMT
                 | IF_STMT ELSE_STMT




IF_STMT : IF '(' EXPR ')' SIMPLE_STMT
        | IF '(' EXPR ')' BLOCK

ELSE_STMT : ELSE SIMPLE_STMT
          | ELSE BLOCK 
          | ELSE IF_STMT
          | ELSE IF_STMT ELSE_STMT


// define loop stmt 

LOOP_STMT : WHILE_STMT
          | FOR_STMT


// define while stmt
WHILE_STMT : WHILE '(' EXPR ')' SIMPLE_STMT {
                Trace(" while without block");
                if($3->valueType != boolType){
                    yyerror("while EXPR must be boolean");
                }

           }
           | WHILE '(' EXPR ')' BLOCK{
                Trace(" while with block");
                if($3->valueType != boolType){
                    yyerror("while EXPR must be boolean");
                }
           }

// define for stmt
FOR_STMT : FOR '(' ID LT '-' VALUE TO VALUE ')' SIMPLE_STMT {

         }
         | FOR '(' ID LT '-' VALUE TO VALUE ')' BLOCK{

         }









%%

// yyerror(msg)
// char *msg;
// {
//     fprintf(stderr, "%s\n", msg);
// }
// void yyerror(string s) {
//   cerr << "line " << linenum << ": " << s << endl;
//   exit(1);
// }
//Yacc Required Function


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
}
