#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

/*****LIBRARIES*****/
#include <stdio.h>
#include <stdlib.h> /*malloc, free, atoi*/
#include <unistd.h> /*file handling*/
#include <fcntl.h> /*file handling flags*/
#include <string.h> /*strcmp*/
#include <ctype.h>
#include <sys/types.h>


/**
 * struct global_s - tracker structure that contains
 * neccessary info to traverse the monty file
 * @arg: value
 * @line: input line content
 * @file: pointer to the monty file
 *
 * Description: holds values throught the program
 */
typedef struct global_s
{
	char *arg;
	FILE *file;
	char *line;
} glob_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/*****GLOBAL VARIABLE*****/
extern glob_t glob;

/*****PROTOTYPES*****/
void execute_file(stack_t **stack);
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number);

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/*****HELPER FUNCTIONS*****/
stack_t *add_node(stack_t **stack,  const int n);
void free_stack(stack_t *stack);
int is_number(char *str);


#endif /* MAIN_H */
