#include <stdio.h>


int main()
 {
    int i, j, n;
    printf("Enter the number: ");
    scanf("%d", &n);

    for(i = n; i > 0; i--) {  
        for(j = 0; j < n - i; j=j+2) {
            printf(" ");
        }

        
        for(j = i; j > 0; j=j-2) {
            if(j % 2 != 0) {
                printf("%d ", j);
            }
        }

        printf("\n");
    }

    return 0;
}
