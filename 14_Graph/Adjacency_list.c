#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// queue
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
    if ((q->front == 0 && q->rear == MAX - 1) || q->front == q->rear + 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
struct queue *Enqueue(struct queue *q, int value)
{

    if (IsEmpty(q))
    {
        q->front = q->rear = 0;
    }

    else if (q->rear == MAX - 1)
    {
        q->rear = 0;
    }
    else
    {
        q->rear = q->rear + 1;
    }
    // another way else{q->rear = (q->rear +1 ) % MAX}
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
        (*q)->front = ((*q)->front + 1) % MAX;
    }
    return t;
}


int visited[20] = {0};
int visited1[20] = {0};

// adjacency list
struct node
{
    int vertex;
    struct node *next;
};

void create(struct node *arr[], int n)
{
    int v;
    char ch;
    struct node *p;
    for (int i = 0; i < n; i++)
    {
        arr[i] = NULL;
        struct node *last = NULL;

        printf("Enter the value of vertex %d: ", i + 1);
        scanf("%d", &v);
        p = (struct node *)malloc(sizeof(struct node));
        p->vertex = v;
        p->next = NULL;
        arr[i] = p;
        last = arr[i];
        do
        {
            printf("add another adjacent vertex to %d? (y/n): ", v);
            scanf(" %c", &ch);
            if (ch == 'y' || ch == 'Y')
            {
                struct node *newNode = (struct node *)malloc(sizeof(struct node));
                printf("Enter the adjacent vertex: ");
                scanf("%d", &newNode->vertex);
                newNode->next = NULL;

                last->next = newNode;
                last = newNode;
            }
        } while (ch == 'y' || ch == 'Y');
    }
}

void printGraph(struct node *arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        struct node *temp = arr[i];
        printf("Vertex %d: ", i + 1);
        printf("[%d]", temp->vertex);
        temp = temp->next;
        while (temp != NULL)
        {
            printf(" -> [%d]", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DFS(struct node *arr1[20], int n)
{
    visited[n - 1] = 1;
    printf("V%d  ", n);
    struct node *p;
    p = arr1[n - 1];
    while (p != NULL)
    {
        if (visited[(p->vertex) - 1] == 0)
        {
            DFS(arr1, p->vertex);
        }
        p = p->next;
    }
}

void BFS(struct node *arr1[20], int n)
{
    struct queue *q = create_queue();
    struct node *p;
    visited1[n - 1] = 1;
    printf("V%d  ", n);
    p = arr1[n - 1];
    while (1)
    {
        while (p != NULL)
        {
            if (visited1[(p->vertex) - 1] == 0)
            {
                Enqueue(q, p->vertex);
                visited1[(p->vertex) - 1] = 1;
            }
            p = p->next;
        }

        if (IsEmpty(q))
        {
            return;
        }
        n = Dequeue(&q);
        printf("V%d ", n);
        p = arr1[n - 1];
    }
}

int main()
{
    struct node *arr[20];
    int n, sVertice, choice;
    do
    {
        printf("\nMENU\n");
        printf("1. Create Graph.\n");
        printf("2. Display the list.\n");
        printf("3. Depth first search.\n");
        printf("4. Breadth first search.\n");
        printf("5. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of vertices: ");
            scanf("%d", &n);
            create(arr, n);
            break;
        case 2:
            printf("\nAdjacency List:\n");
            printGraph(arr, n);
            break;
        case 3:
            printf("Enter the started vertices: ");
            scanf("%d", &sVertice);
            DFS(arr, sVertice);
            break;
        case 4:
            printf("\nEnter the started vertices: ");
            scanf("%d", &sVertice);
            BFS(arr, sVertice);
            break;
        case 5:
            printf("Exit\n");
        default:
            printf("Invalid operation");
        }

    } while (choice != 5);

    return 0;
}
