#include "monty.h"



void pop(stack_t **stack, unsigned int line_no)
{
	stack_t *h;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
		fclose(bus.file);
		free(bus.content);
		freemem(*stack);
		exit(EXIT_FAILURE);
	}
	h = *stack;
	*stack = h->next;
	free(h);

}
