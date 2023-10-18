#include "monty.h"

void pint(stack_t **stack, unsigned int line_no)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

