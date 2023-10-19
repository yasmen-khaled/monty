#include "monty.h"
stack_t *current = *stack;

void pall(stack_t **stack, unsigned int line_no)
{
    (void)line_no;

    

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

