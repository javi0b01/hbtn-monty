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
 * struct prepare_e - take the data, buffer and file to export
 * @data: Tokenized data
 * @buffer: buffer to getline
 * @file: file descriptor to open and close
 *
 * Description: data, buffer and file to export
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct prepare_e
{
	char *data;
	char *buffer;
	FILE *file;
} prepare_t;
/* global variable */
extern prepare_t ready;
/* prototypes */
void _get_opcode(stack_t **stack, unsigned int line_number, char *name);
void _freedom(stack_t *stack);
void _split(char *buffer, stack_t **stack, unsigned int line_number);
int _isdigit(int c);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
#endif /* MONTY_H */
