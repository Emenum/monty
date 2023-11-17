#include "monty.h"

/**
 * add_node - adds a new node at the top of the stack
 * @stack: pointer to the top of the stack
 * @n: value to be added to the new node
 * Return: return pointer to the node
 */
stack_t *add_node(stack_t **stack,  const int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	stack = &new_node; /*new node is top of stack*/

	return (new_node);
}

/**
 * free_stack - frees the stack_t by iterating through
 * the linked list and freeing all the nodes
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
