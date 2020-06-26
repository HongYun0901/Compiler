%{
// #define LIST_NO_PRINT     strcat(buf,yytext)
#define LIST    {/*printf("%s",yytext);*/}
#define MYPRINT   {printf("%d ",++linenum); buf[0]=0;}
#define token(t) {LIST; printf("<%s>\n",t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",t,i);}
#define tokenDouble(t,i) {LIST; printf("<%s:%lf>\n",t,i);}
#define tokenString(t,s) {LIST; /* printf("<%s:%s>\n",t,s); */}

#define MAX_LINE_LENG 256
#include <stdio.h>
#include <memory.h>
#include <limits.h>
#include <stdlib.h>
#include "y.tab.hpp"
using namespace std;



int linenum = 1;
char buf[MAX_LINE_LENG];

%}

%x COMMENT

/* Comments */
/* c comment */
c_comment_s "/*"
c_comment_e "*/"
/* cpp comment (//) */
cpp_comment "//".*

/* delimiters */
delimiters [,:\.;()\[\]\{\}]

/* operators */
arithmetic [\+\-\*/%]
relational <|<=|>=|>|==|!=
logical "&&"|"||"|"!"
assign =
operators {arithmetic}|{relational}|{logical}|{assign}


/* Real Constants and  Integer Constants */
digit  [0-9]
integer {digit}+
realconstants [\+\-]?{integer}"."{integer}([Ee][\+\-]?{integer})?

/* Identifiers */
letter [a-zA-Z]
identifiers ({letter}({letter}|{digit})*)





/* string strings \"(\\.|[^"\n])*\" */
strings  (\"(\"\"|[^"\n])*\")

 /* char */
char '([^'\\\n]|\\.)'





%%
 /* keyworkds */
boolean   {
    LIST;
    return BOOLEAN;
}

break   {
    LIST;
    return BREAK;
}
char   {
    LIST;
    return CHAR;
}
case   {
    LIST;
    return CASE;
}
class   {
    LIST;
    return CLASS;
}
continue   {
    LIST;
    return CONTINUE;
}
def   {
    LIST;
    return DEF;
}
do   {
    LIST;
    return DO;
}
else   {
    LIST;
    return ELSE;
}
exit   {
    LIST;
    return EXIT;
}
false   {
    LIST;
    yylval.boolval = false;
    return BOOL_VALUE;
}
float   {
    LIST;
    return FLOAT;
}
for   {
    LIST;
    return FOR;
}
if   {
    LIST;
    return IF;
}
int   {
    LIST;
    return INT;
}
null   {
    LIST;
    return _NULL;
}
object   {
    LIST;
    return OBJECT;
}
print   {
    LIST;
    return PRINT;
}
println   {
    LIST;
    return PRINTLN;
}
read {
    LIST;
    return READ;
}
repeat   {
    LIST;
    return REPEAT;
}
return   {
    LIST;
    return RETURN;
}
string   {
    LIST;
    return STRING;
}
to   {
    LIST;
    return TO;
}
true   {
    LIST;
    yylval.boolval = true;
    return BOOL_VALUE;
}
type   {
    LIST;
    return TYPE;
}
val   {
    LIST;
    return VAL;
}
var   {
    LIST;
    return VAR;
}
while  {
    LIST;
    return WHILE;
}

 /* operators */
{arithmetic} {
    strcat(buf,yytext);
    return *yytext;
}
 /* delimiters */
{delimiters} {
    strcat(buf,yytext);
    return *yytext;
}
"<" {
    LIST;
    return LT;
}
"<=" {
    LIST;
    return LE;
}
">=" {
    LIST;
    return GE;
}
">" {
    LIST;
    return GT;
}
"==" {
    LIST;
    return EQ;
}
"!=" {
    LIST;
    return NE;
}
"&&" {
    LIST;
    return AND_OP;
}
"||" {
    LIST;
    return OR_OP;
}
"!" {
    LIST;
    return NOT;
}
"=" {
    LIST;
    return ASSIGN;
}

 /* Real Constants and  Integer Constants */
{integer} {
    int tmp;
    sscanf(yytext,"%d",&tmp);
    // tokenInteger("integer",tmp);
    yylval.intval = tmp;
    return INT_VALUE;
}
{realconstants} {
    double tmp;
    sscanf(yytext,"%lf",&tmp);
    // tokenDouble("realconstants",tmp);
    yylval.floatval = tmp;
    return FLOAT_VALUE;
}

{char} {
    char tmp[1024];
    LIST;
    sscanf(yytext,"%s",tmp);
    printf("%s \n",tmp);
    yylval.charval = tmp[1];
    return CHAR_VALUE;




}

 /* identifiers */
{identifiers} {
    tokenString("id",yytext);
    // insert(yytext,symboltable);
    yylval.stringval = new string(yytext);
    // yylval.stringval = string(yytext);
    return ID;

}



 /* comment */
{cpp_comment} {
    LIST;
}

{c_comment_s} {
    LIST;
    BEGIN COMMENT;
}
 /* begin c comment status */
<COMMENT>{c_comment_e} {
    LIST;
    BEGIN INITIAL;
}
<COMMENT>. {
    LIST;
}
<COMMENT>\n {
    LIST;
    linenum++;
    buf[0] = '\0';
}

{strings} {
    // char ch = input();
    // cout << "in" << ch << endl;
    // if(ch=='"'){
    //     unput(ch);
    //     yymore();
    // }
    // else{
        
    // }
    string tmp = string(yytext);
    string result = "";
    for(int i=0; i< tmp.size();i++){
        if(tmp[i]=='"' && i!= tmp.size()-1 && i!=0){
            result += tmp[i++];
        }
        else{
            result += tmp[i];
        }

    }
    cout << result << endl;
    tokenString("string",result);
    yylval.stringval = new string(result);
    return STRING_VALUE;
}

\n      {
        LIST;
        linenum++;
        buf[0] = '\0';
        }

[ \t]*  {LIST;}

.       {
        LIST;
        printf("%d:%s\n", linenum, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        }
%%

