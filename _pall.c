#include "monty.h"

void pall(stack_t **stack, unsigned int line_no)
{
    stack_t *current;

    (void)line_no;

    current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
