#include <stdio.h>
int linearSearch(int arr[], int size, int target, int index) 
{
    if (index>=size) 
	{
        return -1;
    }
    if (arr[index]==target)
	 {
        return index; 
    }
    return linearSearch(arr, size, target, index + 1);
}
int main()
 {
    int size,i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size]; 
    printf("Enter %d elements:\n", size);
    for (i=0; i<size; i++) 
	{
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    int result = linearSearch(arr, size, target, 0);
    if (result!=-1) 
	{
        printf("Element %d found at index %d.\n", target, result);
    } 
	else 
	{
        printf("Element %d not found in the array.\n", target);
    }
    return 0;
}
