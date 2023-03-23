#include "monty.h"

/**
 * checkNexec - Checks for the opcode and executes the correspoding funtion
 * @stack: head of the d. linked list for the stack
 * @count: line_counter
 * @file: pointer to monty bytecode file
 * @content: line contents from bytecode file
 *
 * Return: Nothing
 */
int checkNexec(stack_t **stack, char *content, unsigned int count, FILE *file)
{
	char *op;
	unsigned int i = 0; /* for looping through the opcodes array */
	instruction_t opArray[] = {/* keywords and respective functions */
					{"push", _push}, {"pall", _pall}, {"pint", _pint},
					{"pop", _pop}, {"swap", _swap}, {NULL, NULL}
				 };

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	global.arg = strtok(NULL, " \n\t");

	while (op && opArray[i].opcode)
	{
		if (strcmp(op, opArray[i].opcode) == 0)
		{
			opArray[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (op && opArray[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, op);
		fclose(file);
		free(content);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
