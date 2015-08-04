/*main*/
int main()
{
  return 0;
}
/*main*/

/*fun1*/
int fun1(int a, int b)
{
  if(!(a < b) || !a)
    return a;
  else 
    return b;
}
/*fun1*/

/*fun2*/
int fun2(int a, int b)
{
  if((b < a) && b)
    return b;
  else
    return a;
}
/*fun2*/

/*fun3*/
int fun3(int a)
{
  unsigned ua = (unsigned) a;
  if( a >= 0 )
    return a;
  else 
    return ua;
}
/*fun3*/

/*fun4*/
int fun4(int *ap, int *bp)
{
  int a = *ap;
  int b = *bp;

  return (a + 3*b + b*b);
}
/*fun4*/

/*fun5*/
int fun5(int *ap, int *bp)
{
  int b = *bp;
  int a = *bp + *ap;
  return (a + b);
}
/*fun5*/

/*fun6*/
int fun6(int *ap, int *bp)
{
  int a = *ap;
  int b = *bp - *ap;
  return (a - b);
}
/*fun6*/

/*fun7*/
int fun7(int a)
{
  return (a * 17);
}
/*fun7*/

/*fun8*/
int fun8(int a)
{
  return (a * 34);
}
/*fun8*/

/*fun9*/
int fun9(int a)
{
  return (a * 68);
}
/*fun9*/
