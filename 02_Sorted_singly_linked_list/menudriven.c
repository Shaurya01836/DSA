// menu driven sorted singly linked list
#include <stdio.h>
#include <stdlib.h>
struct linked_list
{
    int data;
    struct linked_list *next;
};
struct linked_list *getnode(int value)
{
    struct linked_list *p = (struct linked_list *)malloc(sizeof(struct linked_list));
    p->data = value;
    p->next = NULL;
    return p;
}
struct linked_list *Insertion(struct linked_list *start)
{
    struct linked_list *p, *q;
    int value;
    printf("Enter the value :");
    scanf("%d", &value);
    p = getnode(value);
    if (start == NULL)
    {
        start = p;
        return start;
    }
    else if (value <= start->data)
    {
        p->next = start;
        start = p;
        return start;
    }
    q = start;
    while (q->next != NULL && value > q->next->data)
    {
        q = q->next;
    }
    if (q->next != NULL)
    {
        p->next = q->next;
        q->next = p;
    }
    else
    {
        q->next = p;
    }
    return start;
}
void traverse(struct linked_list *start)
{
    struct linked_list *p;
    p = start;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

struct linked_list *Deletion(struct linked_list *start)
{
    struct linked_list *p, *q;
    if (start == NULL)
    {
        printf("Empty list \n");
        return start;
    }
    int value;
    p = start;
    printf("Enter the value you want to delete:");
    scanf("%d", &value);
    if (p->data == value)
    {
        start = start->next;
        free(p);
        return start;
    }
    else
    {
        while (p->data != value)
        {
            q = p;
            p = p->next;
            if (p == NULL)
            {
                printf("Value not found \n");
                return start;
            }
        }
        q->next = p->next;
        free(p);
        return start;
    }
}

int main()
{
    int choice;
    struct linked_list *start = NULL;
    do
    {
        printf("\nMenu :\n");
        printf("1.Insertion \n");
        printf("2.Deletion \n");
        printf("3.Traverse \n");
        printf("4.Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = Insertion(start);
            break;
        case 2:
            start = Deletion(start);
            break;
        case 3:
            traverse(start);
            break;
        case 4:
            printf("Exit");
            break;

        default:
            printf("Invalid operation");
            break;
        }
    } while (choice != 4);

    return 0;
}