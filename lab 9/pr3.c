#include<stdio.h>
int isprime(int n);
int main()
{
	int num;
	printf("Enter the number:\n");
	scanf("%d", &num);
	
	if(isprime(num))
	{
		printf("%d is prime number\n", num);
	}
	else
	{
		printf("%d is not prime number\n", num);
	}
	return 0;
}

int isprime(int n)
{
	int i;
	if(n<=1)
	{
		return 0;
	}
	for(i=2; i<=n/2; ++i)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;	
}
