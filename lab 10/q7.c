#include <stdio.h>
#define value 0.001
void conversion(double meters)
{
	static int functioncalled=0;
	functioncalled++;
	double kilometers= meters*value;
	printf("Conversion: %.2f meters to %.4f kilometers\n", meters, kilometers);
    printf("Function has been called %d times.\n", functioncalled);	
}
int main()
{
	double meters;
	char choice;
	do
	{
	printf("Enter meters: ");
	scanf("%lf", &meters);
	conversion(meters);
	printf("\nDo you want to further calculate(y/n):");
	scanf(" %c", &choice);
    }
     while(choice=='y' || choice=='Y');
     if(choice=='n')
     {
 	printf("System Existed!!");
    }
	return 0;
}
