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
#define Trace(t)        {printf(t);printf("\n");}
// #define Error(t)    {printf(t);printf("\n");exit(-1);}
#define Warning(t)  {printf(t);printf("\n");} 
void yyerror(string s){
   cout << buf << " (" << s  << ')' << endl;
   exit(-1);
}
SymbolTableVector tables;





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
#line 21 "yacc.y"
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
#line 227 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 240 "y.tab.cpp"

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
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   397

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  187

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
      55,    56,    51,    49,    60,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
       0,     0,     3,     5,     8,    11,    14,    15,    16,    21,
      22,    31,    34,    36,    37,    38,    44,    47,    48,    53,
      54,    58,    60,    61,    65,    67,    71,    73,    76,    78,
      80,    82,    84,    86,    88,    89,    91,    95,   102,   107,
     112,   115,   117,   118,   123,   126,   129,   131,   132,   137,
     142,   149,   154,   159,   166,   174,   177,   181,   183,   187,
     191,   195,   199,   203,   206,   210,   214,   218,   222,   226,
     230,   234,   238,   241,   243,   248,   250,   252,   254,   256,
     258,   260,   262,   264,   266,   268,   270,   272,   275,   276,
     283,   289,   290,   294,   297,   300,   304,   306,   308,   309,
     316,   322,   323,   335
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    65,    -1,    78,    65,    -1,    68,    65,
      -1,    66,    65,    -1,    -1,    -1,    20,    38,    67,    85,
      -1,    -1,    10,    38,    69,    55,    76,    56,    73,    71,
      -1,    25,    89,    -1,    25,    -1,    -1,    -1,    57,    72,
      78,    70,    58,    -1,    59,    90,    -1,    -1,    38,    55,
      75,    56,    -1,    -1,    89,    60,    75,    -1,    89,    -1,
      -1,    77,    60,    76,    -1,    77,    -1,    38,    59,    90,
      -1,    79,    -1,    79,    78,    -1,    81,    -1,    82,    -1,
      92,    -1,    97,    -1,    87,    -1,    88,    -1,    -1,    80,
      -1,    38,    33,    89,    -1,    38,    61,    89,    62,    33,
      89,    -1,    21,    55,    89,    56,    -1,    22,    55,    89,
      56,    -1,    23,    38,    -1,    89,    -1,    -1,    57,    83,
      78,    58,    -1,    68,    84,    -1,    80,    84,    -1,    68,
      -1,    -1,    57,    86,    84,    58,    -1,    30,    38,    33,
      89,    -1,    30,    38,    59,    90,    33,    89,    -1,    31,
      38,    33,    89,    -1,    31,    38,    59,    90,    -1,    31,
      38,    59,    90,    33,    89,    -1,    31,    38,    59,    90,
      61,    35,    62,    -1,    31,    38,    -1,    55,    89,    56,
      -1,    74,    -1,    89,    49,    89,    -1,    89,    50,    89,
      -1,    89,    51,    89,    -1,    89,    52,    89,    -1,    89,
      53,    89,    -1,    50,    89,    -1,    89,    40,    89,    -1,
      89,    41,    89,    -1,    89,    48,    89,    -1,    89,    47,
      89,    -1,    89,    46,    89,    -1,    89,    45,    89,    -1,
      89,    44,    89,    -1,    89,    43,    89,    -1,    42,    89,
      -1,    38,    -1,    38,    61,    89,    62,    -1,    91,    -1,
       6,    -1,    26,    -1,    18,    -1,     4,    -1,    15,    -1,
      36,    -1,    35,    -1,    34,    -1,    37,    -1,    39,    -1,
      93,    -1,    93,    95,    -1,    -1,    17,    55,    89,    56,
      94,    81,    -1,    17,    55,    89,    56,    82,    -1,    -1,
      12,    96,    81,    -1,    12,    82,    -1,    12,    93,    -1,
      12,    93,    95,    -1,    98,    -1,   100,    -1,    -1,    32,
      55,    89,    56,    99,    81,    -1,    32,    55,    89,    56,
      82,    -1,    -1,    16,    55,    38,    48,    50,    89,    27,
      89,    56,   101,    81,    -1,    16,    55,    38,    48,    50,
      89,    27,    89,    56,    82,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   107,   108,   109,   110,   114,   114,   127,
     127,   162,   166,   170,   175,   175,   191,   194,   200,   231,
     236,   241,   253,   260,   266,   275,   288,   289,   293,   294,
     295,   296,   301,   302,   303,   306,   307,   331,   354,   355,
     356,   358,   363,   363,   379,   380,   381,   382,   382,   394,
     401,   412,   420,   428,   439,   446,   456,   459,   460,   485,
     510,   535,   560,   585,   603,   616,   629,   652,   674,   701,
     724,   746,   774,   786,   817,   837,   847,   850,   853,   857,
     861,   867,   871,   875,   879,   883,   890,   891,   893,   893,
     901,   903,   903,   909,   910,   911,   916,   917,   920,   920,
     930,   938,   938,   949
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
  "'('", "')'", "'{'", "'}'", "':'", "','", "'['", "']'", "$accept",
  "start", "ALL", "PROGRAM", "@1", "FUNCTION", "@2", "FUNCTION_RETURN",
  "FUNCTION_BLOCK", "@3", "FUNCTION_OPTIONAL", "FUNCTION_INVOCATION",
  "COMMA_SEP_EXPR", "ARGS", "ARG", "STMTS", "STMT", "V_DECLARE",
  "SIMPLE_STMT", "BLOCK", "@4", "OBJ_CONTENTS", "OBJ_BLOCK", "@5",
  "VAL_DECLARE", "VAR_DECLARE", "EXPR", "DATA_TYPE", "VALUE",
  "CONDITIONAL_STMT", "IF_STMT", "@6", "ELSE_STMT", "@7", "LOOP_STMT",
  "WHILE_STMT", "@8", "FOR_STMT", "@9", 0
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
      45,    42,    47,    37,   304,    40,    41,   123,   125,    58,
      44,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    65,    65,    67,    66,    69,
      68,    70,    70,    70,    72,    71,    73,    73,    74,    75,
      75,    75,    76,    76,    76,    77,    78,    78,    79,    79,
      79,    79,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    83,    82,    84,    84,    84,    86,    85,    87,
      87,    88,    88,    88,    88,    88,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    90,    90,    90,
      90,    91,    91,    91,    91,    91,    92,    92,    94,    93,
      93,    96,    95,    95,    95,    95,    97,    97,    99,    98,
      98,   101,   100,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     0,     4,     0,
       8,     2,     1,     0,     0,     5,     2,     0,     4,     0,
       3,     1,     0,     3,     1,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     0,     1,     3,     6,     4,     4,
       2,     1,     0,     4,     2,     2,     1,     0,     4,     4,
       6,     4,     4,     6,     7,     2,     3,     1,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     6,
       5,     0,     3,     2,     2,     3,     1,     1,     0,     6,
       5,     0,    11,    10
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    82,    81,    84,    73,    85,     0,     0,     0,
      42,     0,     2,     6,     6,    57,     6,    26,    35,    28,
      29,    32,    33,    41,    75,    30,    86,    31,    96,    97,
       9,     0,     0,     7,     0,     0,    40,     0,    55,     0,
       0,    19,     0,    73,    72,    63,     0,    34,     1,     5,
       4,     3,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
       0,    21,     0,     0,    56,     0,    64,    65,    71,    70,
      69,    68,    67,    66,    58,    59,    60,    61,    62,    93,
      94,    34,    22,     0,    88,    47,     8,    38,    39,    49,
      79,    76,    80,    78,    77,     0,    51,    52,    98,    18,
      19,    74,     0,    43,    95,    92,     0,     0,    24,     0,
      90,    34,     0,     0,     0,     0,   100,    34,    20,     0,
      74,     0,    17,    22,     0,    89,    46,     0,     0,    50,
      53,     0,    99,    37,    25,     0,     0,    23,     0,    44,
      45,    48,    54,    16,    14,    10,     0,    34,   101,    13,
     103,    34,    12,     0,   102,    11,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,    23,    81,    24,    78,   183,   175,   177,
     166,    25,    90,   137,   138,    26,    27,    28,    29,    30,
      57,   158,   116,   142,    31,    32,    33,   125,    34,    35,
      36,   141,    77,   111,    37,    38,   147,    39,   181
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -145
static const yytype_int16 yypact[] =
{
      64,   -20,   -38,   -32,   -12,   -26,   -25,     4,    22,    24,
      16,  -145,  -145,  -145,  -145,   -24,  -145,   205,   205,   205,
    -145,    73,  -145,    64,    64,  -145,    64,   107,  -145,  -145,
    -145,  -145,  -145,   320,  -145,  -145,    65,  -145,  -145,  -145,
    -145,    41,   205,  -145,   205,   205,  -145,   -19,   -18,   205,
     205,   205,   205,   -45,   344,  -145,   236,   107,  -145,  -145,
    -145,  -145,  -145,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   -14,  -145,    33,    44,
     250,    32,   264,   278,   205,    57,   205,    57,   292,   320,
      48,   218,   164,   205,  -145,    39,   333,   344,   131,   131,
     131,   131,   131,   131,    13,    13,  -145,  -145,  -145,  -145,
      65,   137,    67,    61,    53,  -145,  -145,  -145,  -145,   320,
    -145,  -145,  -145,  -145,  -145,    79,   320,   -22,    53,  -145,
     205,    82,   184,  -145,  -145,  -145,    58,    62,    56,   205,
    -145,   137,    60,   205,   205,    85,  -145,   137,  -145,   205,
    -145,    57,    66,    67,   150,  -145,    60,    60,    75,   320,
     320,    69,  -145,   320,  -145,    57,    77,  -145,   205,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,   306,   107,    53,   110,
    -145,   137,   205,    78,  -145,   320,  -145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,    -2,  -145,  -145,  -137,  -145,  -145,  -145,  -145,
    -145,  -145,    10,    -6,  -145,   -21,  -145,   -49,  -103,   -69,
    -145,  -144,  -145,  -145,  -145,  -145,   -17,   -83,  -145,  -145,
      72,  -145,    40,  -145,  -145,  -145,  -145,  -145,  -145
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      54,    55,    56,     3,   127,   156,    62,   109,   135,    50,
      51,   144,   169,   170,    84,    86,    93,    41,    40,   156,
     156,    59,    60,    42,    61,    80,    43,    82,    83,    44,
      45,    51,    88,    89,    91,    92,    95,    52,   155,   145,
      85,    87,    46,    20,   162,   140,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   146,
      47,   120,    48,   121,    73,    74,    75,   119,   164,   126,
       1,    49,   122,    58,     1,   123,   132,    76,   184,    79,
       2,     3,   173,   124,     4,     5,     6,     7,   112,   115,
       8,     9,   113,   157,     8,     9,    10,   133,    11,    12,
      13,    14,    15,    16,   129,   136,    17,   157,   157,   180,
      20,   139,   143,    91,    18,   149,   153,   151,   152,    19,
     161,    20,   154,     2,     3,   165,   159,   160,     5,     6,
       7,   172,   163,   171,   174,   182,   186,     8,     9,    10,
     148,    11,    12,    13,    14,    15,    16,   167,   110,    17,
     134,   176,     0,     0,     0,     0,   179,    18,     5,     6,
       7,     0,    19,     0,    20,   185,     0,     8,     9,     0,
       0,    11,    12,    13,    14,    15,    16,   168,     0,    17,
      71,    72,    73,    74,    75,     0,     0,    18,     0,     0,
      63,    64,    19,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    63,    64,     0,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,     0,
       0,     0,     0,     0,    63,    64,   131,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,    11,
      12,    13,    14,    53,    16,     0,   150,    17,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,    63,    64,
      19,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,     0,     0,    63,    64,   130,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      63,    64,    94,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    63,    64,   114,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    63,    64,
     117,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    63,    64,   118,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    63,    64,   128,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      63,    64,   178,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75
};

