#include "monty_header.h"

/**
 * f_rotr - Rotate the stack to move the top
 * elements to the bottom.
 * head: Pointer to the stack head
 * @counter: Unused line number counter
 * Return: No return value
 */

void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *current_node;

	current_node = *head;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	while (current_node->next)
	{
		current_node = current_node->next;
	}

	current_node->next = *head;
	current_node->prev->next = NULL;
	current_node->prev = NULL;
	(*head)->prev = current_node;
	(*head) = current_node;
}

