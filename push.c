#include "monty.h"

/**
 * push - adds a new node at the top of the
 * stack
 * @stack: pointer to the top of the stack
 * @line_number: current line where the opcode is in the monty file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (glob.arg == NULL || !is_number(glob.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}

	n = atoi(glob.arg);
	if (add_node(stack, n) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_number - tests to see if the argument passed to push
 * is a number
 * @str: pointer to the string that represents
 * the argument passed to push
 * Return: 1 if it is a number and 0 if it is not
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	/* do a check to see if there is a + or - before the number*/
	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	/**
	 * if the argument passed to push (glob.arg)
	 * is not empty
	 * is not a null-terminating byte (\0)
	 * return (1) == TRUE
	 */
	return (1);
}
