#include<stdio.h>
int main()
{
	int b[2][2][2] = {{{4,5},{8,5}},{{4,0},{1,9}}};
	int sum1=0, sum2=0;
	int i,j,k;
	
	printf("Matrix is\n");
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			for(k=0; k<2; k++)
			{
					printf("%d ", b[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			sum1 = sum1+b[0][i][j];
			sum2 = sum2+b[1][i][j];
			
		}
	}
	
	printf("Sum of elements1: %d\n", sum1);
	printf("Sum of elements2: %d\n", sum2);
	
	return 0;
	
}
