%{
#include <iostream>
#include "main.h"
#include "lex.yy.cpp"
#define Trace(t)        printf(t)
void yyerror(const char *s){
   cout << buf << " (" << s  << ')' << endl;
}



%}

// declare my union
%union {
    float floatval;
    int intval;
    bool boolval;
    string *stringval;
    int type;
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




%type <value> VALUE
// define data type token and return value is enum type
%type <type> DATA_TYPE




%left OR_OP
%left AND_OP
%left NOT
%left LT LE EQ GT GE NE
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%%
program:        VALUE
                {
                Trace("Reducing to program\n");
                }
                ;

// constant variables declarations
VAL_DECLARE : VAL ID EQ VALUE{
            }
            | VAL ID ":" DATA_TYPE EQ VALUE {

            }

VAR_DECLARE : VAR ID EQ VALUE {

            }
            | VAR ID ":" DATA_TYPE {

            }
            | VAR ID ":" DATA_TYPE EQ VALUE{

            }
            | VAR ID ":" DATA_TYPE "[" INT_VALUE "]" {

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
        cout << *$1 << endl;
        $$ = stringValue($1);
    }
      | INT_VALUE {
        $$ = intValue($1);
        cout << $1 << endl;
      }
      | BOOL_VALUE {
        $$ = boolValue($1);
        cout << $1 << endl;
      }
      | FLOAT_VALUE {
          $$  = floatValue($1);
          cout << $1 << endl;
      }
      | "'" 
      ;

// EXPR : "(" EXPR ")"{
//     $$ = $2;

// }
//     | EXPR "+" EXPR{

//     }
//     | EXPR "-" EXPR{

//     }
//     | EXPR "*" EXPR{

//     }
//     | EXPR "/" EXPR{

//     }
//     | EXPR "%" EXPR{

//     }
//     | EXPR

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
