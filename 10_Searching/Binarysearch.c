// Binary search for sorted array (It only works in sorted array)
#include <stdio.h>
#define MAX (10)

int BinarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = MAX - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[MAX];
    int size, element, searchIndex;
    printf("Enter the size of the array (must be less than %d) :", MAX);
    scanf("%d", &size);
    printf("Enter elements in the array (must be in sorted form) :"); // we have to create a sorted array for binary search
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to search :");
    scanf("%d", &element);
    searchIndex = BinarySearch(arr, size, element);
    if (searchIndex != -1)
    {
        printf("Element %d found at %d index of the array", element, searchIndex);
    }
    else
    {
        printf("Element not found");
    }

    return 0;
}