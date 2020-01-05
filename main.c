#include "monty.h"
prepare_t ready = {NULL, NULL, NULL};
/**
 * main - Entry point
 * @argc: lenght of arguments
 * @argv: arguments
 * Return: Always
 */
int main(int argc, char **argv)
{
	stack_t *stack;
	unsigned int line_number;
	ssize_t obtained;
	size_t length;

	stack = NULL;
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ready.source = fopen(argv[1], "r");
	if (!ready.source)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((obtained = getline(&ready.line, &length, ready.source)) != EOF)
	{
		line_number++;
		_split(ready.line, &stack, line_number);
	}
	_freelist(stack);
	exit(EXIT_SUCCESS);
	return  (0);
}
