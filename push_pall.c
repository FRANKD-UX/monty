#include "monty.h"

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

