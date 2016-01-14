/*****************************************************************************/
/*  Analizador sintáctico del compilador Menos C                             */
/*  Autores:                                                                 */
/*        Pau Baquero Arnal       pabaar@inf.upv.es                          */
/*        Axel Guzmán Godia       axguzgo@inf.upv.es                         */
/*        Carlos Millán Soler     carmilso@inf.upv.es                        */
/*****************************************************************************/


%{
#include <stdio.h>
#include "libtds.h"
#include "libgci.h"
#include "header.h"
#include "headops.h"
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

%token DO_                /*EXAMEN*/

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

%type <expr> expresion
%type <expr> expresionLogica
%type <expr> expresionIgualdad
%type <expr> expresionRelacional
%type <expr> expresionAditiva
%type <expr> expresionMultiplicativa
%type <expr> expresionUnaria
%type <expr> expresionSufija

%type <expr> instruccionNewWhile    /*EXAMEN*/

%type <cte> operadorAsignacion
%type <cte> operadorLogico
%type <cte> operadorIgualdad
%type <cte> operadorRelacional
%type <cte> operadorAditivo
%type <cte> operadorMultiplicativo
%type <cte> operadorUnario
%type <cte> operadorIncremento

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
  | instruccionIteracion
  | instruccionNewWhile;
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
	  else if (sim.tipo != T_ENTERO) yyerror("El argumento del read debe ser entero");
	  emite(EREAD, crArgNul(), crArgNul(), crArgPos(sim.desp));
	}
  | PRINT_ ABREPARENTESIS_ expresion CIERRAPARENTESIS_ PUNTOCOMA_
  { if ($3.tipo != T_ENTERO) yyerror("La expresion del print debe ser entera");
    emite(EWRITE, crArgNul(), crArgNul(), crArgPos($3.pos));
  };
/************************************************************************/

/************************************************************************/
instruccionSeleccion:
	IF_ ABREPARENTESIS_ expresion CIERRAPARENTESIS_
	{ if ($3.tipo != T_ERROR && $3.tipo != T_LOGICO) yyerror("La expresion en IF no es de tipo logico");
	  $<cte>$ = creaLans(si);
	  emite(EIGUAL, crArgPos($3.pos), crArgEnt(0), crArgNul());
	}
	instruccion
	{ $<cte>$ = creaLans(si);
    emite(GOTOS, crArgNul(), crArgNul(), crArgNul());
    completaLans($<cte>5, crArgEtq(si));
	}
	ELSE_ instruccion
  {
    completaLans($<cte>7, crArgEtq(si));
  };
/************************************************************************/

/************************************************************************/
instruccionIteracion:
	WHILE_
	{
          $<cte>$ = si;
  }
	ABREPARENTESIS_ expresion CIERRAPARENTESIS_
	{
	  if ($4.tipo != T_LOGICO) yyerror("La expresion en WHILE no es de tipo logico");
	  $<cte>$ = creaLans(si);
	  emite(EIGUAL, crArgPos($4.pos), crArgEnt(0), crArgNul());
	}
	instruccion
	{
	  emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<cte>2));
	  completaLans($<cte>6, crArgEtq(si));
	}
	;

