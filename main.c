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
	size_t len = 32;
	ssize_t read;
	stack_t *stack;
	unsigned int line_number;

	stack = NULL;
	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	ready.file = fopen(argv[1], "r");
	if (!ready.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&ready.buffer, &len, ready.file)) != EOF)
	{
		line_number++;
		split(ready.buffer, &stack, line_number);
	}
	freedom(stack);
	exit (EXIT_SUCCESS);
}
