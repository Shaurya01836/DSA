#include <stdio.h>

struct list
{
    int data;
    struct list *next;
};

struct queue
{
    struct list *front, *rear;
};

struct list *create_queue(struct queue *q)
{
    q->front = q->rear = NULL;
}

int IsEmpty(struct queue *q)
{
    return (q->front == NULL);
}

void *Enqueue(struct queue *q)
{
    int value;
    printf("Enter the value :");
    scanf("%d", &value);
    struct list *p;
    p = (struct list *)malloc(sizeof(struct list));
    p->data = value;
    p->next = NULL;
    if (IsEmpty(q))
    {
        q->front = q->rear = p;
    }
    else
    {
        (q->rear)->next = p;
        q->rear = p;
    }
}

int main()
{
    struct queue q;
    create_queue(&q);

    Enqueue(&q);
    return 0;
}