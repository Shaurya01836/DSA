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

int main()
{
    struct headerNode *start = NULL;
    readMatrix(&start);
    printf("Sparse Matrix Representation:\n");
    printMatrix(start);
    return 0;
}