static const yytype_int16 yycheck[] =
{
      17,    18,    19,    17,    87,   142,    27,    76,   111,    33,
      55,    33,   156,   157,    33,    33,    61,    55,    38,   156,
     157,    23,    24,    55,    26,    42,    38,    44,    45,    55,
      55,    55,    49,    50,    51,    52,    57,    61,   141,    61,
      59,    59,    38,    57,   147,   114,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,   128,
      38,     4,    38,     6,    51,    52,    53,    84,   151,    86,
      10,    55,    15,     0,    10,    18,    93,    12,   181,    38,
      16,    17,   165,    26,    20,    21,    22,    23,    55,    57,
      30,    31,    48,   142,    30,    31,    32,    58,    34,    35,
      36,    37,    38,    39,    56,    38,    42,   156,   157,   178,
      57,    50,    33,   130,    50,    33,    60,    59,    56,    55,
      35,    57,   139,    16,    17,    59,   143,   144,    21,    22,
      23,    62,   149,    58,    57,    25,    58,    30,    31,    32,
     130,    34,    35,    36,    37,    38,    39,   153,    76,    42,
     110,   168,    -1,    -1,    -1,    -1,   177,    50,    21,    22,
      23,    -1,    55,    -1,    57,   182,    -1,    30,    31,    -1,
      -1,    34,    35,    36,    37,    38,    39,    27,    -1,    42,
      49,    50,    51,    52,    53,    -1,    -1,    50,    -1,    -1,
      40,    41,    55,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    62,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    34,
      35,    36,    37,    38,    39,    -1,    62,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    40,    41,
      55,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    -1,    -1,    -1,    40,    41,    60,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      40,    41,    56,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    40,    41,    56,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    40,    41,
      56,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    40,    41,    56,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    40,    41,    56,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      40,    41,    56,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    41,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    16,    17,    20,    21,    22,    23,    30,    31,
      32,    34,    35,    36,    37,    38,    39,    42,    50,    55,
      57,    64,    65,    66,    68,    74,    78,    79,    80,    81,
      82,    87,    88,    89,    91,    92,    93,    97,    98,   100,
      38,    55,    55,    38,    55,    55,    38,    38,    38,    55,
      33,    55,    61,    38,    89,    89,    89,    83,     0,    65,
      65,    65,    78,    40,    41,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    12,    95,    69,    38,
      89,    67,    89,    89,    33,    59,    33,    59,    89,    89,
      75,    89,    89,    61,    56,    78,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    82,
      93,    96,    55,    48,    56,    57,    85,    56,    56,    89,
       4,     6,    15,    18,    26,    90,    89,    90,    56,    56,
      60,    62,    89,    58,    95,    81,    38,    76,    77,    50,
      82,    94,    86,    33,    33,    61,    82,    99,    75,    33,
      62,    59,    56,    60,    89,    81,    68,    80,    84,    89,
      89,    35,    81,    89,    90,    59,    73,    76,    27,    84,
      84,    58,    62,    90,    57,    71,    89,    72,    56,    78,
      82,   101,    25,    70,    81,    89,    58
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
        case 2:
#line 102 "yacc.y"
    {
        Trace("Reducing to program\n");
    }
    break;

  case 7:
#line 114 "yacc.y"
    {
            Trace("declare an id to objet type");
            int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (2)].stringval),objectType);
            if(result == -1){
                yyerror(*(yyvsp[(2) - (2)].stringval) + "already exists");
            }
            tables.push();
        }
    break;

  case 8:
