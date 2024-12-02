#include <stdio.h>

int insertheap(int tree[], int *n, int item)
{
    int ptr, par;
    (*n)++;
    ptr = *n;
    while (ptr > 1)
    {
        par = ptr / 2;
        if (item <= tree[par])
        {
            tree[ptr] = item;
            return;
        }
        tree[ptr] = tree[par];
        ptr = par;
    }
    tree[1] = item;
    return;
}

void delheap(int tree[], int *n, int *item)
{
    int last;
    *item = tree[1];
    last = tree[*n];
    (*n)--;
    int ptr = 1, left = 2, right = 3;
    while (right <= *n)
    {
        if (last >= tree[left] && last >= tree[right])
        {
            tree[ptr] = last;
            return;
        }
        if (tree[right] <= tree[left])
        {
            tree[ptr] = tree[left];
            ptr = left;
        }
        else
        {
            tree[ptr] = tree[right];
            ptr = right;
        }
        left = 2 * ptr;
        right = left + 1;
    }
    if (left == *n && last < tree[left])
    {
        tree[ptr] = tree[left];
        ptr = left;
    }
    tree[ptr] = last;
}

void heapSort(int a[], int n)
{
    for (int j = 1; j <= n - 1; j++)
    {
        insertheap(a, &j, a[j + 1]);
    }
    while (n > 1)
    {
        int i = 1;
        int items;
        int b[50];
        delheap(a, n, items);
        b[i] = items;
        i++;
    }
}

int main()
{
    int n = 0;
    int tree[20];

    int items[] = {0, 10, 20, 5, 6, 1};
    n = 5;
    for (int i = 2; i <= n; i++)
    {
        insertheap(tree, &i, items[i]);
    }

    printf("Heap before sorting:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", tree[i]);
    }
    printf("\n");

    heapSort(tree, n);

    printf("Sorted array:\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", tree[i]);
    }
    printf("\n");

    return 0;
}