/************************************************************************/
instruccionNewWhile:
  DO_ {
    $<cte>$ = si;
  }
  instruccion WHILE_ ABREPARENTESIS_ expresion CIERRAPARENTESIS_ {
    if ($6.tipo != T_LOGICO) yyerror("La expresion en DO WHILE no es de tipo logico");
    $<cte>$ = creaLans(si);
    emite(EIGUAL, crArgPos($6.pos), crArgEnt(0), crArgNul());
  }
  instruccion {
    emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<cte>2));
    completaLans($<cte>8, crArgEtq(si));
  }

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
               (sim.tipo == $3.tipo) || ($3.tipo == T_ERROR))){
        yyerror("Error de tipos en la 'asignacion'");}
    else $$.tipo = sim.tipo;

    $$.pos = creaVarTemp();

    if ($2 == OPIGUAL)
      emite(EASIG, crArgPos($3.pos), crArgNul(), crArgPos($$.pos));
    else if ($2 == OPSUMIG)
      emite(ESUM, crArgPos(sim.desp), crArgPos($3.pos), crArgPos($$.pos));
    else
      emite(EDIF, crArgPos(sim.desp), crArgPos($3.pos), crArgPos($$.pos));

    emite(EASIG, crArgPos($$.pos), crArgNul(), crArgPos(sim.desp));
  }

  | ID_ ABRECLAUDATOR_ expresion CIERRACLAUDATOR_ operadorAsignacion expresion
  { SIMB sim = obtenerTDS($1); $$.tipo = T_ERROR;
    if (sim.tipo == T_ERROR) yyerror("Objeto no declarado");
    else if ($3.tipo != T_ENTERO) yyerror("Indice no entero");
    else if (sim.tipo != T_ARRAY) yyerror("El objeto debe ser un vector");
    else if (!((($6.tipo == T_ENTERO) || ($6.tipo == T_LOGICO)) &&
              ((sim.telem == T_ENTERO) || (sim.telem == T_LOGICO)) &&
               (sim.telem == $6.tipo)) && ($6.tipo != T_ERROR))
	  yyerror("Error de tipos en la 'asignacion'");
	  else $$.tipo = sim.telem;

    $$.pos = creaVarTemp();

    if ($5 == OPIGUAL)
      emite(EASIG, crArgPos($6.pos), crArgNul(), crArgPos($$.pos));
    else if ($5 == OPSUMIG) {
      emite(EAV, crArgPos(sim.desp), crArgPos($3.pos), crArgPos($$.pos));
      emite(ESUM, crArgPos($$.pos), crArgPos($6.pos), crArgPos($$.pos));
    }
    else {
      emite(EAV, crArgPos(sim.desp), crArgPos($3.pos), crArgPos($$.pos));
      emite(EDIF, crArgPos($$.pos), crArgPos($6.pos), crArgPos($$.pos));
    }

    emite(EVA, crArgPos(sim.desp), crArgPos($3.pos), crArgPos($$.pos));
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
    if ($2 == OPANDAND) {
	  emite(EASIG, crArgEnt(0), crArgNul(), crArgPos($$.pos));
	  emite(EIGUAL, crArgPos($1.pos), crArgEnt(0), crArgEtq(si+3));
	  emite(EIGUAL, crArgPos($3.pos), crArgEnt(0), crArgEtq(si+2));
	  emite(EASIG, crArgEnt(1), crArgNul(), crArgPos($$.pos));
	}
    else {
	  emite(EASIG, crArgEnt(1), crArgNul(), crArgPos($$.pos));
	  emite(EIGUAL, crArgPos($1.pos), crArgEnt(1), crArgEtq(si+3));
	  emite(EIGUAL, crArgPos($3.pos), crArgEnt(1), crArgEtq(si+2));
	  emite(EASIG, crArgEnt(0), crArgNul(), crArgPos($$.pos));
	}
  };
/************************************************************************/

/************************************************************************/
expresionIgualdad:
	expresionRelacional
    { $$.tipo = $1.tipo;
      $$.pos = creaVarTemp();
      emite(EASIG, crArgPos($1.pos), crArgNul(), crArgPos($$.pos));
    }
  | expresionIgualdad operadorIgualdad expresionRelacional
  { $$.tipo = T_ERROR;
    if (!((($1.tipo == T_ENTERO) || ($1.tipo == T_LOGICO)) &&
        (($3.tipo == T_ENTERO) || ($3.tipo == T_LOGICO)) &&
        ($1.tipo == $3.tipo)))
        yyerror("Las expresiones no son del mismo tipo o no son validas");
    else
        $$.tipo = T_LOGICO;

	$$.pos = creaVarTemp();
	emite(EASIG, crArgEnt(1), crArgNul(), crArgPos($$.pos));

	if ($2 == OPIGIG)
	  emite(EIGUAL, crArgPos($1.pos), crArgPos($3.pos), crArgEtq(si+2));
	else
	  emite(EDIST, crArgPos($1.pos), crArgPos($3.pos), crArgEtq(si+2));

	emite(EASIG, crArgEnt(0), crArgNul(), crArgPos($$.pos));
  };
/************************************************************************/

