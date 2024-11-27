#include <stdio.h>
void bubbleSort(int arr[], int n) 
{
	int i;
    if (n<=1)
	 {
        return;
     }
    for(i=0; i<n-1; i++)
	 {
        if (arr[i]>arr[i + 1]) 
		{
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    bubbleSort(arr, n-1);
}
void printArray(int arr[], int size) 
{
	int i;
    for (i=0; i<size; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() 
{
    int n,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) 
	{
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Original array: \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
