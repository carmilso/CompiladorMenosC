/* Subseccion preambulo C */
%{
#include <stdio.h>
extern FILE *yyin;
void visualizar(int opcion, char* texto);
%}

/* Subseccion de definiciones */
%option yylineno

delimitador [ \t]+
letraMay [A-Z]+



%%

{delimitador}	{ECHO;}
"\n"		{visualizar(0, "");}
{letraMay}	{visualizar(1, "Letra Mayuscula:");}

%%

void visualizar(int opcion, char* texto) {
	switch(opcion) {
		case 0: printf("%3d- Nueva Linea\n", yylineno);
			break;
		case 1: printf("%3d- \%s \%s\n", yylineno, texto, yytext);
			break;
	}
}
