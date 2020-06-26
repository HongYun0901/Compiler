/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SEMICOLON = 258,
     BOOLEAN = 259,
     BREAK = 260,
     CHAR = 261,
     CASE = 262,
     CLASS = 263,
     CONTINUE = 264,
     DEF = 265,
     DO = 266,
     ELSE = 267,
     EXIT = 268,
     FALSE = 269,
     FLOAT = 270,
     FOR = 271,
     IF = 272,
     INT = 273,
     _NULL = 274,
     OBJECT = 275,
     PRINT = 276,
     PRINTLN = 277,
     READ = 278,
     REPEAT = 279,
     RETURN = 280,
     STRING = 281,
     TO = 282,
     TRUE = 283,
     TYPE = 284,
     VAL = 285,
     VAR = 286,
     WHILE = 287,
     ASSIGN = 288,
     BOOL_VALUE = 289,
     INT_VALUE = 290,
     STRING_VALUE = 291,
     FLOAT_VALUE = 292,
     ID = 293,
     CHAR_VALUE = 294,
     OR_OP = 295,
     AND_OP = 296,
     NOT = 297,
     NE = 298,
     GE = 299,
     GT = 300,
     EQ = 301,
     LE = 302,
     LT = 303,
     UMINUS = 304
   };
#endif
/* Tokens.  */
#define SEMICOLON 258
#define BOOLEAN 259
#define BREAK 260
#define CHAR 261
#define CASE 262
#define CLASS 263
#define CONTINUE 264
#define DEF 265
#define DO 266
#define ELSE 267
#define EXIT 268
#define FALSE 269
#define FLOAT 270
#define FOR 271
#define IF 272
#define INT 273
#define _NULL 274
#define OBJECT 275
#define PRINT 276
#define PRINTLN 277
#define READ 278
#define REPEAT 279
#define RETURN 280
#define STRING 281
#define TO 282
#define TRUE 283
#define TYPE 284
#define VAL 285
#define VAR 286
#define WHILE 287
#define ASSIGN 288
#define BOOL_VALUE 289
#define INT_VALUE 290
#define STRING_VALUE 291
#define FLOAT_VALUE 292
#define ID 293
#define CHAR_VALUE 294
#define OR_OP 295
#define AND_OP 296
#define NOT 297
#define NE 298
#define GE 299
#define GT 300
#define EQ 301
#define LE 302
#define LT 303
#define UMINUS 304




