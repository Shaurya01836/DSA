// creation of a Doubly linked list
#include <stdio.h>
#include <stdlib.h>
struct Doubly_linked_list
{
    int data;
    struct Doubly_linked_list *prev, *next;
};

struct Doubly_linked_list *create(struct Doubly_linked_list *start, int n)
{
    int value;
    struct Doubly_linked_list *p, *q;
    if (n <= 0)
    {
        return NULL;
    }
    else
    {
        p = (struct Doubly_linked_list *)malloc(sizeof(struct Doubly_linked_list));
        printf("Enter the value :");
        scanf("%d", &value);
        p->data = value;
        p->prev = NULL;
        p->next = NULL;
        start = p;
        for (int i = 2; i <= n; i++)
        {
            q = (struct Doubly_linked_list *)malloc(sizeof(struct Doubly_linked_list));
            printf("Enter the value :");
            scanf("%d", &value);
            q->data = value;
            q->prev = p;
            q->next = NULL;
            p->next = q;
            p = p->next;
        }
    }
    return start;
}
void traverse(struct Doubly_linked_list *start)
{
    struct Doubly_linked_list *p;
    p = start;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
int main()
{
    int n;
    printf("Enter the value of n :");
    scanf("%d", &n);
    struct Doubly_linked_list *start = NULL;
    start = create(start, n);
    traverse(start);

    return 0;
}