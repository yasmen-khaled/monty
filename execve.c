#include "monty.h"

#define _GUN_SOURCE

int execute(char *content, stack_t **stack, unsigned int line_no, FILE *file)
{
    instruction_t *opst = get_instructions();

    char *op = strtok(content, " \n\t");
    if (op && op[0] == '#')
        return 0;

    bus.arg = strtok(NULL, " \n\t");

    instruction_t *current = opst;
    while (current != NULL)
    {
        if (strcmp(op, current->opcode) == 0)
        {
            current->f(stack, line_no);
            return 0;
        }
        current = current->next;
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_no, op);
    fclose(file);
    free(content);
    memo(*stack);
    exit(EXIT_FAILURE);
}
