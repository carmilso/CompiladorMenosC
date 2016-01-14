// Ejemplo sencillo de manipulacion de vectores.
// Debe devolver la cuenta inversa desde 9
{ int a[10];
  int i;

  i = 0;
  do a[i]=i; while (i < 10) i++;

  i = 9; 
  do print(a[i]); while (i > 0) i--;
}
