#include<stdio.h>
int main()
{
	int i,j;
	int a[2][3];
	
	printf("Enter the elements of matrix:\n");
	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d", &a[i][j]);
		}
		
	}
	
	printf("Matrix is :\n");
	for(i=0; i<2; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
	printf("Transpose of matrix:\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("%d ", a[j][i]);
		}
		printf("\n");
	}
	
}
