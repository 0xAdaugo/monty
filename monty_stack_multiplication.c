#include "monty_header.h"

/**
 * f_mul - This multiplies the top two
 * elements of the stack.
 * @head: Pointer to the stack's head.
 * @counter: Line numbber in the file.
 * *Return: No return value.
 */

void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	int length = 0, result;

	ptr = *head;
	while (ptr)
	{
		ptr = ptr->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	ptr = *head;
	result = ptr->next->n * ptr->n;
	ptr->next->n = result;
	*head = ptr->next;
	free(ptr);
}
