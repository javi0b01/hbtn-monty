#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct prepare_e - prepare for export
 * @token: Tokenized data
 * @line: buffer to getline
 * @source: file descriptor to open and close
 *
 * Description: data, buffer and file to export
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct prepare_e
{
	char *token;
	char *line;
	FILE *source;
} prepare_t;
/* global variable */
extern prepare_t ready;
/* prototypes */
void _freelist(stack_t *stack);
void _split(char *buffer, stack_t **stack, unsigned int line_number);
void _get_opcode(stack_t **stack, unsigned int line_number, char *name);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
int main(int argc, char **argv);
#endif /* MONTY_H */
