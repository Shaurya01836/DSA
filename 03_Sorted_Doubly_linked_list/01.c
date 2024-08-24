// Sorted doubly linked list
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
    // return p;
}
struct doubly_linked_list *insert(struct doubly_linked_list *start , int value)
{
    struct doubly_linked_list *p, *q;
    p = getnode(5);
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

int main()
{
    int value;
    struct doubly_linked_list *start = NULL;
    insert(start, value);
    return 0;
}