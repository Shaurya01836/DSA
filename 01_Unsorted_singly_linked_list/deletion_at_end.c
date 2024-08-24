// deletion at the end
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
    struct singly_linked_list *p;
    p = start;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct singly_linked_list *delete_at_end(struct singly_linked_list *start)
{
    struct singly_linked_list *p, *q;
    p = start;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    free(p);
    q->next = NULL;
    return start;
}

int main()
{
    int n, a;
    struct singly_linked_list *start = NULL;
    printf("Enter the value of n :");
    scanf("%d", &n);
    start = create(start, n);
    traverse(start);
    printf("Do you want to delete Last Node - (1) for yes & (0) for No :");
    scanf("%d", &a);
    if (a == 1)
    {
        start = delete_at_end(start);
        traverse(start);
    }
    else if (a == 0)
    {
        printf("Happy coding");
    }

    return 0;
}