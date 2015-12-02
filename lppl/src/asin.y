%{
#include <stdio.h>
#include "header.h"
#include "libtds.h"
%}

%union
{
  char *id;
  int cte;
  int tip;
  EXPR expre; /*para los no terminales expresion*/
}


%token ABRECORCHETE_ CIERRACORCHETE_
%token ABRECLAUDATOR_ CIERRACLAUDATOR_
%token ABREPARENTESIS_ CIERRAPARENTESIS_
%token PUNTOCOMA_

%token <id> ID_
%token <cte> CTE_

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

%type <tip> tipoSimple
%type <expre> expresion

%%

programa:
    ABRECORCHETE_ secuenciaSentencias CIERRACORCHETE_

      { mostrarTDS();
      }

  | ABRECORCHETE_ CIERRACORCHETE_;

secuenciaSentencias:
    	sentencia
  | secuenciaSentencias sentencia;

sentencia:
    	declaracion
  | instruccion;

declaracion:
    tipoSimple ID_ PUNTOCOMA_

	{ 
	  if (!insertarTSimpleTDS($2, $1, dvar))
	    yyerror("Identificador repetido");
	  else
	    dvar += TALLA_TIPO_SIMPLE;
	}

  | tipoSimple ID_ ABRECLAUDATOR_ CTE_ CIERRACLAUDATOR_ PUNTOCOMA_
	{ int numelem = $4;
    if ($4 <= 0) {
      yyerror("Talla inapropiada del array");
      numelem = 0;
    }
    if (!insertarTVectorTDS($2, T_ARRAY, dvar, $1, numelem))
      yyerror("Identificador repetido");
    else
      dvar += TALLA_TIPO_SIMPLE * $4;
	};

tipoSimple:
    INT_
	{ $$ = T_ENTERO; }
  | BOOL_
	{ $$ = T_LOGICO; };

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
	{ SIMB sim = obtenerTDS($3);
	  if (sim.tipo == T_ERROR) yyerror("Objeto no declarado");
	}
  | PRINT_ ABREPARENTESIS_ expresion CIERRAPARENTESIS_ PUNTOCOMA_;

instruccionSeleccion:
	IF_ ABREPARENTESIS_ expresion CIERRAPARENTESIS_ instruccion ELSE_ instruccion
	{ if ($3.tipo != T_LOGICO) yyerror("La expresion en IF no es de tipo logico");
	};

instruccionIteracion:
	WHILE_ ABREPARENTESIS_ expresion CIERRAPARENTESIS_ instruccion
	{ if ($3.tipo != T_LOGICO) yyerror("La expresion en WHILE no es de tipo logico");
	};

expresion:
    expresionLogica
  { $$.tipo = T_LOGICO;
  }
  
  | ID_ operadorAsignacion expresion
  { SIMB sim = obtenerTDS($1); $$.tipo = T_ERROR;
    if (sim.tipo == T_ERROR) yyerror("Objeto no declarado");
    else if (!((($3.tipo == T_ENTERO) || ($3.tipo == T_LOGICO)) &&
              ((sim.tipo == T_ENTERO) || (sim.tipo == T_LOGICO)) &&
               (sim.tipo == $3.tipo)))
      yyerror("Error de tipos en la 'asignacion'");
    else $$.tipo = sim.tipo;
  }
  
  | ID_ ABRECLAUDATOR_ expresion CIERRACLAUDATOR_ operadorAsignacion expresion
  { SIMB sim = obtenerTDS($1); $$.tipo = T_ERROR;
    if (sim.tipo == T_ERROR) yyerror("Objeto no declarado");
    else if ($3.tipo != T_ENTERO) yyerror("Indice no entero");
    else if (sim.tipo != T_ARRAY) yyerror("El objeto debe ser un vector");
    else if (!((($6.tipo == T_ENTERO) || ($6.tipo == T_LOGICO)) &&
              ((sim.telem == T_ENTERO) || (sim.telem == T_LOGICO)) &&
               (sim.telem == $6.tipo)))
	  yyerror("Error de tipos en la 'asignacion'");
	else $$.tipo = sim.telem;
  };

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