#line 121 "yacc.y"
    {
            Trace("OBJECT ID BLOCK");
        }
    break;

  case 9:
#line 127 "yacc.y"
    {
            Trace("create an function id");
            int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (2)].stringval),functionType);
            if(result == -1){
                yyerror(*(yyvsp[(2) - (2)].stringval) + "already exists");
            }
            tables.push();
        }
    break;

  case 10:
#line 134 "yacc.y"
    {
            Trace("declare method end");
            idInfo * id = tables.lookup(*(yyvsp[(2) - (8)].stringval));
            if((yyvsp[(7) - (8)].valueType) != unknownType){
                cout << "function return type is " << valueType2Str((yyvsp[(7) - (8)].valueType)) << endl;
                id->returnType = (yyvsp[(7) - (8)].valueType);
                // check return value is same as declared 
                if((*(yyvsp[(8) - (8)].idMap))["return"]->value->valueType != (yyvsp[(7) - (8)].valueType)){
                    yyerror("function return type is different from declared");
                }
            }
            Trace("Saveing function arguments and inside id map");
            id->argumentsInfo = tables.vec[tables.top].idMap;
            id->insideIdMap = *(yyvsp[(8) - (8)].idMap);
            cout << "size check : "<< id->argumentsInfo.size() << endl;
            // the answer include return idinfo
            cout << "size check : "<< id->insideIdMap.size() << endl;
            tables.pop();
            cout << (yyvsp[(5) - (8)].argumentsInfo)->empty() << endl;
            for(int i = 0; i < (yyvsp[(5) - (8)].argumentsInfo)->size(); ++i){
                cout << "id : " << (*(yyvsp[(5) - (8)].argumentsInfo))[i]->first << " type : " << valueType2Str((*(yyvsp[(5) - (8)].argumentsInfo))[i]->second) << endl;
            }
            // store the function declare arguments sequence
            // can check when function invocation
            id->argumentsInfoSeq = *(yyvsp[(5) - (8)].argumentsInfo);
        }
    break;

  case 11:
