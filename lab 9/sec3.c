#include<stdio.h>
int main()
{
	char words[3][50];
	char substr[6]="hello";
	
	int i;
	printf("Enter 3 words:\n");
	for(i=0; i<3; i++)
	{
		printf("word %d : ", i+1);
		scanf("%s", words[i]);
	}
	
	int found = 0;
	for(i=0; i<3; i++)
	{
		if(strstr(words[i],substr))
		{
			printf("substring '%s' found in word %d.\n", substr, i+1);
			found = 1;
		}
	}
	
	if(!found)
	{
		printf("substring '%s' not found in word\n", substr);
	}
	return 0;
	
}
