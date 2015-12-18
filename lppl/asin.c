/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 10 "src/asin.y"

#include <stdio.h>
#include "libtds.h"
#include "libgci.h"
#include "header.h"
#include "headops.h"

/* Line 371 of yacc.c  */
#line 76 "asin.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "asin.h".  */
#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ABRECORCHETE_ = 258,
     CIERRACORCHETE_ = 259,
     ABRECLAUDATOR_ = 260,
     CIERRACLAUDATOR_ = 261,
     ABREPARENTESIS_ = 262,
     CIERRAPARENTESIS_ = 263,
     PUNTOCOMA_ = 264,
     ID_ = 265,
     CTE_ = 266,
     COMENTARIO_ = 267,
     INT_ = 268,
     BOOL_ = 269,
     READ_ = 270,
     PRINT_ = 271,
     IF_ = 272,
     ELSE_ = 273,
     WHILE_ = 274,
     TRUE_ = 275,
     FALSE_ = 276,
     IGUAL_ = 277,
     MASIGUAL_ = 278,
     MENOSIGUAL_ = 279,
     OROR_ = 280,
     ANDAND_ = 281,
     IGUALIGUAL_ = 282,
     DIFERENTE_ = 283,
     MAYORQ_ = 284,
     MENORQ_ = 285,
     MAYORIG_ = 286,
     MENORIG_ = 287,
     MENOS_ = 288,
     MAS_ = 289,
     ENTRE_ = 290,
     POR_ = 291,
     NEG_ = 292,
     MASMAS_ = 293,
     MENOSMENOS_ = 294
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 20 "src/asin.y"

  char *id;
  int cte;
  int tip;
  struct {
    int tipo;
    int pos;
  } expr; /*para los no terminales expresion*/