#line 162 "yacc.y"
    {
                    Trace("FUNCTION HAS RETURN VALUE");
                    (yyval.value) = (yyvsp[(2) - (2)].value);
                }
    break;

  case 12:
#line 166 "yacc.y"
    {
                    Trace("FUNCTION HAS NO RETURN VALUE");
                    (yyval.value) = new valueInfo();
                }
    break;

  case 13:
#line 170 "yacc.y"
    {
                    Trace("FUNCTION HAS NO RETURN VALUE");
                    (yyval.value) = new valueInfo();
                }
    break;

  case 14:
#line 175 "yacc.y"
    {
        Trace("FUNCTION BLOCK START");
        tables.push();
      }
    break;

  case 15:
#line 178 "yacc.y"
    {
          Trace("FUNCTION BLOCK END");
            (yyval.idMap) =  new map<string,idInfo*>();
          *(yyval.idMap) = tables.vec[tables.top].idMap;
          (*(yyval.idMap))["return"] =  new idInfo();
          (*(yyval.idMap))["return"]->value = (yyvsp[(4) - (5)].value);
          tables.dump();
          if(tables.pop() == -1){
              yyerror("symbol table error");
          }
      }
    break;

  case 16:
#line 191 "yacc.y"
    {
                    (yyval.valueType) = (yyvsp[(2) - (2)].valueType);
                }
    break;

  case 17:
