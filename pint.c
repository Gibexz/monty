#include "monty.h"
/**
 * _pint - prints the top
 * @head: stack head
 * @count: line_number
 * Return: Nothing
*/
void _pint(stack_t **head, unsigned int count)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", count);
		fclose(global.file);
		free(global.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