/************************************************************************/
expresionRelacional:
	expresionAditiva
    { $$.tipo = $1.tipo;
      $$.pos = creaVarTemp();
      emite(EASIG, crArgPos($1.pos), crArgNul(), crArgPos($$.pos));
    }
  | expresionRelacional operadorRelacional expresionAditiva
  { $$.tipo = T_ERROR;
    if (!($1.tipo == T_ENTERO && $3.tipo == T_ENTERO))
        yyerror("Los tipos deben ser enteros para comparar");
    else
        $$.tipo = T_LOGICO;

	$$.pos = creaVarTemp();
	emite(EASIG, crArgEnt(1), crArgNul(), crArgPos($$.pos));

	if ($2 == OPMAYOR)
	  emite(EMAY, crArgPos($1.pos), crArgPos($3.pos), crArgEtq(si+2));
	else if ($2 == OPMENOR)
	  emite(EMEN, crArgPos($1.pos), crArgPos($3.pos), crArgEtq(si+2));
	else if ($2 == OPMAYIG)
	  emite(EMAYEQ, crArgPos($1.pos), crArgPos($3.pos), crArgEtq(si+2));
	else
	  emite(EMENEQ, crArgPos($1.pos), crArgPos($3.pos), crArgEtq(si+2));

	emite(EASIG, crArgEnt(0), crArgNul(), crArgPos($$.pos));
  };
/************************************************************************/

/************************************************************************/
expresionAditiva:
	expresionMultiplicativa
    { $$.tipo = $1.tipo;
      $$.pos = creaVarTemp();
      emite(EASIG, crArgPos($1.pos), crArgNul(), crArgPos($$.pos));
    }
  | expresionAditiva operadorAditivo expresionMultiplicativa
  { $$.tipo = T_ERROR;
    if (!($1.tipo == T_ENTERO && $3.tipo == T_ENTERO))
        yyerror("Los tipos deben ser enteros en 'expresion aditiva'");
    else
        $$.tipo = T_ENTERO;

	$$.pos = creaVarTemp();
	if ($2 == OPSUMA)
	  emite(ESUM, crArgPos($1.pos), crArgPos($3.pos), crArgPos($$.pos));
	else
	  emite(EDIF, crArgPos($1.pos), crArgPos($3.pos), crArgPos($$.pos));
  };
/************************************************************************/

/************************************************************************/
expresionMultiplicativa:
	expresionUnaria
    { $$.tipo = $1.tipo;
      $$.pos = creaVarTemp();
      emite(EASIG, crArgPos($1.pos), crArgNul(), crArgPos($$.pos));
    }
  | expresionMultiplicativa operadorMultiplicativo expresionUnaria
  { $$.tipo = T_ERROR;
    if (!($1.tipo == T_ENTERO && $3.tipo == T_ENTERO))
        yyerror("Los tipos deben ser enteros en 'expresion multiplicativa'");
    else
        $$.tipo = T_ENTERO;

	$$.pos = creaVarTemp();
	if ($2 == OPMULT)
	  emite(EMULT, crArgPos($1.pos), crArgPos($3.pos), crArgPos($$.pos));
	else
	  emite(EDIVI, crArgPos($1.pos), crArgPos($3.pos), crArgPos($$.pos));
  };
/************************************************************************/

