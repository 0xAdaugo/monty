#include "monty_header.h"
/**
  *f_rotl - Rotates the stack to move the top element
  *to the end
  *@head: Pointer to the stack's head
  *@counter: Line number in the file (unused in this function)
  *Return: No return value.
 */
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	/*Pointers to traverse and manipulate the stack*/
	stack_t *tmpNode = *head, *newTop;

	/*If the stack is empty or has onlt one element, no rotation needed*/
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	/*Store the new top node after rotation*/
	newTop = (*head)->next;
	newTop->prev = NULL;

	/*Traverse to the end of the stack*/
	while (tmpNode->next != NULL)
	{
		tmpNode = tmpNode->next;
	}

	/*Rotate the stack elements to the left*/
	tmpNode->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmpNode;
	(*head) = newTop;
}
