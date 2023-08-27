#include "monty_header.h"
/**
 * f_queue - Switches to queue mode (FIFO).
 * @head: Pointer to the stack's head.
 * @counter: Line number in the file.
 * Return: No return value
*/
void f_queue(stack_t **head, unsigned int counter)
{
	/*Suppress unused parameter warnings*/
	(void)head;
	(void)counter;

	/*Set bus.lifi to 1 to enable queue mode*/
	bus.lifi = 1;
}

/**
 * addqueue - Adds a new node to the tail of the stack/
 * @head: Pointer t the head of the stack.
 * @n: The value to be store in the new node.
 * Return: No return value.
*/
void addqueue(stack_t **head, int n)
{
	stack_t *newNode, *currentNode;

	currentNode = *head;
	newNode = malloc(sizeof(stack_t));

	/*Check for memory allocation error*/
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = n;
	newNode->next = NULL;

	/*If stack is not empty, traverse to the end*/
	if (currentNode)
	{
		while (currentNode->next)
			currentNode = currentNode->next;
	}

	/*if the stack isempty, update the stack's head*/
	if (!currentNode)
	{
		*head = newNode;
		newNode->prev = NULL;
	}
	/*Otherwise, add the new node to the end of the stack*/
	else
	{
		currentNode->next = newNode;
		newNode->prev = currentNode;
	}
}
