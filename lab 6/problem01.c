#include <stdio.h>

int main() {
    int total = 0;
    int num;

    do {
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num != 0) {
            total += num;
            printf("Current sum: %d\n", total);
        }
    } while (num != 0);

    printf("Total Value: %d\n", total);

    return 0;
}
