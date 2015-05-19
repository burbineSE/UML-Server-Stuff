int main()
{
  return 0;
}

int fun1(int a, int b)
{
  if(!(a < b) || !a)
    return a;
  else 
    return b;
}
/*
int fun2(int a, int b)
{
  if((b < a) && b)
    return b;
  else
    return a;
}

int fun3(int a)
{
  unsigned ua = (unsigned) a;
  if( a >= 0 )
    return a;
  else 
    return ua;
}

int fun4(int *ap, int *bp)
{
  int a = *ap;
  int b = *bp;

  return (a + 3*b + b*b);
}

int fun5(int *ap, int *bp)
{
  int b = *bp;
  int a = *bp + *ap;
  return (a + b);
}

int fun6(int *ap, int *bp)
{
  int a = *ap;
  int b = *bp - *ap;
  return (a - b);
}

int fun7(int a)
{
  return (a * 17);
}

int fun8(int a)
{
  return (a * 34);
}

int fun9(int a)
{
  return (a * 68);
}
*/
