#include "monty.h"

/**
 * nop - does nothing
 * @stack: pointer to the top of the stack
 * @line_number: line number from monty file where
 * opcode is from
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
