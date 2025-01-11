#include <stdio.h>
#define MAX 10

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void MergeSort(int a[], int b[], int c[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
        {
            c[k] = a[i];
            k++, i++;
        }
        else
        {
            c[k] = b[j];
            k++, j++;
        }
    }
    while (i < m)
    {
        c[k] = a[i];
        k++, i++;
    }
    while (j < n)
    {
        c[k] = b[j];
        k++, j++;
    }
}

int main()
{
    int a[MAX], b[MAX], c[MAX * 2];
    int size_a, size_b;

    printf("Enter the size of the array A (must be less than or equal to %d): ", MAX);
    scanf("%d", &size_a);

    printf("Enter elements of array A: ");
    for (int i = 0; i < size_a; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the size of the array B (must be less than or equal to %d): ", MAX);
    scanf("%d", &size_b);

    printf("Enter elements of array B: ");
    for (int i = 0; i < size_b; i++)
    {
        scanf("%d", &b[i]);
    }

    printf("Two sorted arrays:\n");
    printArray(a, size_a);
    printArray(b, size_b);

    MergeSort(a, b, c, size_a, size_b);

    printf("Array after merging the sorted arrays:\n");
    printArray(c, size_a + size_b);

    return 0;
}
