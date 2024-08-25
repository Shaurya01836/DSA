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
    int sum = 0;
    struct singly_linked_list *p;
    p = start;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        sum += p->data;
        p = p->next;
    }
    printf("NULL\n");
    printf("The sum of the values in node is %d \n", sum);
}

struct singly_linked_list *delete_at_any_pos(struct singly_linked_list *start)
{
    struct singly_linked_list *p, *q;
    int value;
    printf("Enter the value which you want to delete :");
    scanf("%d", &value);
    p = start;
    if (p->data == value)
    {
        start = p->next;
        free(p);
        return start;
    }
    while (p->data != value)
    {
        q = p;
        p = p->next;
        if (p == NULL)
        {
            printf("value not found");
        }
    }
    q->next = p->next;
    free(p);
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
    printf("Do you want to delete the Node - (1) for yes & (0) for No :");
    scanf("%d", &a);
    if (a == 1)
    {
        start = delete_at_any_pos(start);
        traverse(start);
    }
    else if (a == 0)
    {
        printf("Happy coding");
    }

    return 0;
}