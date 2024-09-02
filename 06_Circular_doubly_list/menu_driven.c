// Menu driven Circular Doubly unsorted linked list

#include <stdio.h>
#include <stdlib.h>
struct circular_list
{
    int data;
    struct circular_list *prev, *next;
};

// Function to create a new node
struct circular_list *getnode(int value)
{
    struct circular_list *p = (struct circular_list *)malloc(sizeof(struct circular_list));
    p->data = value;
    p->prev = p->next = p;
    return p;
}
struct circular_list *Insertion(struct circular_list *start, int value)
{
    struct circular_list *p;
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
        start->next = p;
        p->prev = start;
        start = p;
        return start;
    }
}

void traverse(struct circular_list *start)
{
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