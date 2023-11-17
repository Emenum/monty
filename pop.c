#include "monty.h"

/**
 * pop - removes the top element from the stack
 * @stack: pointer to the top of the stack
 * @line_number: line where the opcode is from in the
 * monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	/**
	 * LOGIC:
	 * make temp point to top of stack
	 * change *stack to point to the node below top node in the stack
	 * free the node at the top of the stack so that the node
	 * that *stack is pointing to is now the top of the stack
	 */
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);

	if (*stack != NULL)
		(*stack)->prev = NULL;
}
