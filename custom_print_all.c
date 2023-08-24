#include "monty_header.h"

/**
 * f_pall - Display the elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *current_node;

	current_node = *head;

	if (current_node == NULL)
		return;

	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

