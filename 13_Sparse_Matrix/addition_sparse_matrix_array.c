#include <stdio.h>

void read_array(int arr[][3])
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
}

void print(int arr[][3])
{

    for (int i = 0; i <= arr[0][2]; i++)
    {
        printf("%d %d %d \n", arr[i][0], arr[i][1], arr[i][2]);
    }
}

void add_SparseMatrix(int mat1[][3], int mat2[][3], int mat3[][3])
{
    int t1, t2, i, j, k;
    j = k = i = 1;
    t1 = mat1[0][2];
    t2 = mat2[0][2];
    while (i <= t1 && j <= t2)
    {
        if (mat1[i][0] < mat2[j][0])
        {
            mat3[k][0] = mat1[i][0];
            mat3[k][1] = mat1[i][1];
            mat3[k][2] = mat1[i][2];
            k++;
            i++;
        }
        else if (mat1[i][0] > mat2[j][0])
        {
            mat3[k][0] = mat2[j][0];
            mat3[k][1] = mat2[j][1];
            mat3[k][2] = mat2[j][2];
            k++;
            j++;
        }
        else if (mat1[i][1] < mat2[j][1])
        {
            mat3[k][0] = mat1[i][0];
            mat3[k][1] = mat1[i][1];
            mat3[k][2] = mat1[i][2];
            k++;
            i++;
        }
        else if (mat1[i][1] > mat2[j][1])
        {
            mat3[k][0] = mat2[j][0];
            mat3[k][1] = mat2[j][1];
            mat3[k][2] = mat2[j][2];
            k++;
            j++;
        }
        else
        {
            mat3[k][0] = mat2[j][0];
            mat3[k][1] = mat2[j][1];
            mat3[k][2] = mat2[j][2] + mat1[i][2];
            k++;
            j++;
            i++;
        }
    }

    while (i <= t1)
    {
        mat3[k][0] = mat1[i][0];
        mat3[k][1] = mat1[i][1];
        mat3[k][2] = mat1[i][2];
        k++;
        i++;
    }

    while (j <= t2)
    {
        mat3[k][0] = mat2[j][0];
        mat3[k][1] = mat2[j][1];
        mat3[k][2] = mat2[j][2];
        j++;
        k++;
    }
    mat3[0][0] = mat1[0][0];
    mat3[0][1] = mat1[0][1];
    mat3[0][2] = k - 1;
}

int main()
{
    int mat1[50][3], mat2[50][3], mat3[50][3];
    read_array(mat1);
    read_array(mat2);
    add_SparseMatrix(mat1, mat2, mat3);
    printf("\n \nMatrix after addition :\n");
    print(mat3);
    return 0;
}