#include "monty_header.h"
/**
 * f_pint - Prints the top integar of the stack.
 * @head: Pointer to the stack's head.
 * @counter: Line number in the file.
 * Return: No return Value.
*/
void f_pint(stack_t **head, unsigned int counter)
{
	/* checks if the stack is empty */
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* Prints the top integer of the stack*/
	printf("%d\n", (*head)->n);
}
