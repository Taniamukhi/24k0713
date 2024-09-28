#include<stdio.h>
int main()
{
 int num;
printf("Enter the number:");
scanf("%d", &num);

if(num==0)
{
printf("num is Zero.\n");
}
else if(num>0)
{
if(num%2==0)
{
printf("num is even.\n");
}
else
{
printf("num is odd.\n");
}
}
else if(num<0)
{
printf("num is negative.\n");
}
return 0;
} 
