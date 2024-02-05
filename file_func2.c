#include "monty.h"
/**
 * free_stack - A function that frees the stack
 * @head: pointer to the head node
 *
 * Return: Nothing
 */

void free_stack(stack_t **head)
{
	stack_t *current = *head;
	stack_t *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}

	/**head = NULL;*/
}

/**
 * add_stack - A function that adds the top two elements
 * of the stack.
 * @stack: pointer to the stack
 * @line_number: line number of the instruction to execute
 *
 * Return: Nothing
 */

void add_stack(stack_t **stack, unsigned int line_number)
{
	int temp1, temp2, result;
	(void)stack;

	if (arg_s->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(&arg_s->head);
		free_tokens();
		fclose(arg_s->file);
		free(arg_s);
		exit(EXIT_FAILURE);
	}

	temp1 = arg_s->head->n;
	temp2 = arg_s->head->next->n;

	result = temp1 + temp2;
	arg_s->head->next->n = result;
	pop_stack(&arg_s->head, line_number);
}

/**
 * nop_stack - A function that does nothing
 * @stack: pointer to the stack
 * @line_number: line numbers of instructions read
 *
 * Return: Nothing
 */

void nop_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
