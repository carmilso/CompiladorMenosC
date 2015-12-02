/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2058 of yacc.c  */
#line 8 "src/asin.y"

  char *id;
  int cte;
  int tip;
  EXPR expre; /*para los no terminales expresion*/


/* Line 2058 of yacc.c  */
#line 104 "asin.h"
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
