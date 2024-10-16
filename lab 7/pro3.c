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

   int minimum_num =array[0];
   for( int i = 1; i<num; i++)
{
   
  
   if(array[i] < minimum_num)
{
   minimum_num = array[i];
}
}
    printf("Minimum_num is %d\n", minimum_num);

 int maximum_num =array[0];
   for( int i = 1; i<num; i++)
{
   
  
   if(array[i] > maximum_num)
{
   maximum_num = array[i];
}
}
    printf("Maximum_num is %d\n", maximum_num);


return 0;

}
