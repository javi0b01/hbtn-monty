#include "monty.h"
/**
 * _freelist - function that free a list.
 * @stack: doubly linked list.
 * Return: nothing.
 */
void _freelist(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	fclose(ready.source);
	free(ready.line);
}
/**
 * _split - function that generates tokens
 * @line: buffer that keeps lines
 * @stack: Doubly linked list
 * @line_number: Counter of lines in the source file
 * Return: nothing
 */
void _split(char *line, stack_t **stack, unsigned int line_number)
{
	char *content;
	char *token;

	content = strtok(line, " \n\t");
	token = strtok(NULL, " \n\t");
	ready.token = token;
	if (content && content[0] != '#')
	{
		_get_opcode(stack, line_number, content);
	}
}
/**
 * _get_opcode - funtion to select the opcode to be used.
 * @stack: doubly linked list.
 * @line_number: number of line.
 * @content: opcode to find.
 * Return: EXIT_FAILURE if fail.
 */
void _get_opcode(stack_t **stack, unsigned int line_number, char *content)
{
	int i;

	instruction_t select[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	i = 0;
	while (select[i].opcode)
	{
		if (strcmp(select[i].opcode, content) == 0)
		{
			select[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (!select[i].opcode)
	{
		dprintf(2, "L%u: unknown instruction %s\n", line_number, content);
		_freelist(*stack);
		exit(EXIT_FAILURE);
	}
}
