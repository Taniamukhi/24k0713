#include<stdio.h>

int main()
 {
    int num, i;
    printf("Enter the number: ");
    scanf("%d", &num);

  
    while (num >= 10 || num <= -10)
 {
        
        printf("Given number is multiple digit.\n");
        break;
    }

       if(num < 10 && num > -10) 
{
        printf("Given number is not a multiple digit.\n");
    }




 if(num > 1)
{
 int isprime = 1;
 for(i=2; i<=num/2; i++)
 {

    if(num%i==0)
        {
           printf("Number is composite\n");
           isprime=0;
          break;
        }
     }
        
        if (isprime)
 {
            printf("Number is prime.\n");
}
    
}
 else if(num == 1)
 {
        printf("Given number %d is neither prime nor composite.\n", num);
    } 

else {
        printf("Given number %d is not a prime or composite number.\n", num);
    }
    return 0;
}
