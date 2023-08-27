#include "monty_header.h"
/**
 * f_push - Pushes an integar unto the stack or queue.
 * @head: Poointer to the stack's head
 * @counter: Line numbe in the file.
 *
 * Return: No return value.
*/

void f_push(stack_t **head, unsigned int counter)
{
	int n, b = 0, invalidCharFlag = 0;

	/**Check if there is an argument provided*/
	if (bus.arg)
	{
		/**Handle negative values*/
		if (bus.arg[0] == '-')
			b++;

		/**Check if argument contains valid digits*/
		for (; bus.arg[b] != '\0'; b++)
		{
			if (bus.arg[b] > '9' || bus.arg[b] < '0')
				invalidCharFlag = 1;
		}
		/*Handle invalid argument format*/
		if (invalidCharFlag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*Handle missing argument*/
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/*convert the argument to an integer*/
	n = atoi(bus.arg);
	/**Decide if to add to the stack or queue based on bus.lifi value*/
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
