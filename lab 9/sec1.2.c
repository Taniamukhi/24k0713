#include<stdio.h>

int checkEvenorOdd(int n);
int main()
{
	int n;
	printf("Enter the number:\n");
	scanf("%d", &n);
	checkEvenorodd(n);
	
}

int checkEvenorOdd(int n)
{
	if(n%2==0)
	{
		printf("Number is even\n");
	}
	else
	{
		printf("Number is odd\n");
	}
}
