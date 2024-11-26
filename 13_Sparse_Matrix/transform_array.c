#include <stdio.h>

int read_array(int arr[][3])
{
    int row, col, nterms;
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
        printf("%d %d %d\n", arr[i][0], arr[i][1], arr[i][2]);
    }
}

void transpose(int arr[][3], int b[][3])
{
    int m, n, t, q;
    m = arr[0][0];
    n = arr[0][1];
    t = arr[0][2];
    b[0][0] = n;
    b[0][1] = m;
    b[0][2] = t;

    if (t <= 0)
    {
        return;
    }

    q = 1;
    for (int col = 1; col <= n; col++)
    {
        for (int p = 1; p <= t; p++)
        {
            if (arr[p][1] == col)
            {
                b[q][0] = arr[p][1];
                b[q][1] = arr[p][0];
                b[q][2] = arr[p][2];
                q++;
            }
        }
    }
}

int main()
{
    int nterms;
    int arr[50][3];
    int b[50][3];
    nterms = read_array(arr);
    printf("\n \nMatrix before transpose\n");
    print(arr, nterms);
    transpose(arr, b);
    printf("\n \nMatrix after transpose\n");
    print(b, nterms);
    return 0;
}
