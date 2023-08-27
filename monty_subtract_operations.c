#include "monty_header.h"
/**
  *f_sub - Subtracts the top element from the second element.
  *@head: Pointer to the stack's head
  *@counter: Line number in the file.
  *Return: No return value
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;
	int sub, numNodes;

	/*Temporary pointer for traversing the stack*/
	currentNode = *head;

	/*Count the number of nodes in the stack*/
	for (numNodes = 0; currentNode != NULL; numNodes++)
		currentNode = currentNode->next;

	/*If the stack has less than 2 elements, cannot perform subtraction*/
	if (numNodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	/*Perform the subtraction on the top two elements of the stack*/
	currentNode = *head;
	sub = currentNode->next->n - currentNode->n;
	currentNode->next->n = sub;
	*head = currentNode->next;
	free(currentNode);
}
