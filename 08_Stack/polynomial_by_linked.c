#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int expo;
    struct poly *next;
};

struct poly *createpoly(struct poly *poly)
{
    int n, coef, expo;
    struct poly *p, *q;
    printf("Enter the no. of terms : ");
    scanf("%d", &n);
    if (n <= 0)
    {
        return NULL;
    }
    printf("Enter the exponent : ");
    scanf("%d", &expo);
    p = (struct poly *)malloc(sizeof(struct poly));
    p->expo = expo;
    printf("Enter the coefficient : ");
    scanf("%d", &coef);
    p->coeff = coef;
    p->next = NULL;
    poly = p;
    for (int i = 1; i < n; i++)
    {
        q = (struct poly *)malloc(sizeof(struct poly));
        printf("Enter the exponent : ");
        scanf("%d", &expo);
        q->expo = expo;
        printf("Enter the coefficient : ");
        scanf("%d", &coef);
        q->coeff = coef;
        q->next = NULL;
        p->next = q;
        p = p->next;
    }
    return poly;
}

void readpoly(struct poly *poly)
{
    if (poly == NULL)
    {
        printf("Polynomial not found\n");
    }
    else
    {
        struct poly *p = poly;
        int check = 1; // Flag to check if it's the first term being printed

        while (p != NULL)
        {
            if (p->coeff != 0)
            { // Only print if the coefficient is not zero
                if (!check)
                {
                    printf(" + ");
                }
                if (p->expo == 0)
                {
                    printf("%d", p->coeff);
                }
                else if (p->expo == 1)
                {
                    printf("%dx", p->coeff);
                }
                else
                {
                    printf("%dx^%d", p->coeff, p->expo);
                }

                check = 0; // After printing the first term, set this flag to 0
            }
            p = p->next;
        }

        if (check)
        {
            // If no term was printed (all coefficients were zero)
            printf("0");
        }

        printf("\n");
    }
}

struct poly *polyAdd(struct poly *poly1, struct poly *poly2)
{
    struct poly *result = NULL, *temp, *last = NULL;
    int coeffSum;

    while (poly1 != NULL && poly2 != NULL)
    {
        temp = (struct poly *)malloc(sizeof(struct poly));

        // Add corresponding terms
        if (poly1->expo == poly2->expo)
        {
            coeffSum = poly1->coeff + poly2->coeff;
            if (coeffSum != 0)
            { // Only create a node if the sum is non-zero
                temp->coeff = coeffSum;
                temp->expo = poly1->expo;
                temp->next = NULL;
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->expo > poly2->expo)
        {
            // Copy poly1 term to result
            temp->coeff = poly1->coeff;
            temp->expo = poly1->expo;
            temp->next = NULL;
            poly1 = poly1->next;
        }
        else
        {
            // Copy poly2 term to result
            temp->coeff = poly2->coeff;
            temp->expo = poly2->expo;
            temp->next = NULL;
            poly2 = poly2->next;
        }
        // Attach to result
        if (result == NULL)
        {
            result = temp;
            last = result;
        }
        else
        {
            last->next = temp;
            last = last->next;
        }
    }

    // Copy remaining terms from poly1, if any
    while (poly1 != NULL)
    {
        temp = (struct poly *)malloc(sizeof(struct poly));
        temp->coeff = poly1->coeff;
        temp->expo = poly1->expo;
        temp->next = NULL;
        last->next = temp;
        last = last->next;
        poly1 = poly1->next;
    }

    // Copy remaining terms from poly2, if any
    while (poly2 != NULL)
    {
        temp = (struct poly *)malloc(sizeof(struct poly));
        temp->coeff = poly2->coeff;
        temp->expo = poly2->expo;
        temp->next = NULL;
        last->next = temp;
        last = last->next;
        poly2 = poly2->next;
    }

    return result;
}

int main()
{
    struct poly *poly1 = NULL;
    struct poly *poly2 = NULL;
    struct poly *result = NULL;
    printf("For first polynomial : \n");
    poly1 = createpoly(poly1);
    readpoly(poly1);
    printf("For second polynomial : \n");
    poly2 = createpoly(poly2);
    readpoly(poly2);
    printf("Final Polynomial : \n");
    result = polyAdd(poly1, poly2);
    readpoly(result);
    return 0;
}