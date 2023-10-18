#include "monty.h"

int execute(char *content, stack_t **stack, unsigned int line_no, FILE *file)
{
    instruction_t instructions[] = {
        {"push", push_function}, {"pall", pall_function}, {"pint", pint_function},
        {"pop", pop_function}, {"swap", swap_function}, {"add", add_function},
        {"nop", nop_function}, {NULL, NULL}
    };

    char *op = strtok(content, " \n\t");
    if (op && op[0] == '#')
        return 0;

    for (unsigned int i = 0; instructions[i].opcode; i++)
    {
        if (strcmp(op, instructions[i].opcode) == 0)
        {
            instructions[i].function(stack, line_no);
            return 0;
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_no, op);
    fclose(file);
    free(content);
    freemem(*stack);
    exit(EXIT_FAILURE);
}
