#include "monty_header.h"

/**
 * f_pstr - Print the string represented by stack values.
 * @head: Pointer to the stack head
 * @counter: Unused line number counter
 * Return: No return value
 */

void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *ptr;

	/*Suppress unused parameter warnings*/
	(void)counter;

	ptr = *head;

	while (ptr)
	{
		if (ptr->n > 127 || ptr->n <= 0)
		{
			break;
		}
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	printf("\n");
}

