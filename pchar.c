#include "monty.h"

/**
 * _pchar -  prints the char at the top of the stack
 * @head: head of the stack
 * @count: line_number
 *
 * Return: Nothing
 */
void _pchar(stack_t **head, unsigned int count)
{
	int value;

	if (!(*head))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", count);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		value = (*head)->n;
		if (value > 127 || value < 0)
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", count);
			freeStack(*head);
			exit(EXIT_FAILURE);
		}
		else
			fprintf(stdout, "%c\n", value);
	}
}
