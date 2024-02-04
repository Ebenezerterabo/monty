#include "monty.h"

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Always 0 Success
 */
glo_var *arg_s = NULL;

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	arg_s = malloc(sizeof(glo_var));
	if (arg_s == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* initializing Global variables */
	arg_s->buf = NULL;
	arg_s->line_num = 0;
	arg_s->file = NULL;
	arg_s->num_tokens = 0;
	arg_s->head = NULL;
	arg_s->stack_len = 0;

	arg_s->file = fopen(av[1], "r");
	if (arg_s->file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free(arg_s);
		exit(EXIT_FAILURE);
	}

	read_and_execute_file(arg_s->file);
	free_stack(&arg_s->head);
	fclose(arg_s->file);

	free(arg_s);
	return (0);
}
