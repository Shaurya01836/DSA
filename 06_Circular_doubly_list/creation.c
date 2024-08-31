// Circular Doubly unsorted linked list

#include <stdio.h>
#include <stdlib.h>
struct circular_list
{
    int data;
    struct circular_list *prev, *next;
};
struct circular_list *creation(struct circular_list *start, int n)
{
    struct circular_list *p, *q;
    if (n <= 0)
    {
        return NULL;
    }
    else
    {
        p = (struct circular_list *)malloc(sizeof(struct circular_list));
        int value;
        printf("Enter the value :");
        scanf("%d", &value);
        p->data = value;
        p->prev = p;
        p->next = p;
        start = p;
        for (int i = 2; i <= n; i++)
        {
            q = (struct circular_list *)malloc(sizeof(struct circular_list));
            int value;
            printf("Enter the value :");
            scanf("%d", &value);
            q->data = value;
            q->prev = start;
            q->next = start;
            p->next = q;
            p->prev = q;
            p = p->next;
        }
    }
    return start;
}

void traverse(struct circular_list *start)
{
    struct circular_list *p;
    p = start;
    do
    {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != start);
    printf("NULL\n");
}

int main()
{
    int n;
    printf("Enter the no of nodes :");
    scanf("%d", &n);
    struct circular_list *start = NULL;
    start = creation(start, n);
    traverse(start);
    return 0;
}