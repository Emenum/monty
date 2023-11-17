#include "monty.h"

/**
 * execute_file - reads lines from the bytecode and executes
 * the opcode read
 *
 * @stack: pointer to the top of the stack
 */
void execute_file(stack_t **stack)
{
	char *opcode = NULL;
	size_t len = 0;
	ssize_t r;
	unsigned int line_number = 0;

	while ((r = getline(&glob.line, &len, glob.file)) != -1)
	{
		line_number++;
		opcode = strtok(glob.line, " \n\t\a\r");
		glob.arg = strtok(NULL, " \n\t");

		if (opcode == NULL || *opcode == '#')
		{
			/**
			 * NULL means that nothing was read
			 * # means that a comment was encountered
			 */
			continue;
		}
		execute_opcode(opcode, stack, line_number);
	}
}

/**
 * execute_opcode - executes a single opcode
 * @opcode: opcode previously read, that needs to be executed
 * @stack: pointer to the top of the stack
 * @line_number: the number of the line in the monty bytecode
 * where the opcoe read comes from
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
}
