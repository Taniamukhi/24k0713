#include<stdio.h>
void main()
{
	int i,j,l;
	char s1[30];
	char c;
	printf("Enter string");
	gets(s1);
	l=strlen(s1);
	
	for(i=0,j=l-1; i<j; i++,j--)
	{
		c=s1[i];
		s1[i]=s1[j];
		s1[j]=c;
	}
	printf("%s", s1);
}
