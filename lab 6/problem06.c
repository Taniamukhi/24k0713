#include<stdio.h>
int main()
{

   int num1=1, num2=2, i, next;
   printf("%d %d", num1, num2);

   for(i=3; i<=9; i++)
{
    next = num1*num2;
    printf(" , %d", next);

    num1=num2;
    num2 = next;

}

    return 0;

}


   
   
   
