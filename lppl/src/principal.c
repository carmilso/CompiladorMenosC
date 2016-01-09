/*****************************************************************************/
/*  Programa principal del compilador Menos C                                */
/*  Autores:                                                                 */
/*        Pau Baquero Arnal       pabaar@inf.upv.es                          */
/*        Axel Guzmán Godia       axguzgo@inf.upv.es                         */
/*        Carlos Millán Soler     carmilso@inf.upv.es                        */
/*****************************************************************************/

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "libgci.h"

int verbosidad=FALSE;               /* Flag para saber si se desea una traza */
int numErrores=0;                   /* Contador del numero de errores        */
int flagMostrarTDS=FALSE;           /* Flag para mostrar la TDS              */
/*****************************************************************************/
void yyerror(const char * msg)
/*  Tratamiento de errores.                                                  */
{
  numErrores++;
  fprintf(stdout, "\nError at line %d: %s\n", yylineno, msg);
}
/*****************************************************************************/
int main (int argc, char **argv)
/* Gestiona la linea de comandos e invoca al analizador sintactico-semantico.*/
{ char *nom_fich;
  int i, n = 0;

  for (i=0; i<argc; ++i) {
    if (strcmp(argv[i], "-v")==0) { verbosidad = TRUE; n++; }
    if (strcmp(argv[i], "-t")==0) { flagMostrarTDS = TRUE; n++; }
  }
  --argc; n++;
  if (argc == n) {
    if ((yyin = fopen (argv[argc], "r")) == NULL)
      fprintf (stderr, "Fichero no valido %s\n", argv[argc]);
    else {
      if (verbosidad == TRUE) fprintf(stdout,"%3d.- ", yylineno);
      nom_fich = argv[argc];
      yyparse ();
      if (numErrores > 0)
        fprintf(stdout,"\nNumero de errores: %d\n", numErrores);
      else
      {
        fprintf(stdout, "Volcando codigo...\n");
        volcarCodigo(nom_fich);
      }
    }
  }
  else fprintf (stderr, "Uso: cmc [-v] [-t] fichero\n");
}
/*****************************************************************************/