#line 194 "yacc.y"
    {
                    (yyval.valueType) = unknownType;
                }
    break;

  case 18:
#line 200 "yacc.y"
    {
                        Trace("call function invocation");
                        idInfo* id = tables.lookup(*(yyvsp[(1) - (4)].stringval));
                        if(id == NULL){
                            yyerror(*(yyvsp[(1) - (4)].stringval) + "doesn't exist");
                        }
                        if(id->idType != functionType){
                            yyerror(*(yyvsp[(1) - (4)].stringval) + "is not a function");
                        }
                        cout << "parameter nums : " << (yyvsp[(3) - (4)].valueInfoVec)->size() << endl;
                        for(int i = 0; i < (yyvsp[(3) - (4)].valueInfoVec)->size(); ++i){
                            cout << "type : " << valueType2Str((*(yyvsp[(3) - (4)].valueInfoVec))[i]->valueType) << endl;
                        }
                        // check parameter is same as declared 
                        if((yyvsp[(3) - (4)].valueInfoVec)->size()!= id->argumentsInfo.size()){
                            yyerror("parameter nums error");
                        }
                        // check type and assign
                        for(int i = 0; i < (yyvsp[(3) - (4)].valueInfoVec)->size(); ++i){
                            if((*(yyvsp[(3) - (4)].valueInfoVec))[i]->valueType!=id->argumentsInfoSeq[i]->second){
                                yyerror("parameter type error");
                            }
                            // call by reference?...
                            id->argumentsInfo[id->argumentsInfoSeq[i]->first]->value =  (*(yyvsp[(3) - (4)].valueInfoVec))[i];
                        }
                        valueInfo* buf = new valueInfo();
                        // here need to push id's tow idmap into idmap
                        (yyval.value) = id->insideIdMap["return"]->value; 
                    }
    break;

  case 19:
#line 231 "yacc.y"
    {
                    Trace("check arugment start");
                    vector<valueInfo*>* buf = new vector<valueInfo*>();
                    (yyval.valueInfoVec) = buf;
                }
    break;

  case 20:
#line 236 "yacc.y"
    {
                   Trace("checking argument...");
                   (yyvsp[(3) - (3)].valueInfoVec)->push_back((yyvsp[(1) - (3)].value));
                   (yyval.valueInfoVec) = (yyvsp[(3) - (3)].valueInfoVec);
               }
    break;

  case 21:
#line 241 "yacc.y"
    {
                   Trace("check arugment start");
                    vector<valueInfo*>* buf = new vector<valueInfo*>();
                    buf->push_back((yyvsp[(1) - (1)].value));
                    (yyval.valueInfoVec) = buf;
               }
    break;

  case 22:
#line 253 "yacc.y"
    {
            Trace("ARGS empty");
           vector<pair<string,int>*>* buf = new vector<pair<string,int>*>();
           buf->clear(); 
           (yyval.argumentsInfo) = buf;

       }
    break;

  case 23:
#line 260 "yacc.y"
    {
         Trace("ARG , ARGS");  
         (yyval.argumentsInfo) = (yyvsp[(3) - (3)].argumentsInfo);
        (yyval.argumentsInfo)->push_back((yyvsp[(1) - (3)].argumentInfo));

       }
    break;

  case 24:
#line 266 "yacc.y"
    {
           Trace("ARG");
           vector<pair<string,int>*>* buf = new vector<pair<string,int>*>();
           (yyval.argumentsInfo) = buf;
           (yyval.argumentsInfo)->push_back((yyvsp[(1) - (1)].argumentInfo));
           
       }
    break;

  case 25:
#line 275 "yacc.y"
    {
        Trace("ID : DataType");
        int result = tables.vec[tables.top].insert(*(yyvsp[(1) - (3)].stringval),variableType,(yyvsp[(3) - (3)].valueType));
        if(result == -1){
            yyerror("id has been used");
        }
        pair<string,int>* p = new pair<string,int>();
        p->first = *(yyvsp[(1) - (3)].stringval);
        p->second = (yyvsp[(3) - (3)].valueType);
        (yyval.argumentInfo) = p;
    }
    break;

  case 36:
