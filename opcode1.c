#include "monty.h"
/**
 * _push - opcode that pushes an element to the stack
 * @stack: head of the stack
 * @line_number: where the opcode is located
 * Return: nothing
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (_isdigit(line_number) == 1)
	{
		fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(new);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		new->n = line_number;
		new->prev = NULL;
		new->next = *stack;
	}
	if (*stack != NULL)
	{
		(*stack)->prev = new;
	}
	*stack = new;
}
/**
 * _pall - opcode that print all stack
 * @stack: head of the stack
 * @line_number: where the opcode is located
 * Return: nothing
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	if (*stack == NULL)
	{
		return;
	}
	if (stack == NULL)
	{
		return;
	}
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
