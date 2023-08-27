#include "monty_header.h"
/**
 * f_pop - Removes the top element from the stack.
 * @head: Pointer to the stack's head
 * @counter: Line number in the file
 * Return: No return value
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *ptr;

	/**Checks if the stack is empty*/
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	/*Move the stack's head to the next node*/
	*head = ptr->next;
	/*Free the previous top element*/
	free(ptr);
}
