#include "monty.h"

/**
 * tokenize_buf - A function that tokenize the buffer passed to it by the
 * getline function.
 *
 * Return: Nothing
 */

void tokenize_buf(void)
{
	int i = 0;
	char *buf = NULL, *token = NULL;

	buf = malloc(sizeof(char) * strlen(arg_s->buf) + 1);
	if (buf == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(buf, arg_s->buf);
	arg_s->num_tokens = 0;
	token = strtok(buf, DELIM);

	while (token)
	{
		arg_s->num_tokens += 1;
		token = strtok(NULL, DELIM);
	}

	arg_s->tokens = malloc(sizeof(char *) * (arg_s->num_tokens + 1));
	strcpy(buf, arg_s->buf);
	token = strtok(buf, DELIM);

	while (token)
	{
		arg_s->tokens[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (arg_s->tokens[i] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(arg_s->tokens[i], token);
		token = strtok(NULL, DELIM);
		i++;
	}
	arg_s->tokens[i] = NULL;
	free(buf);
}
/**
 * read_and_execute_file - Reads and executes monty bytecocde instructions
 * from a file.
 * @filename: the name of the file.
 *
 * Return: Nothing
 */

void read_and_execute_file(FILE *filename)
{
	size_t len = 0;

	while (getline(&arg_s->buf, &len, filename) != -1)
	{
		arg_s->line_num++;
		if (arg_s->buf == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_tokens();
			fclose(arg_s->file);
			free(arg_s);
			exit(EXIT_FAILURE);
		}

		tokenize_buf();
		execute_instruction();
		free_tokens();

	}
	fclose(arg_s->file);

	/*free(arg_s->buf);*/
	free(arg_s);
}

/**
 * free_tokens - A function that frees tokens in the buffer
 *
 * Return: Nothing
 */

void free_tokens(void)
{
	int i = 0;

	if (arg_s->tokens == NULL)
		return;

	while (i < arg_s->num_tokens)
	{
		free(arg_s->tokens[i]);
		i++;
	}
	free(arg_s->tokens);
	arg_s->tokens = NULL;

}


/**
 * execute_instruction - A function that executes the opcode instruction
 * base on the array of instructions.
 *
 * Return: Nothing
 */

void execute_instruction(void)
{
	stack_t *stack = NULL;

	int i = 0;
	instruction_t instructions[] = {
		{"push", push_stack},
		{"pall", pall_stack},
		{"pint", pint_stack},
		{"pop", pop_stack},
		{"swap", swap_stack},
		{"add", add_stack},
		{"nop", nop_stack},
		{NULL, NULL}
	};

	if (arg_s->num_tokens == 0)
		return;

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, arg_s->tokens[0]) == 0)
		{
			instructions[i].f(&stack, arg_s->line_num);
			return;
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", arg_s->line_num,
		arg_s->tokens[0]);
	fclose(arg_s->file);
	free(arg_s);
	exit(EXIT_FAILURE);
}

/**
 * is_valid_integer - A function that checks a string to see
 * if it's a valid integer
 * @str: string
 *
 * Return: Always 1 on Success, otherwise 0.
 */

int is_valid_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '+' || *str == '-')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
