#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int length;
	int k;
	int i;
	int n=5;
	char str[5][21];
	printf("Enter %d word(20 characters each):\n", n);
	for(i=0; i<n; i++)
	{
		printf("word %d:", i+1);
		fgets(str[i],sizeof(str[i]),stdin);
		str[i][strcspn(str[i],"\n")]='\0';
	}
	
	for(i=0; i<n; i++)
	{
		length=strlen(str[i])-1;
		k=0;
		int ispalindrome=1;
	
	
	while(length>k)
	{
		if(str[i][length]!= str[i][k])
		{
			ispalindrome=0;
			break;
		}
		length--;
		k++;
	}
	
	 if(ispalindrome) 
	 {
            printf("%s is a palindrome\n", str[i]);
        } else {
            printf("%s is not palindrome\n", str[i]);
        }
    }
        return 0;
}
