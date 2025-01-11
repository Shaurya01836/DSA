#include <stdio.h>

void create(int arr[50][50], int n)
{
    arr[n][n];
    int a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter 0 or 1 for %dth row %dth column :", i, j);
            scanf("%d", &a);
            arr[i][j] = a;
        }
    }
}

void print(int arr[50][50], int n)
{
    arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    int arr[50][50];
    int visited[50];
    printf("Enter the no of vertex in the graph :");
    scanf("%d", &n);
    create(arr, n);
    print(arr, n);
    return 0;
}