/* Copy the first part of user declarations.  */
#line 1 "yacc.y"

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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 46 "yacc.y"
{
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
/* Line 193 of yacc.c.  */
#line 252 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 265 "y.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   298

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    53,     2,     2,
      57,    58,    51,    49,    55,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    56,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,     8,    13,    14,    18,    20,
      24,    25,    26,    27,    38,    39,    42,    43,    49,    50,
      54,    56,    58,    61,    63,    65,    67,    69,    71,    73,
      74,    79,    82,    85,    86,    90,    95,   102,   107,   112,
     119,   127,   130,   132,   136,   143,   144,   148,   149,   153,
     156,   159,   161,   165,   167,   170,   172,   176,   180,   184,
     188,   192,   196,   200,   204,   208,   212,   216,   220,   224,
     227,   232,   234,   236,   238,   240,   242,   244,   246,   248,
     250,   252,   254,   256,   259,   260,   261,   268,   269,   278,
     279,   283,   286,   288,   290,   293,   295,   296,   297,   305,
     308,   310,   311,   312
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    65,    64,    -1,    -1,    -1,    20,    38,
      66,    83,    -1,    -1,    68,    55,    67,    -1,    68,    -1,
      38,    56,    90,    -1,    -1,    -1,    -1,    10,    38,    70,
      57,    67,    71,    58,    73,    72,    80,    -1,    -1,    56,
      90,    -1,    -1,    38,    75,    57,    76,    58,    -1,    -1,
      89,    55,    76,    -1,    89,    -1,    78,    -1,    78,    77,
      -1,    80,    -1,    95,    -1,    99,    -1,    86,    -1,    85,
      -1,    84,    -1,    -1,    59,    81,    77,    60,    -1,    69,
      82,    -1,    79,    82,    -1,    -1,    59,    82,    60,    -1,
      30,    38,    33,    89,    -1,    30,    38,    56,    90,    33,
      89,    -1,    31,    38,    33,    89,    -1,    31,    38,    56,
      90,    -1,    31,    38,    56,    90,    33,    89,    -1,    31,
      38,    56,    90,    61,    35,    62,    -1,    31,    38,    -1,
      79,    -1,    38,    33,    89,    -1,    38,    61,    89,    62,
      33,    89,    -1,    -1,    21,    87,    89,    -1,    -1,    22,
      88,    89,    -1,    23,    38,    -1,    25,    89,    -1,    25,
      -1,    57,    89,    58,    -1,    38,    -1,    50,    89,    -1,
      74,    -1,    89,    49,    89,    -1,    89,    50,    89,    -1,
      89,    51,    89,    -1,    89,    52,    89,    -1,    89,    53,
      89,    -1,    89,    40,    89,    -1,    89,    41,    89,    -1,
      89,    48,    89,    -1,    89,    47,    89,    -1,    89,    46,
      89,    -1,    89,    45,    89,    -1,    89,    44,    89,    -1,
      89,    43,    89,    -1,    42,    89,    -1,    38,    61,    89,
      62,    -1,    91,    -1,     6,    -1,    26,    -1,    18,    -1,
       4,    -1,    15,    -1,    36,    -1,    35,    -1,    34,    -1,
      37,    -1,    39,    -1,    80,    -1,    93,    86,    -1,    -1,
      -1,    17,    57,    89,    58,    94,    92,    -1,    -1,    17,
      57,    89,    58,    94,    92,    96,    97,    -1,    -1,    12,
      98,    95,    -1,    12,    92,    -1,   101,    -1,   105,    -1,
      93,    86,    -1,    80,    -1,    -1,    -1,    32,   102,    57,
      89,    58,   103,   100,    -1,    93,    86,    -1,    80,    -1,
      -1,    -1,    16,    57,    38,   106,    48,    50,    89,    27,
      89,    58,   107,   104,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   137,   140,   140,   179,   186,   192,   201,
     220,   233,   237,   220,   296,   299,   306,   306,   353,   358,
     363,   372,   373,   377,   378,   379,   380,   384,   385,   391,
     391,   412,   413,   414,   417,   421,   433,   447,   468,   492,
     518,   525,   546,   547,   588,   611,   611,   616,   616,   622,
     623,   627,   636,   639,   705,   725,   726,   755,   785,   815,
     844,   872,   889,   907,   934,   964,   996,  1024,  1051,  1083,
    1102,  1125,  1133,  1136,  1139,  1143,  1147,  1153,  1158,  1163,
    1168,  1172,  1182,  1189,  1196,  1200,  1221,  1233,  1233,  1254,
    1254,  1257,  1276,  1277,  1280,  1286,  1294,  1311,  1294,  1337,
    1357,  1379,  1400,  1379
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "BOOLEAN", "BREAK", "CHAR",
  "CASE", "CLASS", "CONTINUE", "DEF", "DO", "ELSE", "EXIT", "FALSE",
  "FLOAT", "FOR", "IF", "INT", "_NULL", "OBJECT", "PRINT", "PRINTLN",
  "READ", "REPEAT", "RETURN", "STRING", "TO", "TRUE", "TYPE", "VAL", "VAR",
  "WHILE", "ASSIGN", "BOOL_VALUE", "INT_VALUE", "STRING_VALUE",
  "FLOAT_VALUE", "ID", "CHAR_VALUE", "OR_OP", "AND_OP", "NOT", "NE", "GE",
  "GT", "EQ", "LE", "LT", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS",
  "','", "':'", "'('", "')'", "'{'", "'}'", "'['", "']'", "$accept",
  "PROGRAM", "OBJECT_DECLARE", "@1", "ARGS", "ARG", "FUNCTION", "@2", "@3",
  "@4", "FUNCTION_OPTIONAL", "FUNCTION_INVOCATION", "@5", "COMMA_SEP_EXPR",
  "STMTS", "STMT", "V_DECLARE", "BLOCK", "@6", "OBJ_CONTENTS", "OBJ_BLOCK",
  "VAL_DECLARE", "VAR_DECLARE", "SIMPLE_STMT", "@7", "@8", "EXPR",
  "DATA_TYPE", "VALUE", "BLOCK_OR_SIMPLE", "PUSH", "if_dosomething",
  "IF_STMT", "@9", "ELSEIF_STMT", "@10", "LOOP_STMT",
  "while_block_or_simplestmt", "WHILE_STMT", "@11", "@12",
  "for_block_or_simplestmt", "FOR_STMT", "@13", "@14", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    43,
      45,    42,    47,    37,   304,    44,    58,    40,    41,   123,
     125,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    66,    65,    67,    67,    67,    68,
      70,    71,    72,    69,    73,    73,    75,    74,    76,    76,
      76,    77,    77,    78,    78,    78,    78,    79,    79,    81,
      80,    82,    82,    82,    83,    84,    84,    85,    85,    85,
      85,    85,    86,    86,    86,    87,    86,    88,    86,    86,
      86,    86,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    91,    91,    91,
      91,    91,    92,    92,    93,    94,    95,    96,    95,    98,
      97,    97,    99,    99,   100,   100,   102,   103,   101,   104,
     104,   106,   107,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     0,     4,     0,     3,     1,     3,
       0,     0,     0,    10,     0,     2,     0,     5,     0,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     0,
       4,     2,     2,     0,     3,     4,     6,     4,     4,     6,
       7,     2,     1,     3,     6,     0,     3,     0,     3,     2,
       2,     1,     3,     1,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     0,     6,     0,     8,     0,
       3,     2,     1,     1,     2,     1,     0,     0,     7,     2,
       1,     0,     0,    12
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     3,     4,     1,     2,     0,    33,     5,
       0,     0,     0,    33,    33,     0,    28,    27,    10,     0,
      41,    31,    32,    34,     0,     0,     0,     0,     0,     6,
      79,    78,    77,    80,    53,    81,     0,     0,     0,    55,
      35,    71,    75,    72,    76,    74,    73,     0,    37,    38,
       0,    11,     8,     0,     0,    69,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     0,    18,    52,
      61,    62,    68,    67,    66,    65,    64,    63,    56,    57,
      58,    59,    60,    36,    39,     0,     9,    14,     7,    70,
       0,    20,    40,     0,    12,    17,    18,    15,     0,    19,
      29,    13,     0,     0,     0,    45,    47,     0,    51,    96,
       0,     0,    21,    42,    23,    26,    24,    25,    92,    93,
       0,     0,     0,     0,    49,    50,     0,     0,     0,    30,
      22,   101,     0,    46,    48,     0,    43,     0,     0,    85,
       0,     0,     0,    84,    97,     0,     0,    82,    86,     0,
      84,    44,     0,     0,    83,    95,     0,    98,     0,    84,
      88,    94,     0,    91,     0,   102,    90,    84,   100,     0,
     103,    99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    51,    52,    13,    24,    75,   108,
     104,    39,    54,   100,   121,   122,   123,   124,   112,    15,
       9,    16,    17,   125,   132,   133,   101,    47,    41,   158,
     159,   153,   126,   163,   170,   174,   127,   167,   128,   136,
     160,   180,   129,   148,   177
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -156
static const yytype_int16 yypact[] =
{
     -12,    -6,    56,   -12,  -156,  -156,  -156,    -2,    -4,  -156,
      37,    39,    42,    -4,    -4,    11,  -156,  -156,  -156,    18,
      20,  -156,  -156,  -156,    30,    31,   110,    31,   110,    52,
    -156,  -156,  -156,  -156,   -40,  -156,    31,    31,    31,  -156,
     221,  -156,  -156,  -156,  -156,  -156,  -156,    72,   221,   -32,
      53,  -156,    34,    31,    54,   245,  -156,   141,    31,    31,
      31,    31,    31,    31,    31,    31,    31,    31,    31,    31,
      31,    31,    31,    75,   110,    65,    52,   101,    31,  -156,
     234,   245,    33,    33,    33,    33,    33,    33,    10,    10,
    -156,  -156,  -156,   221,   221,    62,  -156,    73,  -156,  -156,
      74,   205,  -156,   110,  -156,  -156,    31,  -156,    78,  -156,
    -156,  -156,    -7,    76,    81,  -156,  -156,   102,    31,  -156,
      -3,    79,    -7,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
     117,    31,    31,    31,  -156,   221,    99,    31,    31,  -156,
    -156,  -156,   157,   221,   221,    31,   221,   121,   109,  -156,
     173,   125,   126,    78,  -156,    31,    31,  -156,   147,    96,
      78,   221,    51,   148,  -156,  -156,    96,  -156,    31,   -10,
    -156,  -156,   189,  -156,   158,  -156,  -156,    78,  -156,    96,
    -156,  -156
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,   174,  -156,  -156,   103,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,    89,    58,  -156,    46,  -105,  -156,     6,
    -156,  -156,  -156,   -44,  -156,  -156,   -25,   -24,  -156,     9,
    -155,  -156,    22,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -90
static const yytype_int16 yytable[] =
{
      40,    72,    48,   111,    49,   166,    10,   -89,     1,   113,
     114,    55,    56,    57,   115,   116,   117,   -16,   118,    21,
      22,    53,   179,    11,    12,   119,    11,    12,    77,    73,
     137,   120,     4,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,   157,   110,
      96,    25,   110,    27,    14,   165,     5,     8,   138,    14,
      14,    68,    69,    70,   157,    30,    31,    32,    33,    34,
      35,    23,   178,    36,    26,    18,    28,    19,   168,   107,
      20,    37,    66,    67,    68,    69,    70,    29,    38,    76,
      50,    58,    59,   135,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,   142,   143,   144,    74,
      95,    78,   146,   147,    42,   164,    43,   115,   116,   117,
     150,   118,   171,    97,   102,    44,    11,    12,    45,   103,
     161,   162,   105,   130,   120,   181,    46,   110,   131,   139,
     134,    58,    59,   172,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,   141,   145,   152,   155,   -87,
     169,    58,    59,    99,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,   114,   156,     6,   173,    98,
     140,    58,    59,   151,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,   109,   176,    58,    59,    79,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,    58,    59,   149,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,     0,    58,
      59,   154,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,    58,    59,   175,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
     106,    58,    59,     0,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    59,     0,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
      25,    33,    27,   108,    28,   160,    10,    17,    20,    16,
      17,    36,    37,    38,    21,    22,    23,    57,    25,    13,
      14,    61,   177,    30,    31,    32,    30,    31,    53,    61,
      33,    38,    38,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,   153,    59,
      74,    33,    59,    33,     8,   160,     0,    59,    61,    13,
      14,    51,    52,    53,   169,    34,    35,    36,    37,    38,
      39,    60,   177,    42,    56,    38,    56,    38,    27,   103,
      38,    50,    49,    50,    51,    52,    53,    57,    57,    55,
      38,    40,    41,   118,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    33,   131,   132,   133,    56,
      35,    57,   137,   138,     4,   159,     6,    21,    22,    23,
     145,    25,   166,    58,    62,    15,    30,    31,    18,    56,
     155,   156,    58,    57,    38,   179,    26,    59,    57,    60,
      38,    40,    41,   168,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    38,    57,    48,    33,    12,
      12,    40,    41,    62,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    17,    50,     3,   169,    76,
     122,    40,    41,    62,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,   106,   174,    40,    41,    58,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    -1,    40,    41,    58,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    40,
      41,    58,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    -1,    40,    41,    58,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    40,    41,    -1,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    64,    65,    38,     0,    64,    66,    59,    83,
      10,    30,    31,    69,    79,    82,    84,    85,    38,    38,
      38,    82,    82,    60,    70,    33,    56,    33,    56,    57,
      34,    35,    36,    37,    38,    39,    42,    50,    57,    74,
      89,    91,     4,     6,    15,    18,    26,    90,    89,    90,
      38,    67,    68,    61,    75,    89,    89,    89,    40,    41,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    33,    33,    61,    56,    71,    55,    89,    57,    58,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    35,    90,    58,    67,    62,
      76,    89,    62,    56,    73,    58,    55,    90,    72,    76,
      59,    80,    81,    16,    17,    21,    22,    23,    25,    32,
      38,    77,    78,    79,    80,    86,    95,    99,   101,   105,
      57,    57,    87,    88,    38,    89,   102,    33,    61,    60,
      77,    38,    89,    89,    89,    57,    89,    89,   106,    58,
      89,    62,    48,    94,    58,    33,    50,    80,    92,    93,
     103,    89,    89,    96,    86,    80,    93,   100,    27,    12,
      97,    86,    89,    92,    98,    58,    95,   107,    80,    93,
     104,    86
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 140 "yacc.y"
    {
            Trace("declare an id to objet type");
            tables.push();
            int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (2)].stringval),objectType);
            if(result == -1){
                yyerror(*(yyvsp[(2) - (2)].stringval) + " already exists");
            }
            className = *(yyvsp[(2) - (2)].stringval);
            jbfile << "class " << *(yyvsp[(2) - (2)].stringval) << "{"  << endl; 
        
        }
    break;

  case 5:
