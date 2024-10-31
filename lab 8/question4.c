#include<stdio.h>
int main()
{
	int a[3][3];
	int b[3][3];
	int c[3][3];
	int i,j,k;
	int sum,m,n,p,q;
	
	printf("Enter rows and columns for first matrix:\n");
	scanf("%d %d", &m , &n);
	
	printf("Enter first matrix:\n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("Enter rows and columns for second matrix:\n");
	scanf("%d %d", &p, &q);
	
	printf("\nenter second matrix:\n");
	for(i=0; i<p; i++)
	{
		for(j=0; j<q; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}
	
	printf("\nFirst matrix is :\n");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	
	printf("\nSecond matrix is:\n");
		for(i=0; i<p; i++)
	{
		for(j=0; j<q; j++)
		{
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}
	
	if(n !=p)
	{
		printf("can not multiply");
	}
	else
	{
        
        for(i = 0; i < m; i++) {
            for(j = 0; j < q; j++) {
                c[i][j] = 0;
            }
        }

        
        for(i = 0; i < m; i++) {
            for(j = 0; j < q; j++) {
                for(k = 0; k < n; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
	printf("Multiplication is :\n");
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<q; j++)
		{
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
	
	
	
	return 0;
}
}
