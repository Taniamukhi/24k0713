#include<stdio.h>

int main()

{
  float principal;
  float timeperiod;
  float interest;
  

  printf("Enter the values of principal, timeperiod, interest");
  
  scanf("%f %f %f",&principal, &timeperiod, &interest);
  
  
  printf("simple interest: %f",(principal*timeperiod*interest)/100 ); 

}