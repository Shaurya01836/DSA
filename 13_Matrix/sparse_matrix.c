#include <stdio.h>

int read_array(int arr[][3])
{
    int row, col, nterms, term;
    printf("Enter the rows of the matrix :");
    scanf("%d", &row);
    printf("Enter the columns of the matrix :");
    scanf("%d", &col);
    printf("Enter the non zero terms of the matrix :");
    scanf("%d", &nterms);
    arr[0][0] = row;
    arr[0][1] = col;
    arr[0][2] = nterms;

    for (int i = 1; i <= nterms; i++)
    {
        printf("Enter row index, column index, and value of term %d: ", i);
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }

    return nterms;
}

void print(int arr[][3], int n)
{

    for (int i = 0; i <= n; i++)
    {
        printf("%d %d %d \n", arr[i][0], arr[i][1], arr[i][2]);
    }
}

int main()
{
    int nterms;
    int arr[50][3];
    nterms = read_array(arr);
    print(arr, nterms);
    return 0;
}