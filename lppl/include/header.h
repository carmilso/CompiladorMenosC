/*****************************************************************************/
/*  Cabecera del compilador Menos C                                          */
/*  Autores:                                                                 */
/*        Pau Baquero Arnal       pabaar@inf.upv.es                          */
/*        Axel Guzmán Godia       axguzgo@inf.upv.es                         */
/*        Carlos Millán Soler     carmilso@inf.upv.es                        */
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
extern int flagMostrarTDS;          /* Flag para mostrar la TDS              */
/****************************************Funciones para el analizador lexico */
void creaNombre();
void creaCentera();
void truncCreal();
/****************************************Estructuras *************************/

/***************************** Variables externas definidas en las librerías */
extern int si;
/*****************************************************************************/
#endif  /* _HEADER_H */
