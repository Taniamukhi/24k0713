#include<stdio.h>
int main()
{
  int num;
  int sum=0;
  printf("Enter the total number:");
  scanf("%d", &num);


  int array[num];

  for(int i = 0; i<num; i++)
{ 
   printf("Enter the number:");
   scanf("%d", &array[i]);

}


   for(int i = 0; i<num; i++)
{
   printf("array[%d]= %d\n" , i, array[i]);
   sum += array[i];

}

   printf("Sum of array numbers: %d\n", sum);
   return 0;
}
