/* Subseccion preambulo C */
%{
#include <stdio.h>
extern FILE *yyin;
void visualizar(int opcion, char* texto);
%}


/* Subseccion de definiciones */
%option yylineno

digito		[0-9]
id		{letra}({letra}|{digito})*
delimitador 	[ \t\n]+
letraMay 	[A-Z]
letraMin	[a-z]
letra		{letraMay}|{letraMin}|"_"
cte		{digito}+


%%


{delimitador}	{ ECHO; }
{letraMay}	{ ECHO; }
{letraMin}	{ ECHO; }

"{"		{ ECHO; }
"}"		{ ECHO; }
"["		{ ECHO; }
"]"		{ ECHO; }
"("		{ ECHO; }
")"		{ ECHO; }

";"		{ ECHO; }

"+="		{ ECHO; }
"-="		{ ECHO; }
"++"		{ ECHO; }
"--"		{ ECHO; }
"+"		{ ECHO; }
"-"		{ ECHO; }
"*"		{ ECHO; }
"/"		{ ECHO; }

"=="		{ ECHO; }
"!="		{ ECHO; }
"!"		{ ECHO; }
">="		{ ECHO; }
"<="		{ ECHO; }
">"		{ ECHO; }
"<"		{ ECHO; }

"="		{ ECHO; }

"||"		{ ECHO; }
"&&"		{ ECHO; }

"int"		{ ECHO; }
"bool"		{ ECHO; }

"read"		{ ECHO; }
"print"		{ ECHO; }

"if"		{ ECHO; }
"else"		{ ECHO; }

"while"		{ ECHO; }

"true"		{ ECHO; }
"false"		{ ECHO; }		

{id}		{ ECHO; }
{cte}		{ ECHO; }

.		{ ECHO; }

%%

void visualizar(int opcion, char* texto) {
	switch(opcion) {
		case 0: printf("%3d- Nueva Linea\n", yylineno);
			break;
		case 1: printf("%3d- \%s \%s\n", yylineno, texto, yytext);
			break;
	}
}

int main (int argc, char **argv) {
	if ((yyin = fopen (argv[1], "r")) == NULL)
		fprintf (stderr, "Fichero no valido \%s", argv[1]);
	yylex();
}
