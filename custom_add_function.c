#include "monty_header.h"

/**
 * f_add - Add the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */

void f_add(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	int stack_length = 0, result;

	current_node = *head;

	/* Calculate the length of the stack */
	while (current_node)
	{
		current_node = current_node->next;
		stack_length++;
	}

	/* Check if there are at least two elements in the stack */
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: insufficient elements to perform addition\n", line_counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current_node = *head;

	/* Perform addition and update the stack */
	result = current_node->n + current_node->next->n;
	current_node->next->n = result;
	*head = current_node->next;
	free(current_node);
}

