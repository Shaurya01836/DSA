// Linear search for unsorted array
#include <stdio.h>
#define MAX (10)

int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i; // Return index if element is found
        }
    }
    return -1; // Return -1 if element is not found
}

int main()
{
    int arr[MAX];
    int size, element, searchIndex;
    printf("Enter the size of the array (must be less than %d) :", MAX);
    scanf("%d", &size);
    printf("Enter elements in the array :");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to search :");
    scanf("%d", &element);
    searchIndex = linearsearch(arr, size, element);
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