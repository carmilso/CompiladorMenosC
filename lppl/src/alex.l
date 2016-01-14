/*****************************************************************************/
/*  Analizador léxico del compilador Menos C                                 */
/*  Autores:                                                                 */
/*        Pau Baquero Arnal       pabaar@inf.upv.es                          */
/*        Axel Guzmán Godia       axguzgo@inf.upv.es                         */
/*        Carlos Millán Soler     carmilso@inf.upv.es                        */
/*****************************************************************************/

/* Subseccion preambulo C */
%{
#include <stdio.h>
#include <string.h>
#include "asin.h"
#include "header.h"

#define procesar(x) { if (verbosidad) ECHO; return x; }
%}


/* Subseccion de definiciones */
%option yylineno

digito          [0-9]
id              {letra}({letra}|{digito})*
delimitador     [ \t]+
nuevalinea      \n
letraMay        [A-Z]
letraMin        [a-z]
letra           {letraMay}|{letraMin}|"_"
ctr             ({digito}*"."{digito}+)|({digito}+"."{digito}*)
cte             {digito}+
comentario      "//"[^\n]*"\n"


%%

{comentario}    { if (verbosidad) fprintf(stdout,"\n%3d.- ", yylineno); }
{delimitador}   { if (verbosidad) ECHO; }
{nuevalinea}    { if (verbosidad) {ECHO; fprintf(stdout,"%3d.- ", yylineno);}}

"{"             { procesar (ABRECORCHETE_); }
"}"             { procesar (CIERRACORCHETE_); }
"["             { procesar (ABRECLAUDATOR_); }
"]"             { procesar (CIERRACLAUDATOR_); }
"("             { procesar (ABREPARENTESIS_); }
")"             { procesar (CIERRAPARENTESIS_); }

";"             { procesar (PUNTOCOMA_); }

"+="            { procesar (MASIGUAL_); }
"-="            { procesar (MENOSIGUAL_); }
"++"            { procesar (MASMAS_); }
"--"            { procesar (MENOSMENOS_); }
"+"             { procesar (MAS_); }
"-"             { procesar (MENOS_); }
"*"             { procesar (POR_); }
"/"             { procesar (ENTRE_); }

"=="            { procesar (IGUALIGUAL_); }
"!="            { procesar (DIFERENTE_); }
"!"             { procesar (NEG_); }
">="            { procesar (MAYORIG_); }
"<="            { procesar (MENORIG_); }
">"             { procesar (MAYORQ_); }
"<"             { procesar (MENORQ_); }

"="             { procesar (IGUAL_); }

"||"            { procesar (OROR_); }
"&&"            { procesar (ANDAND_); }

"int"           { procesar (INT_); }
"bool"          { procesar (BOOL_); }

"read"          { procesar (READ_); }
"print"         { procesar (PRINT_); }

"if"            { procesar (IF_); }
"else"          { procesar (ELSE_); }

"do"            { procesar (DO_); }       /*EXAMEN*/

"while"         { procesar (WHILE_); }

"true"          { procesar (TRUE_); }
"false"         { procesar (FALSE_); }

{id}            { creaNombre(); procesar (ID_) ; }
{cte}           { creaCentera(); procesar (CTE_); }
{ctr}           { truncCreal(); procesar (CTE_); }

.               { yyerror("Caracter desconocido"); }

%%
/********************************************************************************/
void creaNombre()
/* Comprueba que el identificador no exceda la talla maxima (14) o lo trunca */
{ char *t;
  if (yyleng > MAX_LENGTH) {
    fprintf(stdout,"\nWarning at line %d: identificador truncado a longitud %d\n",
            yylineno, MAX_LENGTH);
    yyleng=MAX_LENGTH;
  }
  t = (char *)malloc(yyleng+1); strncpy(t, yytext, yyleng);
  t[yyleng] = '\0'; yylval.id = t;
}
/********************************************************************************/
void creaCentera()
/* Transforma una subcadena a la constante entera que representa */
{ yylval.cte = atoi(yytext); }
/********************************************************************************/
void truncCreal()
/* Transforma una subcadena a una constante entera truncandola. */
{ yylval.cte = atoi(yytext);
  fprintf(stdout,"\nWarning at line %d: constante real truncada a entera %d\n",
          yylineno,yylval.cte);
}
/********************************************************************************/
