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
	int i, j, number;

	if (ready.token)
	{
		for (i = 0; ready.token[i] != '\0'; i++)
		{
			if (ready.token[i] > 47 && ready.token[i] < 58)
				j = 0;
			else
				j = 1;
		}
		if (j == 0)
			number = atoi(ready.token);
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			_freelist(*stack), exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "Error: L%u: usage: push integer\n", line_number);
		_freelist(*stack), exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		_freelist(new), _freelist(*stack), exit(EXIT_FAILURE);
	}
	else
	{
		new->n = number;
		new->prev = NULL;
		new->next = *stack;
	}
	if (*stack != NULL)
		(*stack)->prev = new;
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