#line 307 "yacc.y"
    {
                Trace("ID ASSIGN EXPR");
                idInfo* buf = new idInfo();
                // buf = tables.vec[tables.top].lookup(*$1);
                buf = tables.lookup(*(yyvsp[(1) - (3)].stringval));
                if(buf == NULL){
                    yyerror(*(yyvsp[(1) - (3)].stringval) + " doesn't exist");
                }

                if(buf->idType != variableType){
                    yyerror(*(yyvsp[(1) - (3)].stringval) + " can not be assign");
                }
                if(buf->hasInit){
                    if(buf->value->valueType != (yyvsp[(3) - (3)].value)->valueType){
                        yyerror(*(yyvsp[(1) - (3)].stringval) + " already assigen other data type");
                    }
                    *(buf->value) = *(yyvsp[(3) - (3)].value);
                }
                else{
                    buf->value = new valueInfo();
                    *(buf->value) = *(yyvsp[(3) - (3)].value);
                    buf->hasInit = true;
                }
            }
    break;

  case 37:
#line 331 "yacc.y"
    {
                Trace("ID '[' EXPR ']' ASSIGN EXPR");
                // idInfo* buf = tables.vec[tables.top].lookup(*$1);
                idInfo* buf = tables.lookup(*(yyvsp[(1) - (6)].stringval));
                if(buf == NULL){
                    yyerror("id does not exist");
                }
                if(buf->idType != arrayType){
                    yyerror(*(yyvsp[(1) - (6)].stringval) + " is not an array");
                }
                if((yyvsp[(3) - (6)].value)->valueType != intType){
                    yyerror("only can assess int index");
                }
                else if((yyvsp[(3) - (6)].value)->intval >= buf->arraySize || (yyvsp[(3) - (6)].value)->intval <0){
                    yyerror("access array out of range");
                }
                if(buf->arrayValueType != (yyvsp[(6) - (6)].value)->valueType){
                    yyerror("assign different value type in array");
                }
                else{
                    *(buf->arrayValue[(yyvsp[(3) - (6)].value)->intval]) = *((yyvsp[(6) - (6)].value));
                }
            }
    break;

  case 42:
#line 363 "yacc.y"
    {
        Trace("BLOCK START");
        tables.push();
      }
    break;

  case 43:
#line 367 "yacc.y"
    {
          Trace("BLOCK END");
            (yyval.idMap) =  new map<string,idInfo*>();
          *(yyval.idMap) = tables.vec[tables.top].idMap;
            tables.dump();
          if(tables.pop() == -1){
              yyerror("symbol table error");
          }
      }
    break;

  case 47:
#line 382 "yacc.y"
    {
        tables.push();
      }
    break;

  case 48:
#line 385 "yacc.y"
    {
          tables.dump();
          if(tables.pop() == -1){
              yyerror("symbol table error");
          }
      }
    break;

  case 49:
#line 394 "yacc.y"
    {
                Trace("VAL ID ASSIGN EXPR");
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (4)].stringval),constType,(yyvsp[(4) - (4)].value));
                if(result == -1){
                    yyerror("id has been used");
                }
            }
    break;

  case 50:
#line 401 "yacc.y"
    {
                Trace("VAL ID : DATA_TYPE ASSIGN EXPR");
                if((yyvsp[(4) - (6)].valueType) != (yyvsp[(6) - (6)].value)->valueType){
                    yyerror("data type and value type doesn't match");
                }
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (6)].stringval),constType,(yyvsp[(6) - (6)].value));
                if(result == -1){
                    yyerror("id has been used");
                }
            }
    break;

  case 51:
#line 412 "yacc.y"
    {
                Trace("VAR ID ASSIGN EXPR");
                // declare var with value
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (4)].stringval),variableType,(yyvsp[(4) - (4)].value));
                if(result == -1){
                    yyerror("id has been used");
                }
            }
    break;

  case 52:
#line 420 "yacc.y"
    {
                Trace("VAR ID ':' DATA_TYPE");
                // declare var but only have type
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (4)].stringval),variableType,(yyvsp[(4) - (4)].valueType));
                if(result == -1){
                    yyerror("id has been used");
                }
            }
    break;

  case 53:
#line 428 "yacc.y"
    {
                Trace("VAR ID : DATA_TYPE ASSIGN EXPR");
                if((yyvsp[(4) - (6)].valueType) != (yyvsp[(6) - (6)].value)->valueType){
                    yyerror("data type and value type doesn't match");
                }
                // declare var with sepcific data type and value
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (6)].stringval),variableType,(yyvsp[(6) - (6)].value));
                if(result == -1){
                    yyerror("id has been used");
                }
            }
    break;

  case 54:
#line 439 "yacc.y"
    {
                Trace("VAR ID : DATA_TYPE [ INT_VALUE ]");
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (7)].stringval),arrayType,(yyvsp[(4) - (7)].valueType),(yyvsp[(6) - (7)].intval));
                if(result == -1){
                    yyerror("id has been used");
                }
            }
    break;

  case 55:
