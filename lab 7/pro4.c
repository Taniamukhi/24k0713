#include<stdio.h>
int main()
{

  int num;
int repeat=0;
printf("Enter the size of array:");
scanf("%d", &num);

int array[num];
int count[100]={0};

for( int i = 0; i<num; i++)
{

  printf("Enter the number:\n");
scanf("%d", &array[i]);
count[array[i]]++;
}

printf("Occurrence more than once:");
for( int i = 0; i<100; i++)
{
  if(count[i]>1)
{
printf("%d", i);
repeat = 1;
}
}
if(!repeat)
{
printf("no duplicate found");
}
return 0;
}


 



