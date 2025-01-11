// sort an array by using Selection sort
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
void SelectionSort(int *a, int n)
{
    int indexofMin, temp;
    for (int i = 0; i < (n - 1); i++)
    {
        indexofMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexofMin])
            {
                indexofMin = j;
            }
        }
        // swap
        temp = a[i];
        a[i] = a[indexofMin];
        a[indexofMin] = temp;
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
    printArray(a, size);    // before sorting
    SelectionSort(a, size); // sorting by Selection sort algo
    printf("Array after sorting :\n");
    printArray(a, size); // after sorting
    return 0;
}