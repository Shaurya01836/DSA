// sort an array by using bubble sort 
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

void SortArray(int *a, int n) //adaptive version of bubble sort
{
    int temp;
    int isSorted = 0;

    for (int i = 0; i < n - 1; i++)
    {
        isSorted = 1;
        printf("Working on pass number %d \n", i + 1);
        for (int j = 0; j < (n - 1 - i); j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                isSorted = 0;
            }
            if (isSorted)
            {
                return;
            }
        }
    }
}

int main()
{
    int a[MAX];
    int size;
    printf("Enter the size of the array (Must less than %d) : ", MAX);
    scanf("%d", &size);
    a[size];
    printf("Enter elements :");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printArray(a, size); // before sorting
    SortArray(a, size);  // for sorting the array
    printArray(a, size); // after sorting
    return 0;
}