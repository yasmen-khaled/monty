#include "monty.h"

void push(stack_t **stack, unsigned int line_no)
{
  
    if (bus.arg == NULL || bus.arg[0] == '\0') {
        fprintf(stderr, "L%d: usage: push integer\n", line_no);
        fclose(bus.file);
        free(bus.content);
        freemem(*stack);
        exit(EXIT_FAILURE);
    }

 
    char *endptr;
    long int n = strtol(bus.arg, &endptr, 10);
    if (*endptr != '\0') {
        fprintf(stderr, "L%d: usage: push integer\n", line_no);
        fclose(bus.file);
        free(bus.content);
        freemem(*stack);
        exit(EXIT_FAILURE);
    }

  
    addnode(stack, (int)n);
}

