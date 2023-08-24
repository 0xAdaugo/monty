#include "monty_header.h"

/**
 * f_mod - Calculate the remainder of division between the
 * second and top elements of the custom stack
 * @head: Pointer to the stack's head
 * @counter: Line number of the operation
 * Return: No return value
 */

void f_mod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: insufficient elements for mod computation\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current_node = *head;

	/* Check if the divisor is zero */
	if (current_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Calculate the remainder and update the stack */
	result = current_node->next->n % current_node->n;
	current_node->next->n = result;
	*head = current_node->next;
	free(current_node);
}