#line 150 "yacc.y"
    {
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


        }
    break;

  case 6:
#line 179 "yacc.y"
    {
           Trace("ARGS empty");
           vector<pair<string,int>*>* buf = new vector<pair<string,int>*>();
           buf->clear(); 
           (yyval.argumentsInfo) = buf;

       }
    break;

  case 7:
#line 186 "yacc.y"
    {
         Trace("ARG , ARGS");  
         (yyval.argumentsInfo) = (yyvsp[(3) - (3)].argumentsInfo);
        (yyval.argumentsInfo)->push_back((yyvsp[(1) - (3)].argumentInfo));

       }
    break;

  case 8:
#line 192 "yacc.y"
    {
           Trace("ARG");
           vector<pair<string,int>*>* buf = new vector<pair<string,int>*>();
           (yyval.argumentsInfo) = buf;
           (yyval.argumentsInfo)->push_back((yyvsp[(1) - (1)].argumentInfo));
           
       }
    break;

  case 9:
#line 201 "yacc.y"
    {
        Trace("ID : DataType");
        cout << "when arg table top is" << tables.top << endl;
        int result = tables.vec[tables.top].insert(*(yyvsp[(1) - (3)].stringval),variableType,(yyvsp[(3) - (3)].valueType));
        if(result == -1){
            yyerror("id has been used");
        }
        idInfo* id = tables.lookup(*(yyvsp[(1) - (3)].stringval));
        id->stackID = varStackID++;
        pair<string,int>* p = new pair<string,int>();
        p->first = *(yyvsp[(1) - (3)].stringval);
        p->second = (yyvsp[(3) - (3)].valueType);
        (yyval.argumentInfo) = p;
    }
    break;

  case 10:
#line 220 "yacc.y"
    {
            Trace("create an function id");
            int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (2)].stringval),functionType);
            if(result == -1){
                yyerror(*(yyvsp[(2) - (2)].stringval) + " already exists");
                *(yyvsp[(2) - (2)].stringval) = *(yyvsp[(2) - (2)].stringval) + "(error)";
                tables.vec[tables.top].insert(*(yyvsp[(2) - (2)].stringval),functionType);
            }
            cout << "method id is " << *(yyvsp[(2) - (2)].stringval) << endl;
            tables.push();
            returnFlag = false;
            varStackID = 0;

        }
    break;

  case 11:
#line 233 "yacc.y"
    {
            idInfo *id = tables.lookup(*(yyvsp[(2) - (5)].stringval));
            id->argumentsInfoSeq = *(yyvsp[(5) - (5)].argumentsInfo);
            id->argumentsInfo = tables.vec[tables.top].idMap;
        }
    break;

  case 12:
