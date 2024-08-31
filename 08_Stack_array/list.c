#include <stdio.h>
#include <stdlib.h>
struct list
{
    int data;
    struct list *next;
};

struct list *init(struct list *tos)
{
    tos = NULL;
    return tos;
};

int IsEmpty(struct list *tos)
{
    if (tos == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct list *push(struct list *tos)
{
    struct list *p;
    p = (struct list *)malloc(sizeof(struct list));
    int value;
    printf("Enter the value you want to insert :");
    scanf("%d", &value);
    p->data = value;
    p->next = tos;
    tos = p;
    return tos;
};

struct list *Top(struct list *tos)
{
    if (IsEmpty(tos))
    {
        printf("Stack is empty :");
    }
    else
    {
        printf("\n%d\n", tos->data);
    }
};

struct list *dispose(struct list *tos)
{
    struct list *p;
    while (tos != NULL)
    {
        p = tos;
        tos = tos->next;
        free(p);
    }
    return tos;
}

void traverse(struct list *tos)
{
    if (IsEmpty(tos))
    {
        printf("\nStack is empty\n");
        return;
    }
    else
    {
        struct list *p;
        p = tos;
        while (p != NULL)
        {
            printf("%d -> ", p->data);
            p = p->next;
        }
    }
}

int main()
{
    struct list *tos;
    tos = init(tos);
    tos = push(tos);
    tos = push(tos);
    traverse(tos);
    Top(tos);
    tos = dispose(tos);
    traverse(tos);

    return 0;
}