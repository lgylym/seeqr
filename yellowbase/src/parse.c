
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parse.y"

/*
 * parser.y: yacc specification for RQL
 *
 * Authors: Dallan Quass
 *          Jan Jannink
 *          Jason McHugh
 *
 * originally by: Mark McAuliffe, University of Wisconsin - Madison, 1991
 *
 * 1997: Added "print buffer", "print io", "reset io" and the "*" in
 * SFW Query.
 * 1998: Added "reset buffer", "resize buffer [int]", "queryplans on",
 * and "queryplans off".
 * 2000: Added "const" to yyerror-header
 *
 */

#include <cstdio>
#include <iostream>
#include <sys/types.h>
#include <cstdlib>
#include <unistd.h>
#include "redbase.h"
#include "parser_internal.h"
#include "pf.h"     // for PF_PrintError
#include "rm.h"     // for RM_PrintError
#include "ix.h"     // for IX_PrintError
#include "sm.h"
#include "ql.h"

using namespace std;

  // Added by Wendy Tobagus
#ifndef yyrestart
void yyrestart(FILE*);
#endif

// The PF_STATS indicates that we will be tracking statistics for the PF
// Layer.  The Manager is defined within pf_buffermgr.cc.  
// We include it within the parser so that a system command can display
// statistics about the DB.
#ifdef PF_STATS
#include "statistics.h"

// This is defined within the pf_buffermgr.cc
extern StatisticsMgr *pStatisticsMgr;

#endif    // PF_STATS

/*
 * string representation of tokens; provided by scanner
 */
extern char *yytext;

/*
 * points to root of parse tree
 */
static NODE *parse_tree;

int bExit;                 // when to return from RBparse

int bQueryPlans;           // When to print the query plans

PF_Manager *pPfm;          // PF component manager
SM_Manager *pSmm;          // SM component manager
QL_Manager *pQlm;          // QL component manager



/* Line 189 of yacc.c  */
#line 144 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     RW_CREATE = 258,
     RW_DROP = 259,
     RW_TABLE = 260,
     RW_INDEX = 261,
     RW_LOAD = 262,
     RW_SET = 263,
     RW_HELP = 264,
     RW_PRINT = 265,
     RW_EXIT = 266,
     RW_SELECT = 267,
     RW_FROM = 268,
     RW_WHERE = 269,
     RW_ORDER = 270,
     RW_GROUP = 271,
     RW_MAX = 272,
     RW_MIN = 273,
     RW_SUM = 274,
     RW_AVG = 275,
     RW_COUNT = 276,
     RW_BY = 277,
     RW_DESC = 278,
     RW_ASC = 279,
     RW_INSERT = 280,
     RW_DELETE = 281,
     RW_UPDATE = 282,
     RW_AND = 283,
     RW_INTO = 284,
     RW_VALUES = 285,
     T_EQ = 286,
     T_LT = 287,
     T_LE = 288,
     T_GT = 289,
     T_GE = 290,
     T_NE = 291,
     T_EOF = 292,
     NOTOKEN = 293,
     RW_RESET = 294,
     RW_IO = 295,
     RW_BUFFER = 296,
     RW_RESIZE = 297,
     RW_QUERY_PLAN = 298,
     RW_ON = 299,
     RW_OFF = 300,
     T_INT = 301,
     T_REAL = 302,
     T_STRING = 303,
     T_QSTRING = 304,
     T_SHELL_CMD = 305
   };