#line 237 "yacc.y"
    {
            idInfo *id = tables.lookup(*(yyvsp[(2) - (8)].stringval));
            id->returnType = (yyvsp[(8) - (8)].valueType);

            if(*(yyvsp[(2) - (8)].stringval) == "main"){
                jbfile << "\tmethod public static void main(java.lang.String[])" << endl;
                jbfile << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl;
                jbfile << "\t{" << endl;
            }
            else{
                if(id->returnType == unknownType){
                    jbfile << "\tmethod public static void " << *(yyvsp[(2) - (8)].stringval);
                }
                else{
                    jbfile << "\tmethod public static " << valueType2Str((yyvsp[(8) - (8)].valueType)) << " " <<  *(yyvsp[(2) - (8)].stringval);
                }
                    if((yyvsp[(5) - (8)].argumentsInfo)->size() == 0){
                        jbfile << "()" << endl;
                    }
                    else{
                        jbfile << "(";
                        for(int i=(yyvsp[(5) - (8)].argumentsInfo)->size()-1;i>=0;--i){
                            if(i == (yyvsp[(5) - (8)].argumentsInfo)->size()-1){
                                jbfile << valueType2Str((*(yyvsp[(5) - (8)].argumentsInfo))[i]->second);
                            }
                            else{
                                jbfile << "," <<  valueType2Str((*(yyvsp[(5) - (8)].argumentsInfo))[i]->second);
                            }
                        }
                        jbfile << ")" << endl;

                    }
                    jbfile << "\tmax_stack 15" << endl << "\tmax_locals 15" << endl; 
                    jbfile << "\t{" << endl;
            }

            

        }
    break;

  case 13:
#line 275 "yacc.y"
    {
            Trace("declare method end");
            idInfo *id = tables.lookup(*(yyvsp[(2) - (10)].stringval));
            for(int i = 0; i < (yyvsp[(5) - (10)].argumentsInfo)->size(); ++i){
                cout << "id : " << (*(yyvsp[(5) - (10)].argumentsInfo))[i]->first << " type : " << valueType2Str((*(yyvsp[(5) - (10)].argumentsInfo))[i]->second) << endl;
            }

            tables.functionSymbolTables[*(yyvsp[(2) - (10)].stringval)] = tables.vec[tables.top];
            tables.pop(); 
            methodNumCount ++ ;

            if((yyvsp[(8) - (10)].valueType) == unknownType && !returnFlag){
                jbfile << "\t\treturn" << endl;
            }
            jbfile << "\t}" << endl;
            
        }
    break;

  case 14:
#line 296 "yacc.y"
    {
                    (yyval.valueType) = unknownType;
                  }
    break;

  case 15:
#line 299 "yacc.y"
    {
                    (yyval.valueType) = (yyvsp[(2) - (2)].valueType);
                    Trace(": DataType");
                  }
    break;

  case 16:
#line 306 "yacc.y"
    {
                        // tables.push(tables.functionSymbolTables[*$1]);
                    }
    break;

  case 17:
#line 308 "yacc.y"
    {
                        Trace("call function invocation");
                    
                        idInfo* id = tables.lookup(*(yyvsp[(1) - (5)].stringval));
                        //cout << "after lookup " <<  id->id << " address " << &id << " " << tables.top << endl;
                        if(id == NULL){
                            yyerror(*(yyvsp[(1) - (5)].stringval) + "doesn't exist");
                        }
                        if(id->idType != functionType){
                            yyerror(*(yyvsp[(1) - (5)].stringval) + "is not a function");
                        }
                        cout << "parameter nums : " << (yyvsp[(4) - (5)].valueInfoVec)->size() << endl;
                        for(int i = 0; i < (yyvsp[(4) - (5)].valueInfoVec)->size(); ++i){
                            cout << "type : " << valueType2Str((*(yyvsp[(4) - (5)].valueInfoVec))[i]->valueType) << endl;
                        }

                        // cout << $4->size() << " " << id->argumentsInfoSeq.size() << endl;
                        // check parameter is same as declared 
                        if((yyvsp[(4) - (5)].valueInfoVec)->size() != id->argumentsInfo.size()){
                            yyerror("parameter nums error");
                        }
                        // check type
                        for(int i = 0; i < (yyvsp[(4) - (5)].valueInfoVec)->size(); ++i){
                            if((*(yyvsp[(4) - (5)].valueInfoVec))[i]->valueType!= id->argumentsInfoSeq[i]->second){
                                yyerror("parameter type error");
                            }
                        }
                        (yyval.value) = new valueInfo();
                        (yyval.value)->valueType = id->returnType;
                        jbfile << "\t\tinvokestatic int " << className << "." << *(yyvsp[(1) - (5)].stringval) << "(" ;

                        for(int i=(yyvsp[(4) - (5)].valueInfoVec)->size()-1;i>=0;--i){
                            if(i == (yyvsp[(4) - (5)].valueInfoVec)->size()-1){
                                jbfile << valueType2Str((*(yyvsp[(4) - (5)].valueInfoVec))[i]->valueType);
                            }
                            else{
                                jbfile << "," <<  valueType2Str((*(yyvsp[(4) - (5)].valueInfoVec))[i]->valueType);
                            }
                        }
                        jbfile << ")" << endl;
                        
                        
                    }
    break;

  case 18:
#line 353 "yacc.y"
    {
                    Trace("check arugment start");
                    vector<valueInfo*>* buf = new vector<valueInfo*>();
                    (yyval.valueInfoVec) = buf;
                }
    break;

  case 19:
#line 358 "yacc.y"
    {
                   Trace("checking argument...");
                   (yyvsp[(3) - (3)].valueInfoVec)->push_back((yyvsp[(1) - (3)].value));
                   (yyval.valueInfoVec) = (yyvsp[(3) - (3)].valueInfoVec);
               }
    break;

  case 20:
#line 363 "yacc.y"
    {
                   Trace("check arugment start");
                    vector<valueInfo*>* buf = new vector<valueInfo*>();
                    buf->push_back((yyvsp[(1) - (1)].value));
                    (yyval.valueInfoVec) = buf;
               }
    break;

  case 29:
#line 391 "yacc.y"
    {
        Trace("BLOCK START");
        tables.push();
      }
    break;

  case 30:
#line 395 "yacc.y"
    {
          Trace("BLOCK END");
            (yyval.idMap) =  new map<string,idInfo*>();
          *(yyval.idMap) = tables.vec[tables.top].idMap;
            // tables.dump();
          if(tables.pop() == -1){
              yyerror("symbol table error");
          }
      }
    break;

  case 35:
