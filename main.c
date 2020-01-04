#include "monty.h"
prepare_t ready = {NULL, NULL, NULL};
/**
 * main - Entry point
 * @argc: lenght of arguments pass to prepare_e
 * @argv: arguments used by prepare_e
 * Return: Always
 */
int main(int argc, char **argv)
{
	size_t length = 32;
	ssize_t read;
	stack_t *stack;
	unsigned int line_number;

	stack = NULL;
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ready.file = fopen(argv[1], "r");
	if (!ready.file)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&ready.buffer, &length, ready.file)) != EOF)
	{
		line_number++;
		split(ready.buffer, &stack, line_number);
	}
	freedom(stack);
	exit(EXIT_SUCCESS);
	return  (0);
}
