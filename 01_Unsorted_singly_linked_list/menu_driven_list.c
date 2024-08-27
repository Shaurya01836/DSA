// Menu driven
#include <stdio.h>
#include <stdlib.h>

struct singly_linked_list
{
    int data;
    struct singly_linked_list *next;
};

// function for creating a n no. of linked list
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
        for (i = 2; i <= n; i++)
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

// function for counting no. of linked list
int count(struct singly_linked_list *start)
{
    struct singly_linked_list *p;
    p = start;
    int c = 0;
    while (p != NULL)
    {
        p = p->next;
        c = c + 1;
    }
    return c;
}

// function for inserting a value at beginning
struct singly_linked_list *insertion(struct singly_linked_list *start)
{
    struct singly_linked_list *p;
    int v;
    p = (struct singly_linked_list *)malloc(sizeof(struct singly_linked_list));
    printf("Enter the value of v :");
    scanf("%d", &v);
    p->data = v;
    p->next = start;
    start = p;
    return start;
}

// function for inserting a value at the end
struct singly_linked_list *insertion_at_end(struct singly_linked_list *start)
{
    struct singly_linked_list *p, *q;
    int v;
    p = (struct singly_linked_list *)malloc(sizeof(struct singly_linked_list));
    printf("Enter the value of v :");
    scanf("%d", &v);
    p->data = v;
    p->next = NULL;
    if (start == NULL)
    {
        start = p;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
    return start;
}

// function for inserting a value at a specific position
struct singly_linked_list *insertion_at_position(struct singly_linked_list *start)
{
    int n, pos, val;
    printf("Enter the position where you want to insert a node :");
    scanf("%d", &pos);
    struct singly_linked_list *p, *q;
    n = count(start);

    if (pos <= 1 || pos > n)
    {
        printf("Invalid position\n");
        return start;
    }
    else
    {
        p = start;
        for (int i = 1; i < (pos - 1); i++)
        {
            p = p->next;
        }

        q = (struct singly_linked_list *)malloc(sizeof(struct singly_linked_list));
        printf("Enter the value of val :");
        scanf("%d", &val);
        q->data = val;
        q->next = p->next;
        p->next = q;
    }
    return start;
}

// function for deleting a value at beginning
struct singly_linked_list *delete_at_beginnning(struct singly_linked_list *start)
{
    struct singly_linked_list *p;
    if (start == NULL)
    {
        printf("Empty list");
    }
    else
    {
        p = start;
        start = start->next;
        free(p);
    }
    return start;
}

// function for deleting a value at end
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

// function for deleting a value
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
            printf("value not found\n");
            return start;
        }
    }
    q->next = p->next;
    free(p);
    return start;
}

// function for printing the linked list
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
    struct singly_linked_list *start = NULL;
    int choice, n;
    printf("Enter the number of nodes (n): ");
    scanf("%d", &n);
    start = create(start, n);

    while (1)
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
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = insertion(start);
            break;
        case 2:
            start = insertion_at_end(start);
            break;
        case 3:
            start = insertion_at_position(start);
            break;
        case 4:
            start = delete_at_beginnning(start);
            break;
        case 5:
            start = delete_at_end(start);
            break;
        case 6:
            start = delete_at_any_pos(start);
           break;
        case 7:
            traverse(start);
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
