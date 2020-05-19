%{
#define Trace(t)        printf(t)
%}


%union {
    double realval;
    int intval;
    bool boolval;
    string stringval;

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
%token NULL
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

%token <boolval> BOOL_VALUE
%token <intval> INT_VALUE
%token <stringval> STRING_VALUE
%token <realval> REAL_VALUE
%token <stringval> ID




%left OR_OP
%left AND_OP
%left NOT
%left LT LE EQ GT GE NE
%left '+' '-'
%left '*' '/' '%'
%nonassoc UMINUS

%%
program:        identifier semi
                {
                Trace("Reducing to program\n");
                }
                ;




semi:           SEMICOLON
                {
                Trace("Reducing to semi\n");
                }
                ;


// constant variables declarations

VAL_DECLARE : VAL ID EQ somevalue{
            }
            | VAL ID ":" type EQ somevalue{

            }

VAR_DECLARE : VAR ID EQ somevalue{

}
            | VAR ID ":" type {

            }
            | VAR ID ":" type EQ somevalue{

            }
            | VAR ID ":" type "[" INT "]"{

            }


EXPR : "(" EXPR ")"{
    $$ = $2;

}
    | EXPR "+" EXPR{

    }
    | EXPR "-" EXPR{

    }
    | EXPR "*" EXPR{

    }
    | EXPR "/" EXPR{

    }
    | EXPR "%" EXPR{

    }
    | EXPR

%%
#include "lex.yy.c"

yyerror(msg)
char *msg;
{
    fprintf(stderr, "%s\n", msg);
}

main()
{
    /* open the source program file */
    if (argc != 2) {
        printf ("Usage: sc filename\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");         /* open input file */

    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */
}
