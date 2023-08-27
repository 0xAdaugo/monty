#include "monty_header.h"
/**
 * f_div - performs division on the top two elements of the stack.
 * @head: pointer to stack head
 * @counter: line number
 * Return: no return value
 */
void f_div(stack_t **head, unsigned int counter)
{
	/*bus_t bus = {NULL, NULL, NULL, 0};*/
	stack_t *ptr;
	int length = 0, result;

	ptr = *head;

	/* calculate the length of the head */
	while (ptr)
	{
		ptr = ptr->next;
		length++;
	}

	/* check if there are atleast two elements in the stack */
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	ptr = *head;

	/* check if divisor is zero */
	if (ptr->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/* perform the division and update the head */
	result = ptr->next->n / ptr->n;
	ptr->next->n = result;
	*head = ptr->next;
	free(ptr);
}

