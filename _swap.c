#include "monty.h"

/**
 * swap - aps the top two elements of the stack.
 *@stack:pointer
 *@line_no: number
 *
 */

void swap(stack_t **stack, unsigned int line_no)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
	memo(*stack);
	exit(EXIT_FAILURE);
}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
