#include "monty.h"

/**
	* push - Pushes an element to the stack.
	* @stack: Double pointer to the stack.
	* @line_number: Line number of the instruction.
	* @arg: Argument to be pushed.
	*/
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	stack_t *new_node;
	int num;

	if (!arg || sscanf(arg, "%d", &num) != 1)
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	malloc_error();

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
	(*stack)->prev = new_node;
	*stack = new_node;
}

/**
	* pall - Prints all the values on the stack.
	* @stack: Double pointer to the stack.
	* @line_number: Line number of the instruction.
	*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp)
	{
	printf("%d\n", temp->n);
	temp = temp->next;
	}
}

/**
	* pint - Prints the value at the top of the stack.
	* @stack: Double pointer to the stack.
	* @line_number: Line number of the instruction.
	*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