#line 446 "yacc.y"
    {
                Trace("VAR ID");
                // declare unknownType var
                int result = tables.vec[tables.top].insert(*(yyvsp[(2) - (2)].stringval),variableType,unknownType);
                if(result == -1){
                    yyerror("id has been used");
                }
            }
    break;

  case 56:
#line 456 "yacc.y"
    {
        (yyval.value) = (yyvsp[(2) - (3)].value);
    }
    break;

  case 58:
#line 460 "yacc.y"
    {
        Trace("EXPR + EXPR");
        valueInfo* buf = new valueInfo();
        if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->valueType = intType;
            buf->intval = ((yyvsp[(1) - (3)].value)->intval + (yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==intType){
            buf->valueType = floatType;
            buf->floatval = ((yyvsp[(1) - (3)].value)->floatval + (float)(yyvsp[(3) - (3)].value)->intval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==intType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ((float)(yyvsp[(1) - (3)].value)->intval + (yyvsp[(3) - (3)].value)->floatval);
        }
        else if((yyvsp[(1) - (3)].value)->valueType==floatType && (yyvsp[(3) - (3)].value)->valueType==floatType){
            buf->valueType = floatType;
            buf->floatval = ((yyvsp[(1) - (3)].value)->floatval + (yyvsp[(3) - (3)].value)->floatval);
        }
        else{
            yyerror("EXPR + EXPR TYPE ERROR");
        }
        (yyval.value) = buf;
        
    }
    break;

  case 59:
#line 485 "yacc.y"
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
        else{
            yyerror("EXPR - EXPR TYPE ERROR");
        }
        (yyval.value) = buf;

    }
    break;

  case 60:
#line 510 "yacc.y"
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
        else{
            yyerror("EXPR * EXPR TYPE ERROR");
        }
        (yyval.value) = buf;

    }
    break;

  case 61:
#line 535 "yacc.y"
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
        else{
            yyerror("EXPR / EXPR TYPE ERROR");
        }
        (yyval.value) = buf;

    }
    break;

  case 62:
#line 560 "yacc.y"
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
        else{
            yyerror("EXPR / EXPR TYPE ERROR");
        }
        (yyval.value) = buf;

    }
    break;

  case 63:
#line 585 "yacc.y"
    {
        Trace("- EXPR")
        valueInfo* buf = new valueInfo();
        if ((yyvsp[(2) - (2)].value)->valueType== intType) {
            *buf = *(yyvsp[(2) - (2)].value);
            buf->intval = -1 * buf->intval;
        }
        else if((yyvsp[(2) - (2)].value)->valueType== floatType){
            *buf = *(yyvsp[(2) - (2)].value);
            buf->floatval = -1 * buf->floatval;
        }
        else{
            yyerror("- EXPR type error");
        }
        (yyval.value) = buf;


    }
    break;

  case 64:
#line 603 "yacc.y"
    {
        Trace("EXPR OR_OP EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if((yyvsp[(1) - (3)].value)->valueType!=boolType || (yyvsp[(3) - (3)].value)->valueType!=boolType){
            yyerror("EXPR OR_OP EXPR type must be bool");
        }
        else{
            buf->boolval = (yyvsp[(1) - (3)].value)->boolval || (yyvsp[(3) - (3)].value)->boolval;
        }
        (yyval.value) = buf;

    }
    break;

  case 65:
#line 616 "yacc.y"
    {
        Trace("EXPR AND_OP EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if((yyvsp[(1) - (3)].value)->valueType!=boolType || (yyvsp[(3) - (3)].value)->valueType!=boolType){
            yyerror("EXPR OR_OP EXPR type must be bool");
        }
        else{
            buf->boolval = (yyvsp[(1) - (3)].value)->boolval && (yyvsp[(3) - (3)].value)->boolval;
        }
        (yyval.value) = buf;

    }
    break;

  case 66:
#line 629 "yacc.y"
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
        else{
            yyerror("EXPR LT EXPR TYPE ERROR");
        }
        (yyval.value) = buf;


    }
    break;

  case 67:
#line 652 "yacc.y"
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
        else{
            yyerror("EXPR LE EXPR TYPE ERROR");
        }
        (yyval.value) = buf;

    }
    break;

  case 68:
#line 674 "yacc.y"
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
        else{
            yyerror("EXPR EQ EXPR TYPE ERROR");
        }
        (yyval.value) = buf;
    }
    break;

  case 69:
#line 701 "yacc.y"
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
        else{
            yyerror("EXPR GT EXPR TYPE ERROR");
        }
        (yyval.value) = buf;

    }
    break;

  case 70:
#line 724 "yacc.y"
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
        else{
            yyerror("EXPR GE EXPR TYPE ERROR");
        }
        (yyval.value) = buf;

    }
    break;

  case 71:
