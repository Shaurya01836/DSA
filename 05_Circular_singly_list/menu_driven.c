// Menu driven Circular singly unsorted linked list

#include <stdio.h>
#include <stdlib.h>
struct circular_list
{
    int data;
    struct circular_list *next;
};

int count(struct circular_list *start)
{
    struct circular_list *p;
    p = start;
    int c = 0;
    do
    {
        p = p->next;
        c = c + 1;
    } while (p != start);

    return c;
}

struct circular_list *Insertion_beg(struct circular_list *start)
{
    int value;
    printf("Enter the value:");
    scanf("%d", &value);
    struct circular_list *p, *q;
    p = (struct circular_list *)malloc(sizeof(struct circular_list));
    if (start == NULL)
    {
        p->data = value;
        p->next = p;
        start = p;
    }
    else
    {
        q = (struct circular_list *)malloc(sizeof(struct circular_list));
        q->data = value;
        q->next = start;
        p = start;
        start = q;
        p->next = start;
    }
    return start;
}

struct circular_list *Insertion_end(struct circular_list *start)
{
    int value;
    printf("Enter the value:");
    scanf("%d", &value);
    struct circular_list *p, *q;
    p = (struct circular_list *)malloc(sizeof(struct circular_list));
    if (start == NULL)
    {
        p->data = value;
        p->next = p;
        start = p;
    }
    else
    {
        p = start;
        q = (struct circular_list *)malloc(sizeof(struct circular_list));
        while (p->next != start)
        {
            p = p->next;
        }
        p->next = q;
        q->data = value;
        q->next = start;
    }
    return start;
}

struct circular_list *Insertion(struct circular_list *start)
{
    int value, n, pos;
    printf("Enter the position:");
    scanf("%d", &pos);
    n = count(start);
    struct circular_list *p, *q;
    p = (struct circular_list *)malloc(sizeof(struct circular_list));
    p = start;
    if (pos <= 1 || pos > n)
    {
        printf("Invalid Position\n");
        return start;
    }
    printf("Enter the value:");
    scanf("%d", &value);
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    q = (struct circular_list *)malloc(sizeof(struct circular_list));
    q->data = value;
    q->next = p->next;
    p->next = q;
    return start;
}
struct circular_list *Deletion_beg(struct circular_list *start)
{
    struct circular_list *p;
    if (start == NULL)
    {
        printf("Empty list \n");
    }
    else
    {
        p = start;
        start = start->next;
        free(p);
    }
    return start;
}

struct circular_list *Deletion_end(struct circular_list *start)
{
    struct circular_list *p;
    if (start == NULL)
    {
        printf("Empty list \n");
    }
    else
    {
        p = start;
        while (p->next != start)
        {
           
        }
    }
    return start;
}

void traverse(struct circular_list *start)
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

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
    int choice;
    struct circular_list *start = NULL;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert Node at beginning\n");
        printf("2. Insert Node at end\n");
        printf("3. Insert Node at Position\n");
        printf("4. Delete Node at beginning\n");
        printf("5. Delete Node at end\n");
        printf("6. Delete Node at Position\n");
        printf("7. Traverse Linked List\n");
        printf("8. Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = Insertion_beg(start);
            break;
        case 2:
            start = Insertion_end(start);
            break;
        case 3:
            start = Insertion(start);
            break;
        case 4:
            start = Deletion_beg(start);
            break;
        case 5:

            break;
        case 6:

            break;
        case 7:
            traverse(start);
            break;
        case 8:
            printf("Exit...");
            break;

        default:
            printf("Valid operation");
            break;
        }
    } while (choice != 8);
    return 0;
}