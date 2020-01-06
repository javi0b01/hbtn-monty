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
			dprintf(2, "L%u: usage: push integer\n", line_number);
			_freelist(*stack);
			exit(EXIT_FAILURE);
		}
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		_freelist(new);
		_freelist(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		new->n = number;
		new->prev = NULL;
		new->next = *stack;
		if (*stack != NULL)
		{
			(*stack)->prev = new;
		}
		*stack = new;
	}
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
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 * @stack: head of the stack
 * @line_number: where the opcode is located
 * Return: nothing
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		_freelist(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pop - removes the top element of the stack.
 * @stack: head of the stack
 * @line_number: where the opcode is located
 * Return: nothing
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
		if (*stack)
		{
			(*stack)->prev = NULL;
		}
	}
	else
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		_freelist(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * _swap - swaps the top two elements of the stack.
 * @stack: head of the stack
 * @line_number: where the opcode is located
 * Return: nothing
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		_freelist(*stack);
		exit(EXIT_FAILURE);
	}
}
