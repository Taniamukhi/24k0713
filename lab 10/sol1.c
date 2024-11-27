#include<stdio.h>
void printarray(int arr[], int size) {
    if (size == 0)
	{
        return;
    }
    printf("%d  ", arr[0]); 
    printarray(arr + 1, size - 1); 
}
int main()
{
    int array[30], n,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &array[i]); 
    }
    printf("The elements are: ");
    printarray(array, n);
    return 0;
}
