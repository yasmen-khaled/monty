#include "monty.h"

void pop(stack_t **stack, unsigned int line_no)
{
    stack_t *temp;

    if (*stack == NULL)
    {
    fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
