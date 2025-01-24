#include "monty.h"

int global_var = 0;

void usage_error(void)
{
    fprintf(stderr, "USAGE: monty file\n");
    exit(EXIT_FAILURE);
}

void file_open_error(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    exit(EXIT_FAILURE);
}

void malloc_error(void)
{
    fprintf(stderr, "Error: malloc failed\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 1024; /* Specify a reasonable buffer size */
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    char *opcode, *arg;

    if (argc != 2)
        usage_error();

    file = fopen(argv[1], "r");
    if (!file)
        file_open_error(argv[1]);

    line = malloc(len);
    if (!line)
        malloc_error();

    while (fgets(line, len, file) != NULL)
    {
        line_number++;
        opcode = strtok(line, " \n\t");
        if (opcode == NULL || opcode[0] == '#')
            continue;
        if (strcmp(opcode, "push") == 0)
        {
            arg = strtok(NULL, " \n\t");
            push(&stack, line_number, arg);
        }
        else
        {
            execute(opcode, &stack, line_number);
        }
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return (0);
}

