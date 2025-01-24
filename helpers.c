#include "monty.h"

/**
	* free_stack - Frees a stack.
	* @stack: Pointer to the stack to be freed.
	*/
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

/**
	* execute - Executes the opcode.
	* @opcode: The opcode to be executed.
	* @stack: Double pointer to the stack.
	* @line_number: Line number of the instruction.
	*/
void execute(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
	{"pall", pall},
	{"pint", pint},
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

