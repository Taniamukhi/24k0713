#include<stdio.h>
void swapintegers(int *a, int *b);
int main()
{
	int num1;
	int num2;
	printf("Enter number 1:\n");
	scanf("%d", &num1);
	printf("Enter number 2:\n");
	scanf("%d", &num2);
	
	printf("integers before swapping:\n");
	printf("num1=%d, num2=%d\n", num1, num2);
	
	swapintegers(&num1, &num2);
	printf("integers after swapping:\n");
	printf("num1=%d, num2=%d", num1, num2);
	
	return 0;
}

void swapintegers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


