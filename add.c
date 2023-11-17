#include "monty.h"

/**
 * add - takes the value of the top node and adds it to
 * the value of the node below it
 * it then pops the node at the top
 * @stack: pointer to the top of the stack
 * @line_number: line number in the monty file where the
 * opcode is from
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
