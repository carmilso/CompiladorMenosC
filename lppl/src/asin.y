%{
#include <stdio.h>
#include "header.h"
%}

%token ABRECORCHETE_ CIERRACORCHETE_
%token ABRECLAUDATOR_ CIERRACLAUDATOR_
%token ABREPARENTESIS_ CIERRAPARENTESIS_
%token PUNTOCOMA_

%token ID_
%token CTE_

%token COMENTARIO_

%token INT_ BOOL_

%token READ_ PRINT_

%token IF_ ELSE_ WHILE_

%token TRUE_ FALSE_

%token IGUAL_ MASIGUAL_ MENOSIGUAL_
%left OROR_
%left ANDAND_
%token IGUALIGUAL_ DIFERENTE_
%token MAYORQ_ MENORQ_ MAYORIG_ MENORIG_
%left MAS_ MENOS_
%left POR_ ENTRE_
%token NEG_
%token MASMAS_ MENOSMENOS_

%%

programa:
    	ABRECORCHETE_ secuenciaSentencias CIERRACORCHETE_
  | ABRECORCHETE_ CIERRACORCHETE_;

secuenciaSentencias:
    	sentencia
  | secuenciaSentencias sentencia;

sentencia:
    	declaracion
  | instruccion;

declaracion:
	tipoSimple ID_ PUNTOCOMA_
  | tipoSimple ID_ ABRECLAUDATOR_ CTE_ CIERRACLAUDATOR_ PUNTOCOMA_;

tipoSimple:
	INT_
  | BOOL_;

instruccion:
	ABRECORCHETE_ listaInstrucciones CIERRACORCHETE_
  | instruccionExpresion
  | instruccionEntradaSalida
  | instruccionSeleccion
  | instruccionIteracion;

listaInstrucciones:
  | listaInstrucciones instruccion;

instruccionExpresion:
	expresion PUNTOCOMA_
  | PUNTOCOMA_;

instruccionEntradaSalida:
	READ_ ABREPARENTESIS_ ID_ CIERRAPARENTESIS_ PUNTOCOMA_
  | PRINT_ ABREPARENTESIS_ expresion CIERRAPARENTESIS_ PUNTOCOMA_;

instruccionSeleccion:
	IF_ ABREPARENTESIS_ expresion CIERRAPARENTESIS_ instruccion ELSE_ instruccion;

instruccionIteracion:
	WHILE_ ABREPARENTESIS_ expresion CIERRAPARENTESIS_ instruccion;

expresion:
	expresionLogica
  | ID_ operadorAsignacion expresion
  | ID_ ABRECLAUDATOR_ expresion CIERRACLAUDATOR_ operadorAsignacion expresion;

expresionLogica:
	expresionIgualdad
  | expresionLogica operadorLogico expresionIgualdad;

expresionIgualdad:
	expresionRelacional
  | expresionIgualdad operadorIgualdad expresionRelacional;

expresionRelacional:
	expresionAditiva
  | expresionRelacional operadorRelacional expresionAditiva;

expresionAditiva:
	expresionMultiplicativa
  | expresionAditiva operadorAditivo expresionMultiplicativa;

expresionMultiplicativa:
	expresionUnaria
  | expresionMultiplicativa operadorMultiplicativo expresionUnaria;

expresionUnaria:
	expresionSufija
  | operadorUnario expresionUnaria
  | operadorIncremento ID_;

expresionSufija:
	ID_ ABRECLAUDATOR_ expresion CIERRACLAUDATOR_
  | ABREPARENTESIS_ expresion CIERRAPARENTESIS_
  | ID_
  | ID_ operadorIncremento
  | CTE_
  | TRUE_
  | FALSE_;

operadorAsignacion:
	IGUAL_
  | MASIGUAL_
  | MENOSIGUAL_;

operadorLogico:
	ANDAND_
  | OROR_;

operadorIgualdad:
	IGUALIGUAL_
  | DIFERENTE_;

operadorRelacional:
    MAYORQ_
  | MENORQ_
  | MAYORIG_
  | MENORIG_;

operadorAditivo:
	MAS_
  | MENOS_;

operadorMultiplicativo:
    POR_
  | ENTRE_;

operadorUnario:
    MAS_
  | MENOS_
  | NEG_;

operadorIncremento:
    MASMAS_
  | MENOSMENOS_;


%%
