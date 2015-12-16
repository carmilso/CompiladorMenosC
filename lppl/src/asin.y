/*****************************************************************************/
/*  Analizador sintáctico del compilador Menos C                             */
/*  Autores:                                                                 */
/*        Pau Baquero Arnal       pabaar@inf.upv.es                          */
/*        Axel Guzmán Godia       axguzgo@inf.upv.es                         */
/*        Carlos Millán Soler     carmilso@inf.upv.es                        */
/*****************************************************************************/


/* TODO: Ajustar espais de les regles */


%{
#include <stdio.h>
#include "libtds.h"
#include "libgci.h"
#include "header.h"
%}


%union
{
  char *id;
  int cte;
  int tip;
  struct {
    int tipo;
    int pos;
  } expr; /*para los no terminales expresion*/
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

/* TODO: cada tipo en una linea */

%type <tip> tipoSimple operadorUnario
%type <expr> expresion expresionLogica expresionIgualdad expresionRelacional expresionAditiva expresionMultiplicativa expresionUnaria expresionSufija
%type <cte> operadorAsignacion operadorLogico operadorIgualdad operadorRelacional operadorAditivo operadorMultiplicativo operadorUnario operadorIncrmento

%%

/************************************************************************/
programa:
    ABRECORCHETE_ secuenciaSentencias CIERRACORCHETE_
      { if (flagMostrarTDS) mostrarTDS();
      }
  | ABRECORCHETE_ CIERRACORCHETE_;
/************************************************************************/

/************************************************************************/
secuenciaSentencias:
    	sentencia
  | secuenciaSentencias sentencia;
/************************************************************************/

/************************************************************************/
sentencia:
    	declaracion
  | instruccion;
/************************************************************************/

/************************************************************************/
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
/************************************************************************/

/************************************************************************/
tipoSimple:
    INT_
	{ $$ = T_ENTERO; }
  | BOOL_
	{ $$ = T_LOGICO; };
/************************************************************************/

/************************************************************************/
instruccion:
	ABRECORCHETE_ listaInstrucciones CIERRACORCHETE_
  | instruccionExpresion
  | instruccionEntradaSalida
  | instruccionSeleccion
  | instruccionIteracion;
/************************************************************************/

/************************************************************************/
listaInstrucciones:
  | listaInstrucciones instruccion;
/************************************************************************/

/************************************************************************/
instruccionExpresion:
	expresion PUNTOCOMA_
  | PUNTOCOMA_;
/************************************************************************/

/************************************************************************/
instruccionEntradaSalida:
	READ_ ABREPARENTESIS_ ID_ CIERRAPARENTESIS_ PUNTOCOMA_
	{ SIMB sim = obtenerTDS($3);
	  if (sim.tipo == T_ERROR) yyerror("Objeto no declarado");
	  else emite(EREAD, crArgNul(), crArgNul(), crArgPos(sim.desp));
	}
  | PRINT_ ABREPARENTESIS_ expresion CIERRAPARENTESIS_ PUNTOCOMA_
  { emite(EWRITE, crArgNul(), crArgNul(), crArgPos($3.pos));
  };
/************************************************************************/

/************************************************************************/
instruccionSeleccion:
	IF_ ABREPARENTESIS_ expresion CIERRAPARENTESIS_
	{ if ($3.tipo != T_ERROR && $3.tipo != T_LOGICO) yyerror("La expresion en IF no es de tipo logico");
	  $<cte>$ = creaLans(si);
	  emite(EIGUAL, crArgPos($3.pos), crArgEnt(0), crArgPos($<cte>$));
	}
	instruccion
	{ completaLans($<cte>5, crArgPos(si));
	}
	ELSE_ instruccion;
/************************************************************************/

/************************************************************************/
instruccionIteracion:
	WHILE_
	{ 
          $<cte>$ = si;
       	}
	ABREPARENTESIS_ expresion CIERRAPARENTESIS_
	{
	  if ($3.tipo != T_LOGICO) yyerror("La expresion en WHILE no es de tipo logico");
	  $<cte>$ = creaLans(si);
	  emite(EIGUAL, crArgPos($4.pos), crArgEnt(0), crArgPos($<cte>$));
	}
	instruccion
	{
	  emite(GOTOS, crArgNul(), crArgNul(), crArgPos($<cte>2));
	  completaLans($<cte>5, crArgPos(si));
	}
	;

/************************************************************************/

/************************************************************************/
expresion:
    expresionLogica
  { $$.tipo = $1.tipo;
    $$.pos = creaVarTemp();
    emite(EASIG, crArgPos($1.pos), crArgNul(), crArgPos($$.pos));
  }

  | ID_ operadorAsignacion expresion
  { SIMB sim = obtenerTDS($1); $$.tipo = T_ERROR;
    if (sim.tipo == T_ERROR) yyerror("Objeto no declarado");
    else if (!((($3.tipo == T_ENTERO) || ($3.tipo == T_LOGICO)) &&
              ((sim.tipo == T_ENTERO) || (sim.tipo == T_LOGICO)) &&
               (sim.tipo == $3.tipo)) && ($3.tipo != T_ERROR))
      yyerror("Error de tipos en la 'asignacion'");
    else $$.tipo = sim.tipo;
    
    emite(EASIG, crArgPos($3.pos), crArgNul(), crArgPos(sim.desp));
  }

  | ID_ ABRECLAUDATOR_ expresion CIERRACLAUDATOR_ operadorAsignacion expresion
  { SIMB sim = obtenerTDS($1); $$.tipo = T_ERROR;
    if (sim.tipo == T_ERROR) yyerror("Objeto no declarado");
    else if ($3.tipo != T_ENTERO) yyerror("Indice no entero");
    else if (sim.tipo != T_ARRAY) yyerror("El objeto debe ser un vector");
    else if (!((($6.tipo == T_ENTERO) || ($6.tipo == T_LOGICO)) &&
              ((sim.telem == T_ENTERO) || (sim.telem == T_LOGICO)) &&
               (sim.telem == $6.tipo)) && ($3.tipo != T_ERROR))
	  yyerror("Error de tipos en la 'asignacion'");
	else $$.tipo = sim.telem;
    
    emite(EVA, crArgPos(sim.desp), crArgPos($3.pos), crArgPos($6.pos));
  };
/************************************************************************/

/************************************************************************/
expresionLogica:
	expresionIgualdad
    { $$.tipo = $1.tipo;
      $$.pos = creaVarTemp();
      emite(EASIG, crArgPos($1.pos), crArgNul(), crArgPos($$.pos));
    }
  | expresionLogica operadorLogico expresionIgualdad
  { $$.tipo = T_ERROR;
    if ($1.tipo != T_LOGICO || $3.tipo != T_LOGICO)
        yyerror("Los tipos no son 'T_LOGICO'");
    else
        $$.tipo = $1.tipo;

    $$.pos = creaVarTemp();
    
  };
/************************************************************************/

/************************************************************************/
expresionIgualdad:
	expresionRelacional
    { $$.tipo = $1.tipo;
    }
  | expresionIgualdad operadorIgualdad expresionRelacional
  { $$.tipo = T_ERROR;
    if (!((($1.tipo == T_ENTERO) || ($1.tipo == T_LOGICO)) &&
        (($3.tipo == T_ENTERO) || ($3.tipo == T_LOGICO)) &&
        ($1.tipo == $3.tipo)))
        yyerror("Las expresiones no son del mismo tipo o no son validas");
    else
        $$.tipo = T_LOGICO;
  };
/************************************************************************/

/************************************************************************/
expresionRelacional:
	expresionAditiva
    { $$.tipo = $1.tipo;
    }
  | expresionRelaci#define onal operadorRelacional expresionAditiva
  { $$.tipo = T_ERROR;
    if (!($1.tipo == T_ENTERO && $3.tipo == T_ENTERO))
        yyerror("Los tipos deben ser enteros para comparar");
    else
        $$.tipo = T_LOGICO;
  };
/************************************************************************/

/************************************************************************/
expresionAditiva:
	expresionMultiplicativa
    { $$.tipo = $1.tipo;
    }
  | expresionAditiva operadorAditivo expresionMultiplicativa
  { $$.tipo = T_ERROR;
    if (!($1.tipo == T_ENTERO && $3.tipo == T_ENTERO))
        yyerror("Los tipos deben ser enteros para operar");
    else
        $$.tipo = T_ENTERO;
  };
/************************************************************************/

/************************************************************************/
expresionMultiplicativa:
	expresionUnaria
    { $$.tipo = $1.tipo;
    }
  | expresionMultiplicativa operadorMultiplicativo expresionUnaria
  { $$.tipo = T_ERROR;
    if (!($1.tipo == T_ENTERO && $3.tipo == T_ENTERO))
        yyerror("Los tipos deben ser enteros para operar");
    else
        $$.tipo = T_ENTERO;
  };
/************************************************************************/

/************************************************************************/
expresionUnaria:
	expresionSufija
    { $$.tipo = $1.tipo;
    }
  | operadorUnario expresionUnaria
  { $$.tipo = T_ERROR;
    if ($1 != $2.tipo)
        yyerror("Esta operacion no es valida para este tipo");
    else
        $$.tipo = $2.tipo;
  }
  | operadorIncremento ID_
  { $$.tipo = T_ERROR;
    SIMB sim = obtenerTDS($2);
    if (sim.tipo == T_ERROR)
        yyerror("El identificador no esta declarado");
    else if (sim.tipo != T_ENTERO)
        yyerror("Esta operacion no es valida para este tipo");
    else
        $$.tipo = T_ENTERO;
  };
/************************************************************************/

/************************************************************************/
expresionSufija:
	ID_ ABRECLAUDATOR_ expresion CIERRACLAUDATOR_
    { $$.tipo = T_ERROR;
      SIMB sim = obtenerTDS($1);
      if (sim.tipo == T_ERROR)
          yyerror("El identificador no esta declarado");
      else if ($3.tipo != T_ENTERO)
          yyerror("El indice debe ser entero");
      else
          $$.tipo = sim.telem;
    }
  | ABREPARENTESIS_ expresion CIERRAPARENTESIS_
  { $$.tipo = $2.tipo;
  }
  | ID_
  { $$.tipo = T_ERROR;
    SIMB sim = obtenerTDS($1);
    if (sim.tipo == T_ERROR)
        yyerror("El identificador no esta declarado");
    else
        $$.tipo = sim.tipo;
  }
  | ID_ operadorIncremento
  { $$.tipo = T_ERROR;
    SIMB sim = obtenerTDS($1);
    if (sim.tipo == T_ERROR)
        yyerror("El identificador no esta declarado");
    else if (sim.tipo != T_ENTERO)
        yyerror("La variable debe ser entera");
    else
        $$.tipo = sim.tipo;
  }
  | CTE_
  { $$.tipo = T_ENTERO; }
  | TRUE_
  { $$.tipo = T_LOGICO; }
  | FALSE_
  { $$.tipo = T_LOGICO; };
/************************************************************************/

/************************************************************************/
operadorAsignacion:
    IGUAL_
  | MASIGUA#define L_
  | MENOSIGUAL_;
/************************************************************************/

/************************************************************************/
operadorLogico:
    ANDAND_
    { $$ = asdfasdf; }
  | OROR_;
/************************************************************************/

/************************************************************************/
operadorIgualdad:
    IGUALIGUAL_
  | DIFERENTE_;
/************************************************************************/

/************************************************************************/
operadorRelacional:
    MAYORQ_
  | MENORQ_
  | MAYORIG_
  | MENORIG_;
/************************************************************************/

/************************************************************************/
operadorAditivo:
	MAS_
  | MENOS_;
/************************************************************************/

/************************************************************************/
operadorMultiplicativo:
    POR_
  | ENTRE_;
/************************************************************************/

/************************************************************************/
operadorUnario:
    MAS_
    { $$ = T_ENTERO; }
  | MENOS_
  { $$ = T_ENTERO; }
  | NEG_
  { $$ = T_LOGICO; };
/************************************************************************/

/************************************************************************/
operadorIncremento:
    MASMAS_
  | MENOSMENOS_;
/************************************************************************/


%%
