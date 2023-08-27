#include "monty_header.h"

/**
 * f_pall - Display the elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Unused counter
 * Return: No return value
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *ptr;

	/*Suppress unused parameter warnings*/
	(void)counter;

	ptr = *head;

	if (ptr == NULL)
		return;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

