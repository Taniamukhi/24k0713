#include <stdio.h>

int max(int arr[], int size);
int mini(int arr[], int size);

int main()
 {
    int a[100];
    int size, i;
	printf("Enter size of array: ");
    scanf("%d", &size);
    
    printf("Enter values in array:\n");
    for (i=0; i<size; i++) 
	{
        scanf("%d", &a[i]);
    }

    int maximum = max(a, size);
    int minimum = mini(a, size);

    printf("Maximum value in array: %d\n", maximum);
    printf("Minimum value in array: %d\n", minimum);

    return 0;
}

int max(int arr[], int size)
 {
    int max = arr[0];
    int i;
    for (i=1; i<size; i++) 
	{
        if (arr[i]>max)
		 {
            max=arr[i];
        }
    }
    return max;
}


int mini(int arr[], int size) 
{
    int mini = arr[0];
    int i;
    for (i=1; i<size; i++) 
	{
        if (arr[i]<mini) 
		{
            mini=arr[i];
        }
    }
    return mini;
}

