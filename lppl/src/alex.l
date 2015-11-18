/* Subseccion preambulo C */
%{
#include <stdio.h>
#include "asin.h"
#include "header.h"

#define procesar(x) { if (verbosidad) ECHO; return x; }
%}


/* Subseccion de definiciones */
%option yylineno

digito		[0-9]
id		{letra}({letra}|{digito})*
delimitador 	[ \t\n]+
letraMay 	[A-Z]
letraMin	[a-z]
letra		{letraMay}|{letraMin}|"_"
cte         	{digito}+
comentario  	"//"[^\n]*"\n"


%%

{comentario}	{ ; }
{delimitador}	{ if (verbosidad) ECHO; }

"{"		{ procesar (ABRECORCHETE_); }
"}"		{ procesar (CIERRACORCHETE_); }
"["		{ procesar (ABRECLAUDATOR_); }
"]"		{ procesar (CIERRACLAUDATOR_); }
"("		{ procesar (ABREPARENTESIS_); }
")"		{ procesar (CIERRAPARENTESIS_); }

";"		{ procesar (PUNTOCOMA_); }

"+="		{ procesar (MASIGUAL_); }
"-="		{ procesar (MENOSIGUAL_); }
"++"		{ procesar (MASMAS_); }
"--"		{ procesar (MENOSMENOS_); }
"+"		{ procesar (MAS_); }
"-"		{ procesar (MENOS_); }
"*"		{ procesar (POR_); }
"/"		{ procesar (ENTRE_); }

"=="		{ procesar (IGUALIGUAL_); }
"!="		{ procesar (DIFERENTE_); }
"!"		{ procesar (NEG_); }
">="		{ procesar (MAYORIG_); }
"<="		{ procesar (MENORIG_); }
">"		{ procesar (MAYORQ_); }
"<"		{ procesar (MENORQ_); }

"="		{ procesar (IGUAL_); }

"||"		{ procesar (OROR_); }
"&&"		{ procesar (ANDAND_); }

"int"		{ procesar (INT_); }
"bool"		{ procesar (BOOL_); }

"read"		{ procesar (READ_); }
"print"		{ procesar (PRINT_); }

"if"		{ procesar (IF_); }
"else"		{ procesar (ELSE_); }

"while"		{ procesar (WHILE_); }

"true"		{ procesar (TRUE_); }
"false"		{ procesar (FALSE_); }

{id}		{ yylval.id = yytext; printf(yylval.id);  procesar (ID_) ; }
{cte}		{ yylval.cte = atoi(yytext); procesar (CTE_); }

.		{ yyerror("Caracter desconocido"); }

%%
