{
  int length; read(length);

  int v[20];
  int i; i = 0;
  int x;

  if (length > 20)
   print(-1);
  else{
    while (i < length){
      print(v[i] = ++i);
    }		// funciona

    print(100);
    i = 0;

    while (i < length)
      print(v[i++]);
  }

  int a;
  a = 1;
  print (a+=a+=a+=a+=a+=1);


  int xx; read(xx);
  if (length < 10 || (length < 15 && (xx-=a/2) == 16))
    print(1);
  else print(-1);

  print(v[v[a -= 30] += 2]);
  print(9999);
  i = 0;
  while (i<length) print(v[i++]);
}
