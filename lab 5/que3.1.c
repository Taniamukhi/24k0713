#include<stdio.h>
int main()
{

int num1, num2, max;

printf("Enter two numbers");
scanf("%d %d", &num1, &num2);

max=(num1>num2)?printf("num1 is maximum.\n"):printf("num2 is maximum.\n");

return 0;

}