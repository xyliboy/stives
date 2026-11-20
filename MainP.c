#include <stdio.h>
#include <stdlib.h>
#include "MyStacks.h"

int main(void)
{
    Stack1 arrayStack;
    Stack2 listStack;
    int value;

    if (!S1Init(&arrayStack, 3))
    {
        fprintf(stderr, "Αποτυχία αρχικοποίησης της στοίβας με πίνακα.\n");
        return EXIT_FAILURE;
    }

    for (value = 10; value <= 30; value += 10)
        S1Push(&arrayStack, value);

    if (!S1Push(&arrayStack, 40))
        puts("Ο πίνακας γέμισε.");

    puts("Στοίβα με πίνακα");
    while (S1Pop(&arrayStack, &value))
        printf("%d\n", value);
    free(arrayStack.items);

    S2Init(&listStack);
    for (value = 10; value <= 40; value += 10)
    {
        if (!S2Push(&listStack, value))
        {
            fprintf(stderr, "Αποτυχία εισαγωγής στη στοίβα με λίστα.\n");
            while (S2Pop(&listStack, &value))
            {
            }
            return EXIT_FAILURE;
        }
    }

    puts("Στοίβα με λίστα");
    while (S2Pop(&listStack, &value))
        printf("%d\n", value);

    return EXIT_SUCCESS;
}
