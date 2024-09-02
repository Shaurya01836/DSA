// array by the use of stack
#include <stdio.h>

struct stack
{
    int arr[10];
    int tos;
};

struct stack init(struct stack s)
{
    s.tos = -1;
    return s;
}

int IsFull(struct stack s)
{
    if (s.tos == 9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int IsEmpty(struct stack s)
{
    if (s.tos == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct stack push(struct stack s, int value)
{
    if (IsFull(s))
    {
        printf("Stack overflow\n");
    }
    else
    {

        s.arr[s.tos + 1] = value;
        s.tos = s.tos + 1;
    }
    return s;
}
struct stack pop(struct stack *s)
{
    if (IsEmpty(*s))
    {
        printf("Stack Underflow\n");
        return *s;
    }
    else
    {
        int t;
        t = s->arr[s->tos];
        s->tos = s->tos - 1;
        return *s;
    }
}
struct stack Top(struct stack s)
{
    if (IsEmpty(s))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d", s.arr[s.tos]);
    }
}
struct stack Clear(struct stack s)
{
    s.tos = -1;
    return s;
}
void traverse(struct stack s)
{
    if (s.tos == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    for (int i = 0; i <= s.tos; i++)
    {
        printf("[%d] ", s.arr[i]);
    }
}

int main()
{
    struct stack s = init(s);
    int choice, value;

    do
    {

        printf("\nMenu\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Top\n");
        printf("4.Traverse\n");
        printf("5.Clear\n");
        printf("6.Is Full\n");
        printf("7.Is Empty\n");
        printf("8.Exit\n");
        printf("Enter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value which you want to insert: ");
            scanf("%d", &value);
            s = push(s, value);
            break;
        case 2:
            s = pop(&s);
            break;
        case 3:
            Top(s);
            break;
        case 4:
            traverse(s);
            break;
        case 5:
            s = Clear(s);
            break;
        case 6:
            if (IsFull(s))
            {
                printf("stack is Full");
            }
            else
            {
                printf("stack is not Full");
            }
            break;
        case 7:
            if (IsEmpty(s))
            {
                printf("stack is empty");
            }
            else
            {
                printf("stack is not empty");
            }
            break;
        case 8:
            printf("Exit...");
            break;
        default:
            printf("Invalid choice ");
            break;
        }
    } while (choice != 8);

    return 0;
}
