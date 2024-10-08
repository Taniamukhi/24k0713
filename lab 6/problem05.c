#include<stdio.h>
int main()
{
   int num1=65536;
   int i;
   for(i = 2; i<=9; i++)
{
   printf("%d ", num1);
   num1/=i;
}
   printf("%d\n", num1);
   return 0;
}
  