#include "monty_header.h"

/**
 * f_pstr - Print the string represented by stack values.
 * @head: Pointer to the stack head
 * @counter: Unused line number counter
 * Return: No return value
 */

void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *current_node;

	current_node = *head;

	while (current_node)
	{
		if (current_node->n > 127 || current_node->n <= 0)
		{
			break;
		}
		printf("%c", current_node->n);
		current_node = current_node->next;
	}
	printf("\n");
}

