#include<stdio.h>

int main()
 {
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);

    while (num >= 10 || num <= -10)
 {
        
        printf("%d is multiple digit.\n");
        break;
    }

       if (num < 10 && num > -10) 
{
        printf("%d is not a multiple digit.\n");
    }

    return 0;
}
