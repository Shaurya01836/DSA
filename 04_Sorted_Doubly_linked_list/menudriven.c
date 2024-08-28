// menu driven sorted doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct doubly_linked_list
{
    int data;
    struct doubly_linked_list *prev;
    struct doubly_linked_list *next;
};

// Function to create a new node
struct doubly_linked_list *getnode(int value)
{
    struct doubly_linked_list *p = (struct doubly_linked_list *)malloc(sizeof(struct doubly_linked_list));
    p->data = value;
    p->prev = p->next = NULL;
    return p;
}

// Function to insert a node in a sorted doubly linked list
struct doubly_linked_list *insert(struct doubly_linked_list *start, int value)
{
    struct doubly_linked_list *p, *q;
    p = getnode(value);
    if (start == NULL)
    {
        start = p;
        return start;
    }
    else if (value <= start->data)
    {
        p->next = start;
        start->prev = p;
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
        p->prev = q;
        q->next->prev = p;
        q->next = p;
    }
    else
    {
        p->prev = q;
        q->next = p;
    }
    return start;
}
// Function to delete a node in a sorted doubly linked list
struct doubly_linked_list *delete(struct doubly_linked_list *start)
{
    if (start == NULL)
    {
        printf("Empty list\n");
        return NULL;
    }

    int value;
    printf("Enter the value which you want to delete :");
    scanf("%d", &value);
    struct doubly_linked_list *p, *q;
    p = start;
    if (p->data == value)
    {
        start = start->next;
        start->prev = NULL;
        free(p);
        return start;
    }
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
    p->next->prev = q;
    free(p);
    return start;
}

// Function to traverse and print the doubly linked list
void traverse_beginning(struct doubly_linked_list *start)
{
    struct doubly_linked_list *p;
    p = start;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void traverse_end(struct doubly_linked_list *start)
{
    if (start == NULL)
    {
        printf("NULL \n");
        return;
    }
    struct doubly_linked_list *p;
    p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    printf("NULL ");
    while (p != NULL)
    {
        printf("<- %d ", p->data);
        p = p->prev;
    }
}

int main()
{
    int n, value, choice;
    struct doubly_linked_list *start = NULL;

    while (1)
    {
        printf("\nMenu :\n");
        printf("1.Insertion \n");
        printf("2.Deletion \n");
        printf("3.Traverse from beginning \n");
        printf("4.Traverse from end \n");
        printf("5.Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value of n : ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("Enter value : ");
                scanf("%d", &value);
                start = insert(start, value);
            }
            break;
        case 2:
            start = delete (start);
            break;
        case 3:
            traverse_beginning(start);
            break;
        case 4:
            traverse_end(start);
            break;
        case 5:
            printf("Exit\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    }

    return 0;
}
