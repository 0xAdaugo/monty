#include "monty_header.h"
/**
 * f_swap - Swaps the positions of the top two elements in the stack.
 * @head: Pointer to the stack's head
 * @counter: Line number in the file.
 * Return: No return value
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *ptr;
	int length = 0, result;

	ptr = *head;

	/*Calculate the length of the stack*/
	while (ptr)
	{
		ptr = ptr->next;
		length++;
	}

	/*Check if there is at least two elements in the stack*/
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;

	/*Swap the values of the top two elements*/
	result = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = result;
}
