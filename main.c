#include "monty_header.h"
bus_t bus = {0, NULL, NULL, NULL};
/**
 * main - Monty code interpreter entry point
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;
	/*Check for correct number of command-line arguments*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*Open the Monty file*/
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/*Read and process each line of the Monty file*/
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;
		/*Execute the content of the line if read successfully*/
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		/*Free the allocated content memory*/
		free(content);
	}
	/*Clean up and close the file*/
	free_stack(stack);
	fclose(file);
	return (0);
}

