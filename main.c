#define _GNU_SOURCE
#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
    char content[1024];
    FILE *file;
    stack_t *stack = NULL;
    unsigned int line_no = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    bus.file = file;
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (fgets(content, sizeof(content), file) != NULL)
    {
        bus.content = content;
        line_no++;
        execute(content, &stack, line_no, file);
    }
    memo(stack);
    fclose(file);
    return 0;
}
