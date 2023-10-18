#include "monty.h"

void addnode(stack_t **stack, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory for new node\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
    {
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}


void freememo(stack_t *stack)
{
    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }
}



void queue(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
	bus.lifi = 1;
}



void addqueue(stack_t **stack, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory for new node\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*stack == NULL)
    {
        *stack = new_node;
    }
    else
    {
        stack_t *last_node = *stack;
        while (last_node->next != NULL)
        {
            last_node = last_node->next;
        }
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}


void starck(stack_t **stack, unsigned int line_no)
{
	(void)stack;
	(void)line_no;
	bus.lifi = 0;
}

