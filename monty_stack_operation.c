#include "monty_header.h"
/**
 * f_stack - Sets the stack mode.
 * @head: Pointer to the stack's head
 * @counter: Line counter in the file.
 * Return: No return value
*/
void f_stack(stack_t **head, unsigned int counter)
{
	/*Suppress unused parameter warnings*/
	(void)head;
	(void)counter;

	/*Set bus.lifi to 0 to enable stack mode*/
	bus.lifi = 0;
}
