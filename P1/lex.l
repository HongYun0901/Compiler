%{
#define LIST     strcat(buf,yytext)
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



int linenum = 1;
char buf[MAX_LINE_LENG];

/* symbol table */
typedef struct {
    char *key;
    char *value;
    void *next;
    void *prev;
} SymbolNode;

// symbol node
typedef struct{
    SymbolNode **table;
    int size;
} SymbolTable;

SymbolTable* create(int);
unsigned int hash(char *,SymbolTable*);
int lookup(char*,SymbolTable*);
int insert(char*,SymbolTable*);
void dump(SymbolTable*);

SymbolTable *symboltable;

%}

%x COMMENT
%x STRING

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

/*Boolean Constants */
boolean true|false



/* string */
strings \"(\\.|[^"\n])*\"

char '([^'\\\n]|\\.)'

%%
 /* keyworkds */
boolean   {
    token("BOOLEAN");
}

break   {
    token("BREAK");
}
char   {
    token("CHAR");
}
case   {
    token("CASE");
}
class   {
    token("CLASS");
}
continue   {
    token("CONTINUE");
}
def   {
    token("DEF");
}
do   {
    token("DO");
}
else   {
    token("ELSE");
}
exit   {
    token("EXIT");
}
false   {
    token("FALSE");
}
float   {
    token("FLOAT");
}
for   {
    token("FOR");
}
if   {
    token("IF");
}
int   {
    token("INT");
}
null   {
    token("NULL");
}
object   {
    token("OBJECT");
}
print   {
    token("PRINT");
}
println   {
    token("PRINTLN");
}
repeat   {
    token("REPEAT");
}
return   {
    token("RETURN");
}
string   {
    token("STRING");
}
to   {
    token("TO");
}
true   {
    token("TRUE");
}
type   {
    token("TYPE");
}
val   {
    token("VAL");
}
var   {
    token("VAR");
}
while   {
    token("WHILE");
}

 /* operators */
{operators} {
    tokenString("operators",yytext);
}

 /* delimiters */
{delimiters} {
    token(yytext);
    // tokenString("delimiters",yytext);
}

 /* Real Constants and  Integer Constants */
{integer} {
    int tmp;
    sscanf(yytext,"%d",&tmp);
    tokenInteger("integer",tmp);
}
{realconstants} {
    double tmp;
    sscanf(yytext,"%lf",&tmp);
    tokenDouble("realconstants",tmp);

}
 /* boolean */
{boolean} {
    tokenString("boolean",yytext);
}

 /* identifiers */
{identifiers} {
    tokenString("id",yytext);
    insert(yytext,symboltable);
}

{char} {
    LIST;
    printf("get char %c \n",yytext[1]);
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
        // printf("yytext : %s\n",yytext);
        // printf("yyleng : %lu\n",(yyleng));
        strcpy(tmp,yytext);
        // printf("tmp : %s\n",tmp);
        // printf("tmp len = %lu\n",strlen(tmp));
        // printf("tmp len = %lu \n",sizeof(tmp));

        // 消除字串中的"" 把它變成"
        for(int i=0;i< strlen(tmp);i++){
            if(tmp[i]=='"' && i!= strlen(tmp)-1 && i!=0){
                // printf("tmp : %s\n",tmp);
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
                // new_tmp[strlen(tmp-1)] = 0;
                tmp = new_tmp;
                // printf("tmp len = %zu \n",strlen(tmp));
                // free(left);
                // free(right);
                // printf("tmp : %s\n",tmp);

            }
        }
        // printf("tmp : %s\n",tmp)
        // printf("tmp len = %zu \n",strlen(tmp));
        char *result = (char *)malloc(sizeof(char)*(strlen(tmp)-2));
        strncpy(result,tmp+1, sizeof(char)*(strlen(tmp)-2));
        // printf(" reuslt :%s\n",result);
        tokenString("strings",result);
        unput(ch);
        free(tmp);
    }
}

\n      {
        LIST;
        printf("%d: %s", linenum++, buf);
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

// 創立hash表，提供指定size 若size滿了，用lin list串起來
SymbolTable * create(int size){
    SymbolTable *new_symboltable = NULL;
    if (size < 1){
        return NULL;
    }
	if((new_symboltable = malloc(sizeof( SymbolTable))) == NULL) {
		return NULL;
	}
	if((new_symboltable->table = malloc(sizeof(SymbolNode*) * size)) == NULL ) {
		return NULL;
	}
    // 先把每個bucket內的head設為node
	for(int i = 0; i < size; i++ ) {
		new_symboltable->table[i] = NULL;
	}
	new_symboltable->size = size;
	return new_symboltable;
}
// hash function 
unsigned int hash(char *key,SymbolTable* symboltable){
    unsigned long long int hashval = 0;
    int i = 0;
	while( hashval < ULONG_MAX && i < strlen( key ) ) {
		hashval = hashval << 8;
		hashval += key[i];
		i++;
	}
    //printf("now hashing key: %s, key length: %d,result: %d\n",key,strlen(key),hashval % symboltable->size);
    return hashval % symboltable->size;
}

// 查找key(及變數名字)
int lookup(char* key, SymbolTable* symboltable){
    unsigned int idx = hash(key,symboltable);
    SymbolNode * curr = symboltable->table[idx];
    while(1){
        if(curr==NULL){
            break;
        }
        // 一樣即return 1
        if(strcmp(curr->key,key)==0){
                // key same dont need to create new noed
                return 1;
        }
        else{
            curr = curr->next;
        }
    }
    // 找不到

    return 0;
}
// insert node to table
int insert(char* key,SymbolTable* symboltable){
    unsigned int idx = hash(key,symboltable);
    SymbolNode * curr = symboltable->table[idx];
    if(curr == NULL){
        // 這條目前是空的，可以直接新增在第一個
        SymbolNode *newnode = malloc(sizeof(SymbolNode));
        //newnode->key = malloc(yyleng+1);
        newnode->key = malloc(sizeof(char)*strlen(key));
        strcpy(newnode->key,key);
        newnode->prev = NULL;
        newnode->next = NULL;
        symboltable->table[idx] = newnode;
        return 1;
    }
    else{
        SymbolNode *prev = NULL;
        while(1){
            if(curr == NULL){
                break;
            }
            if(strcmp(curr->key,key)==0){
                // key same dont need to create new noed
                return 0;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        // 都不存在在table內創一個新的
        SymbolNode *newnode = malloc(sizeof(SymbolNode));
        //newnode->key = malloc(yyleng+1);
        newnode->key = malloc(sizeof(char)*strlen(key));
        strcpy(newnode->key,key);
        newnode->next = NULL;
        newnode->prev = prev;
        prev->next = newnode;
        return 1;
    }
}
// print symbol table
void dump(SymbolTable* symboltable){
    printf("dump symboltable:\n");
    for(int i=0;i<symboltable->size;++i){
        SymbolNode* curr = symboltable->table[i];
        if(curr==NULL){
            continue;
        }
        while(1){
            if(curr==NULL){
                break;
            }
            else{
                printf("%s ",curr->key);
                curr = curr->next;
            }
        }
        printf("\n");
    }
}

int main(int argc, char ** argv) { 
    symboltable = create(5);
    if(argc>1){
        yyin = fopen(argv[1],"r");
        if(!yyin){
            printf("file open error\n");
            exit(-1);
        }
    }
    else{
        yyin = stdin;
    }
    yylex();
    printf("\n");
    dump(symboltable);
}