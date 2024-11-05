// Linear queue by an array

#include <stdio.h>
#include <stdlib.h>
#define MAX (10)

struct queue
{
    int element[MAX];
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
    if (q->front == 0 && q->rear == MAX - 1)
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

    else if (q->rear == MAX - 1)
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

int Dequeue(struct queue **q)
{
    int t;
    t = (*q)->element[(*q)->front];
    if ((*q)->front == (*q)->rear)
    {
        (*q)->front = (*q)->rear = -1;
    }
    else
    {
        (*q)->front++;
    }
    return t;
}

int Front(struct queue *q)
{
    return q->element[q->front];
}

void traverse(struct queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("[%d] ",q->element[i]);
    }
}

int main()
{
    int choice, t;
    struct queue *q = create_queue();
    do
    {
        printf("\n Menu \n");
        printf("1. Enqueue \n");
        printf("2. Dequeue \n");
        printf("3. Traverse \n");
        printf("4. Front \n");
        printf("5. Is Empty \n");
        printf("6. Is Full \n");
        printf("7. Exit \n");
        printf("Enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (IsFull(q))
            {
                printf("Queue is full");
            }
            else
            {
                q = Enqueue(q);
            }
            break;
        case 2:
            if (IsEmpty(q))
            {
                printf("Queue is empty\n");
            }
            else
            {
                t = Dequeue(&q);
                printf("The value deleted is %d", t);
            }
            break;
        case 3:
            traverse(q);
            break;
        case 4:
            if (IsEmpty(q))
            {
                printf("Queue is empty");
            }
            else
            {
                t = Front(q);
                printf("The value at the top is %d", t);
            }

            break;
        case 5:
            if (IsEmpty(q))
            {
                printf("Queue is empty");
            }
            else
            {
                printf("Queue is not empty");
            }
            break;
        case 6:
            if (IsFull(q))
            {
                printf("Queue is Full");
            }
            else
            {
                printf("Queue is not Full");
            }
            break;
        case 7:
            printf("Exit");
            break;
        default:
            printf("Invalid operation\n");
            break;
        }
    } while (choice != 7);

    return 0;
}