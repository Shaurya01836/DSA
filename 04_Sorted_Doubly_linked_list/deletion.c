// insertion and deletion in sorted doubly linked list
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

int main()
{
    int n, value;
    struct doubly_linked_list *start = NULL;
    printf("Enter the value of n : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value : ");
        scanf("%d", &value);
        start = insert(start, value);
    }

    traverse_beginning(start);
    start = delete (start);
    traverse_beginning(start);

    return 0;
}
