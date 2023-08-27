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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	ptr = *head;

	/* Check if the divisor is zero */
	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Calculate the remainder and update the stack */
	result = ptr->next->n % ptr->n;
	ptr->next->n = result;
	*head = ptr->next;
	free(ptr);
}

