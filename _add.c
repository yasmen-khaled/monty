#include "monty.h"

void add(stack_t **stack, unsigned int line_no)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
        exit(EXIT_FAILURE);
    }

    stack_t *temp = *stack;
    int sum = temp->n + temp->next->n;

    *stack = temp->next;
    (*stack)->n = sum;

    free(temp);
}
