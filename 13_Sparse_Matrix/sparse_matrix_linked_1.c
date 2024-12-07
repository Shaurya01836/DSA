#include <stdio.h>
#include <stdlib.h>

struct columnNode
{
    int col, elem;
    struct columnNode *link;
};

struct rowNode
{
    int row;
    struct rowNode *next;
    struct columnNode *first;
};

struct headerNode
{
    int nRow, nCol, nTerm;
    struct rowNode *head;
};

void readMatrix(struct headerNode **start)
{
    int nrow, ncol, nterms;

    *start = (struct headerNode *)malloc(sizeof(struct headerNode));

    printf("Enter the rows of the matrix: ");
    scanf("%d", &nrow);
    (*start)->nRow = nrow;

    printf("Enter the columns of the matrix: ");
    scanf("%d", &ncol);
    (*start)->nCol = ncol;

    printf("Enter the non-zero terms of the matrix: ");
    scanf("%d", &nterms);
    (*start)->nTerm = nterms;

    (*start)->head = NULL;

    if (nterms <= 0)
    {
        printf("Invalid operation");
        return;
    }

    int row, col, term;
    struct rowNode *newRow, *currentRow;
    currentRow = NULL;
    struct columnNode *newCol, *currentCol;
    for (int i = 0; i < nterms; i++)
    {
        printf("Enter row,col and value :");
        scanf("%d %d %d", &row, &col, &term);
        if (currentRow == NULL || currentRow->row != row)
        {
            newRow = (struct rowNode *)malloc(sizeof(struct rowNode));
            newRow->row = row;

            newRow->first = NULL;
            newRow->next = NULL;
            if ((*start)->head == NULL)
            {
                (*start)->head = newRow;
            }
            else
            {
                currentRow->next = newRow;
            }
            currentRow = newRow;
            currentCol = NULL;
        }
        newCol = (struct columnNode *)malloc(sizeof(struct columnNode));
        newCol->col = col;
        newCol->elem = term;
        newCol->link = NULL;
        if (currentRow->first == NULL)
        {
            currentRow->first = newCol;
        }
        else
        {
            currentCol->link = newCol;
        }
        currentCol = newCol;
    }
}

void printMatrix(struct headerNode *start)
{
    if (start == NULL)
    {
        printf("Matrix is empty.\n");
        return;
    }
    struct rowNode *row = start->head;
    struct columnNode *col;

    while (row != NULL)
    {
        printf("[%d] -> ", row->row);
        col = row->first;
        while (col != NULL)
        {
            printf("[%d] [%d] ", col->col, col->elem);
            col = col->link;
            if (col != NULL)
            {
                printf("-> ");
            }
        }
        printf("\n");
        row = row->next;
    }
}

int readArray(struct headerNode *start, int arr[][3])
{
    if (start == NULL)
    {
        printf("Matrix is empty.\n");
        return -1;
    }
    arr[0][0] = start->nRow;
    arr[0][1] = start->nCol;
    arr[0][2] = start->nTerm;
    struct rowNode *row = start->head;
    struct columnNode *col;
    int i = 1;
    while (row != NULL)
    {

        arr[i][0] = row->row;
        col = row->first;
        while (col != NULL)
        {

            arr[i][1] = col->col;
            arr[i][2] = col->elem;
            col = col->link;
            if (col != NULL)
            {
                i++;
                arr[i][0] = row->row;
            }
        }
        row = row->next;
        i++;
    }
    return arr[0][2];
}

void fast_transpose(int A[][3], int B[][3])
{
    int C[10], S[10];
    int m = A[0][0];
    int n = A[0][1];
    int t = A[0][2];
    B[0][0] = n;
    B[0][1] = m;
    B[0][2] = t;
    if (t <= 0)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        C[i] = 0;
    }

    for (int i = 1; i <= t; i++)
    {
        C[A[i][1]]++;
    }

    S[0] = 1;
    for (int k = 1; k <= n; k++)
    {
        S[k] = S[k - 1] + C[k - 1];
    }

    for (int i = 1; i <= t; i++)
    {
        int j = A[i][1];
        B[S[j]][0] = A[i][1];
        B[S[j]][1] = A[i][0];
        B[S[j]][2] = A[i][2];

        S[j] = S[j] + 1;
    }
}

void arrayToLinked(int arr[][3], struct headerNode **start)
{
    *start = (struct headerNode *)malloc(sizeof(struct headerNode));
    (*start)->nRow = arr[0][0];
    (*start)->nCol = arr[0][1];
    (*start)->nTerm = arr[0][2];
    (*start)->head = NULL;

    struct rowNode *currentRow = NULL, *newRow;
    struct columnNode *currentCol = NULL, *newCol;

    for (int i = 1; i <= arr[0][2]; i++)
    {
        if (currentRow == NULL || currentRow->row != arr[i][0])
        {
            newRow = (struct rowNode *)malloc(sizeof(struct rowNode));
            newRow->row = arr[i][0];
            newRow->first = NULL;
            newRow->next = NULL;
            if ((*start)->head == NULL)
            {
                (*start)->head = newRow;
            }
            else
            {
                currentRow->next = newRow;
            }
            currentRow = newRow;
            currentCol = NULL;
        }
        newCol = (struct columnNode *)malloc(sizeof(struct columnNode));
        newCol->col = arr[i][1];
        newCol->elem = arr[i][2];
        newCol->link = NULL;
        if (currentRow->first == NULL)
        {
            currentRow->first = newCol;
        }
        else
        {
            currentCol->link = newCol;
        }
        currentCol = newCol;
    }
}

int main()
{
    int n;
    int arr[50][3], b[50][3];
    struct headerNode *start = NULL, *transposedStart = NULL;
    readMatrix(&start);
    printf("Sparse Matrix Representation:\n");
    printMatrix(start);
    n = readArray(start, arr);
    fast_transpose(arr, b);
    arrayToLinked(b, &transposedStart);
    printf("\nTransposed Sparse Matrix Representation:\n");
    printMatrix(transposedStart);
    return 0;
}
