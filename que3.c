#include<stdio.h>





int main(){
	int taxrate;
	int salary;
	printf("enter taxrate and salary");
	scanf("%d %d", &taxrate, &salary);
	float calculatesalary = ( salary * taxrate ) / 100;
	float tax = calculatesalary - salary;
	printf("the salary after the tax is : %f", calculatesalary);
	printf("the tax amount is %f", tax);
}