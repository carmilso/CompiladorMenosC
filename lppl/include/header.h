/*****************************************************************************/
/**   Ejemplo de un posible fichero de cabeceras ("header.h") donde situar  **/
/** las definiciones de constantes, variables y estructuras para MenosC.16  **/
/** Los alumos deberan adaptarlo al desarrollo de su propio compilador.     **/ 
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H
/****************************************************** Constantes generales */
#define TRUE  1
#define FALSE 0
/************************************************************** Talla tipos  */
#define TALLA_TIPO_SIMPLE 1
#define MAX_LENGTH 14
/************************************* Variables externas definidas en el AL */
extern FILE *yyin;
extern int   yylineno;
extern int   yydebug;
extern char *yytext;
/********************* Variables externas definidas en el Programa Principal */
extern int verbosidad;              /* Flag para saber si se desea una traza */
extern int numErrores;              /* Contador del numero de errores        */

#endif  /* _HEADER_H */
/****************************************Funciones para el analizador lexico */
void creaNombre();
void creaCentera();
void truncCreal();
/*****************************************************************************/
typedef struct 
{
  int tipo;
  int pos;
} EXPR;
