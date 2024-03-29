#include "monty.h"

/**
 * push_stack - A function that pushes an element to the stack
 * of a doubly linked list.
 * @stack: pointer to the stack
 * @line_number: line number of each instruction
 *
 * Return: Nothing
 */

void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *top_new = *stack;
	(void)line_number;

	if (arg_s->num_tokens <= 1 || !(is_valid_integer(arg_s->tokens[1])))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(arg_s->buf);
		free_tokens();
		fclose(arg_s->file);
		free(arg_s);
		exit(EXIT_FAILURE);
	}
	top_new = malloc(sizeof(stack_t));
	if (top_new == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		free(arg_s->buf);
		free_tokens();
		fclose(arg_s->file);
		free(arg_s);
		exit(EXIT_FAILURE);
	}

	top_new->n = atoi(arg_s->tokens[1]);

	if (arg_s->head == NULL)
	{
		top_new->next = NULL;
		top_new->prev = NULL;
		arg_s->head = top_new;
	}
	else
	{
		top_new->next = arg_s->head;
		arg_s->head->prev = top_new;
		top_new->prev = NULL;
		arg_s->head = top_new;
	}
	arg_s->head = top_new;
	arg_s->stack_len += 1;
}

/**
 * pall_stack - A function that prints all the values on the stack,
 * starting from the top.
 * @stack: pointer to the stack;
 * @line_number: line number of each instruction
 *
 * Return: Nothing
 */

void pall_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = arg_s->head;
	(void)stack;
	(void)line_number;

	if (arg_s->head == NULL)
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint_stack - A function that print a value at the
 * current node
 * @stack: pointer to the stack;
 * @line_number: line number of each instruction
 *
 * Return: Nothing
 */

void pint_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	if (arg_s->head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", arg_s->head->n);
}

/**
 * pop_stack - Removes the top element of the stack
 * @stack: The head of the stack
 * @line_number: The line where the error occurred
 *
 * Return: Nothing
 */

void pop_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	(void)stack;

	if (arg_s->head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = arg_s->head;
	arg_s->head = top->next;

	if (arg_s->head)
		top->next->prev = NULL;

	free(top);
	arg_s->stack_len -= 1;
}

/**
 * swap_stack - A function that swaps the top two elements of the stack.
 * @stack: pointer to the stack
 * @line_number: line number of each instruction
 *
 * Return: Nothing
 */

void swap_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;
	(void)stack;

	if (arg_s->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(&arg_s->head);
		free_tokens();
		free(arg_s);
		fclose(arg_s->file);
		exit(EXIT_FAILURE);
	}

	temp1 = arg_s->head;
	temp2 = temp1->next;
	temp1->next = temp2->next;

	temp2->next = temp1;
	/*temp1->prev = temp2;*/
	/*temp1->prev = NULL;*/
	arg_s->head = temp2;
}
