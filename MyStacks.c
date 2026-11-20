#include <stdint.h>
#include <stdlib.h>
#include "MyStacks.h"

struct Node
{
    int value;
    Node *next;
};

int S1Init(Stack1 *stack, int capacity)
{
    stack->items = NULL;
    stack->capacity = 0;
    stack->count = 0;

    if (capacity <= 0 || (uintmax_t)capacity > SIZE_MAX / sizeof(int))
        return 0;

    stack->items = malloc((size_t)capacity * sizeof(int));
    if (stack->items == NULL)
        return 0;

    stack->capacity = capacity;
    return 1;
}

int S1Push(Stack1 *stack, int value)
{
    if (stack->count == stack->capacity)
        return 0;

    stack->items[stack->count] = value;
    stack->count++;
    return 1;
}

int S1Pop(Stack1 *stack, int *value)
{
    if (stack->count == 0)
        return 0;

    stack->count--;
    *value = stack->items[stack->count];
    return 1;
}

void S2Init(Stack2 *stack)
{
    stack->top = NULL;
}

int S2Push(Stack2 *stack, int value)
{
    Node *node = malloc(sizeof *node);
    if (node == NULL)
        return 0;

    node->value = value;
    node->next = stack->top;
    stack->top = node;
    return 1;
}

int S2Pop(Stack2 *stack, int *value)
{
    Node *node = stack->top;
    if (node == NULL)
        return 0;

    *value = node->value;
    stack->top = node->next;
    free(node);
    return 1;
}
