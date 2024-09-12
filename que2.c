#include<stdio.h>

int main()

{
    int a,b,c;
    
    printf("enter value of a,b");
    scanf("%d %d", &a, &b);
    
    printf("before swap\n"
           "value of a:%d\n"
           "value of b:%d\n",a,b);
            c=a;
            a=b;
            b=c;

    printf("after swap\n"
           "value of a:%d\n"
           "value of b:%d\n",a,b);

}
            
            
         
    
    
  
  