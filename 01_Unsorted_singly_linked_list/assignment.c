// assignment problems solve - sum of all elements in the linked list , linear search for a particular value.
#include <stdio.h>
#include <stdlib.h>
struct singly_linked_list
{
    int data;
    struct singly_linked_list *next;
};

struct singly_linked_list *create(struct singly_linked_list *start, int n)
{
    struct singly_linked_list *p, *q;
    int value;
    if (n <= 0)
    {
        return NULL;
    }
    else
    {
        p = (struct singly_linked_list *)malloc(sizeof(struct singly_linked_list));
        printf("Enter the value of value :");
        scanf("%d", &value);
        p->data = value;
        p->next = NULL;
        start = p;
        for (int i = 2; i <= n; i++)
        {
            q = (struct singly_linked_list *)malloc(sizeof(struct singly_linked_list));
            printf("Enter the value of value :");
            scanf("%d", &value);
            q->data = value;
            q->next = NULL;
            p->next = q;
            p = p->next;
        }
    }
    return start;
}
void traverse(struct singly_linked_list *start)
{
    int sum = 0;
    struct singly_linked_list *p;
    p = start;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        sum += p->data; // evaluating the sum of the node
        p = p->next;
    }
    printf("NULL\n");
    printf("The sum of the values in node is %d \n", sum);
}

void linear_search(struct singly_linked_list *start)
{
    struct singly_linked_list *p;
    p = start;
    int value, index = 1;
    printf("Enter the value to search: ");
    scanf("%d", &value);
    while (p != NULL)
    {

        if (value == p->data)
        {
            printf("Value %d found in the list and index is %d \n", value, index);
            return;
        }

        p = p->next;
        index++;
    }
    printf("Value %d not found in the list.\n", value);
}

int main()
{
    int n, a;
    struct singly_linked_list *start = NULL;
    printf("Enter the value of n :");
    scanf("%d", &n);
    start = create(start, n);
    traverse(start);
    linear_search(start);
    return 0;
}