#endif
/* Tokens.  */
#define RW_CREATE 258
#define RW_DROP 259
#define RW_TABLE 260
#define RW_INDEX 261
#define RW_LOAD 262
#define RW_SET 263
#define RW_HELP 264
#define RW_PRINT 265
#define RW_EXIT 266
#define RW_SELECT 267
#define RW_FROM 268
#define RW_WHERE 269
#define RW_ORDER 270
#define RW_GROUP 271
#define RW_MAX 272
#define RW_MIN 273
#define RW_SUM 274
#define RW_AVG 275
#define RW_COUNT 276
#define RW_BY 277
#define RW_DESC 278
#define RW_ASC 279
#define RW_INSERT 280
#define RW_DELETE 281
#define RW_UPDATE 282
#define RW_AND 283
#define RW_INTO 284
#define RW_VALUES 285
#define T_EQ 286
#define T_LT 287
#define T_LE 288
#define T_GT 289
#define T_GE 290
#define T_NE 291
#define T_EOF 292
#define NOTOKEN 293
#define RW_RESET 294
#define RW_IO 295
#define RW_BUFFER 296
#define RW_RESIZE 297
#define RW_QUERY_PLAN 298
#define RW_ON 299
#define RW_OFF 300
#define T_INT 301
#define T_REAL 302
#define T_STRING 303
#define T_QSTRING 304
#define T_SHELL_CMD 305




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 71 "parse.y"

    int ival;
    CompOp cval;
    AggFun aval;
    float rval;
    char *sval;
    NODE *n;



