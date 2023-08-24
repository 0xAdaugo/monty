#ifndef MONTY_H
#define MONTY_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

/**
 * struct stack_s - A structure representing a doubly linked list 
 * for a stack (or queue).
 * @n: An integer value
 * @prev: Pointer to the previous element of the stack (or queue)
 * @next: Pointer to the next element of the stack (or queue)
 * Description: This structure defines a node in 
 * a doubly linked list.
 * It is used for implementing stacks, queues, LIFO, and FIFO 
 * in the Holberton project.
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct bus_s - A container for arguments, file, line content,
 * and flag
 * @arg: Value being carried
 * @file: A Pointer to the monty file
 * @content: Content of the line
 * @lifi: Flag indicating change between stack and queue
 * Description: This structure is used to transport various values and settings within the program.
 */

typedef struct bus_s
{
	int lifi;
	char *content;
	char *arg;
	File *file;
} bus_t;
extern bus_t bus;

/**
 * struct instruction_s - Structure to hold an opcode and 
 * its corresponding function.
 * @opcode: The opcode abbreviation.
 * @f: Pointer to the function that handles the opcode.
 * Description: This structure associates an opcode 
 * with its corresponding function,
 * used in the context of stack, queues, LIFO, and FIFO operation
 * in the Holberton project.
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char  *clean_line(char *content);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
void free_stack(stack_t *head);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
ssize_t getstdin(char **lineptr, int file);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
#endif
