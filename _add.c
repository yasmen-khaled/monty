#include "monty.h"

void add(stack_t **stack, unsigned int line_no)
{
    int sum;

    if (*stack == NULL || (*stack)->prev == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
        memo(*stack);
        exit(EXIT_FAILURE);
    }

    sum = (*stack)->n + (*stack)->prev->n;
    *stack = (*stack)->next;
    (*stack)->n = sum;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
