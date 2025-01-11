// sort an array by using insertion sort
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

void InsertionSort(int *a, int n)
{
    int key, j;
    for (int i = 1; i <= (n - 1); i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
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

    printArray(a, size);    // before sorting
    InsertionSort(a, size); // sorting by insertion sort algo
    printArray(a, size);    // after sorting
    return 0;
}