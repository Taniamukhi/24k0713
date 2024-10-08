#include<stdio.h>
int main()
{
    int total = 0;
    int num;

   printf("Enter the number:");
   scanf("%d", &num);

while(num != 0)
{
   if (num != 0) {
            total += num;
            printf("Current sum: %d\n", total);


            printf("Enter the number:");
            scanf("%d", &num);



        }

  
      printf("Total Value: %d\n", total);


}
return 0;

}
   

   
