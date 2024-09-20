// linked list by stack
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
}

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
}
struct list *pop(struct list **tos)
{
    if (IsEmpty(*tos))
    {
        printf("Stack is empty\n");
    }
    else
    {
        int t;
        struct list *p;
        t = (*tos)->data;
        p = *tos;
        *tos = (*tos)->next;
        free(p);
        return *tos;
    }
}

struct list *Top(struct list *tos)
{
    if (IsEmpty(tos))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("\n%d\n", tos->data);
    }
}

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
        printf("Null\n");
    }
}

int main()
{
    struct list *tos;
    tos = init(tos);
    int choice;

    do
    {
        printf("\nMenu\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Top\n");
        printf("4.Dispose\n");
        printf("5.Traverse\n");
        printf("6.Is empty \n");
        printf("7.Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            tos = push(tos);
            break;
        case 2:
            tos = pop(&tos);
            break;
        case 3:
            Top(tos);
            break;
        case 4:
            tos = dispose(tos);
            break;
        case 5:
            traverse(tos);
            break;
        case 6:
            if (IsEmpty(tos))
            {
                printf("stack is empty");
            }
            else
            {
                printf("stack is not empty");
            }
            break;
        case 7:
            printf("Exit");
            break;

        default:
            printf("Valid operation");
            break;
        }
    } while (choice != 7);

    return 0;
}