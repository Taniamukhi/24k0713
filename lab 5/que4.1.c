#include<stdio.h>
int main()
{
int a;
int b;

printf("Enter the number:");
scanf("%d", &a);

printf("Enter the number:");
scanf("%d", &b);

printf("Before swapping: a=%d, b=%d", a, b);

a=a^b;
b=a^b;
a=a^b;

printf("After swapping: a=%d, b=%d", a, b);

return 0;
}