#line 746 "yacc.y"
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
        else{
            yyerror("EXPR NE EXPR TYPE ERROR");
        }
        (yyval.value) = buf;

    }
    break;

  case 72:
#line 774 "yacc.y"
    {
        Trace("NOT EXPR");
        valueInfo* buf = new valueInfo();
        buf->valueType = boolType;
        if((yyvsp[(2) - (2)].value)->valueType != boolType){
            yyerror("NOT EXPR type error");
        }
        else{
            buf->boolval = !((yyvsp[(2) - (2)].value)->boolval);
        }
        (yyval.value) = buf;
    }
    break;

  case 73:
#line 786 "yacc.y"
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
            valueInfo* v = new valueInfo();
            // here need to push id's tow idmap into idmap
            (yyval.value) = v;

            // yyerror(*$1 + " is function make grammar error");
        }
        // check has init or not
        else if(!buf->hasInit){
            yyerror(*(yyvsp[(1) - (1)].stringval) + " has not init");
        }
        (yyval.value) = buf->value;
    }
    break;

  case 74:
#line 817 "yacc.y"
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
        (yyval.value) = buf->arrayValue[(yyvsp[(3) - (4)].value)->intval];
    }
    break;

  case 75:
#line 837 "yacc.y"
    {
        Trace("value ")
        (yyval.value) = (yyvsp[(1) - (1)].value);
    }
    break;

  case 76:
#line 847 "yacc.y"
    {
            (yyval.valueType) = charType;
         }
    break;

  case 77:
#line 850 "yacc.y"
    {
             (yyval.valueType) = stringType;
         }
    break;

  case 78:
#line 853 "yacc.y"
    {
             (yyval.valueType) = intType;

         }
    break;

  case 79:
#line 857 "yacc.y"
    {
             (yyval.valueType) = boolType;

         }
    break;

  case 80:
#line 861 "yacc.y"
    {
            (yyval.valueType) = floatType;
         }
    break;

  case 81:
#line 867 "yacc.y"
    {
        Trace("string value");
        (yyval.value) = stringValue((yyvsp[(1) - (1)].stringval));
    }
    break;

  case 82:
#line 871 "yacc.y"
    {
        Trace("int value");
        (yyval.value) = intValue((yyvsp[(1) - (1)].intval));
      }
    break;

  case 83:
#line 875 "yacc.y"
    {
        Trace(" boolean value");
        (yyval.value) = boolValue((yyvsp[(1) - (1)].boolval));
      }
    break;

  case 84:
#line 879 "yacc.y"
    {
            Trace(" float value");
            (yyval.value)  = floatValue((yyvsp[(1) - (1)].floatval));
      }
    break;

  case 85:
#line 883 "yacc.y"
    {
          Trace(" char value");
          (yyval.value)  = charValue((yyvsp[(1) - (1)].charval));
      }
    break;

  case 88:
#line 893 "yacc.y"
    {
            tables.push();

        }
    break;

  case 89:
#line 896 "yacc.y"
    {
            tables.dump();
            tables.pop();

        }
    break;

  case 91:
#line 903 "yacc.y"
    {
            tables.push();
        }
    break;

  case 92:
#line 905 "yacc.y"
    {
            tables.dump();
            tables.pop();
        }
    break;

  case 98:
#line 920 "yacc.y"
    {
                    tables.push();
                }
    break;

  case 99:
#line 922 "yacc.y"
    {
                tables.dump();
                tables.pop();
                Trace(" while without block");
                if((yyvsp[(3) - (6)].value)->valueType != boolType){
                    yyerror("while EXPR must be boolean");
                }
           }
    break;

  case 100:
#line 930 "yacc.y"
    {
                Trace(" while with block");
                if((yyvsp[(3) - (5)].value)->valueType != boolType){
                    yyerror("while EXPR must be boolean");
                }
           }
    break;

  case 101:
#line 938 "yacc.y"
    {
                tables.push();

            }
    break;

  case 102:
#line 941 "yacc.y"
    {
                tables.dump();
                tables.pop();
                Trace("for stmt without block");
            if((yyvsp[(6) - (11)].value)->valueType != intType || (yyvsp[(8) - (11)].value)->valueType != intType){
                yyerror("for loop args must be int");
            }
         }
    break;

  case 103:
#line 949 "yacc.y"
    {
             Trace("for stmt with block");
             if((yyvsp[(6) - (10)].value)->valueType != intType || (yyvsp[(8) - (10)].value)->valueType != intType){
                yyerror("for loop args must be int");
            }
         }
    break;


/* Line 1267 of yacc.c.  */
#line 2700 "y.tab.cpp"
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


#line 956 "yacc.y"

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

