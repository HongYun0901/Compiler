%{
// #define LIST     strcat(buf,yytext)
#define LIST    {printf("%s",yytext); charnum+=yyleng;}
#define PRINT   {printf("%d ",++linenum); buf[0]=0;charnum=0;}
#define token(t) {LIST; printf("<%s>\n",t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%d>\n",t,i);}
#define tokenDouble(t,i) {LIST; printf("<%s:%lf>\n",t,i);}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",t,s);}

#define MAX_LINE_LENG 256
#include <stdio.h>
#include <memory.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
using namespace std;



int linenum = 1;
int charnum = 0;
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





/* string */
strings \"(\\.|[^"\n])*\"

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
    return CLASS:
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
    return ESLE;
}
exit   {
    LIST;
    return EXIT;
}
false   {
    LIST;
    yylval.bval = false;
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
    return NULL;
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
    yylval.bval = true;
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
while   {
    LIST;
    return WHILE;
}

 /* operators */
{arithmetic} {
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
    return AND_OP
}
"||" {
    LIST;
    return OR_OP
}
"!" {
    LIST;
    return NOT
}
"=" {
    LIST;
    return ASSIGN
}






 /* Real Constants and  Integer Constants */
{integer} {
    int tmp;
    sscanf(yytext,"%d",&tmp);
    tokenInteger("integer",tmp);
    yylval.ival = tmp;
    return INT_VALUE;
}
{realconstants} {
    double tmp;
    sscanf(yytext,"%lf",&tmp);
    tokenDouble("realconstants",tmp);
    yylval.dval = tmp;
    return REAL_VALUE;
}

 /* identifiers */
{identifiers} {
    tokenString("id",yytext);
    // insert(yytext,symboltable);
    yylval = new string(yytext);
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
    printf("%d: %s", linenum++, buf);
    buf[0] = '\0';
}

{strings} {
    char ch = input();
    if(ch=='"'){
        unput(ch);
        yymore();
        
    }
    else{
        char *tmp = (char *)malloc(sizeof(char)*yyleng);
        strcpy(tmp,yytext);
        // 消除字串中的"" 把它變成"
        for(int i=0;i< strlen(tmp);i++){
            if(tmp[i]=='"' && i!= strlen(tmp)-1 && i!=0){
                // 每次看到有""存在 開一個新的memory給新字串放，長度為原本的減1
                char * new_tmp = (char *)malloc(sizeof(char)*(strlen(tmp)-1));
                // 把"" 左半部拿出來
                char *left = (char *)malloc(sizeof(char)*(i+1));
                strncpy(left,tmp,i+1);
                // 拿右半部
                char *right = (char *)malloc(sizeof(char)*(strlen(tmp)-(i+2)));
                strncpy(right,tmp+i+2,strlen(tmp)-(i+2));
                // 拼在一起
                strcat(new_tmp,left);
                strcat(new_tmp,right);
                tmp = new_tmp;

            }
        }
        char *result = (char *)malloc(sizeof(char)*(strlen(tmp)-2));
        strncpy(result,tmp+1, sizeof(char)*(strlen(tmp)-2));
        tokenString("strings",result);
        unput(ch);
        free(tmp);
        yylval.stringval = new string(result);
        return STRING_VALUE;
    }
}

\n      {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
        charnum = 0;
        }

[ \t]*  {LIST;}

.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        }
%%

