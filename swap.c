#include "monty.h"

void print_err(const int line_number);

/**
 * swap - swaps the values of the 2 top nodes in the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number in the monty file where the opcode
 * is from
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		print_err(line_number);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	/**
	 * LOGIC:
	 * temp to point to the top node in stack
	 * stack to point to the node after the top node
	 * then update the pointer:
	 * stack next to point to temp next
	 */
	temp = *stack;
	*stack = temp->next;

	if ((*stack)->next != NULL) /*More than 2 elements in the stack*/
	{
		temp2 = (*stack)->next;
		temp2->prev = temp;
		(*stack)->next = temp;
		(*stack)->prev = NULL;
		temp->next = temp2;
		temp->prev = *stack;
		temp2 = NULL;
		free(temp2);
	}
	else if ((*stack)->next == NULL) /*Only 2 elements in the stack*/
	{
		(*stack)->prev = NULL;
		(*stack)->next = temp;
		temp->next = NULL;
		temp->prev = *stack;
	}
}

/**
 * print_err - prints error message
 * function used only in this file to avoid line length over 80chars!
 * @line_number: line number where the opcode gives error
 */
void print_err(const int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too shower", line_number);
}
