// creation of a singly linked list
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
    int i, v;
    if (n <= 0)
    {
        return NULL;
    }
    else
    {
        p = (struct singly_linked_list *)malloc(sizeof(struct singly_linked_list));
        printf("Enter the value of v :");
        scanf("%d", &v);
        p->data = v;
        p->next = NULL;
        start = p;
        for (int i = 2; i <= n; i++)
        {
            q = (struct singly_linked_list *)malloc(sizeof(struct singly_linked_list));
            printf("Enter the value of v :");
            scanf("%d", &v);
            q->data = v;
            q->next = NULL;
            p->next = q;
            p = p->next;
        }
    }
    return start;
}

void traverse(struct singly_linked_list *start)
{
    struct singly_linked_list *p;
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
    struct singly_linked_list *start = NULL;
    printf("Enter the value of n :");
    scanf("%d", &n);
    start = create(start, n);
    traverse(start);
    return 0;
}