#line 421 "yacc.y"
    {
                Trace("VAL ID ASSIGN EXPR");
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (4)].stringval),constType,(yyvsp[(4) - (4)].value));
                if(result == -1){
                    yyerror("id has been used");
                }

                idInfo *id = tables.lookup(*(yyvsp[(2) - (4)].stringval));

                id->value = (yyvsp[(4) - (4)].value);

            }
    break;

  case 36:
#line 433 "yacc.y"
    {
                Trace("VAL ID : DATA_TYPE ASSIGN EXPR");
                if((yyvsp[(4) - (6)].valueType) != (yyvsp[(6) - (6)].value)->valueType){
                    yyerror("data type and value type doesn't match");
                }
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (6)].stringval),constType,(yyvsp[(6) - (6)].value));
                if(result == -1){
                    yyerror("id has been used");
                }

                idInfo *id = tables.lookup(*(yyvsp[(2) - (6)].stringval));
                id->value = (yyvsp[(6) - (6)].value);
            }
    break;

  case 37:
#line 447 "yacc.y"
    {
                Trace("VAR ID ASSIGN EXPR");
                // declare var with value
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (4)].stringval),variableType,(yyvsp[(4) - (4)].value));
                if(result == -1){
                    yyerror("id has been used");
                }
                idInfo* id = tables.lookup(*(yyvsp[(2) - (4)].stringval));
                

                if(tables.top == GLOBAL){
                    jbGlobalVar(*(yyvsp[(2) - (4)].stringval));
                    jbfile << "\t\tputstatic int " << className << "." << *(yyvsp[(2) - (4)].stringval) << endl;

                }
                else{
                    id->stackID = varStackID;
                    jbStore(varStackID++);
                }

            }
    break;

  case 38:
#line 468 "yacc.y"
    {
                Trace("VAR ID ':' DATA_TYPE");
                // declare var but only have type
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (4)].stringval),variableType,(yyvsp[(4) - (4)].valueType));

                idInfo* id = tables.lookup(*(yyvsp[(2) - (4)].stringval));

                if(result == -1){
                    yyerror("id has been used");
                }


                if(tables.top == GLOBAL){
                    jbGlobalVar(*(yyvsp[(2) - (4)].stringval));
                }
                else{
                    jbPushInt(0);
                    id->stackID = varStackID;
                    jbStore(varStackID++);
                }



            }
    break;

  case 39:
#line 492 "yacc.y"
    {
                Trace("VAR ID : DATA_TYPE ASSIGN EXPR");
                if((yyvsp[(6) - (6)].value)->valueType == unknownType){
                     Warning("unknownType!!!!");
                }
                else if((yyvsp[(4) - (6)].valueType) != (yyvsp[(6) - (6)].value)->valueType){
                    yyerror("data type and value type doesn't match");
                }
                // declare var with sepcific data type and value
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (6)].stringval),variableType,(yyvsp[(6) - (6)].value));
                if(result == -1){
                    yyerror("id has been used");
                }
                idInfo* id = tables.lookup(*(yyvsp[(2) - (6)].stringval));
            

                if(tables.top == GLOBAL){
                    jbGlobalVar(*(yyvsp[(2) - (6)].stringval));
                    jbfile << "\t\tputstatic int " << className << "." << *(yyvsp[(2) - (6)].stringval) << endl;

                }
                else{
                    id->stackID = varStackID;
                    jbStore(varStackID++);
                }
            }
    break;

  case 40:
#line 518 "yacc.y"
    {
                Trace("VAR ID : DATA_TYPE [ INT_VALUE ]");
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (7)].stringval),arrayType,(yyvsp[(4) - (7)].valueType),(yyvsp[(6) - (7)].intval));
                if(result == -1){
                    yyerror("id has been used");
                }
            }
    break;

  case 41:
#line 525 "yacc.y"
    {
                Trace("VAR ID");
                // declare unknownType var
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (2)].stringval),variableType,unknownType);
                if(result == -1){
                    yyerror("id has been used");
                }
                idInfo* id = tables.lookup(*(yyvsp[(2) - (2)].stringval));
                if(tables.top == GLOBAL){
                    jbGlobalVar(*(yyvsp[(2) - (2)].stringval));
                }
                else{
                    jbPushInt(0);
                    id->stackID = varStackID;
                    jbStore(varStackID++);
                }
            }
    break;

  case 43:
#line 547 "yacc.y"
    {
                Trace("ID ASSIGN EXPR");
                idInfo* buf = tables.lookup(*(yyvsp[(1) - (3)].stringval));
                if(buf == NULL){
                    yyerror(*(yyvsp[(1) - (3)].stringval) + " doesn't exist");
                }

                if(buf->idType != variableType){
                    yyerror(*(yyvsp[(1) - (3)].stringval) + " can not be assign");
                }
                if(buf->hasInit){
                    if((yyvsp[(3) - (3)].value)->valueType == intType && buf->value->valueType == floatType){
                        *(buf->value) = *(yyvsp[(3) - (3)].value);
                    }
                    else if((yyvsp[(3) - (3)].value)->valueType == floatType && buf->value->valueType == intType){
                        *(buf->value) = *(yyvsp[(3) - (3)].value);
                    }
                    else if((yyvsp[(3) - (3)].value)->valueType == unknownType){
                        Warning("unknownType!!!");
                    }
                    else if(buf->value->valueType != (yyvsp[(3) - (3)].value)->valueType){
                        yyerror(*(yyvsp[(1) - (3)].stringval) + " already assigen other data type");
                    }
                    *(buf->value) = *(yyvsp[(3) - (3)].value);
                }
                else{
                    buf->value = new valueInfo();
                    *(buf->value) = *(yyvsp[(3) - (3)].value);
                    buf->hasInit = true;
                }
                
                if(buf->stackID == -1){
                    jbfile << "\t\tputstatic int " << className << "." << *(yyvsp[(1) - (3)].stringval) << endl;
                }
                else{
                    jbfile << "\t\tistore " << buf->stackID << endl;
                }
                


            }
    break;

  case 44:
#line 588 "yacc.y"
    {
                Trace("ID '[' EXPR ']' ASSIGN EXPR");
                idInfo* buf = tables.lookup(*(yyvsp[(1) - (6)].stringval));
                if(buf == NULL){
                    yyerror("id does not exist");
                }
                if(buf->idType != arrayType){
                    yyerror(*(yyvsp[(1) - (6)].stringval) + " is not an array");
                }
                if((yyvsp[(3) - (6)].value)->valueType == unknownType){
                    Warning("unknownType!!!!");
                }
                else if((yyvsp[(3) - (6)].value)->valueType != intType){
                    yyerror("only can assess int index");
                }
                else if((yyvsp[(3) - (6)].value)->intval >= buf->arraySize || (yyvsp[(3) - (6)].value)->intval <0){
                    yyerror("access array out of range");
                }
                if(buf->arrayValueType != (yyvsp[(6) - (6)].value)->valueType){
                    yyerror("assign different value type in array");
                }
                
            }
    break;

  case 45:
