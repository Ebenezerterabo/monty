#ifndef MAIN_H
#define MAIN_H

#define DELIM " \t\n\r"
/** Standard Libraries **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queue, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_var_s - A structure that keeps all global variable
 * in the program
 * @file: Name of file
 * @buf: Temporal container
 * @line_num: line number
 * @tokens: array of string
 * @num_tokens: number of tokens
 *
 * Description: global variable arguments used in our program
 */

typedef struct global_var_s
{
	FILE *file;
	unsigned int line_num;
	char *buf;
	char **tokens;
	int num_tokens;
} glo_var;

extern glo_var *arg_s;

/** Function Prototypes **/
void read_and_execute_file(FILE *filename);
void tokenize_buf(void);
void free_tokens(void);
#endif
