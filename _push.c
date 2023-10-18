#include "monty.h"

int is_valid_integer(const char *str);

void push(stack_t **stack, unsigned int line_no)
{
    if (bus.arg == NULL || !is_valid_integer(bus.arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_no);
        exit(EXIT_FAILURE);
    }

    int n = atoi(bus.arg);
    if (bus.lifi == 0)
        addnode(stack, n);
    else
        addqueue(stack, n);
}

int is_valid_integer(const char *str)
{
    if (str == NULL || *str == '\0')
        return 0;

    int i = 0;
    if (str[i] == '-')
        i++;

    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }

    return 1;
}