#line 611 "yacc.y"
    {
                jbfile << "\t\tgetstatic java.io.PrintStream java.lang.System.out" << endl;
            }
    break;

  case 46:
#line 613 "yacc.y"
    {
                jbfile << "\t\tinvokevirtual void java.io.PrintStream.print(" << valueType2Str((yyvsp[(3) - (3)].value)->valueType) <<")" << endl;
            }
    break;

  case 47:
#line 616 "yacc.y"
    {
                jbfile << "\t\tgetstatic java.io.PrintStream java.lang.System.out" << endl;
            }
    break;

  case 48:
#line 618 "yacc.y"
    {
                jbfile << "\t\tinvokevirtual void java.io.PrintStream.println(" << valueType2Str((yyvsp[(3) - (3)].value)->valueType) <<")" << endl;

            }
    break;

  case 50:
#line 623 "yacc.y"
    {
                returnFlag = true;
                jbfile << "\t\tireturn" << endl; 
            }
    break;

  case 51:
#line 627 "yacc.y"
    {
                returnFlag = true;
                jbfile << "\t\treturn" << endl;
                
            }
    break;

  case 52:
#line 636 "yacc.y"
    {
        (yyval.value) = (yyvsp[(2) - (3)].value);
    }
    break;

  case 53:
#line 639 "yacc.y"
    {
        Trace("ID");
        idInfo* buf = tables.lookup(*(yyvsp[(1) - (1)].stringval));
        if( buf == NULL){
            yyerror("ID does not exist");
        }

        // if id is array 
        if(buf->idType == arrayType){
            yyerror(*(yyvsp[(1) - (1)].stringval) + " is array make grammar error");
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
            (yyval.value) = v;

        }
        // check has init or not
        else if(!buf->hasInit){
            Warning(*(yyvsp[(1) - (1)].stringval) + " may  has not been init");
        }
        if(buf->value == NULL){
            (yyval.value) = new valueInfo();
        }
        else{
            (yyval.value) = buf->value;
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
                    jbfile << "\t\tgetstatic int " << className << "." << *(yyvsp[(1) - (1)].stringval) << endl;
                }
                else{
                    jbLoad(buf->stackID);
                }

            }

            
            
        }
    }
    break;

  case 54:
