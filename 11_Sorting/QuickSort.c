// sort an array by using Quick sort
#include <stdio.h>
#define MAX (10)

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void QuickSort(int a[], int low, int high) // recursive function
{
    int partitionIndex; // index of pivot after partition
    if (low < high)
    {
        partitionIndex = partition(a, low, high); // for partition
        QuickSort(a, low, partitionIndex - 1);    // sort left sub array
        QuickSort(a, partitionIndex + 1, high);   // sort right sub array
    }
}

int main()
{
    // 4 5 9 1 2 3
    int a[MAX];
    int size;
    printf("Enter the size of the array (Must less than %d) : ", MAX);
    scanf("%d", &size);
    printf("Enter elements :");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array before sorting :\n");
    printArray(a, size);         // before sorting
    QuickSort(a, 0, (size - 1)); // sorting by Quick sort algo
    printf("Array after sorting :\n");
    printArray(a, size); // after sorting
    return 0;
}