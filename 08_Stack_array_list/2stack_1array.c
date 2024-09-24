#include <stdio.h>
#include <stdlib.h>
#define MAX (10)

typedef struct
{
    int arr[MAX];
    int top[2];
} stack;

void push(stack *st, int value, int sn)
{
    switch (sn)
    {
    case 1:
        if (st->top[sn - 1] == (MAX / 2) - 1)
        {
            printf("\n Stack overflow ");
            return;
        }
        st->top[sn - 1]++;
        st->arr[st->top[sn - 1]] = value;
        break;
    case 2:
        if (st->top[sn - 1] == (MAX / 2))
        {
            printf("\n Stack overflow ");
            return;
        }
        st->top[sn - 1]--;
        st->arr[st->top[sn - 1]] = value;
        break;
    }
}
int pop(stack *st, int sn)
{
    int value;
    switch (sn)
    {
    case 1:
        if (st->top[sn - 1] == -1)
        {
            printf("\n Stack underflow\n");
            return -1;
        }
        value = st->arr[st->top[sn - 1]];
        st->top[sn - 1]--;
        break;
    case 2:
        if (st->top[sn - 1] == MAX)
        {
            printf("\n Stack underflow\n");
            return -1;
        }
        value = st->arr[st->top[sn - 1]];
        st->top[sn - 1]++;
        break;
    }
    return value;
}
void traverse(stack st, int sn)
{
    switch (sn)
    {
    case 1:
        for (int i = 0; i <= st.top[0]; i++)
        {
            printf("%d ", st.arr[i]);
        }
        break;
    case 2:
        for (int i = MAX - 1; i >= st.top[1]; i--)
        {
            printf("%d ", st.arr[i]);
        }
        break;
    }
}

int main()
{
    stack st = {{0}, {-1, MAX}};
    int value, ch;
    do
    {
        printf("\n Menu \n");
        printf("1. Push in first stack \n");
        printf("2. Push in second stack\n");
        printf("3. Pop in first stack \n");
        printf("4. Pop in second stack\n");
        printf("5. Traverse first stack\n");
        printf("6. Traverse second staxck \n");
        printf("7.Exit\n");
        printf("Enter your choice :");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value :");
            scanf("%d", &value);
            push(&st, value, 1);
            break;
        case 2:
            printf("Enter the value :");
            scanf("%d", &value);
            push(&st, value, 2);
            break;
        case 3:
            value = pop(&st, 1);
            printf("the value is %d", value);
            break;
        case 4:
            value = pop(&st, 2);
            printf("the value is %d", value);
            break;
        case 5:
            printf("\n First stack is :");
            traverse(st, 1);
            break;
        case 6:
            printf("\n Second stack is :");
            traverse(st, 2);
            break;
        case 7:
            printf("Exit");
            break;
        default:
            printf("Invalid choice :");
            break;
        }
    } while (ch != 7);

    return 0;
}