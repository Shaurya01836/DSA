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
    printf("[%d]    [%d] [%d]\n", start->nRow, start->nCol, start->nTerm);
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

void addSparseMatrix(struct headerNode *mat1, struct headerNode *mat2, struct headerNode **mat3)
{
    *mat3 = (struct headerNode *)malloc(sizeof(struct headerNode));
    (*mat3)->nRow = mat1->nRow;
    (*mat3)->nCol = mat1->nCol;
    (*mat3)->nTerm = 0;
    (*mat3)->head = NULL;

    struct rowNode *row1 = mat1->head, *row2 = mat2->head, *newRow = NULL, *lastRow = NULL;
    struct columnNode *col1, *col2, *newCol, *lastCol;

    while (row1 != NULL || row2 != NULL)
    {
        if (row2 == NULL || (row1 != NULL && row1->row < row2->row))
        {
            // Copy row from mat1
            newRow = (struct rowNode *)malloc(sizeof(struct rowNode));
            newRow->row = row1->row;
            newRow->first = NULL;
            newRow->next = NULL;

            if ((*mat3)->head == NULL)
            {
                (*mat3)->head = newRow;
            }
            else
            {
                lastRow->next = newRow;
            }
            lastRow = newRow;

            col1 = row1->first;
            lastCol = NULL;
            while (col1 != NULL)
            {
                newCol = (struct columnNode *)malloc(sizeof(struct columnNode));
                newCol->col = col1->col;
                newCol->elem = col1->elem;
                newCol->link = NULL;

                if (newRow->first == NULL)
                {
                    newRow->first = newCol;
                }
                else
                {
                    lastCol->link = newCol;
                }
                lastCol = newCol;

                (*mat3)->nTerm++;
                col1 = col1->link;
            }
            row1 = row1->next;
        }
        else if (row1 == NULL || (row2 != NULL && row1->row > row2->row))
        {
            // Copy row from mat2
            newRow = (struct rowNode *)malloc(sizeof(struct rowNode));
            newRow->row = row2->row;
            newRow->first = NULL;
            newRow->next = NULL;

            if ((*mat3)->head == NULL)
            {
                (*mat3)->head = newRow;
            }
            else
            {
                lastRow->next = newRow;
            }
            lastRow = newRow;

            col2 = row2->first;
            lastCol = NULL;
            while (col2 != NULL)
            {
                newCol = (struct columnNode *)malloc(sizeof(struct columnNode));
                newCol->col = col2->col;
                newCol->elem = col2->elem;
                newCol->link = NULL;

                if (newRow->first == NULL)
                {
                    newRow->first = newCol;
                }
                else
                {
                    lastCol->link = newCol;
                }
                lastCol = newCol;

                (*mat3)->nTerm++;
                col2 = col2->link;
            }
            row2 = row2->next;
        }
        else
        { // Rows are equal
            newRow = (struct rowNode *)malloc(sizeof(struct rowNode));
            newRow->row = row1->row;
            newRow->first = NULL;
            newRow->next = NULL;

            if ((*mat3)->head == NULL)
            {
                (*mat3)->head = newRow;
            }
            else
            {
                lastRow->next = newRow;
            }
            lastRow = newRow;

            col1 = row1->first;
            col2 = row2->first;
            lastCol = NULL;
            while (col1 != NULL || col2 != NULL)
            {
                if (col2 == NULL || (col1 != NULL && col1->col < col2->col))
                {
                    // rows are equal and copying col1 as it is less
                    newCol = (struct columnNode *)malloc(sizeof(struct columnNode));
                    newCol->col = col1->col;
                    newCol->elem = col1->elem;
                    newCol->link = NULL;
                    col1 = col1->link;
                }
                else if (col1 == NULL || (col2 != NULL && col1->col > col2->col))
                {
                    // rows are equal and copying col2 as it is less
                    newCol = (struct columnNode *)malloc(sizeof(struct columnNode));
                    newCol->col = col2->col;
                    newCol->elem = col2->elem;
                    newCol->link = NULL;
                    col2 = col2->link;
                }
                else
                { 
                    // rows are equal and col are also equal
                    newCol = (struct columnNode *)malloc(sizeof(struct columnNode));
                    newCol->col = col1->col;
                    newCol->elem = col1->elem + col2->elem;
                    newCol->link = NULL;
                    col1 = col1->link;
                    col2 = col2->link;
                }

                if (newRow->first == NULL)
                {
                    newRow->first = newCol;
                }
                else
                {
                    lastCol->link = newCol;
                }
                lastCol = newCol;

                (*mat3)->nTerm++;
            }
            row1 = row1->next;
            row2 = row2->next;
        }
    }
}

int main()
{
    struct headerNode *mat1 = NULL, *mat2 = NULL, *mat3 = NULL;

    printf("Enter details for Matrix 1:\n");
    readMatrix(&mat1);
    printf("Enter details for Matrix 2:\n");
    readMatrix(&mat2);
    addSparseMatrix(mat1, mat2, &mat3);
    printf("Resultant Matrix after Addition:\n");
    printMatrix(mat3);
    return 0;
}
