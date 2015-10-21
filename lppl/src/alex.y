/* Subseccion preambulo C */
%{
#include <stdio.h>
extern FILE *yyin;
void visualizar(int opcion, char* texto);
%}


/* Subseccion de definiciones */
%option yylineno

digito		[0-9]
id		{letra}({letra} | {digito})*
delimitador 	[ \t\n]+
letraMay 	[A-Z]
letraMin	[a-z]
letra		{letraMay} | {letraMin} | "_"
cte		{digito}+


%%


{delimitador}	{ECHO;}
"\n"		{visualizar(0, "");}
{letraMay}	{ ; }

"{"		{ return (ABRECORCHETE_); }
"}"		{ return (CIERRACORCHETE_); }
"["		{ return (ABRECLAUDATOR_); }
"]"		{ return (CIERRACLAUDATOR_); }
"("		{ return (ABREPARENTESIS_); }
")"		{ return (CIERRAPARENTESIS_); }

";"		{ return (PUNTOCOMA_); }

"+="		{ return (MASIGUAL_); }
"-="		{ return (MENOSIGUAL_); }
"++"		{ return (MASMAS_); }
"--"		{ return (MENOSMENOS_); }
"+"		{ return (MAS_); }
"-"		{ return (MENOS_); }
"*"		{ return (POR_); }
"/"		{ return (ENTRE_); }

"=="		{ return (IGUALIGUAL_); }
"!="		{ return (DIFERENTE_); }
"!"		{ return (NEG_); }
">="		{ return (MAYORIG_); }
"<="		{ return (MENORIG_); }
">"		{ return (MAYORQ_); }
"<"		{ return (MENORQ_); }

"="		{ return (IGUAL_); }

"||"		{ return (OROR_); }
"&&"		{ return (ANDAND_); }

"int"		{ return (INT_); }
"bool"		{ return (BOOL_); }

"read"		{ return (READ_); }
"print"		{ return (PRINT_); }

"if"		{ return (IF_); }
"else"		{ return (ELSE_); }

"while"		{ return (WHILE_): }

"true"		{ return (TRUE_); }
"false"		{ return (FALSE_); }		

{id}		{ return (ID_) ; }
{cte}		{ return (CTE_); }

%%

void visualizar(int opcion, char* texto) {
	switch(opcion) {
		case 0: printf("%3d- Nueva Linea\n", yylineno);
			break;
		case 1: printf("%3d- \%s \%s\n", yylineno, texto, yytext);
			break;
	}
}
