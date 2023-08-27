#include "monty_header.h"

/**
 * free_stack - Frees memory occupied by
 * a doubly linked list
 * @head: Head of the stack
 */

void free_stack(stack_t *head)
{
	stack_t *currentNode;

	currentNode = head;
	while (head)
	{
		currentNode = head->next;
		free(head);
		head = currentNode;
	}
}
