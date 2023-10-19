#include "monty.h"

void add(stack_t **stack, unsigned int line_no)
{
    if (*stack == NULL || (*stack)->prev == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_no);
        memo(*stack);
        exit(EXIT_FAILURE);
    }

    int sum = (*stack)->n + (*stack)->prev->n;
    stack_t *temp = *stack;
    *stack = (*stack)->next;
    (*stack)->n = sum;
    (*stack)->prev = NULL;
    free(temp);
}
