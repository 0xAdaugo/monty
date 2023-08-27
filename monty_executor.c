#include "monty_header.h"

/**
 * Execute - Executes the specified opcode
 * @opcode: The opcode to execute
 * @stack: Pointer to the stack
 * @counter: The Line counter
 * @file: Pointer to the Monty file
 * @content: Line content
 * Return: 0 if successful, 1 if an error occurred
 */

int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opcodes[] = {
		{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
		{"div", f_div},
		{"add", f_add},
		{"mod", f_mod},
		{"pstr", f_pstr},
		{"pchar", f_pchar},
		{"mul", f_mul},
		{"pop", f_pop},
		{"nop", f_nop},
		{"rotr", f_rotr},
		{"rotl", f_rotl},
		{"sub", f_sub},
		{"stack", f_stack},
		{"swap", f_swap},
		{"queue", f_queue},
		{NULL, NULL}
	};
	unsigned int a = 0;
	char *op;
	op = strtok(content, " \n\t");

	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opcodes[a].opcode && op)
	{
		if (strcmp(op, opcodes[a].opcode) == 0)
		{
			opcodes[a].f(stack, counter);
			return (0);
		}
		a++;
	}
	if (op && opcodes[a].opcode == NULL)
	{		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
free_stack(*stack);
		exit(EXIT_FAILURE);	}
	return (1);
}
