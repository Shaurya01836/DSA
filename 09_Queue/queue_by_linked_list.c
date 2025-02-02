// Queue by an linked list

#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};

struct queue
{
    struct list *front, *rear;
};

struct queue *create_queue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct queue *q)
{
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

void Enqueue(struct queue *q)
{
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    struct list *p = (struct list *)malloc(sizeof(struct list));
    p->data = value;
    p->next = NULL;

    if (isEmpty(q))
    {
        q->front = q->rear = p;
    }
    else
    {
        (q->rear)->next = p;
        q->rear = p;
    }
}

int Dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int t;
    struct list *p;
    t = (q->front)->data;
    p = q->front;
    if (q->front == q->rear)
    {
        q->front = q->rear = NULL;
    }
    else
    {
        q->front = (q->front)->next;
    }
    free(p);
    return t;
}

int Front(struct queue *q)
{
    return (q->front)->data;
}

void traverse(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }

    struct list *p;
    p = q->front;
    while (p != NULL)
    {
        printf("[%d] ", p->data);
        p = p->next;
    }
}

void dispose(struct queue *q)
{
    struct list *p;
    while (q->front != NULL)
    {
        p = q->front;
        q->front = (q->front)->next;
        free(p);
    }
    q->rear = NULL;
    printf("Queue disposed.\n");
}

int main()
{
    struct queue *q = create_queue();
    int choice, value, t;

    do
    {
        printf("\n Menu \n");
        printf("1. Enqueue value\n");
        printf("2. Dequeue value\n");
        printf("3. Check if empty\n");
        printf("4. Traverse queue\n");
        printf("5. Dispose queue\n");
        printf("6. Front\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Enqueue(q);
            break;
        case 2:
            value = Dequeue(q);
            if (value != -1)
            {
                printf("Dequeued: %d\n", value);
            }
            break;
        case 3:
            if (isEmpty(q))
                printf("The queue is empty.\n");
            else
                printf("Queue is not empty.\n");
            break;
        case 4:
            traverse(q);
            break;
        case 5:
            dispose(q);
            break;
        case 6:
            if (isEmpty(q))
                printf("The queue is empty.\n");
            else
            {
                t = Front(q);
                printf("%d", t);
            }
            break;
        case 7:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 7);

    return 0;
}
