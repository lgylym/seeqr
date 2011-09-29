
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     LPAREN = 258,
     RPAREN = 259,
     SEMICOLON = 260,
     COMMA = 261,
     DBLQUOTE = 262,
     SHELL = 263,
     USE = 264,
     CREATE = 265,
     DROP = 266,
     DATABASE = 267,
     TABLE = 268,
     DELETE = 269,
     FROM = 270,
     CROSS_PRODUCT = 271,
     EQUIJOIN = 272,
     EQUIJOIN_OPT = 273,
     ON = 274,
     EQUALS = 275,
     LOAD = 276,
     HELP = 277,
     PRINT = 278,
     EXIT = 279,
     INTVAL = 280,
     FLOATVAL = 281,
     STRINGVAL = 282,
     ID = 283,
     ATTRTYPE = 284,
     RESET = 285,
     IO = 286,
     BUFFER = 287
   };
#endif
/* Tokens.  */
#define LPAREN 258
#define RPAREN 259
#define SEMICOLON 260
#define COMMA 261
#define DBLQUOTE 262
#define SHELL 263
#define USE 264
#define CREATE 265
#define DROP 266
#define DATABASE 267
#define TABLE 268
#define DELETE 269
#define FROM 270
#define CROSS_PRODUCT 271
#define EQUIJOIN 272
#define EQUIJOIN_OPT 273
#define ON 274
#define EQUALS 275
#define LOAD 276
#define HELP 277
#define PRINT 278
#define EXIT 279
#define INTVAL 280
#define FLOATVAL 281
#define STRINGVAL 282
#define ID 283
#define ATTRTYPE 284
#define RESET 285
#define IO 286
#define BUFFER 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


