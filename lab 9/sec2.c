#include<stdio.h>
#include<string.h>

int main()
{
	char destination[20];
	char source[10];
	int n;
	
	printf("Enter characters for destination string:\n");
	fgets(destination,20,stdin);
	destination[strcspn(destination, "\n")]=0;
	
	printf("Enter characters for source string:\n");
	fgets(source,10,stdin);
	destination[strcspn(source, "\n")]=0;
	
	printf("Enter the number:\n");
	scanf("%d", &n);
	
	strncat(destination,source,n);
	printf("Resulting string is %s", destination);
	return 0;
}