#line 705 "yacc.y"
    {
        Trace("- EXPR")
        valueInfo* buf = new valueInfo();
        if ((yyvsp[(2) - (2)].value)->valueType == intType) {
            *buf = *(yyvsp[(2) - (2)].value);
            buf->intval = -1 * buf->intval;
        }
        else if((yyvsp[(2) - (2)].value)->valueType== floatType){
            *buf = *(yyvsp[(2) - (2)].value);
            buf->floatval = -1 * buf->floatval;
        }
        else if((yyvsp[(2) - (2)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("- EXPR type error");
        }
        (yyval.value) = buf;
        jbOperation('m');
    }
    break;

  case 56:
#line 726 "yacc.y"
    {
        Trace("EXPR + EXPR");
        valueInfo* buf = new valueInfo();
        if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->valueType = intType;
            buf->intval = ((yyvsp[(1) - (3)].value)->intval + (yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->valueType = floatType;
            //buf->floatval = ($1->floatval + (float)$3->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->valueType = floatType;
            //buf->floatval = ((float)$1->intval + $3->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->valueType = floatType;
            //buf->floatval = ($1->floatval + $3->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR + EXPR TYPE ERROR");
        }
        (yyval.value) = buf;
        jbOperation('+');
        
    }
    break;

  case 57:
#line 755 "yacc.y"
    {
        Trace("EXPR - EXPR");
        valueInfo* buf = new valueInfo();
        if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->valueType = intType;
            buf->intval = ((yyvsp[(1) - (3)].value)->intval - (yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->valueType = floatType;
            buf->floatval = ((yyvsp[(1) - (3)].value)->floatval - (float)(yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ((float)(yyvsp[(1) - (3)].value)->intval - (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ((yyvsp[(1) - (3)].value)->floatval - (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR - EXPR TYPE ERROR");
        }
        (yyval.value) = buf;
        jbOperation('-');


    }
    break;

  case 58:
#line 785 "yacc.y"
    {
        Trace("EXPR * EXPR");
        valueInfo* buf = new valueInfo();
        if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->valueType = intType;
            buf->intval = ((yyvsp[(1) - (3)].value)->intval * (yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->valueType = floatType;
            buf->floatval = ((yyvsp[(1) - (3)].value)->floatval * (float)(yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ((float)(yyvsp[(1) - (3)].value)->intval * (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ((yyvsp[(1) - (3)].value)->floatval * (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR * EXPR TYPE ERROR");
        }
        (yyval.value) = buf;
        jbOperation('*');


    }
    break;

  case 59:
#line 815 "yacc.y"
    {
        Trace("EXPR / EXPR");
        valueInfo* buf = new valueInfo();
        if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->valueType = intType;
            buf->intval = ((yyvsp[(1) - (3)].value)->intval / (yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->valueType = floatType;
            buf->floatval = ((yyvsp[(1) - (3)].value)->floatval / (float)(yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ((float)(yyvsp[(1) - (3)].value)->intval / (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ((yyvsp[(1) - (3)].value)->floatval / (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR / EXPR TYPE ERROR");
        }
        (yyval.value) = buf;
        jbOperation('/');

    }
    break;

  case 60:
#line 844 "yacc.y"
    {
        Trace("EXPR / EXPR");
        valueInfo* buf = new valueInfo();
        if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->valueType = intType;
            buf->intval = ((yyvsp[(1) - (3)].value)->intval % (yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->valueType = floatType;
            buf->floatval = fmod((double)(yyvsp[(1) - (3)].value)->floatval,(double)(yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = fmod((double)(yyvsp[(1) - (3)].value)->intval,(double)(yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = fmod((double)(yyvsp[(1) - (3)].value)->floatval,(double)(yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR / EXPR TYPE ERROR");
        }
        (yyval.value) = buf;

    }
    break;

  case 61:
#line 872 "yacc.y"
    {
        Trace("EXPR OR_OP EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if((yyvsp[(1) - (3)].value)->valueType!=boolType || (yyvsp[(3) - (3)].value)->valueType!=boolType){
            yyerror("EXPR OR_OP EXPR type must be bool");
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            buf->boolval = (yyvsp[(1) - (3)].value)->boolval || (yyvsp[(3) - (3)].value)->boolval;
        }
        (yyval.value) = buf;
        jbOperation('|');

    }
    break;

  case 62:
#line 889 "yacc.y"
    {
        Trace("EXPR AND_OP EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if((yyvsp[(1) - (3)].value)->valueType!=boolType || (yyvsp[(3) - (3)].value)->valueType!=boolType){
            yyerror("EXPR OR_OP EXPR type must be bool");
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            buf->boolval = (yyvsp[(1) - (3)].value)->boolval && (yyvsp[(3) - (3)].value)->boolval;
        }
        (yyval.value) = buf;
        jbOperation('&');


    }
    break;

  case 63:
#line 907 "yacc.y"
    {
        Trace("EXPR LT EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->intval < (yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->floatval < (float)(yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->boolval = ((float)(yyvsp[(1) - (3)].value)->intval < (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->floatval < (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR LT EXPR TYPE ERROR");
        }
        (yyval.value) = buf;
        jbLogicalOperation(IFLT);


    }
    break;

  case 64:
#line 934 "yacc.y"
    {
        Trace("EXPR LE EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->intval <= (yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->floatval <= (float)(yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->boolval = ((float)(yyvsp[(1) - (3)].value)->intval <= (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->floatval <= (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR LE EXPR TYPE ERROR");
        }
        (yyval.value) = buf;
        jbLogicalOperation(IFLE);


    }
    break;

  case 65:
#line 964 "yacc.y"
    {
        Trace("EXPR EQ EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if((yyvsp[(1) - (3)].value)->valueType != (yyvsp[(3) - (3)].value)->valueType){
            yyerror("EXPR EQ EXPR type mismatch");
        }
        else if((yyvsp[(1) - (3)].value)->valueType==intType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->intval == (yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->floatval == (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==boolType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->boolval == (yyvsp[(3) - (3)].value)->boolval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==stringType){
            buf->boolval = (*((yyvsp[(1) - (3)].value)->stringval) == *((yyvsp[(3) - (3)].value)->stringval));
        }
        else if((yyvsp[(1) - (3)].value)->valueType==charType){
            buf->boolval = (((yyvsp[(1) - (3)].value)->charval) == ((yyvsp[(3) - (3)].value)->charval));
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR EQ EXPR TYPE ERROR");
        }
        (yyval.value) = buf;
        jbLogicalOperation(IFEQ);

    }
    break;

  case 66:
#line 996 "yacc.y"
    {
        Trace("EXPR GT EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;

        if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->intval > (yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->floatval > (float)(yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->boolval = ((float)(yyvsp[(1) - (3)].value)->intval > (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->floatval > (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR GT EXPR TYPE ERROR");
        }
        (yyval.value) = buf;
        jbLogicalOperation(IFGT);


    }
    break;

  case 67:
#line 1024 "yacc.y"
    {
        Trace("EXPR GE EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->intval >= (yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->floatval >= (float)(yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->boolval = ((float)(yyvsp[(1) - (3)].value)->intval >= (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->floatval >= (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR GE EXPR TYPE ERROR");
        }
        (yyval.value) = buf;
        jbLogicalOperation(IFGE);


    }
    break;

  case 68:
#line 1051 "yacc.y"
    {
        Trace("EXPR NE EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if((yyvsp[(1) - (3)].value)->valueType != (yyvsp[(3) - (3)].value)->valueType){
            yyerror("EXPR EQ EXPR type mismatch");
        }
        else if((yyvsp[(1) - (3)].value)->valueType==intType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->intval != (yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->floatval != (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==boolType){
            buf->boolval = ((yyvsp[(1) - (3)].value)->boolval != (yyvsp[(3) - (3)].value)->boolval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==stringType){
            buf->boolval = (*((yyvsp[(1) - (3)].value)->stringval) != *((yyvsp[(3) - (3)].value)->stringval));
        }
        else if((yyvsp[(1) - (3)].value)->valueType==charType){
            buf->boolval = (((yyvsp[(1) - (3)].value)->charval) != ((yyvsp[(3) - (3)].value)->charval));
        }
        else if((yyvsp[(1) - (3)].value)->valueType==unknownType || (yyvsp[(3) - (3)].value)->valueType==unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            yyerror("EXPR NE EXPR TYPE ERROR");
        }
        (yyval.value) = buf;
        jbLogicalOperation(IFNE);

    }
    break;

  case 69:
#line 1083 "yacc.y"
    {
        Trace("NOT EXPR");
        cout << valueType2Str((yyvsp[(2) - (2)].value)->valueType) << endl;
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        
        if((yyvsp[(2) - (2)].value)->valueType != boolType){
            yyerror("NOT EXPR type error");
        }
        else if((yyvsp[(2) - (2)].value)->valueType == unknownType){
            Warning("beside operator may have unknownType");
        }
        else{
            buf->boolval = !((yyvsp[(2) - (2)].value)->boolval);
        }
        (yyval.value) = buf;
        jbOperation('!');

    }
    break;

  case 70:
#line 1102 "yacc.y"
    {
        Trace("ID [ EXPR ]");
        idInfo* buf = tables.lookup(*(yyvsp[(1) - (4)].stringval));
        // cant find id
        if(buf == NULL){
            yyerror("cant find " + *(yyvsp[(1) - (4)].stringval));

        }
        if(buf->idType != arrayType){
            yyerror("ID is not an array");
        }
        if((yyvsp[(3) - (4)].value)->valueType != intType){
            yyerror("ID[EXPR] must be int");
        }
        // if access out of range
        if((yyvsp[(3) - (4)].value)->intval>=buf->arraySize || (yyvsp[(3) - (4)].value)->intval<0){
            yyerror("access out of range");
        }
        // get id array value
        (yyval.value) = new valueInfo();
        
        (yyval.value)->valueType = buf->arrayValueType;
    }
    break;

  case 71:
#line 1125 "yacc.y"
    {
        Trace("value ")
        (yyval.value) = (yyvsp[(1) - (1)].value);
    }
    break;

  case 72:
#line 1133 "yacc.y"
    {
            (yyval.valueType) = charType;
         }
    break;

  case 73:
#line 1136 "yacc.y"
    {
             (yyval.valueType) = stringType;
         }
    break;

  case 74:
#line 1139 "yacc.y"
    {
             (yyval.valueType) = intType;

         }
    break;

  case 75:
#line 1143 "yacc.y"
    {
             (yyval.valueType) = boolType;

         }
    break;

  case 76:
#line 1147 "yacc.y"
    {
            (yyval.valueType) = floatType;
         }
    break;

  case 77:
#line 1153 "yacc.y"
    {
        Trace("string value");
        (yyval.value) = stringValue((yyvsp[(1) - (1)].stringval));
        jbfile << "\t\tldc "  << *(yyvsp[(1) - (1)].stringval)  << endl;
    }
    break;

  case 78:
#line 1158 "yacc.y"
    {
        Trace("int value");
        (yyval.value) = intValue((yyvsp[(1) - (1)].intval));
        jbPushInt((yyvsp[(1) - (1)].intval));
      }
    break;

  case 79:
#line 1163 "yacc.y"
    {
        Trace(" boolean value");
        (yyval.value) = boolValue((yyvsp[(1) - (1)].boolval));
        jbPushInt((yyvsp[(1) - (1)].boolval) ? 1 : 0);
      }
    break;

  case 80:
#line 1168 "yacc.y"
    {
            Trace(" float value");
            (yyval.value)  = floatValue((yyvsp[(1) - (1)].floatval));
      }
    break;

  case 81:
#line 1172 "yacc.y"
    {
          Trace(" char value");
          (yyval.value)  = charValue((yyvsp[(1) - (1)].charval));
      }
    break;

  case 82:
#line 1182 "yacc.y"
    {
                    (yyval.boolval) = false;

                    vector<int> top = ifLabelsVector[ifLabelsVector.size()-1];
                    int l = top[0];
                    jbfile << "\t\tgoto L" << l << endl;
                }
    break;

  case 83:
#line 1189 "yacc.y"
    {
                    (yyval.boolval) = true;
                    vector<int> top = ifLabelsVector[ifLabelsVector.size()-1];
                    int l = top[0];
                    jbfile << "\t\tgoto L" << l << endl;
                }
    break;

  case 84:
#line 1196 "yacc.y"
    {
    tables.push();
}
    break;

  case 85:
#line 1200 "yacc.y"
    {
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
    break;

  case 86:
#line 1221 "yacc.y"
    {
            if((yyvsp[(3) - (6)].value)->valueType != boolType){
                yyerror("if expr must be a boolean");
            }
            if((yyvsp[(6) - (6)].boolval)){
                tables.pop();
            }
            vector<int> top = ifLabelsVector[ifLabelsVector.size()-1];
            int l = top[0];
            jbfile << "\tL" << l <<  ":" << endl;
            ifLabelsVector.pop_back();
        }
    break;

  case 87:
#line 1233 "yacc.y"
    {
            if((yyvsp[(6) - (6)].boolval)){
                tables.pop();
            }
            // declare LX label
            if((yyvsp[(3) - (6)].value)->valueType != boolType){
                yyerror("if expr must be a boolean");
            }

            vector<int> top = ifLabelsVector[ifLabelsVector.size()-1];
            int l = top[top.size()-1];
            top.pop_back();
            ifLabelsVector[ifLabelsVector.size()-1] = top;
            jbfile << "\tL" << l <<  ":" << endl;

        }
    break;

  case 89:
#line 1254 "yacc.y"
    {
                elseifFlag = true;
            }
    break;

  case 91:
#line 1257 "yacc.y"
    {
                if((yyvsp[(2) - (2)].boolval)){
                    tables.pop();
                }
                vector<int> top = ifLabelsVector[ifLabelsVector.size()-1];
                int l = top[0];
                jbfile << "\tL" << l << ":" << endl; 
                ifLabelsVector.pop_back();
            }
    break;

  case 94:
#line 1280 "yacc.y"
    {
                                (yyval.boolval) = true;
                                vector<int> top = loopLabelsVector[loopLabelsVector.size()-1];
                                int l = top[0];
                                jbfile << "\t\tgoto Lbegin" << l << endl;
                            }
    break;

  case 95:
#line 1286 "yacc.y"
    {
                              (yyval.boolval) = false;
                              vector<int> top = loopLabelsVector[loopLabelsVector.size()-1];
                                int l = top[0];
                                jbfile << "\t\tgoto Lbegin" << l << endl;
                          }
    break;

  case 96:
#line 1294 "yacc.y"
    {
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

            }
    break;

  case 97:
#line 1311 "yacc.y"
    {
                vector<int> top = loopLabelsVector[loopLabelsVector.size()-1];
                int l = top[3];
                jbfile << "\t\tifeq Lexit" << l << endl;
                jbfile << "\t\tgoto Ltrue" << l << endl;
                jbfile << "\tLtrue" << l << ":" << endl;

            }
    break;

  case 98:
#line 1318 "yacc.y"
    {
                if((yyvsp[(4) - (7)].value)->valueType == unknownType){
                    Warning("unknownType!!!!");
                }
                else if((yyvsp[(4) - (7)].value)->valueType != boolType){
                    yyerror("while EXPR must be boolean");
                }
                if((yyvsp[(7) - (7)].boolval)){
                    tables.pop();
                }

                vector<int> top = loopLabelsVector[loopLabelsVector.size()-1];
                int l = top[3];
                jbfile << "\tLexit" << l << ":" << endl;
                loopLabelsVector.pop_back();
            }
    break;

  case 99:
#line 1337 "yacc.y"
    {
                                (yyval.boolval) = true;
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
    break;

  case 100:
#line 1357 "yacc.y"
    {
                              (yyval.boolval) = false;
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
    break;

  case 101:
#line 1379 "yacc.y"
    {
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

                idInfo * id = tables.lookup(*(yyvsp[(3) - (3)].stringval));
                if(id == NULL){
                    yyerror(*(yyvsp[(3) - (3)].stringval) +" does not exist");
                }
                forIdVector.push_back(id);
                forLabelsVector.push_back(buf);


            }
    break;

  case 102:
#line 1400 "yacc.y"
    {
                if((yyvsp[(7) - (10)].value)->valueType == unknownType || (yyvsp[(9) - (10)].value)->valueType == unknownType){
                    Warning("unknownType!!!");
                }
                else if((yyvsp[(7) - (10)].value)->valueType != intType || (yyvsp[(9) - (10)].value)->valueType != intType){
                    yyerror("for loop args must be int");
                }
                idInfo * id = tables.lookup(*(yyvsp[(3) - (10)].stringval));
                forLabelsVector[forLabelsVector.size()-1].push_back((yyvsp[(9) - (10)].value)->intval);
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
                jbPushInt((yyvsp[(9) - (10)].value)->intval);
                jbfile << "\t\tisub" << endl;
                jbfile << "\t\tifeq Lexit" << l << endl;
                jbfile << "\t\tgoto Ltrue" << l << endl;
                jbfile << "\tLtrue" << l << ":" << endl;
            }
    break;

  case 103:
#line 1434 "yacc.y"
    {
            if((yyvsp[(12) - (12)].boolval)){
                tables.pop();
            }
            vector<int> top = forLabelsVector[forLabelsVector.size()-1];
            int l = top[3];
            jbfile << "\tLexit" << l << ":" << endl;
            forLabelsVector.pop_back();
            forIdVector.pop_back();

         }
    break;


/* Line 1267 of yacc.c.  */
#line 3185 "y.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1447 "yacc.y"

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

