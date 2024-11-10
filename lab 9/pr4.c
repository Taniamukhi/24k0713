#include <stdio.h>
int calculate(int num1, int num2, char operator);
int main() {
    int num1;
	int  num2;
	int result;
    char operator;
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    result = calculate(num1, num2, operator);
    printf("Result: %d\n", result);
    return 0;
}

int calculate(int num1, int num2, char operator)
 {
    int result;
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("Invalid input.\n");
            return 0;
    }
    return result;
}
