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
