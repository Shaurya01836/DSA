// Menu driven Circular sorted singly linked list

#include <stdio.h>
#include <stdlib.h>
struct circular_list
{
    int data;
    struct circular_list *next;
};

// Function to create a new node
struct circular_list *getnode(int value)
{
    struct circular_list *p = (struct circular_list *)malloc(sizeof(struct circular_list));
    p->data = value;
    p->next = p;
    return p;
}

struct circular_list *Insertion(struct circular_list *start, int value)
{
    struct circular_list *p, *q, *r;
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
        q = start->next;
        do
        {
            p = p->next;
        } while (p->next != q);
        p->next = start;
        p = start;
        return start;
    }
    r = start;

    while (r->next != start && value > r->next->data)
    {
        r = r->next;
    }
    if (r->next != start)
    {
        p->next = r->next;
        r->next = p;
    }
    else
    {
        r->next = p;
        p->next = start;
    }
    return start;
}

struct circular_list *Deletion(struct circular_list *start)
{
    int value;
    printf("Enter the value :");
    scanf("%d", &value);
    struct circular_list *p, *q;
    p = start;
    if (start == NULL)
    {
        printf("Empty list \n");
        return start;
    }
    else if (start->next == start && start->data == value)
    {
        free(start);
        start = NULL;
        return start;
    }
    else if (p->data == value)
    {
        q = start->next;
        while (q->next != start)
        {
            q = q->next;
        }
        p = start;
        start = start->next;
        q->next = start;
        free(p);
    }
    while (p->data != value)
    {
        q = p;
        p = p->next;
        if (p == start)
        {
            printf("Value not found\n");
            return start;
        }
    }
    q->next = p->next;
    free(p);
    return start;
}

void traverse(struct circular_list *start)
{
    if (start == NULL)
    {
        printf("Empty list \n");
        return ;
    }
    struct circular_list *p;
    p = start;
    do
    {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != start);
}

int main()
{

    int choice, value;
    struct circular_list *start = NULL;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Traverse Linked List\n");
        printf("4. Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d", &value);
            start = Insertion(start, value);
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
            printf("InValid operation");
            break;
        }
    } while (choice != 4);
    return 0;
}