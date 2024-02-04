#include "monty.h"

/**
 * add_fxn - a funtion that adds the top two elements of the stack
 * @stack: head of the stack
 * @line_number: The line where the error occurred
 *
 * Return: Nothing
 */

void add_fxn(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	int sum_total;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;

	sum_total = top->n + top->next->n;
	top->next->n = sum_total;
	*stack = top->next;
	free(top);
}

/**
  * nop_fxn - a function that doesn’t do anything
  * @stack: head of the stack
  * @line_number: line where the error occurred
  *
  * Return: Nothing
  */
void nop_fxn(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * pop_fxn - Removes the top element of the stack
 * @stack: The head of the stack
 * @line_number: The line where the error occurred
 *
 * Return: Nothing
 */

void pop_fxn(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
