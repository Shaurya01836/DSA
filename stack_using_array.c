#include <stdio.h>
#include <stdbool.h>

#define MAX 5

struct Stack {
    int top;
    int arr[MAX];
};

// Initialize the stack
void initStack(struct Stack *s) {
    s->top = -1;
    for (int i = 0; i < MAX; i++) {
        s->arr[i] = 0;
    }
}

// Check if the stack is empty
bool isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Check if the stack is full
bool isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Push an element onto the stack
void push(struct Stack *s, int val) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        s->top++;
        s->arr[s->top] = val;
    }
}

int main() {
    struct Stack s1;
    initStack(&s1);

    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    push(&s1, 4);
    push(&s1, 5);

    printf("%d\n", s1.arr[2]); // Output should be 3
    return 0;
}
