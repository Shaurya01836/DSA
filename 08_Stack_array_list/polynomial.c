#include <stdio.h>

void read(int N[], int v)
{
    N[0] = v;
    for (int i = 1; i < (2 * v); i++)
    {
        printf("Enter the exponent :");
        scanf("%d", &N[i]);
        printf("Enter the coefficient :");
        scanf("%d", &N[i + 1]);
    }
}

void display(int A[])
{
    for (int i = 0; i < ((A[0] * 2) + 1); i++)
    {
        printf("% d", A[i]);
    }
}

// void padd(int A[], int B[], int C[])
// {
//     A[1] = m;
// }

int main()
{
    int m, n;
    printf("Enter the value of m:");
    scanf("%d", &m);
    // printf("enter the value of n:");
    // scanf("%d", &n);
    int A[100], B[100], C[100];
    read(A[100], m);
    // read(B[100], n);
    // padd(A, B, C);
    display(A[100]);
    return 0;
}