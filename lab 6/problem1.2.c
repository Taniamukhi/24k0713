#include<stdio.h>
int main()
{
    int total = 0;
    int num;

    


 for(num = 1; num != 0;)
{
    printf("Enter the number:");
   scanf("%d", &num);

if(num !=0)
{
   total += num;
    printf("Current sum: %d\n", total);

}
 

   
 printf("Total Value: %d\n", total);

}
return 0;
}

