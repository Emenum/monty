#include "monty.h"

/**
 * pall - prints all the values of the stack from
 * the top to the bottom
 * @stack: pointer to the top of the stack
 * @line_number: line number of the opcode in the monty file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		(void)line_number; /*to avoid compiler warning from unused variable*/
	}
}
