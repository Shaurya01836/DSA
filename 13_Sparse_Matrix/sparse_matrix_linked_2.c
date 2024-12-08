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

struct headerNode *transpose(struct headerNode *head)
{
    if (head == NULL || head->head == NULL)
    {
        return NULL;
    }

    // Create the header for the transposed matrix
    struct headerNode *transposeHead = (struct headerNode *)malloc(sizeof(struct headerNode));
    transposeHead->nRow = head->nCol; // Rows become columns
    transposeHead->nCol = head->nRow; // Columns become rows
    transposeHead->nTerm = head->nTerm;
    transposeHead->head = NULL;

    // Map to store transposed rows
    struct rowNode *transposeRows[head->nCol];
    for (int i = 0; i < head->nCol; i++)
    {
        transposeRows[i] = NULL; // Initialize all rows as NULL
    }

    struct rowNode *currentRow = head->head;
    while (currentRow != NULL)
    {
        struct columnNode *currentCol = currentRow->first;
        while (currentCol != NULL)
        {
            int transposeRowIdx = currentCol->col; // Current column becomes row in transpose

            // Ensure the transposed row exists
            if (transposeRows[transposeRowIdx] == NULL)
            {
                struct rowNode *newRow = (struct rowNode *)malloc(sizeof(struct rowNode));
                newRow->row = transposeRowIdx;
                newRow->first = NULL;
                newRow->next = transposeHead->head;
                transposeHead->head = newRow; // Add to transpose's linked list
                transposeRows[transposeRowIdx] = newRow;
            }

            // Add new column node to the transposed row
            struct columnNode *newCol = (struct columnNode *)malloc(sizeof(struct columnNode));
            newCol->col = currentRow->row; // Current row becomes column in transpose
            newCol->elem = currentCol->elem;
            newCol->link = transposeRows[transposeRowIdx]->first;
            transposeRows[transposeRowIdx]->first = newCol;

            currentCol = currentCol->link;
        }

        currentRow = currentRow->next;
    }

    return transposeHead;
}

int main()
{
    struct headerNode *start = NULL, *transposedMatrix = NULL;
    readMatrix(&start);
    printf("Original Sparse Matrix:\n");
    printMatrix(start);
    transposedMatrix = transpose(start);
    printf("Transposed Sparse Matrix:\n");
    printMatrix(transposedMatrix);
    return 0;
}
