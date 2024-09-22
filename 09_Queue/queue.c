#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int element[10];
    int front, rear;
};

struct queue *create_queue()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = q->rear = -1;
    return q;
}

int IsEmpty(struct queue *q)
{
    if (q->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(struct queue *q)
{
    if (q->front == 0 && q->rear == 9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct queue *Enqueue(struct queue *q)
{
    int value;
    printf("Enter the value :");
    scanf("%d", &value);

    if (IsEmpty(q))
    {
        q->front = q->rear = 0;
    }

    else if (q->rear == 9)
    {
        int i;
        i = q->front;
        while (i <= q->rear)
        {
            q->element[i - q->front] = q->element[i];
            i = i + 1;
        }
        q->rear = q->rear - q->front + 1;
        q->front = 0;
    }
    else
    {
        q->rear = q->rear + 1;
    }
    q->element[q->rear] = value;
    return q;
}

void traverse(struct queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("Element %d: %d\n", i, q->element[i]);
    }
}

int main()
{
    struct queue *q = create_queue();
    q = Enqueue(q);
    q = Enqueue(q);
    q = Enqueue(q);
    traverse(q);
    return 0;
}