/* Line 214 of yacc.c  */
#line 291 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 303 "y.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  71
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   164

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNRULES -- Number of states.  */
#define YYNSTATES  172

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,    53,    55,     2,    54,     2,    56,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    48,    50,    52,    55,    58,    61,
      64,    68,    71,    74,    81,    88,    92,    99,   105,   110,
     113,   116,   118,   126,   134,   142,   147,   155,   159,   161,
     164,   166,   168,   172,   174,   181,   186,   190,   192,   197,
     199,   201,   203,   205,   207,   211,   213,   217,   219,   221,
     224,   226,   228,   232,   234,   238,   241,   243,   245,   247,
     251,   253,   257,   259,   261,   265,   267,   269,   271,   273,
     275,   277,   279,   281,   283,   285,   287,   289
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    51,    -1,    50,    -1,     1,    -1,
      37,    -1,    60,    -1,    61,    -1,    62,    -1,   100,    -1,
      66,    -1,    67,    -1,    68,    -1,    69,    -1,    75,    -1,
      76,    -1,    77,    -1,    78,    -1,    70,    -1,    74,    -1,
      71,    -1,    72,    -1,    73,    -1,    64,    -1,    65,    -1,
      63,    -1,    43,    44,    -1,    43,    45,    -1,    39,    41,
      -1,    10,    41,    -1,    42,    41,    46,    -1,    10,    40,
      -1,    39,    40,    -1,     3,     5,    48,    52,    79,    53,
      -1,     3,     6,    48,    52,    48,    53,    -1,     4,     5,
      48,    -1,     4,     6,    48,    52,    48,    53,    -1,     7,
      48,    52,    49,    53,    -1,     8,    48,    31,    49,    -1,
       9,    98,    -1,    10,    48,    -1,    11,    -1,    12,    81,
      13,    86,    88,    89,    90,    -1,    12,    81,    13,    86,
      88,    90,    89,    -1,    25,    29,    48,    30,    52,    96,
      53,    -1,    26,    13,    48,    88,    -1,    27,    48,     8,
      85,    31,    95,    88,    -1,    80,    54,    79,    -1,    80,
      -1,    48,    48,    -1,    82,    -1,    55,    -1,    83,    54,
      82,    -1,    83,    -1,    84,    52,    48,    56,    48,    53,
      -1,    84,    52,    48,    53,    -1,    48,    56,    48,    -1,
      48,    -1,    84,    52,    55,    53,    -1,    20,    -1,    17,
      -1,    18,    -1,    19,    -1,    21,    -1,    48,    56,    48,
      -1,    48,    -1,    87,    54,    86,    -1,    87,    -1,    48,
      -1,    14,    93,    -1,   100,    -1,   100,    -1,    15,    22,
      91,    -1,   100,    -1,    16,    22,    85,    -1,    85,    92,
      -1,    23,    -1,    24,    -1,   100,    -1,    94,    28,    93,
      -1,    94,    -1,    85,    99,    95,    -1,    85,    -1,    97,
      -1,    97,    54,    96,    -1,    97,    -1,    49,    -1,    46,
      -1,    47,    -1,    48,    -1,   100,    -1,    32,    -1,    33,
      -1,    34,    -1,    35,    -1,    31,    -1,    36,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   181,   181,   186,   196,   202,   211,   212,   213,   214,
     221,   222,   223,   224,   228,   229,   230,   231,   235,   236,
     237,   238,   239,   240,   241,   242,   246,   252,   263,   271,
     276,   284,   295,   308,   315,   322,   329,   336,   344,   351,
     358,   365,   373,   377,   385,   392,   399,   406,   410,   417,
     424,   425,   432,   436,   443,   447,   451,   455,   459,   466,
     470,   474,   478,   482,   500,   504,   511,   515,   522,   529,
     533,   540,   544,   551,   555,   562,   569,   573,   577,   585,
     589,   596,   603,   607,   614,   618,   625,   629,   633,   640,
     644,   651,   655,   659,   663,   667,   671,   677
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RW_CREATE", "RW_DROP", "RW_TABLE",
  "RW_INDEX", "RW_LOAD", "RW_SET", "RW_HELP", "RW_PRINT", "RW_EXIT",
  "RW_SELECT", "RW_FROM", "RW_WHERE", "RW_ORDER", "RW_GROUP", "RW_MAX",
  "RW_MIN", "RW_SUM", "RW_AVG", "RW_COUNT", "RW_BY", "RW_DESC", "RW_ASC",
  "RW_INSERT", "RW_DELETE", "RW_UPDATE", "RW_AND", "RW_INTO", "RW_VALUES",
  "T_EQ", "T_LT", "T_LE", "T_GT", "T_GE", "T_NE", "T_EOF", "NOTOKEN",
  "RW_RESET", "RW_IO", "RW_BUFFER", "RW_RESIZE", "RW_QUERY_PLAN", "RW_ON",
  "RW_OFF", "T_INT", "T_REAL", "T_STRING", "T_QSTRING", "T_SHELL_CMD",
  "';'", "'('", "')'", "','", "'*'", "'.'", "$accept", "start", "command",
  "ddl", "dml", "utility", "queryplans", "buffer", "statistics",
  "createtable", "createindex", "droptable", "dropindex", "load", "set",
  "help", "print", "exit", "query", "insert", "delete", "update",
  "non_mt_attrtype_list", "attrtype", "non_mt_select_clause",
  "non_mt_aggrelattr_list", "aggrelattr", "ammsc", "relattr",
  "non_mt_relation_list", "relation", "opt_where_clause",
  "opt_order_by_clause", "opt_group_by_clause", "ordering_spec",
  "opt_asc_desc", "non_mt_cond_list", "condition", "relattr_or_value",
  "non_mt_value_list", "value", "opt_relname", "op", "nothing", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,    59,    40,    41,    44,    42,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    60,    61,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    64,    64,
      64,    65,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    75,    76,    77,    78,    79,    79,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    83,    84,
      84,    84,    84,    84,    85,    85,    86,    86,    87,    88,
      88,    89,    89,    90,    90,    91,    92,    92,    92,    93,
      93,    94,    95,    95,    96,    96,    97,    97,    97,    98,
      98,    99,    99,    99,    99,    99,    99,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       3,     2,     2,     6,     6,     3,     6,     5,     4,     2,
       2,     1,     7,     7,     7,     4,     7,     3,     1,     2,
       1,     1,     3,     1,     6,     4,     3,     1,     4,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     1,     2,
       1,     1,     3,     1,     3,     2,     1,     1,     1,     3,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     0,     0,    97,     0,    41,     0,
       0,     0,     0,     5,     0,     0,     0,     3,     0,     0,
       6,     7,     8,    25,    23,    24,    10,    11,    12,    13,
      18,    20,    21,    22,    19,    14,    15,    16,    17,     9,
       0,     0,     0,     0,     0,     0,    89,    39,    90,    31,
      29,    40,    60,    61,    62,    59,    63,    57,    51,     0,
      50,    53,     0,     0,     0,     0,    32,    28,     0,    26,
      27,     1,     2,     0,     0,    35,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,    30,     0,     0,     0,
       0,    38,    56,    68,    97,    67,    52,     0,     0,     0,
       0,    45,    70,    65,     0,     0,     0,    48,     0,     0,
      37,    97,     0,    55,     0,    58,     0,     0,    69,    80,
       0,     0,    49,    33,     0,    34,    36,     0,     0,    97,
      97,    71,    66,     0,    87,    88,    86,     0,    85,    95,
      91,    92,    93,    94,    96,     0,     0,    64,    82,    97,
      83,    47,     0,     0,    42,    73,    43,    71,    54,    44,
       0,    81,    79,    46,    97,    72,    74,    84,    76,    77,
      75,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,   106,   107,    59,    60,    61,    62,   117,    94,
      95,   101,   129,   130,   165,   170,   118,   119,   149,   137,
     138,    47,   145,   102
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -119
static const yytype_int8 yypact[] =
{
       4,  -119,    47,    53,   -44,   -20,    -4,   -31,  -119,     1,
      21,    49,    12,  -119,    24,    40,    22,  -119,    80,    31,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
      35,    36,    37,    38,    41,    56,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,    32,  -119,    76,
    -119,    42,    43,    44,    46,    82,  -119,  -119,    45,  -119,
    -119,  -119,  -119,    48,    50,  -119,    51,    52,    57,    59,
      60,    15,   -10,    67,    84,    62,  -119,    64,    65,    66,
      63,  -119,  -119,  -119,    84,    68,  -119,    -5,    70,    69,
      62,  -119,  -119,    71,    73,    72,    75,    77,    79,    81,
    -119,    61,    60,  -119,    78,  -119,    -7,    39,  -119,    87,
      85,   -23,  -119,  -119,    64,  -119,  -119,    83,    95,    93,
     103,   104,  -119,    86,  -119,  -119,  -119,    88,    89,  -119,
    -119,  -119,  -119,  -119,  -119,   -23,    62,  -119,  -119,    84,
    -119,  -119,    62,    62,  -119,  -119,  -119,  -119,  -119,  -119,
      -7,  -119,  -119,  -119,    55,  -119,  -119,  -119,  -119,  -119,
    -119,  -119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,   -25,  -119,  -119,    54,  -119,  -119,   -84,    13,
    -119,   -92,    -6,     7,  -119,  -119,    -9,  -119,    -3,   -22,
    -118,  -119,  -119,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -98
static const yytype_int16 yytable[] =
{
      39,   104,   111,   150,    44,     1,    48,     2,     3,    49,
      50,     4,     5,     6,     7,     8,     9,    51,    52,    53,
      54,    55,    56,   134,   135,   103,   136,   150,    45,    10,
      11,    12,    52,    53,    54,    55,    56,   148,    97,   134,
     135,    13,   136,    14,    46,    98,    15,    16,   113,    57,
      63,   114,    40,    41,    17,   -97,    58,   163,    42,    43,
      65,   148,    64,    57,    66,    67,    69,    70,   164,   166,
     139,   140,   141,   142,   143,   144,   127,   128,   168,   169,
      71,    68,    72,    73,    74,    75,    76,    78,    79,    80,
      85,    86,    83,    77,    84,    82,    81,    99,   100,   151,
      87,    90,    88,    89,   121,   152,    91,    92,    93,   128,
     103,   131,   105,   108,   109,   146,   110,   153,   127,   -73,
     122,   116,   112,   115,   156,   132,   133,   120,   123,   155,
     157,   124,   125,   147,   126,    96,   154,   162,   167,   158,
       0,   159,   161,   160,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   171
};

static const yytype_int16 yycheck[] =
{
       0,    85,    94,   121,    48,     1,     6,     3,     4,    40,
      41,     7,     8,     9,    10,    11,    12,    48,    17,    18,
      19,    20,    21,    46,    47,    48,    49,   145,    48,    25,
      26,    27,    17,    18,    19,    20,    21,   121,    48,    46,
      47,    37,    49,    39,    48,    55,    42,    43,    53,    48,
      29,    56,     5,     6,    50,    51,    55,   149,     5,     6,
      48,   145,    13,    48,    40,    41,    44,    45,   152,   153,
      31,    32,    33,    34,    35,    36,    15,    16,    23,    24,
       0,    41,    51,    48,    48,    48,    48,    31,    56,    13,
       8,    46,    48,    52,    48,    52,    54,    30,    14,   124,
      52,    49,    52,    52,    31,    22,    49,    48,    48,    16,
      48,   111,    48,    48,    48,    28,    53,    22,    15,    15,
      48,    52,    54,    53,   130,   112,    48,    56,    53,   129,
     130,    54,    53,    48,    53,    81,   129,   146,   160,    53,
      -1,    53,   145,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     7,     8,     9,    10,    11,    12,
      25,    26,    27,    37,    39,    42,    43,    50,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   100,
       5,     6,     5,     6,    48,    48,    48,    98,   100,    40,
      41,    48,    17,    18,    19,    20,    21,    48,    55,    81,
      82,    83,    84,    29,    13,    48,    40,    41,    41,    44,
      45,     0,    51,    48,    48,    48,    48,    52,    31,    56,
      13,    54,    52,    48,    48,     8,    46,    52,    52,    52,
      49,    49,    48,    48,    86,    87,    82,    48,    55,    30,
      14,    88,   100,    48,    85,    48,    79,    80,    48,    48,
      53,    88,    54,    53,    56,    53,    52,    85,    93,    94,
      56,    31,    48,    53,    54,    53,    53,    15,    16,    89,
      90,   100,    86,    48,    46,    47,    49,    96,    97,    31,
      32,    33,    34,    35,    36,    99,    28,    48,    85,    95,
      97,    79,    22,    22,    90,   100,    89,   100,    53,    53,
      54,    95,    93,    88,    85,    91,    85,    96,    23,    24,
      92,   100
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 182 "parse.y"
    {
      parse_tree = (yyvsp[(1) - (2)].n);
      YYACCEPT;
   }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 187 "parse.y"
    {
      if (!isatty(0)) {
        cout << ((yyvsp[(1) - (1)].sval)) << "\n";
        cout.flush();
      }
      system((yyvsp[(1) - (1)].sval));
      parse_tree = NULL;
      YYACCEPT;
   }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 197 "parse.y"
    {
      reset_scanner();
      parse_tree = NULL;
      YYACCEPT;
   }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 203 "parse.y"
    {
      parse_tree = NULL;
      bExit = 1;
      YYACCEPT;
   }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 215 "parse.y"
    {
      (yyval.n) = NULL;
   }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 247 "parse.y"
    {
      bQueryPlans = 1;
      cout << "Query plan display turned on.\n";
      (yyval.n) = NULL;
   }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 253 "parse.y"
    { 
      bQueryPlans = 0;
      cout << "Query plan display turned off.\n";
      (yyval.n) = NULL;
   }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 264 "parse.y"
    {
      if (pPfm->ClearBuffer())
         cout << "Trouble clearing buffer!  Things may be pinned.\n";
      else 
         cout << "Everything kicked out of Buffer!\n";
      (yyval.n) = NULL;
   }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 272 "parse.y"
    {
      pPfm->PrintBuffer();
      (yyval.n) = NULL;
   }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 277 "parse.y"
    {
      pPfm->ResizeBuffer((yyvsp[(3) - (3)].ival));
      (yyval.n) = NULL;
   }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 285 "parse.y"
    {
      #ifdef PF_STATS
         cout << "Statistics\n";
         cout << "----------\n";
         pStatisticsMgr->Print();
      #else
         cout << "Statitisics not compiled.\n";
      #endif
      (yyval.n) = NULL;
   }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 296 "parse.y"
    {
      #ifdef PF_STATS
         cout << "Statistics reset.\n";
         pStatisticsMgr->Reset();
      #else
         cout << "Statitisics not compiled.\n";
      #endif
      (yyval.n) = NULL;
   }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 309 "parse.y"
    {
      (yyval.n) = create_table_node((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].n));
   }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 316 "parse.y"
    {
      (yyval.n) = create_index_node((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].sval));
   }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 323 "parse.y"
    {
      (yyval.n) = drop_table_node((yyvsp[(3) - (3)].sval));
   }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 330 "parse.y"
    {
      (yyval.n) = drop_index_node((yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].sval));
   }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 337 "parse.y"
    {
      (yyval.n) = load_node((yyvsp[(2) - (5)].sval), (yyvsp[(4) - (5)].sval));
   }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 345 "parse.y"
    {
      (yyval.n) = set_node((yyvsp[(2) - (4)].sval), (yyvsp[(4) - (4)].sval));
   }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 352 "parse.y"
    {
      (yyval.n) = help_node((yyvsp[(2) - (2)].sval));
   }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 359 "parse.y"
    {
      (yyval.n) = print_node((yyvsp[(2) - (2)].sval));
   }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 366 "parse.y"
    {
      (yyval.n) = NULL;
      bExit = 1;
   }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 374 "parse.y"
    {
     (yyval.n) = query_node((yyvsp[(2) - (7)].n), (yyvsp[(4) - (7)].n), (yyvsp[(5) - (7)].n), (yyvsp[(6) - (7)].n), (yyvsp[(7) - (7)].n));
   }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 378 "parse.y"
    {
     (yyval.n) = query_node((yyvsp[(2) - (7)].n), (yyvsp[(4) - (7)].n), (yyvsp[(5) - (7)].n), (yyvsp[(7) - (7)].n), (yyvsp[(6) - (7)].n));
   }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 386 "parse.y"
    {
      (yyval.n) = insert_node((yyvsp[(3) - (7)].sval), (yyvsp[(6) - (7)].n));
   }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 393 "parse.y"
    {
      (yyval.n) = delete_node((yyvsp[(3) - (4)].sval), (yyvsp[(4) - (4)].n));
   }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 400 "parse.y"
    {
     (yyval.n) = update_node((yyvsp[(2) - (7)].sval), (yyvsp[(4) - (7)].n), (yyvsp[(6) - (7)].n), (yyvsp[(7) - (7)].n));
   }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 407 "parse.y"
    {
      (yyval.n) = prepend((yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n));
   }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 411 "parse.y"
    {
      (yyval.n) = list_node((yyvsp[(1) - (1)].n));
   }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 418 "parse.y"
    {
      (yyval.n) = attrtype_node((yyvsp[(1) - (2)].sval), (yyvsp[(2) - (2)].sval));
   }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 426 "parse.y"
    {
     (yyval.n) = list_node(aggrelattr_node(NO_F, NULL, (char*)"*"));
   }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 433 "parse.y"
    {
      (yyval.n) = prepend((yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n));
   }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 437 "parse.y"
    {
      (yyval.n) = list_node((yyvsp[(1) - (1)].n));
   }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 444 "parse.y"
    {
     (yyval.n) = aggrelattr_node((yyvsp[(1) - (6)].aval), (yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].sval));
   }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 448 "parse.y"
    {
     (yyval.n) = aggrelattr_node((yyvsp[(1) - (4)].aval), NULL, (yyvsp[(3) - (4)].sval));
   }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 452 "parse.y"
    {
     (yyval.n) = aggrelattr_node(NO_F, (yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
   }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 456 "parse.y"
    {
     (yyval.n) = aggrelattr_node(NO_F, NULL, (yyvsp[(1) - (1)].sval));
   }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 460 "parse.y"
    {
     (yyval.n) = aggrelattr_node((yyvsp[(1) - (4)].aval), NULL, (char*)"*");
   }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 467 "parse.y"
    { 
     (yyval.aval) = AVG_F;
   }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 471 "parse.y"
    { 
     (yyval.aval) = MAX_F;
   }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 475 "parse.y"
    { 
     (yyval.aval) = MIN_F;
   }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 479 "parse.y"
    { 
     (yyval.aval) = SUM_F;
   }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 483 "parse.y"
    { 
     (yyval.aval) = COUNT_F;
   }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 501 "parse.y"
    {
      (yyval.n) = relattr_node((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval));
   }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 505 "parse.y"
    {
      (yyval.n) = relattr_node(NULL, (yyvsp[(1) - (1)].sval));
   }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 512 "parse.y"
    {
      (yyval.n) = prepend((yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n));
   }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 516 "parse.y"
    {
      (yyval.n) = list_node((yyvsp[(1) - (1)].n));
   }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 523 "parse.y"
    {
      (yyval.n) = relation_node((yyvsp[(1) - (1)].sval));
   }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 530 "parse.y"
    {
      (yyval.n) = (yyvsp[(2) - (2)].n);
   }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 534 "parse.y"
    {
      (yyval.n) = NULL;
   }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 541 "parse.y"
    {
      (yyval.n) = orderattr_node(0, 0);
   }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 545 "parse.y"
    {
     (yyval.n) = (yyvsp[(3) - (3)].n);
   }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 552 "parse.y"
    {
     (yyval.n) = relattr_node(NULL, NULL);
   }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 556 "parse.y"
    {
     (yyval.n) = (yyvsp[(3) - (3)].n);
   }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 563 "parse.y"
    {
     (yyval.n) = orderattr_node((yyvsp[(2) - (2)].ival), (yyvsp[(1) - (2)].n));
   }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 570 "parse.y"
    {
    (yyval.ival) = -1;
  }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 574 "parse.y"
    {
    (yyval.ival) = 1;
  }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 578 "parse.y"
    {
    (yyval.ival) = 1;
  }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 586 "parse.y"
    {
      (yyval.n) = prepend((yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n));
   }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 590 "parse.y"
    {
      (yyval.n) = list_node((yyvsp[(1) - (1)].n));
   }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 597 "parse.y"
    {
      (yyval.n) = condition_node((yyvsp[(1) - (3)].n), (yyvsp[(2) - (3)].cval), (yyvsp[(3) - (3)].n));
   }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 604 "parse.y"
    {
      (yyval.n) = relattr_or_value_node((yyvsp[(1) - (1)].n), NULL);
   }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 608 "parse.y"
    {
      (yyval.n) = relattr_or_value_node(NULL, (yyvsp[(1) - (1)].n));
   }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 615 "parse.y"
    {
      (yyval.n) = prepend((yyvsp[(1) - (3)].n), (yyvsp[(3) - (3)].n));
   }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 619 "parse.y"
    {
      (yyval.n) = list_node((yyvsp[(1) - (1)].n));
   }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 626 "parse.y"
    {
      (yyval.n) = value_node(STRING, (void *) (yyvsp[(1) - (1)].sval));
   }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 630 "parse.y"
    {
      (yyval.n) = value_node(INT, (void *)& (yyvsp[(1) - (1)].ival));
   }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 634 "parse.y"
    {
      (yyval.n) = value_node(FLOAT, (void *)& (yyvsp[(1) - (1)].rval));
   }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 641 "parse.y"
    {
      (yyval.sval) = (yyvsp[(1) - (1)].sval);
   }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 645 "parse.y"
    {
      (yyval.sval) = NULL;
   }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 652 "parse.y"
    {
      (yyval.cval) = LT_OP;
   }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 656 "parse.y"
    {
      (yyval.cval) = LE_OP;
   }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 660 "parse.y"
    {
      (yyval.cval) = GT_OP;
   }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 664 "parse.y"
    {
      (yyval.cval) = GE_OP;
   }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 668 "parse.y"
    {
      (yyval.cval) = EQ_OP;
   }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 672 "parse.y"
    {
      (yyval.cval) = NE_OP;
   }
    break;



/* Line 1455 of yacc.c  */
#line 2371 "y.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 681 "parse.y"


//
// PrintError
//
// Desc: Print an error message by calling the proper component-specific
//       print-error function
//
void PrintError(RC rc)
{
   if (abs(rc) <= END_PF_WARN)
      PF_PrintError(rc);
   else if (abs(rc) <= END_RM_WARN)
      RM_PrintError(rc);
   else if (abs(rc) <= END_IX_WARN)
      IX_PrintError(rc);
   else if (abs(rc) <= END_SM_WARN)
      SM_PrintError(rc);
   else if (abs(rc) <= END_QL_WARN)
      QL_PrintError(rc);
   else
      cerr << "Error code out of range: " << rc << "\n";
}

//
// RBparse
//
// Desc: Parse redbase commands
//
RC RBparse(PF_Manager &pfm, SM_Manager &smm, QL_Manager &qlm)
{
   RC rc;

   // Set up global variables to their defaults
   pPfm  = &pfm;
   pSmm  = &smm;
   pQlm  = &qlm;
   bExit = 0;
   bQueryPlans = 0;

   /* Do forever */
   while (!bExit) {

      /* Reset parser and scanner for a new query */
      new_query();

      /* Print a prompt */
      cout << PROMPT;

      /* Get the prompt to actually show up on the screen */
      cout.flush(); 

      /* If a query was successfully read, interpret it */
      if(yyparse() == 0 && parse_tree != NULL)
         if ((rc = interp(parse_tree))) {
            PrintError(rc);
            if (rc < 0)
               bExit = TRUE;
         }
   }
   return rc;
}

//
// Functions for printing the various structures to an output stream
//
ostream &operator<<(ostream &s, const AttrInfo &ai)
{
   return
      s << " attrName=" << ai.attrName
      << " attrType=" << 
      (ai.attrType == INT ? "INT" :
       ai.attrType == FLOAT ? "FLOAT" : "STRING")
      << " attrLength=" << ai.attrLength;
}

ostream &operator<<(ostream &s, const RelAttr &qa)
{
   return
      s << (qa.relName ? qa.relName : "NULL")
      << "." << qa.attrName;
}

ostream &operator<<(ostream &s, const AggRelAttr &qa)
{
  if(qa.func == NO_F)
   return 
      s << (qa.relName ? qa.relName : "NULL")
      << "." << qa.attrName;
  else
   return
      s << qa.func << "(" << (qa.relName ? qa.relName : "NULL")
        << "." << qa.attrName << ")";
}

ostream &operator<<(ostream &s, const Condition &c)
{
   s << "\n      lhsAttr:" << c.lhsAttr << "\n"
      << "      op=" << c.op << "\n";
   if (c.bRhsIsAttr)
      s << "      bRhsIsAttr=TRUE \n      rhsAttr:" << c.rhsAttr;
   else
      s << "      bRshIsAttr=FALSE\n      rhsValue:" << c.rhsValue;
   return s;
}

ostream &operator<<(ostream &s, const Value &v)
{
   s << "AttrType: " << v.type;
   switch (v.type) {
      case INT:
         s << " *(int *)data=" << *(int *)v.data;
         break;
      case FLOAT:
         s << " *(float *)data=" << *(float *)v.data;
         break;
      case STRING:
         s << " (char *)data=" << (char *)v.data;
         break;
   }
   return s;
}

ostream &operator<<(ostream &s, const AggFun &func)
{
   switch(func){
      case MIN_F:
         s << " MIN";
         break;
      case MAX_F:
         s << " MAX";
         break;
      case AVG_F:
         s << " AVG";
         break;
      case SUM_F:
         s << " SUM";
         break;
      case COUNT_F:
         s << " COUNT";
         break;
      default:
         // case NO_F:
         s << " ";
         break;
   }
   return s;
}

ostream &operator<<(ostream &s, const CompOp &op)
{
   switch(op){
      case EQ_OP:
         s << " =";
         break;
      case NE_OP:
         s << " <>";
         break;
      case LT_OP:
         s << " <";
         break;
      case LE_OP:
         s << " <=";
         break;
      case GT_OP:
         s << " >";
         break;
      case GE_OP:
         s << " >=";
         break;
      case NO_OP:
         s << " NO_OP";
         break;
   }
   return s;
}

ostream &operator<<(ostream &s, const AttrType &at)
{
   switch(at){
      case INT:
         s << "INT";
         break;
      case FLOAT:
         s << "FLOAT";
         break;
      case STRING:
         s << "STRING";
         break;
   }
   return s;
}

/*
 * Required by yacc
 */
void yyerror(char const *s) // New in 2000
{
   puts(s);
}

#if 0
/*
 * Sometimes required
 */
int yywrap(void)
{
   return 1;
}
#endif

