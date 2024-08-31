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
int IsEmpty(struct stack *s)
{
    if (s->tos == -1)
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
    if (IsEmpty(s))
    {
        printf("Stack Underflow\n");
        return;
    }
    else
    {
        int t;
        t = s->arr[s->tos];
        s->tos = s->tos - 1;
    }
}

void traverse(struct stack s)
{
    for (int i = 0; i <= s.tos; i++)
    {
        printf("[%d] ", s.arr[i]);
    }
}

int main()
{
    struct stack s = init(s);
    int n;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int value;
        printf("Enter the value which you want to insert: ");
        scanf("%d", &value);
        s = push(s, value);
    }
    s = pop(&s);
    traverse(s);
    return 0;
}
