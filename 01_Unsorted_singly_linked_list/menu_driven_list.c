//Menu driven
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
        p = start;  // Initialize p to the start of the list
        for (int i = 1; i < (pos - 1); i++)  // Traverse the list to the (pos-1)th node
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

int main()
{
    struct singly_linked_list *start = NULL;
    int choice, n;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create Linked List\n");
        printf("2. Insert Node at Position\n");
        printf("3. Traverse Linked List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the number of nodes (n): ");
            scanf("%d", &n);
            start = create(start, n);
            break;
        case 2:
            start = insertion_at_position(start);
            break;
        case 3:
            traverse(start);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
