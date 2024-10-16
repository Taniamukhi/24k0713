#include<stdio.h>
int main()
{
  int num;
  printf("Enter the total number:");
  scanf("%d", &num);


  int array[num];

  for(int i = 0; i<num; i++)
{ 
   printf("Enter the number:");
   scanf("%d", &array[i]);

}

   printf("Numbers in reverse order:\n");
   for(int i = num-1; i>=0; i--)
{
   
   printf("%d\n" , array[i]);
   

}
   return 0;
}
