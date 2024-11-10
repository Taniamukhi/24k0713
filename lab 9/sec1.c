#include<stdio.h>
int product(int a, int b);
int main()
{
	int result = product(4,5);
	printf("Product is %d\n", result);
	return 0;
}

int product(int a, int b)
{
	return a*b;
}
