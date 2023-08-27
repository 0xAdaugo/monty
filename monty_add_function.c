#include "monty_header.h"

/**
 * f_add - Add the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */

void f_add(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	int length = 0, result;

	ptr = *head;

	/* Calculate the length of the stack */
	while (ptr)
	{
		ptr = ptr->next;
		length++;
	}

	/* Check if there are at least two elements in the stack */
	if (length < 2)
	{
		fprintf(stderr, "L%d:  can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	ptr = *head;

	/* Perform addition and update the stack */
	result = ptr->n + ptr->next->n;
	ptr->next->n = result;
	*head = ptr->next;
	free(ptr);
}

