#ifndef MY_STACKS_H
#define MY_STACKS_H

typedef struct
{
    int *items;
    int capacity;
    int count;
} Stack1;

typedef struct Node Node;

typedef struct
{
    Node *top;
} Stack2;

/* Functions returning int give 1 on success and 0 on failure. */
int S1Init(Stack1 *stack, int capacity);
int S1Push(Stack1 *stack, int value);
int S1Pop(Stack1 *stack, int *value);

void S2Init(Stack2 *stack);
int S2Push(Stack2 *stack, int value);
int S2Pop(Stack2 *stack, int *value);

#endif