/* Line 387 of yacc.c  */
#line 169 "asin.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_ASIN_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 197 "asin.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   190

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  117

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     7,    10,    12,    15,    17,    19,    23,
      30,    32,    34,    38,    40,    42,    44,    46,    47,    50,
      53,    55,    61,    67,    68,    69,    79,    80,    81,    89,
      91,    95,   102,   104,   108,   110,   114,   116,   120,   122,
     126,   128,   132,   134,   137,   140,   145,   149,   151,   154,
     156,   158,   160,   162,   164,   166,   168,   170,   172,   174,
     176,   178,   180,   182,   184,   186,   188,   190,   192,   194,
     196,   198
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,     3,    42,     4,    -1,     3,     4,    -1,
      43,    -1,    42,    43,    -1,    44,    -1,    46,    -1,    45,
      10,     9,    -1,    45,    10,     5,    11,     6,     9,    -1,
      13,    -1,    14,    -1,     3,    47,     4,    -1,    48,    -1,
      49,    -1,    50,    -1,    53,    -1,    -1,    47,    46,    -1,
      56,     9,    -1,     9,    -1,    15,     7,    10,     8,     9,
      -1,    16,     7,    56,     8,     9,    -1,    -1,    -1,    17,
       7,    56,     8,    51,    46,    52,    18,    46,    -1,    -1,
      -1,    19,    54,     7,    56,     8,    55,    46,    -1,    57,
      -1,    10,    64,    56,    -1,    10,     5,    56,     6,    64,
      56,    -1,    58,    -1,    57,    65,    58,    -1,    59,    -1,
      58,    66,    59,    -1,    60,    -1,    59,    67,    60,    -1,
      61,    -1,    60,    68,    61,    -1,    62,    -1,    61,    69,
      62,    -1,    63,    -1,    70,    62,    -1,    71,    10,    -1,
      10,     5,    56,     6,    -1,     7,    56,     8,    -1,    10,
      -1,    10,    71,    -1,    11,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,    24,    -1,    26,    -1,    25,    -1,
      27,    -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,
      32,    -1,    34,    -1,    33,    -1,    36,    -1,    35,    -1,
      34,    -1,    33,    -1,    37,    -1,    38,    -1,    39,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    87,    92,    93,    98,    99,   104,   113,
     128,   130,   136,   137,   138,   139,   140,   144,   145,   150,
     151,   156,   161,   169,   174,   168,   182,   186,   181,   202,
     208,   225,   242,   247,   272,   277,   300,   305,   330,   335,
     352,   357,   374,   379,   400,   422,   435,   440,   451,   468,
     470,   472,   478,   480,   482,   488,   490,   496,   498,   504,
     506,   508,   510,   516,   518,   524,   526,   532,   534,   536,
     542,   544
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABRECORCHETE_", "CIERRACORCHETE_",
  "ABRECLAUDATOR_", "CIERRACLAUDATOR_", "ABREPARENTESIS_",
  "CIERRAPARENTESIS_", "PUNTOCOMA_", "ID_", "CTE_", "COMENTARIO_", "INT_",
  "BOOL_", "READ_", "PRINT_", "IF_", "ELSE_", "WHILE_", "TRUE_", "FALSE_",
  "IGUAL_", "MASIGUAL_", "MENOSIGUAL_", "OROR_", "ANDAND_", "IGUALIGUAL_",
  "DIFERENTE_", "MAYORQ_", "MENORQ_", "MAYORIG_", "MENORIG_", "MENOS_",
  "MAS_", "ENTRE_", "POR_", "NEG_", "MASMAS_", "MENOSMENOS_", "$accept",
  "programa", "secuenciaSentencias", "sentencia", "declaracion",
  "tipoSimple", "instruccion", "listaInstrucciones",
  "instruccionExpresion", "instruccionEntradaSalida",
  "instruccionSeleccion", "@1", "$@2", "instruccionIteracion", "@3", "@4",
  "expresion", "expresionLogica", "expresionIgualdad",
  "expresionRelacional", "expresionAditiva", "expresionMultiplicativa",
  "expresionUnaria", "expresionSufija", "operadorAsignacion",
  "operadorLogico", "operadorIgualdad", "operadorRelacional",
  "operadorAditivo", "operadorMultiplicativo", "operadorUnario",
  "operadorIncremento", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    41,    42,    42,    43,    43,    44,    44,
      45,    45,    46,    46,    46,    46,    46,    47,    47,    48,
      48,    49,    49,    51,    52,    50,    54,    55,    53,    56,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    70,
      71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     2,     1,     1,     3,     6,
       1,     1,     3,     1,     1,     1,     1,     0,     2,     2,
       1,     5,     5,     0,     0,     9,     0,     0,     7,     1,
       3,     6,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     2,     4,     3,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    17,     3,     0,    20,    47,    49,    10,
      11,     0,     0,     0,    26,    50,    51,    68,    67,    69,
      70,    71,     0,     4,     6,     0,     7,    13,    14,    15,
      16,     0,    29,    32,    34,    36,    38,    40,    42,     0,
       0,     1,     0,     0,     0,    52,    53,    54,     0,    48,
       0,     0,     0,     0,     2,     5,     0,    19,    56,    55,
       0,    57,    58,     0,    59,    60,    61,    62,     0,    64,
      63,     0,    66,    65,     0,    47,    43,    44,    12,    18,
      46,     0,    30,     0,     0,     0,     0,     0,     8,    33,
      35,    37,    39,    41,     0,    45,     0,     0,    23,     0,
       0,     0,     0,    21,    22,     0,    27,     0,    45,    31,
      24,     0,     9,     0,    28,     0,    25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    22,    23,    24,    25,    26,    42,    27,    28,
      29,   105,   113,    30,    53,   111,    31,    32,    33,    34,
      35,    36,    37,    38,    48,    60,    63,    68,    71,    74,
      39,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -42
