#include "monty_header.h"

/* Declaration of program context */
program_context_t program_context = {NULL, NULL, NULL, 0};

/**
 * main - Custom Monty code interpreter
 * @argc: Number of command-line arguments
 * @argv: array of command-line arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *line_content;
	FILE *input_file;
	size_t line_size = 0;
	ssize_t read_line = 1;
	custom_stack_node_t *stack = NULL;
	unsigned int line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: custom_monty file\n");
		exit(EXIT_FAILURE);
	}
	input_file = fopen(argv[1], "r");
	program_context.input_file = input_file;
	if (!input_file)
	{
		fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line_content = NULL;
		read_line = getline(&line_content, &line_size, input_file);
		program_context.line_content = line_content;
		line_counter++;
		if (read_line > 0)
		{
			execute_operation(line_content, &stack, line_counter, input_file);
		}
		free(line_content);
	}
	free_custom_stack(stack);
	fclose(input_file);
	return (0);
}

