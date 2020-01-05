#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @stack: head of the stack
 * @line_number: where the opcode is located
 * Return: nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		(*stack)->next->n = (*stack)->next->n + (*stack)->n;
		_pop(stack, line_number);
	}
	else
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		_freelist(*stack);
		exit(EXIT_FAILURE);
	}
}
/**
 * _nop - doesn’t do anything.
 * @stack: head of the stack
 * @line_number: where the opcode is located
 * Return: nothing
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void) line_number;
}
