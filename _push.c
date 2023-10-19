#include "monty.h"

/**
 *push - add node
 *@stack: pointer
 *@line_no: number
 */


void push(stack_t **stack, unsigned int line_no)
{
	char *endptr;
	long int n;

	if (bus.arg == NULL)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_no);
	fclose(bus.file);
	free(bus.content);
	memo(*stack);
	exit(EXIT_FAILURE);
}

	n = strtol(bus.arg, &endptr, 10);
	if (*endptr != '\0')
{
	fprintf(stderr, "L%d: usage: push integer\n", line_no);
	fclose(bus.file);
	free(bus.content);
	memo(*stack);
	exit(EXIT_FAILURE);
}

	if (bus.lifi == 0)
	_addnode(stack, (int)n);
	else
	_addqueue(stack, (int)n);
}
