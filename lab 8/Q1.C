#include <stdio.h>
int main()
{
	int count, i, j, r1, r2;
	printf("Enter the range:\n");
	printf("Range 1 : ");
	scanf("%d", &r1);
	
	printf("Range 2 : ");
	scanf("%d", &r2);
	
	for(i=r1; i<=r2; i++){
		count=0;
		for(j=1; j<=i; j++){
			if(i%j==0){
				count++;
			}
		}
	if(count==2){
	printf("%d ", i);
	}
}
	return 0;
}
