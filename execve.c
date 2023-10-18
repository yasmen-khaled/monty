#include "monty.h"

  int execute(char *content, stack_t **stack, unsigned int line_no, FILE *file) {
    char *op = strtok(content, " \n\t");
    if (op && op[0] == '#')
        return 0;

    char *arg = strtok(NULL, " \n\t");
    if (strcmp(op, "push") == 0) {
        if (arg) {
            int value = atoi(arg);
            push(stack, value, line_no);
        } else {
            fprintf(stderr, "L%d: missing argument for push\n", line_no);
            fclose(file);
            free(content);
            freemem(*stack);
            exit(EXIT_FAILURE);
        }
    } else if (strcmp(op, "pall") == 0) {
        pall(stack, line_no);
    } else if (strcmp(op, "pint") == 0) {
        pint(stack, line_no);
    } else {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_no, op);
        fclose(file);
        free(content);
        freemem(*stack);
        exit(EXIT_FAILURE);
    }
    return 0;
}

