#include "monty.h"

void pall(stack_t **stack, unsigned int line_no)
{
	stack_t *h;
	(void)line_no;

	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
