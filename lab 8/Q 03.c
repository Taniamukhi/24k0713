#include<stdio.h>
int main()
{
	int matrix[3][3];
	int i,j,c,k;
	int mini=0, max=0;
	int count=0;
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("Enter the elements of matrix[%d][%d]: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("Elements of 3x3 matrix is......:\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf("%d", matrix[i][j]);
			
		}
		printf("\n");
	}
	
	for(i=0; i<3; i++)
	{
		  mini=matrix[i][0];
	    c=0;
	  for(j=0; j<3; j++)
	  {
	  	if(matrix[i][j]<mini)
		  {
				mini=matrix[i][j];
				c=j;
			}
		}
		
		for(k=0; k<3; k++)
		{
			if(matrix[k][c]>max)
			{
				max=matrix[k][c];
				
			}
		}
		
		if(mini==max)
		{
			printf("Saddle point of matrix 3x3 is %d", max);
			count=1;
		}
	
}
    if(count==0){
    	printf("No Saddle point in matrix!!");
	}	
	return 0;
}
	  
	
    
	
	
	
