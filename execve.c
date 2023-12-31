#include "monty.h"

#define _GUN_SOURCE

int execute(char *content, stack_t **stack, unsigned int line_no, FILE *file)
{
    unsigned int i;
    instruction_t opst[] = {
        {"push", push}, {"pall", pall}, {"pint", pint},
        {"pop", pop}, {"swap", swap}, {"add", add},
        {"nop", nop}, {NULL, NULL}
    };

    char *op = strtok(content, " \n\t");
    if (op && op[0] == '#')
        return 0;

    bus.arg = strtok(NULL, " \n\t");

    for (i = 0; opst[i].opcode != NULL; i++)
    {
        if (strcmp(op, opst[i].opcode) == 0)
        {
            opst[i].f(stack, line_no);
            return 0;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_no, op);
    fclose(file);
    free(content);
    memo(*stack);
    exit(EXIT_FAILURE);
}
