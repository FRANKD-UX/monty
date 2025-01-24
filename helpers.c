#include "monty.h"

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
	temp = stack;
	stack = stack->next;
	free(temp);
	}
}

void execute(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
	{"pall", pall},
	{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].opcode)
	{
	if (strcmp(opcode, instructions[i].opcode) == 0)
	{
	instructions[i].f(stack, line_number);
	return;
	}
	i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

