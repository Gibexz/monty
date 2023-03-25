#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack
 * @head: head of the stack
 * @count: line_number
 *
 * Return: Nothing
 */
void _pstr(stack_t **head, unsigned int count)
{
	if (!(*head))
	{
		fprintf(stderr, "L%u: can't pstr, stack empty\n", count);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	while (*head)
	{
		if ((*head)->n > 127 || (*head)->n <= 0)
			break;
		fprintf(stdout, "%c", (*head)->n);
		*head = (*head)->next;
	}
	printf("\n");
}
