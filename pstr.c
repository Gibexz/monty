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
	if (!(*head));
	(void)count;
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", count);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}

	while (*head)
	{
		if ((*head)->n > 126  || (*head)->n < 32)
			break;
		fprintf(stdout, "%c", (*head)->n);
		/*_pchar(head, count);*/
		*head = (*head)->next;
	}
	printf("\n");
}
