/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     REPEAT = 278,
     RETURN = 279,
     STRING = 280,
     TO = 281,
     TRUE = 282,
     TYPE = 283,
     VAL = 284,
     VAR = 285,
     WHILE = 286,
     ASSIGN = 287,
     BOOL_VALUE = 288,
     INT_VALUE = 289,
     STRING_VALUE = 290,
     FLOAT_VALUE = 291,
     ID = 292,
     OR_OP = 293,
     AND_OP = 294,
     NOT = 295,
     NE = 296,
     GE = 297,
     GT = 298,
     EQ = 299,
     LE = 300,
     LT = 301,
     UMINUS = 302
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
#define REPEAT 278
#define RETURN 279
#define STRING 280
#define TO 281
#define TRUE 282
#define TYPE 283
#define VAL 284
#define VAR 285
#define WHILE 286
#define ASSIGN 287
#define BOOL_VALUE 288
#define INT_VALUE 289
#define STRING_VALUE 290
#define FLOAT_VALUE 291
#define ID 292
#define OR_OP 293
#define AND_OP 294
#define NOT 295
#define NE 296
#define GE 297
#define GT 298
#define EQ 299
#define LE 300
#define LT 301
#define UMINUS 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "yacc.y"
{
    float floatval;
    int intval;
    bool boolval;
    string *stringval;
    int type;
    valueInfo* value;
}
/* Line 1529 of yacc.c.  */
#line 152 "y.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

