#include "monty.h"


void swap(stack_t **stack, unsigned int line_no)
{
	stack_t *h = *stack;
	int len = 0;

	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_no);
		memo(*stack);
		exit(EXIT_FAILURE);
	}
	if (*stack)
	{
		stack_t *tmp;

		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		(tmp->next)->prev = *stack;
		tmp->next = *stack;
		(*stack)->prev = tmp;
		tmp->prev = NULL;
		*stack = tmp;
	}
}