static const yytype_int16 yypact[] =
{
       2,     3,    11,   -42,   -42,   131,   -42,    90,   -42,   -42,
     -42,    14,    18,    31,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,    46,   -42,   -42,    -8,   -42,   -42,   -42,   -42,
     -42,    36,    26,     6,    -3,    39,    40,   -42,   -42,   151,
       5,   -42,    83,    50,   131,   -42,   -42,   -42,   131,   -42,
      38,   131,   131,    47,   -42,   -42,    -1,   -42,   -42,   -42,
     151,   -42,   -42,   151,   -42,   -42,   -42,   -42,   151,   -42,
     -42,   151,   -42,   -42,   151,    30,   -42,   -42,   -42,   -42,
     -42,    71,   -42,    70,    74,    80,   131,    85,   -42,     6,
      -3,    39,    40,   -42,   131,     8,    82,    92,   -42,    97,
     100,   101,   131,   -42,   -42,   116,   -42,    99,   -42,   -42,
     -42,   116,   -42,    91,   -42,   116,   -42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -42,    88,   -42,   -42,   -41,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,    -5,   -42,    51,    52,
      56,    59,   -30,   -42,    23,   -42,   -42,   -42,   -42,   -42,
     -42,    -4
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      43,    79,    56,    49,    87,     1,     3,     4,    88,    76,
       5,    41,     6,     7,     8,    77,     9,    10,    11,    12,
      13,    50,    14,    15,    16,    51,    64,    65,    66,    67,
      45,    46,    47,    61,    62,    94,    17,    18,    52,    81,
      19,    20,    21,    82,    93,    57,    84,    85,    83,     3,
      54,    58,    59,     5,    86,     6,     7,     8,    80,     9,
      10,    11,    12,    13,   110,    14,    15,    16,    20,    21,
     114,    49,    69,    70,   116,    72,    73,    95,    96,    17,
      18,    99,    97,    19,    20,    21,     3,    78,    98,   101,
       5,   103,     6,     7,     8,    44,   100,   109,    11,    12,
      13,   104,    14,    15,    16,   106,   107,   108,   112,   115,
      55,    89,    45,    46,    47,    90,    17,    18,   102,     3,
      19,    20,    21,     5,    91,     6,     7,     8,    20,    21,
      92,    11,    12,    13,     0,    14,    15,    16,     5,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,    17,
      18,    15,    16,    19,    20,    21,     0,     0,     5,     0,
       0,    75,     8,     0,    17,    18,     0,     0,    19,    20,
      21,    15,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,     0,     0,    19,    20,
      21
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-42)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       5,    42,    10,     7,     5,     3,     3,     4,     9,    39,
       7,     0,     9,    10,    11,    10,    13,    14,    15,    16,
      17,     7,    19,    20,    21,     7,    29,    30,    31,    32,
      22,    23,    24,    27,    28,     5,    33,    34,     7,    44,
      37,    38,    39,    48,    74,     9,    51,    52,    10,     3,
       4,    25,    26,     7,     7,     9,    10,    11,     8,    13,
      14,    15,    16,    17,   105,    19,    20,    21,    38,    39,
     111,    75,    33,    34,   115,    35,    36,     6,     8,    33,
      34,    86,     8,    37,    38,    39,     3,     4,     8,    94,
       7,     9,     9,    10,    11,     5,    11,   102,    15,    16,
      17,     9,    19,    20,    21,     8,     6,     6,     9,    18,
      22,    60,    22,    23,    24,    63,    33,    34,    95,     3,
      37,    38,    39,     7,    68,     9,    10,    11,    38,    39,
      71,    15,    16,    17,    -1,    19,    20,    21,     7,    -1,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    20,    21,    37,    38,    39,    -1,    -1,     7,    -1,
      -1,    10,    11,    -1,    33,    34,    -1,    -1,    37,    38,
      39,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,    38,
      39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    41,     3,     4,     7,     9,    10,    11,    13,
      14,    15,    16,    17,    19,    20,    21,    33,    34,    37,
      38,    39,    42,    43,    44,    45,    46,    48,    49,    50,
      53,    56,    57,    58,    59,    60,    61,    62,    63,    70,
      71,     0,    47,    56,     5,    22,    23,    24,    64,    71,
       7,     7,     7,    54,     4,    43,    10,     9,    25,    26,
      65,    27,    28,    66,    29,    30,    31,    32,    67,    33,
      34,    68,    35,    36,    69,    10,    62,    10,     4,    46,
       8,    56,    56,    10,    56,    56,     7,     5,     9,    58,
      59,    60,    61,    62,     5,     6,     8,     8,     8,    56,
      11,    56,    64,     9,     9,    51,     8,     6,     6,    56,
      46,    55,     9,    52,    46,    18,    46
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1792 of yacc.c  */
#line 85 "src/asin.y"
    { if (flagMostrarTDS) mostrarTDS();
      }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 106 "src/asin.y"
    {
	  if (!insertarTSimpleTDS((yyvsp[(2) - (3)].id), (yyvsp[(1) - (3)].tip), dvar))
	    yyerror("Identificador repetido");
	  else
	    dvar += TALLA_TIPO_SIMPLE;
	}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 114 "src/asin.y"
    { int numelem = (yyvsp[(4) - (6)].cte);
    if ((yyvsp[(4) - (6)].cte) <= 0) {
      yyerror("Talla inapropiada del array");
      numelem = 0;
    }
    if (!insertarTVectorTDS((yyvsp[(2) - (6)].id), T_ARRAY, dvar, (yyvsp[(1) - (6)].tip), numelem))
      yyerror("Identificador repetido");
    else
      dvar += TALLA_TIPO_SIMPLE * (yyvsp[(4) - (6)].cte);
	}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 129 "src/asin.y"
    { (yyval.tip) = T_ENTERO; }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 131 "src/asin.y"
    { (yyval.tip) = T_LOGICO; }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 157 "src/asin.y"
    { SIMB sim = obtenerTDS((yyvsp[(3) - (5)].id));
	  if (sim.tipo == T_ERROR) yyerror("Objeto no declarado");
	  else emite(EREAD, crArgNul(), crArgNul(), crArgPos(sim.desp));
	}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 162 "src/asin.y"
    { emite(EWRITE, crArgNul(), crArgNul(), crArgPos((yyvsp[(3) - (5)].expr).pos));
  }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 169 "src/asin.y"
    { if ((yyvsp[(3) - (4)].expr).tipo != T_ERROR && (yyvsp[(3) - (4)].expr).tipo != T_LOGICO) yyerror("La expresion en IF no es de tipo logico");
	  (yyval.cte) = creaLans(si);
	  emite(EIGUAL, crArgPos((yyvsp[(3) - (4)].expr).pos), crArgEnt(0), crArgEtq((yyval.cte)));
	}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 174 "src/asin.y"
    { completaLans((yyvsp[(5) - (6)].cte), crArgPos(si));
	}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 182 "src/asin.y"
    { 
          (yyval.cte) = si;
    }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 186 "src/asin.y"
    {
	  if ((yyvsp[(4) - (5)].expr).tipo != T_LOGICO) yyerror("La expresion en WHILE no es de tipo logico");
	  (yyval.cte) = creaLans(si);
	  emite(EIGUAL, crArgPos((yyvsp[(4) - (5)].expr).pos), crArgEnt(0), (yyval.cte));
	}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 192 "src/asin.y"
    {
	  emite(GOTOS, crArgNul(), crArgNul(), (yyvsp[(2) - (7)].cte));
	  completaLans((yyvsp[(5) - (7)].cte), crArgEtq(si));
	}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 203 "src/asin.y"
    { (yyval.expr).tipo = (yyvsp[(1) - (1)].expr).tipo;
    (yyval.expr).pos = creaVarTemp();
    emite(EASIG, crArgPos((yyvsp[(1) - (1)].expr).pos), crArgNul(), crArgPos((yyval.expr).pos));
  }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 209 "src/asin.y"
    { SIMB sim = obtenerTDS((yyvsp[(1) - (3)].id)); (yyval.expr).tipo = T_ERROR;
    if (sim.tipo == T_ERROR) yyerror("Objeto no declarado");
    else if (!((((yyvsp[(3) - (3)].expr).tipo == T_ENTERO) || ((yyvsp[(3) - (3)].expr).tipo == T_LOGICO)) &&
              ((sim.tipo == T_ENTERO) || (sim.tipo == T_LOGICO)) &&
               (sim.tipo == (yyvsp[(3) - (3)].expr).tipo)) && ((yyvsp[(3) - (3)].expr).tipo != T_ERROR))
      yyerror("Error de tipos en la 'asignacion'");
    else (yyval.expr).tipo = sim.tipo;
    
    if ((yyvsp[(2) - (3)].cte) == OPIGUAL)
      emite(EASIG, crArgPos((yyvsp[(3) - (3)].expr).pos), crArgNul(), crArgPos(sim.desp));
    else if ((yyvsp[(2) - (3)].cte) == OPSUMIG)
      emite(ESUM, crArgPos(sim.desp), crArgPos((yyvsp[(3) - (3)].expr).pos), crArgPos(sim.desp));
    else
      emite(EDIF, crArgPos(sim.desp), crArgPos((yyvsp[(3) - (3)].expr).pos), crArgPos(sim.desp));
  }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 226 "src/asin.y"
    { SIMB sim = obtenerTDS((yyvsp[(1) - (6)].id)); (yyval.expr).tipo = T_ERROR;
    if (sim.tipo == T_ERROR) yyerror("Objeto no declarado");
    else if ((yyvsp[(3) - (6)].expr).tipo != T_ENTERO) yyerror("Indice no entero");
    else if (sim.tipo != T_ARRAY) yyerror("El objeto debe ser un vector");
    else if (!((((yyvsp[(6) - (6)].expr).tipo == T_ENTERO) || ((yyvsp[(6) - (6)].expr).tipo == T_LOGICO)) &&
              ((sim.telem == T_ENTERO) || (sim.telem == T_LOGICO)) &&
               (sim.telem == (yyvsp[(6) - (6)].expr).tipo)) && ((yyvsp[(3) - (6)].expr).tipo != T_ERROR))
	  yyerror("Error de tipos en la 'asignacion'");
	else (yyval.expr).tipo = sim.telem;
    
    emite(EVA, crArgPos(sim.desp), crArgPos((yyvsp[(3) - (6)].expr).pos), crArgPos((yyvsp[(6) - (6)].expr).pos));
  }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 243 "src/asin.y"
    { (yyval.expr).tipo = (yyvsp[(1) - (1)].expr).tipo;
      (yyval.expr).pos = creaVarTemp();
      emite(EASIG, crArgPos((yyvsp[(1) - (1)].expr).pos), crArgNul(), crArgPos((yyval.expr).pos));
    }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 248 "src/asin.y"
    { (yyval.expr).tipo = T_ERROR;
    if ((yyvsp[(1) - (3)].expr).tipo != T_LOGICO || (yyvsp[(3) - (3)].expr).tipo != T_LOGICO)
        yyerror("Los tipos no son 'T_LOGICO'");
    else
        (yyval.expr).tipo = (yyvsp[(1) - (3)].expr).tipo;

    (yyval.expr).pos = creaVarTemp();
    if ((yyvsp[(2) - (3)].cte) == OPANDAND) {
	  emite(EASIG, crArgEnt(0), crArgNul(), crArgPos((yyval.expr).pos));
	  emite(EIGUAL, crArgPos((yyvsp[(1) - (3)].expr).pos), crArgEnt(0), crArgEtq(si+3));
	  emite(EIGUAL, crArgPos((yyvsp[(3) - (3)].expr).pos), crArgEnt(0), crArgEtq(si+2));
	  emite(EASIG, crArgEnt(1), crArgNul(), crArgPos((yyval.expr).pos));
	}
    else {
	  emite(EASIG, crArgEnt(1), crArgNul(), crArgPos((yyval.expr).pos));
	  emite(EIGUAL, crArgPos((yyvsp[(1) - (3)].expr).pos), crArgEnt(1), crArgEtq(si+3));
	  emite(EIGUAL, crArgPos((yyvsp[(3) - (3)].expr).pos), crArgEnt(1), crArgEtq(si+2));
	  emite(EASIG, crArgEnt(0), crArgNul(), crArgPos((yyval.expr).pos));
	}
  }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 273 "src/asin.y"
    { (yyval.expr).tipo = (yyvsp[(1) - (1)].expr).tipo;
      (yyval.expr).pos = creaVarTemp();
      emite(EASIG, crArgPos((yyvsp[(1) - (1)].expr).pos), crArgNul(), crArgPos((yyval.expr).pos));
    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 278 "src/asin.y"
    { (yyval.expr).tipo = T_ERROR;
    if (!((((yyvsp[(1) - (3)].expr).tipo == T_ENTERO) || ((yyvsp[(1) - (3)].expr).tipo == T_LOGICO)) &&
        (((yyvsp[(3) - (3)].expr).tipo == T_ENTERO) || ((yyvsp[(3) - (3)].expr).tipo == T_LOGICO)) &&
        ((yyvsp[(1) - (3)].expr).tipo == (yyvsp[(3) - (3)].expr).tipo)))
        yyerror("Las expresiones no son del mismo tipo o no son validas");
    else
        (yyval.expr).tipo = T_LOGICO;
        
	(yyval.expr).pos = creaVarTemp();
	emite(EASIG, crArgEnt(1), crArgNul(), crArgPos((yyval.expr).pos));
	
	if ((yyvsp[(2) - (3)].cte) == OPIGIG)
	  emite(EIGUAL, crArgPos((yyvsp[(1) - (3)].expr).pos), crArgPos((yyvsp[(3) - (3)].expr).pos), crArgEtq(si+2));
	else
	  emite(EDIST, crArgPos((yyvsp[(1) - (3)].expr).pos), crArgPos((yyvsp[(3) - (3)].expr).pos), crArgEtq(si+2));
	
	emite(EASIG, crArgEnt(0), crArgNul(), crArgPos((yyval.expr).pos));
  }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 301 "src/asin.y"
    { (yyval.expr).tipo = (yyvsp[(1) - (1)].expr).tipo;
      (yyval.expr).pos = creaVarTemp();
      emite(EASIG, crArgPos((yyvsp[(1) - (1)].expr).pos), crArgNul(), crArgPos((yyval.expr).pos));
    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 306 "src/asin.y"
    { (yyval.expr).tipo = T_ERROR;
    if (!((yyvsp[(1) - (3)].expr).tipo == T_ENTERO && (yyvsp[(3) - (3)].expr).tipo == T_ENTERO))
        yyerror("Los tipos deben ser enteros para comparar");
    else
        (yyval.expr).tipo = T_LOGICO;
        
	(yyval.expr).pos = creaVarTemp();
	emite(EASIG, crArgEnt(1), crArgNul(), crArgPos((yyval.expr).pos));
	
	if ((yyvsp[(2) - (3)].cte) == OPMAYOR)
	  emite(EMAY, crArgPos((yyvsp[(1) - (3)].expr).pos), crArgPos((yyvsp[(3) - (3)].expr).pos), crArgEtq(si+2));
	else if ((yyvsp[(2) - (3)].cte) == OPMENOR)
	  emite(EMEN, crArgPos((yyvsp[(1) - (3)].expr).pos), crArgPos((yyvsp[(3) - (3)].expr).pos), crArgEtq(si+2));
	else if ((yyvsp[(2) - (3)].cte) == OPMAYIG)
	  emite(EMAYEQ, crArgPos((yyvsp[(1) - (3)].expr).pos), crArgPos((yyvsp[(3) - (3)].expr).pos), crArgEtq(si+2));
	else
	  emite(EMENEQ, crArgPos((yyvsp[(1) - (3)].expr).pos), crArgPos((yyvsp[(3) - (3)].expr).pos), crArgEtq(si+2));
	
	emite(EASIG, crArgEnt(0), crArgNul(), crArgPos((yyval.expr).pos));
  }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 331 "src/asin.y"
    { (yyval.expr).tipo = (yyvsp[(1) - (1)].expr).tipo;
      (yyval.expr).pos = creaVarTemp();
      emite(EASIG, crArgPos((yyvsp[(1) - (1)].expr).pos), crArgNul(), crArgPos((yyval.expr).pos));
    }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 336 "src/asin.y"
    { (yyval.expr).tipo = T_ERROR;
    if (!((yyvsp[(1) - (3)].expr).tipo == T_ENTERO && (yyvsp[(3) - (3)].expr).tipo == T_ENTERO))
        yyerror("Los tipos deben ser enteros para operar");
    else
        (yyval.expr).tipo = T_ENTERO;
        
	(yyval.expr).pos = creaVarTemp();
	if ((yyvsp[(2) - (3)].cte) == OPSUMA)
	  emite(ESUM, crArgPos((yyvsp[(1) - (3)].expr).pos), crArgPos((yyvsp[(3) - (3)].expr).pos), crArgPos((yyval.expr).pos));
	else
	  emite(EDIF, crArgPos((yyvsp[(1) - (3)].expr).pos), crArgPos((yyvsp[(3) - (3)].expr).pos), crArgPos((yyval.expr).pos));
  }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 353 "src/asin.y"
    { (yyval.expr).tipo = (yyvsp[(1) - (1)].expr).tipo;
      (yyval.expr).pos = creaVarTemp();
      emite(EASIG, crArgPos((yyvsp[(1) - (1)].expr).pos), crArgNul(), crArgPos((yyval.expr).pos));
    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 358 "src/asin.y"
    { (yyval.expr).tipo = T_ERROR;
    if (!((yyvsp[(1) - (3)].expr).tipo == T_ENTERO && (yyvsp[(3) - (3)].expr).tipo == T_ENTERO))
        yyerror("Los tipos deben ser enteros para operar");
    else
        (yyval.expr).tipo = T_ENTERO;
        
	(yyval.expr).pos = creaVarTemp();
	if ((yyvsp[(2) - (3)].cte) == OPMULT)
	  emite(EMULT, crArgPos((yyvsp[(1) - (3)].expr).pos), crArgPos((yyvsp[(3) - (3)].expr).pos), crArgPos((yyval.expr).pos));
	else
	  emite(EDIVI, crArgPos((yyvsp[(1) - (3)].expr).pos), crArgPos((yyvsp[(3) - (3)].expr).pos), crArgPos((yyval.expr).pos));
  }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 375 "src/asin.y"
    { (yyval.expr).tipo = (yyvsp[(1) - (1)].expr).tipo;
      (yyval.expr).pos = creaVarTemp();
      emite(EASIG, crArgPos((yyvsp[(1) - (1)].expr).pos), crArgNul(), crArgPos((yyval.expr).pos));
    }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 380 "src/asin.y"
    { (yyval.expr).tipo = T_ERROR;
    int t_op = T_ENTERO;
    if ((yyvsp[(1) - (2)].cte) == OPNOT)
	  t_op = T_LOGICO;
    if (t_op != (yyvsp[(2) - (2)].expr).tipo)
        yyerror("Esta operacion no es valida para este tipo");
    else
        (yyval.expr).tipo = (yyvsp[(2) - (2)].expr).tipo;
        
	(yyval.expr).pos = creaVarTemp();
	if ((yyvsp[(1) - (2)].cte) == OPPOS)
      emite(EASIG, crArgPos((yyvsp[(2) - (2)].expr).pos), crArgNul(), crArgPos((yyval.expr).pos));
	else if ((yyvsp[(1) - (2)].cte) == OPNEG)
	  emite(EDIF, crArgEnt(0), crArgPos((yyvsp[(2) - (2)].expr).pos), crArgPos((yyval.expr).pos));
	else {
	  emite(EASIG, crArgEnt(1), crArgNul(), crArgPos((yyval.expr).pos));
	  emite(EIGUAL, crArgPos((yyvsp[(2) - (2)].expr).pos), crArgEnt(0), crArgEtq(si+2));
	  emite(EASIG, crArgEnt(0), crArgNul(), crArgPos((yyval.expr).pos));
	}
  }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 401 "src/asin.y"
    { (yyval.expr).tipo = T_ERROR;
    SIMB sim = obtenerTDS((yyvsp[(2) - (2)].id));
    if (sim.tipo == T_ERROR)
        yyerror("El identificador no esta declarado");
    else if (sim.tipo != T_ENTERO)
        yyerror("Esta operacion no es valida para este tipo");
    else
        (yyval.expr).tipo = T_ENTERO;
        
	(yyval.expr).pos = creaVarTemp();
	if ((yyvsp[(1) - (2)].cte) == OPMASMAS)
      emite(ESUM, crArgPos(sim.desp), crArgEnt(1), crArgPos((yyval.expr).pos));
	else
	  emite(EDIF, crArgPos(sim.desp), crArgEnt(1), crArgPos((yyval.expr).pos));
	  
	emite(EASIG, crArgPos((yyval.expr).pos), crArgNul(), crArgPos(sim.desp));
  }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 423 "src/asin.y"
    { (yyval.expr).tipo = T_ERROR;
      SIMB sim = obtenerTDS((yyvsp[(1) - (4)].id));
      if (sim.tipo == T_ERROR)
          yyerror("El identificador no esta declarado");
      else if ((yyvsp[(3) - (4)].expr).tipo != T_ENTERO)
          yyerror("El indice debe ser entero");
      else
          (yyval.expr).tipo = sim.telem;
      
	  (yyval.expr).pos = creaVarTemp();
	  emite(EAV, crArgPos(sim.desp), crArgPos((yyvsp[(3) - (4)].expr).pos), crArgPos((yyval.expr).pos));
    }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 436 "src/asin.y"
    { (yyval.expr).tipo = (yyvsp[(2) - (3)].expr).tipo;
    (yyval.expr).pos = creaVarTemp();
    emite(EASIG, crArgPos((yyvsp[(2) - (3)].expr).pos), crArgNul(), crArgPos((yyval.expr).pos));
  }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 441 "src/asin.y"
    { (yyval.expr).tipo = T_ERROR;
    SIMB sim = obtenerTDS((yyvsp[(1) - (1)].id));
    if (sim.tipo == T_ERROR)
        yyerror("El identificador no esta declarado");
    else
        (yyval.expr).tipo = sim.tipo;
        
	(yyval.expr).pos = creaVarTemp();
	emite(EASIG, crArgPos(sim.desp), crArgNul(), crArgPos((yyval.expr).pos));
  }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 452 "src/asin.y"
    { (yyval.expr).tipo = T_ERROR;
    SIMB sim = obtenerTDS((yyvsp[(1) - (2)].id));
    if (sim.tipo == T_ERROR)
        yyerror("El identificador no esta declarado");
    else if (sim.tipo != T_ENTERO)
        yyerror("La variable debe ser entera");
    else
        (yyval.expr).tipo = sim.tipo;
        
	(yyval.expr).pos = creaVarTemp();
	emite(EASIG, crArgPos((yyval.expr).pos), crArgNul(), crArgPos(sim.desp));
	if ((yyvsp[(2) - (2)].cte) == OPMASMAS)
      emite(ESUM, crArgPos(sim.desp), crArgEnt(1), crArgPos(sim.desp));
	else
	  emite(EDIF, crArgPos(sim.desp), crArgEnt(1), crArgPos(sim.desp));
  }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 469 "src/asin.y"
    { (yyval.expr).tipo = T_ENTERO; }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 471 "src/asin.y"
    { (yyval.expr).tipo = T_LOGICO; }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 473 "src/asin.y"
    { (yyval.expr).tipo = T_LOGICO; }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 479 "src/asin.y"
    { (yyval.cte) = OPIGUAL; }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 481 "src/asin.y"
    { (yyval.cte) = OPSUMIG; }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 483 "src/asin.y"
    { (yyval.cte) = OPRESIG; }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 489 "src/asin.y"
    { (yyval.cte) = OPANDAND; }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 491 "src/asin.y"
    { (yyval.cte) = OPOROR; }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 497 "src/asin.y"
    { (yyval.cte) = OPIGIG; }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 499 "src/asin.y"
    { (yyval.cte) = OPNOTIG; }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 505 "src/asin.y"
    { (yyval.cte) = OPMAYOR; }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 507 "src/asin.y"
    { (yyval.cte) = OPMENOR; }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 509 "src/asin.y"
    { (yyval.cte) = OPMAYIG; }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 511 "src/asin.y"
    { (yyval.cte) = OPMENIG; }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 517 "src/asin.y"
    { (yyval.cte) = OPSUMA; }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 519 "src/asin.y"
    { (yyval.cte) = OPRESTA; }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 525 "src/asin.y"
    { (yyval.cte) = OPMULT; }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 527 "src/asin.y"
    { (yyval.cte) = OPDIV; }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 533 "src/asin.y"
    { (yyval.cte) = OPPOS; }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 535 "src/asin.y"
    { (yyval.cte) = OPNEG; }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 537 "src/asin.y"
    { (yyval.cte) = OPNOT; }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 543 "src/asin.y"
    { (yyval.cte) = OPMASMAS; }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 545 "src/asin.y"
    { (yyval.cte) = OPMENMEN; }
    break;


/* Line 1792 of yacc.c  */
#line 2076 "asin.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