/************************************************************************/
expresionUnaria:
	expresionSufija
    { $$.tipo = $1.tipo;
      $$.pos = creaVarTemp();
      emite(EASIG, crArgPos($1.pos), crArgNul(), crArgPos($$.pos));
    }
  | operadorUnario expresionUnaria
  { $$.tipo = T_ERROR;
    int t_op = T_ENTERO;
    if ($1 == OPNOT)
	  t_op = T_LOGICO;
    if (t_op != $2.tipo)
        yyerror("Esta operacion no es valida para este tipo");
    else
        $$.tipo = $2.tipo;

	$$.pos = creaVarTemp();
	if ($1 == OPPOS)
      emite(EASIG, crArgPos($2.pos), crArgNul(), crArgPos($$.pos));
	else if ($1 == OPNEG)
	  emite(EDIF, crArgEnt(0), crArgPos($2.pos), crArgPos($$.pos));
	else {
	  emite(EASIG, crArgEnt(1), crArgNul(), crArgPos($$.pos));
	  emite(EIGUAL, crArgPos($2.pos), crArgEnt(0), crArgEtq(si+2));
	  emite(EASIG, crArgEnt(0), crArgNul(), crArgPos($$.pos));
	}
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

	$$.pos = creaVarTemp();
	if ($1 == OPMASMAS)
      emite(ESUM, crArgPos(sim.desp), crArgEnt(1), crArgPos($$.pos));
	else
	  emite(EDIF, crArgPos(sim.desp), crArgEnt(1), crArgPos($$.pos));

	emite(EASIG, crArgPos($$.pos), crArgNul(), crArgPos(sim.desp));
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

	  $$.pos = creaVarTemp();
	  emite(EAV, crArgPos(sim.desp), crArgPos($3.pos), crArgPos($$.pos));
    }
  | ABREPARENTESIS_ expresion CIERRAPARENTESIS_
  { $$.tipo = $2.tipo;
    $$.pos = creaVarTemp();
    emite(EASIG, crArgPos($2.pos), crArgNul(), crArgPos($$.pos));
  }
  | ID_
  { $$.tipo = T_ERROR;
    SIMB sim = obtenerTDS($1);
    if (sim.tipo == T_ERROR)
        yyerror("El identificador no esta declarado");
    else
        $$.tipo = sim.tipo;

	$$.pos = creaVarTemp();
	emite(EASIG, crArgPos(sim.desp), crArgNul(), crArgPos($$.pos));
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

  	$$.pos = creaVarTemp();
  	emite(EASIG, crArgPos(sim.desp), crArgNul(), crArgPos($$.pos));
  	if ($2 == OPMASMAS)
        emite(ESUM, crArgPos(sim.desp), crArgEnt(1), crArgPos(sim.desp));
  	else
  	  emite(EDIF, crArgPos(sim.desp), crArgEnt(1), crArgPos(sim.desp));
  }
  | CTE_
  { $$.tipo = T_ENTERO;
    $$.pos = creaVarTemp();
    emite(EASIG, crArgEnt(yylval.cte), crArgNul(), crArgPos($$.pos));
  }
  | TRUE_
  { $$.tipo = T_LOGICO;
    $$.pos = creaVarTemp();
    emite(EASIG, crArgEnt(1), crArgNul(), crArgPos($$.pos));
  }
  | FALSE_
  { $$.tipo = T_LOGICO;
    $$.pos = creaVarTemp();
    emite(EASIG, crArgEnt(0), crArgNul(), crArgPos($$.pos));
  };
/************************************************************************/

/************************************************************************/
operadorAsignacion:
    IGUAL_
  { $$ = OPIGUAL; }
  | MASIGUAL_
  { $$ = OPSUMIG; }
  | MENOSIGUAL_
  { $$ = OPRESIG; };
/************************************************************************/

/************************************************************************/
operadorLogico:
    ANDAND_
  { $$ = OPANDAND; }
  | OROR_
  { $$ = OPOROR; };
/************************************************************************/

/************************************************************************/
operadorIgualdad:
    IGUALIGUAL_
  { $$ = OPIGIG; }
  | DIFERENTE_
  { $$ = OPNOTIG; };
/************************************************************************/

/************************************************************************/
operadorRelacional:
    MAYORQ_
  { $$ = OPMAYOR; }
  | MENORQ_
  { $$ = OPMENOR; }
  | MAYORIG_
  { $$ = OPMAYIG; }
  | MENORIG_
  { $$ = OPMENIG; };
/************************************************************************/

/************************************************************************/
operadorAditivo:
	MAS_
  { $$ = OPSUMA; }
  | MENOS_
  { $$ = OPRESTA; };
/************************************************************************/

/************************************************************************/
operadorMultiplicativo:
    POR_
  { $$ = OPMULT; }
  | ENTRE_
  { $$ = OPDIV; };
/************************************************************************/

/************************************************************************/
operadorUnario:
    MAS_
  { $$ = OPPOS; }
  | MENOS_
  { $$ = OPNEG; }
  | NEG_
  { $$ = OPNOT; };
/************************************************************************/

/************************************************************************/
operadorIncremento:
    MASMAS_
  { $$ = OPMASMAS; }
  | MENOSMENOS_
  { $$ = OPMENMEN; };
/************************************************************************/
