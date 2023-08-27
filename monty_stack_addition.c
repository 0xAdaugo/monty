#include "monty_header.h"

/**
 * addnode - Add a new node to the stack's
 * @head: Pointer to the head of the
 * @n: The value to be stored in the new
 * Return: No return
 */

void addnode(stack_t **head, int n)
{
	stack_t *newNode, *currentNode;

	currentNode = *head;
	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	if (currentNode)
		currentNode->prev = newNode;

	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
}

